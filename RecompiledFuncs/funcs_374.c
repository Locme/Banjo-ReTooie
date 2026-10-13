#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808008DC_susubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008E4: jal         0x800D3948
    // 0x808008E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x808008E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008EC: beq         $v0, $zero, L_8080091C
    if (ctx->r2 == 0) {
        // 0x808008F0: nop
    
            goto L_8080091C;
    }
    // 0x808008F0: nop

    // 0x808008F4: jal         0x800F6438
    // 0x808008F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x808008F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808008FC: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800900: beq         $t6, $zero, L_80800930
    if (ctx->r14 == 0) {
        // 0x80800904: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800930;
    }
    // 0x80800904: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800908: jal         0x800A9420
    // 0x8080090C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A9420(rdram, ctx);
        goto after_2;
    // 0x8080090C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800910: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800914: b           L_80800930
    // 0x80800918: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80800930;
    // 0x80800918: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8080091C:
    // 0x8080091C: jal         0x800F54E4
    // 0x80800920: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800920: nop

    after_3:
    // 0x80800924: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800928: xor         $v0, $v0, $t8
    ctx->r2 = ctx->r2 ^ ctx->r24;
    // 0x8080092C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80800930:
    // 0x80800930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800938: jr          $ra
    // 0x8080093C: nop

    return;
    // 0x8080093C: nop

;}
RECOMP_FUNC void func_800F5CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5CC0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5CC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5CD0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5CD4: jal         0x8009EEAC
    // 0x800F5CD8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    bastick_getAngle(rdram, ctx);
        goto after_0;
    // 0x800F5CD8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5CE4: jr          $ra
    // 0x800F5CE8: nop

    return;
    // 0x800F5CE8: nop

;}
RECOMP_FUNC void func_808071D8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808071D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808071DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808071E0: jal         0x80091E6C
    // 0x808071E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80091E6C(rdram, ctx);
        goto after_0;
    // 0x808071E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808071E8: jal         0x800827D0
    // 0x808071EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808071EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808071F0: jal         0x80807C8C
    // 0x808071F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808071F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808071F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808071FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807200: jr          $ra
    // 0x80807204: nop

    return;
    // 0x80807204: nop

;}
RECOMP_FUNC void func_800DC548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC54C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC550: jal         0x800E9320
    // 0x800DC554: nop

    func_800E9320(rdram, ctx);
        goto after_0;
    // 0x800DC554: nop

    after_0:
    // 0x800DC558: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800DC55C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DC560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DC564: bne         $t6, $at, L_800DC574
    if (ctx->r14 != ctx->r1) {
        // 0x800DC568: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DC574;
    }
    // 0x800DC568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC56C: b           L_800DC574
    // 0x800DC570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DC574;
    // 0x800DC570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DC574:
    // 0x800DC574: jr          $ra
    // 0x800DC578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800DC578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC57C: nop

;}
RECOMP_FUNC void _gcstatusDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088320: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088320);
    return;
    // 0x80088324: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808002E0_chjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808002E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002EC: jal         0x800D8FF8
    // 0x808002F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808002F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002F4: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x808002F8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x80800304: bgezl       $t8, L_80800BD0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800308: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800BD0;
    }
    goto skip_0;
    // 0x80800308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080030C: jal         0x80100094
    // 0x80800310: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800310: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800318: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8080031C: jal         0x800897D8
    // 0x80800320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800324: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80800328: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8080032C: bgez        $t1, L_80800344
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800330: nop
    
            goto L_80800344;
    }
    // 0x80800330: nop

    // 0x80800334: jal         0x800E3980
    // 0x80800338: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_800E3980(rdram, ctx);
        goto after_3;
    // 0x80800338: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_3:
    // 0x8080033C: b           L_80800350
    // 0x80800340: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
        goto L_80800350;
    // 0x80800340: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
L_80800344:
    // 0x80800344: jal         0x8010D254
    // 0x80800348: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_8010D254(rdram, ctx);
        goto after_4;
    // 0x80800348: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_4:
    // 0x8080034C: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
L_80800350:
    // 0x80800350: addiu       $at, $zero, 0x48F
    ctx->r1 = ADD32(0, 0X48F);
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x8080035C: srl         $t4, $t3, 20
    ctx->r12 = S32(U32(ctx->r11) >> 20);
    // 0x80800360: bnel        $t4, $at, L_80800374
    if (ctx->r12 != ctx->r1) {
        // 0x80800364: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800374;
    }
    goto skip_1;
    // 0x80800364: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x80800368: jal         0x8010C908
    // 0x8080036C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_8010C908(rdram, ctx);
        goto after_5;
    // 0x8080036C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800370: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800374:
    // 0x80800374: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800378: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8080037C: jal         0x800F1E6C
    // 0x80800380: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800F1E6C(rdram, ctx);
        goto after_6;
    // 0x80800380: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_6:
    // 0x80800384: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800388: jal         0x800F1DCC
    // 0x8080038C: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    func_800F1DCC(rdram, ctx);
        goto after_7;
    // 0x8080038C: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    after_7:
    // 0x80800390: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80800394: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800398: srl         $t5, $v0, 10
    ctx->r13 = S32(U32(ctx->r2) >> 10);
    // 0x8080039C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x808003A0: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x808003A4: beq         $at, $zero, L_80800B80
    if (ctx->r1 == 0) {
        // 0x808003A8: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_80800B80;
    }
    // 0x808003A8: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x808003AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808003B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1672, 0X11C0) << 16);
    // 0x808003B4: addu        $at, $at, $t6
    gpr jr_addend_808003BC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808003B8: lw          $t6, 0x11C0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1672, 0X11C0));
    // 0x808003BC: jr          $t6
    // 0x808003C0: nop

    switch (jr_addend_808003BC >> 2) {
        case 0: goto L_808003C4; break;
        case 1: goto L_80800424; break;
        case 2: goto L_8080045C; break;
        case 3: goto L_80800494; break;
        case 4: goto L_80800B80; break;
        case 5: goto L_80800524; break;
        case 6: goto L_808005EC; break;
        case 7: goto L_808005EC; break;
        case 8: goto L_80800AE4; break;
        default: switch_error(__func__, 0x808003BC, 0x808011C0);
    }
    // 0x808003C0: nop

L_808003C4:
    // 0x808003C4: jal         0x800DC0C0
    // 0x808003C8: nop

    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x808003C8: nop

    after_8:
    // 0x808003CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1672, 0X11E4) << 16);
    // 0x808003D0: lwc1        $f4, 0x11E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1672, 0X11E4));
    // 0x808003D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808003D8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808003DC: nop

    // 0x808003E0: bc1fl       L_80800418
    if (!c1cs) {
        // 0x808003E4: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80800418;
    }
    goto skip_2;
    // 0x808003E4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x808003E8: jal         0x800901CC
    // 0x808003EC: lui         $a1, 0x425C
    ctx->r5 = S32(0X425C << 16);
    func_800901CC(rdram, ctx);
        goto after_9;
    // 0x808003EC: lui         $a1, 0x425C
    ctx->r5 = S32(0X425C << 16);
    after_9:
    // 0x808003F0: beq         $v0, $zero, L_8080040C
    if (ctx->r2 == 0) {
        // 0x808003F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080040C;
    }
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x80102424
    // 0x80800400: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x80800400: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800404: b           L_80800418
    // 0x80800408: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_80800418;
    // 0x80800408: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_8080040C:
    // 0x8080040C: jal         0x80102424
    // 0x80800410: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800410: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80800414: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800418:
    // 0x80800418: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x8080041C: b           L_80800B80
    // 0x80800420: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80800B80;
    // 0x80800420: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80800424:
    // 0x80800424: jal         0x80800F14
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F14_chjinjo(rdram, ctx);
        goto after_12;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080042C: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800430: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800434: jal         0x80101E14
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080043C: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x80800440: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080044C;
    }
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800444: jal         0x80102424
    // 0x80800448: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800448: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
L_8080044C:
    // 0x8080044C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800450: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x80800454: b           L_80800B80
    // 0x80800458: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_80800B80;
    // 0x80800458: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8080045C:
    // 0x8080045C: jal         0x80800F80
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F80_chjinjo(rdram, ctx);
        goto after_15;
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800464: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800468: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x8080046C: jal         0x80101E14
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_16;
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800474: beq         $v0, $zero, L_80800484
    if (ctx->r2 == 0) {
        // 0x80800478: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800484;
    }
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: jal         0x80102424
    // 0x80800480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x80800480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
L_80800484:
    // 0x80800484: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800488: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x8080048C: b           L_80800B80
    // 0x80800490: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80800B80;
    // 0x80800490: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80800494:
    // 0x80800494: jal         0x80800EE4
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800EE4_chjinjo(rdram, ctx);
        goto after_18;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080049C: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808004A0: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x808004A4: jal         0x80101E14
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_19;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808004AC: beq         $v0, $zero, L_808004C8
    if (ctx->r2 == 0) {
        // 0x808004B0: lwc1        $f6, 0x54($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
            goto L_808004C8;
    }
    // 0x808004B0: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: jal         0x80102424
    // 0x808004BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_20;
    // 0x808004BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808004C0: b           L_80800518
    // 0x808004C4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_80800518;
    // 0x808004C4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808004C8:
    // 0x808004C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808004CC: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808004D0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808004D4: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x808004D8: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808004DC: bc1fl       L_80800504
    if (!c1cs) {
        // 0x808004E0: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80800504;
    }
    goto skip_3;
    // 0x808004E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_3:
    // 0x808004E4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808004E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004EC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808004F0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808004F4: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x808004F8: b           L_80800514
    // 0x808004FC: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
        goto L_80800514;
    // 0x808004FC: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x80800500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80800504:
    // 0x80800504: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800508: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080050C: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80800510: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
L_80800514:
    // 0x80800514: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800518:
    // 0x80800518: srl         $t0, $v0, 10
    ctx->r8 = S32(U32(ctx->r2) >> 10);
    // 0x8080051C: b           L_80800B80
    // 0x80800520: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80800B80;
    // 0x80800520: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80800524:
    // 0x80800524: jal         0x80800EE4
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800EE4_chjinjo(rdram, ctx);
        goto after_21;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080052C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800530: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800534: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800538: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8080053C: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80800540: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800548: bc1fl       L_80800570
    if (!c1cs) {
        // 0x8080054C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80800570;
    }
    goto skip_4;
    // 0x8080054C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_4:
    // 0x80800550: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800554: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800558: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080055C: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80800560: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80800564: b           L_80800580
    // 0x80800568: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
        goto L_80800580;
    // 0x80800568: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x8080056C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80800570:
    // 0x80800570: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800574: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800578: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8080057C: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
L_80800580:
    // 0x80800580: jal         0x80101E14
    // 0x80800584: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101E14(rdram, ctx);
        goto after_22;
    // 0x80800584: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_22:
    // 0x80800588: beql        $v0, $zero, L_808005E0
    if (ctx->r2 == 0) {
        // 0x8080058C: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_808005E0;
    }
    goto skip_5;
    // 0x8080058C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_5:
    // 0x80800590: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: srl         $t1, $v0, 4
    ctx->r9 = S32(U32(ctx->r2) >> 4);
    // 0x8080059C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x808005A0: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x808005A4: andi        $t5, $v0, 0xFF0F
    ctx->r13 = ctx->r2 & 0XFF0F;
    // 0x808005A8: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x808005AC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x808005B0: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x808005B4: bne         $t8, $zero, L_808005DC
    if (ctx->r24 != 0) {
        // 0x808005B8: sb          $t6, 0x79($s0)
        MEM_B(0X79, ctx->r16) = ctx->r14;
            goto L_808005DC;
    }
    // 0x808005B8: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
    // 0x808005BC: jal         0x80102424
    // 0x808005C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_23;
    // 0x808005C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_23:
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C8: jal         0x80102FE8
    // 0x808005CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80102FE8(rdram, ctx);
        goto after_24;
    // 0x808005CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x808005D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808005D4: jal         0x800FC63C
    // 0x808005D8: addiu       $a1, $zero, 0x6D60
    ctx->r5 = ADD32(0, 0X6D60);
    func_800FC63C(rdram, ctx);
        goto after_25;
    // 0x808005D8: addiu       $a1, $zero, 0x6D60
    ctx->r5 = ADD32(0, 0X6D60);
    after_25:
L_808005DC:
    // 0x808005DC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808005E0:
    // 0x808005E0: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x808005E4: b           L_80800B80
    // 0x808005E8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80800B80;
    // 0x808005E8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_808005EC:
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: jal         0x80100094
    // 0x808005F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_26;
    // 0x808005F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x808005F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808005FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800600: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800604: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800608: jal         0x800897E8
    // 0x8080060C: nop

    _suexpression_entrypoint_12(rdram, ctx);
        goto after_27;
    // 0x8080060C: nop

    after_27:
    // 0x80800610: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x80800614: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80800618: xori        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 ^ 0X7;
    // 0x8080061C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80800620: beq         $t2, $zero, L_80800648
    if (ctx->r10 == 0) {
        // 0x80800624: sw          $t2, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r10;
            goto L_80800648;
    }
    // 0x80800624: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x80800628: jal         0x80101F24
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_28;
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800630: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1672, 0X11E8) << 16);
    // 0x80800634: lwc1        $f6, 0x11E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1672, 0X11E8));
    // 0x80800638: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8080063C: nop

    // 0x80800640: bc1fl       L_80800770
    if (!c1cs) {
        // 0x80800644: lw          $t4, 0x58($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X58);
            goto L_80800770;
    }
    goto skip_6;
    // 0x80800644: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    skip_6:
L_80800648:
    // 0x80800648: jal         0x8008FFBC
    // 0x8080064C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_8008FFBC(rdram, ctx);
        goto after_29;
    // 0x8080064C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_29:
    // 0x80800650: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800654: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800658: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8080065C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80800660: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800664: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800668: jal         0x800EF334
    // 0x8080066C: nop

    func_800EF334(rdram, ctx);
        goto after_30;
    // 0x8080066C: nop

    after_30:
    // 0x80800670: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80800674: jal         0x800EF04C
    // 0x80800678: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_800EF04C(rdram, ctx);
        goto after_31;
    // 0x80800678: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_31:
    // 0x8080067C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80800680: jal         0x800EF3DC
    // 0x80800684: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EF3DC(rdram, ctx);
        goto after_32;
    // 0x80800684: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_32:
    // 0x80800688: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080068C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800690: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800694: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80800698: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8080069C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808006A0: jal         0x800EF334
    // 0x808006A4: nop

    func_800EF334(rdram, ctx);
        goto after_33;
    // 0x808006A4: nop

    after_33:
    // 0x808006A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808006AC: jal         0x800EF04C
    // 0x808006B0: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_800EF04C(rdram, ctx);
        goto after_34;
    // 0x808006B0: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_34:
    // 0x808006B4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x808006B8: bnel        $t3, $zero, L_808006E4
    if (ctx->r11 != 0) {
        // 0x808006BC: sw          $zero, 0x60($sp)
        MEM_W(0X60, ctx->r29) = 0;
            goto L_808006E4;
    }
    goto skip_7;
    // 0x808006BC: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    skip_7:
    // 0x808006C0: jal         0x80101F24
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_35;
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808006C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1672, 0X11EC) << 16);
    // 0x808006CC: lwc1        $f8, 0x11EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1672, 0X11EC));
    // 0x808006D0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808006D4: nop

    // 0x808006D8: bc1fl       L_80800770
    if (!c1cs) {
        // 0x808006DC: lw          $t4, 0x58($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X58);
            goto L_80800770;
    }
    goto skip_8;
    // 0x808006DC: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    skip_8:
    // 0x808006E0: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_808006E4:
    // 0x808006E4: jal         0x800DC0C0
    // 0x808006E8: nop

    func_800DC0C0(rdram, ctx);
        goto after_36;
    // 0x808006E8: nop

    after_36:
    // 0x808006EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1672, 0X11F0) << 16);
    // 0x808006F0: lwc1        $f10, 0x11F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1672, 0X11F0));
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808006FC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800700: nop

    // 0x80800704: bc1fl       L_8080075C
    if (!c1cs) {
        // 0x80800708: lw          $v0, 0x60($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X60);
            goto L_8080075C;
    }
    goto skip_9;
    // 0x80800708: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    skip_9:
    // 0x8080070C: jal         0x8008A0D0
    // 0x80800710: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_37;
    // 0x80800710: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_37:
    // 0x80800714: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800718: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080071C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800720: jal         0x800DC178
    // 0x80800724: nop

    func_800DC178(rdram, ctx);
        goto after_38;
    // 0x80800724: nop

    after_38:
    // 0x80800728: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8080072C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800730: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800734: jal         0x800DC178
    // 0x80800738: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_39;
    // 0x80800738: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_39:
    // 0x8080073C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800740: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800744: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800748: jal         0x800EF214
    // 0x8080074C: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    func_800EF214(rdram, ctx);
        goto after_40;
    // 0x8080074C: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    after_40:
    // 0x80800750: jal         0x80088AA8
    // 0x80800754: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    _fxtwinkle_entrypoint_0(rdram, ctx);
        goto after_41;
    // 0x80800754: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_41:
    // 0x80800758: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
L_8080075C:
    // 0x8080075C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800760: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800764: bne         $v0, $at, L_808006E4
    if (ctx->r2 != ctx->r1) {
        // 0x80800768: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_808006E4;
    }
    // 0x80800768: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x8080076C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
L_80800770:
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800774: lui         $a1, 0x3E5B
    ctx->r5 = S32(0X3E5B << 16);
    // 0x80800778: beq         $t4, $zero, L_808008CC
    if (ctx->r12 == 0) {
        // 0x8080077C: nop
    
            goto L_808008CC;
    }
    // 0x8080077C: nop

    // 0x80800780: jal         0x80101F24
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_42;
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80800788: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1672, 0X11F4) << 16);
    // 0x8080078C: lwc1        $f18, 0x11F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1672, 0X11F4));
    // 0x80800790: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800798: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8080079C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808007A0: bc1f        L_808007F4
    if (!c1cs) {
        // 0x808007A4: nop
    
            goto L_808007F4;
    }
    // 0x808007A4: nop

    // 0x808007A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808007AC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808007B0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808007B4: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x808007B8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808007BC: bc1fl       L_808007E4
    if (!c1cs) {
        // 0x808007C0: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_808007E4;
    }
    goto skip_10;
    // 0x808007C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_10:
    // 0x808007C4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808007C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007CC: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808007D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808007D4: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x808007D8: b           L_808007F4
    // 0x808007DC: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
        goto L_808007F4;
    // 0x808007DC: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x808007E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_808007E4:
    // 0x808007E4: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808007E8: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x808007EC: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x808007F0: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
L_808007F4:
    // 0x808007F4: jal         0x80101E14
    // 0x808007F8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_43;
    // 0x808007F8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_43:
    // 0x808007FC: beq         $v0, $zero, L_80800870
    if (ctx->r2 == 0) {
        // 0x80800800: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800870;
    }
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800804: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1672, 0X137C) << 16);
    // 0x80800808: addiu       $a3, $a3, 0x137C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1672, 0X137C));
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800814: jal         0x80089D50
    // 0x80800818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_44;
    // 0x80800818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_44:
    // 0x8080081C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800820: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x80800824: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800828: jal         0x800FC63C
    // 0x8080082C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    func_800FC63C(rdram, ctx);
        goto after_45;
    // 0x8080082C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_45:
    // 0x80800830: jal         0x800FCA90
    // 0x80800834: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FCA90(rdram, ctx);
        goto after_46;
    // 0x80800834: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_46:
    // 0x80800838: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080083C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800840: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800844: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800848: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x8080084C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800850: addiu       $a0, $zero, 0x4A2
    ctx->r4 = ADD32(0, 0X4A2);
    // 0x80800854: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    // 0x80800858: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8080085C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800860: jal         0x800C4244
    // 0x80800864: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800C4244(rdram, ctx);
        goto after_47;
    // 0x80800864: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_47:
    // 0x80800868: b           L_80800A98
    // 0x8080086C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
        goto L_80800A98;
    // 0x8080086C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_80800870:
    // 0x80800870: lui         $a1, 0x3EDE
    ctx->r5 = S32(0X3EDE << 16);
    // 0x80800874: jal         0x80101E14
    // 0x80800878: ori         $a1, $a1, 0x353F
    ctx->r5 = ctx->r5 | 0X353F;
    func_80101E14(rdram, ctx);
        goto after_48;
    // 0x80800878: ori         $a1, $a1, 0x353F
    ctx->r5 = ctx->r5 | 0X353F;
    after_48:
    // 0x8080087C: bne         $v0, $zero, L_80800894
    if (ctx->r2 != 0) {
        // 0x80800880: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800894;
    }
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800884: lui         $a1, 0x3F4F
    ctx->r5 = S32(0X3F4F << 16);
    // 0x80800888: jal         0x80101E14
    // 0x8080088C: ori         $a1, $a1, 0x9DB2
    ctx->r5 = ctx->r5 | 0X9DB2;
    func_80101E14(rdram, ctx);
        goto after_49;
    // 0x8080088C: ori         $a1, $a1, 0x9DB2
    ctx->r5 = ctx->r5 | 0X9DB2;
    after_49:
    // 0x80800890: beq         $v0, $zero, L_80800A94
    if (ctx->r2 == 0) {
        // 0x80800894: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_80800A94;
    }
L_80800894:
    // 0x80800894: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800898: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080089C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x808008A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808008A4: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808008A8: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808008AC: addiu       $a0, $zero, 0x4A2
    ctx->r4 = ADD32(0, 0X4A2);
    // 0x808008B0: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    // 0x808008B4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808008B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808008BC: jal         0x800C4244
    // 0x808008C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800C4244(rdram, ctx);
        goto after_50;
    // 0x808008C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_50:
    // 0x808008C4: b           L_80800A98
    // 0x808008C8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
        goto L_80800A98;
    // 0x808008C8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_808008CC:
    // 0x808008CC: jal         0x80101E14
    // 0x808008D0: ori         $a1, $a1, 0x22D1
    ctx->r5 = ctx->r5 | 0X22D1;
    func_80101E14(rdram, ctx);
        goto after_51;
    // 0x808008D0: ori         $a1, $a1, 0x22D1
    ctx->r5 = ctx->r5 | 0X22D1;
    after_51:
    // 0x808008D4: beq         $v0, $zero, L_80800914
    if (ctx->r2 == 0) {
        // 0x808008D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800914;
    }
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008DC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808008E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008E4: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x808008E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808008EC: lui         $a1, 0x3F8C
    ctx->r5 = S32(0X3F8C << 16);
    // 0x808008F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808008F4: addiu       $a0, $zero, 0x4A2
    ctx->r4 = ADD32(0, 0X4A2);
    // 0x808008F8: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    // 0x808008FC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800900: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80800904: jal         0x800C4244
    // 0x80800908: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C4244(rdram, ctx);
        goto after_52;
    // 0x80800908: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_52:
    // 0x8080090C: b           L_808009C8
    // 0x80800910: nop

        goto L_808009C8;
    // 0x80800910: nop

L_80800914:
    // 0x80800914: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x80800918: jal         0x80101E14
    // 0x8080091C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_53;
    // 0x8080091C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_53:
    // 0x80800920: beq         $v0, $zero, L_8080095C
    if (ctx->r2 == 0) {
        // 0x80800924: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080095C;
    }
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800928: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080092C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800930: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800934: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800938: addiu       $a0, $zero, 0x43A
    ctx->r4 = ADD32(0, 0X43A);
    // 0x8080093C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80800940: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    // 0x80800944: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800948: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8080094C: jal         0x800C4244
    // 0x80800950: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800C4244(rdram, ctx);
        goto after_54;
    // 0x80800950: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_54:
    // 0x80800954: b           L_808009C8
    // 0x80800958: nop

        goto L_808009C8;
    // 0x80800958: nop

L_8080095C:
    // 0x8080095C: jal         0x80101E14
    // 0x80800960: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80101E14(rdram, ctx);
        goto after_55;
    // 0x80800960: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_55:
    // 0x80800964: beq         $v0, $zero, L_80800998
    if (ctx->r2 == 0) {
        // 0x80800968: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800998;
    }
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080096C: jal         0x800FCCD4
    // 0x80800970: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FCCD4(rdram, ctx);
        goto after_56;
    // 0x80800970: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_56:
    // 0x80800974: beq         $v0, $zero, L_808009C8
    if (ctx->r2 == 0) {
        // 0x80800978: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_808009C8;
    }
    // 0x80800978: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080097C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800980: jal         0x800FCAE0
    // 0x80800984: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    func_800FCAE0(rdram, ctx);
        goto after_57;
    // 0x80800984: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    after_57:
    // 0x80800988: jal         0x800FCA90
    // 0x8080098C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FCA90(rdram, ctx);
        goto after_58;
    // 0x8080098C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_58:
    // 0x80800990: b           L_808009C8
    // 0x80800994: nop

        goto L_808009C8;
    // 0x80800994: nop

L_80800998:
    // 0x80800998: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x8080099C: jal         0x80101E14
    // 0x808009A0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_59;
    // 0x808009A0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_59:
    // 0x808009A4: beq         $v0, $zero, L_808009C8
    if (ctx->r2 == 0) {
        // 0x808009A8: nop
    
            goto L_808009C8;
    }
    // 0x808009A8: nop

    // 0x808009AC: jal         0x80089D40
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_60;
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x808009B4: jal         0x800C3EB8
    // 0x808009B8: addiu       $a0, $zero, 0x411
    ctx->r4 = ADD32(0, 0X411);
    func_800C3EB8(rdram, ctx);
        goto after_61;
    // 0x808009B8: addiu       $a0, $zero, 0x411
    ctx->r4 = ADD32(0, 0X411);
    after_61:
    // 0x808009BC: jal         0x800FC74C
    // 0x808009C0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FC74C(rdram, ctx);
        goto after_62;
    // 0x808009C0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_62:
    // 0x808009C4: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
L_808009C8:
    // 0x808009C8: jal         0x80101F24
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_63;
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x808009D0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808009D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808009D8: nop

    // 0x808009DC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808009E0: nop

    // 0x808009E4: bc1fl       L_80800A4C
    if (!c1cs) {
        // 0x808009E8: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_80800A4C;
    }
    goto skip_11;
    // 0x808009E8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    skip_11:
    // 0x808009EC: jal         0x80089C90
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_64;
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
    // 0x808009F4: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x808009F8: bne         $at, $zero, L_80800A04
    if (ctx->r1 != 0) {
        // 0x808009FC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800A04;
    }
    // 0x808009FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800A00: addiu       $a1, $v0, -0x7
    ctx->r5 = ADD32(ctx->r2, -0X7);
L_80800A04:
    // 0x80800A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A08: jal         0x80101F24
    // 0x80800A0C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_80101F24(rdram, ctx);
        goto after_65;
    // 0x80800A0C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_65:
    // 0x80800A10: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1672, 0X11F8) << 16);
    // 0x80800A14: lwc1        $f18, 0x11F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1672, 0X11F8));
    // 0x80800A18: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80800A1C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80800A20: slti        $at, $a1, 0x15
    ctx->r1 = SIGNED(ctx->r5) < 0X15 ? 1 : 0;
    // 0x80800A24: bc1f        L_80800A40
    if (!c1cs) {
        // 0x80800A28: nop
    
            goto L_80800A40;
    }
    // 0x80800A28: nop

    // 0x80800A2C: bnel        $at, $zero, L_80800A40
    if (ctx->r1 != 0) {
        // 0x80800A30: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800A40;
    }
    goto skip_12;
    // 0x80800A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_12:
    // 0x80800A34: b           L_80800A40
    // 0x80800A38: addiu       $a1, $a1, -0x15
    ctx->r5 = ADD32(ctx->r5, -0X15);
        goto L_80800A40;
    // 0x80800A38: addiu       $a1, $a1, -0x15
    ctx->r5 = ADD32(ctx->r5, -0X15);
    // 0x80800A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800A40:
    // 0x80800A40: jal         0x80089C98
    // 0x80800A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_66;
    // 0x80800A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x80800A48: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
L_80800A4C:
    // 0x80800A4C: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800A50: jal         0x80101E14
    // 0x80800A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_67;
    // 0x80800A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x80800A58: beq         $v0, $zero, L_80800A94
    if (ctx->r2 == 0) {
        // 0x80800A5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A94;
    }
    // 0x80800A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A60: jal         0x80102424
    // 0x80800A64: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_68;
    // 0x80800A64: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_68:
    // 0x80800A68: lbu         $t6, 0x75($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X75);
    // 0x80800A6C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800A70: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800A74: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
    // 0x80800A78: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x80800A7C: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x80800A80: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x80800A84: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80800A88: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80800A8C: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800A90: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_80800A94:
    // 0x80800A94: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_80800A98:
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A9C: lui         $a1, 0x3F75
    ctx->r5 = S32(0X3F75 << 16);
    // 0x80800AA0: beql        $t5, $zero, L_80800AD8
    if (ctx->r13 == 0) {
        // 0x80800AA4: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80800AD8;
    }
    goto skip_13;
    // 0x80800AA4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_13:
    // 0x80800AA8: jal         0x80101E14
    // 0x80800AAC: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    func_80101E14(rdram, ctx);
        goto after_69;
    // 0x80800AAC: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    after_69:
    // 0x80800AB0: bne         $v0, $zero, L_80800AC8
    if (ctx->r2 != 0) {
        // 0x80800AB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AC8;
    }
    // 0x80800AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800ABC: jal         0x80101E14
    // 0x80800AC0: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_70;
    // 0x80800AC0: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_70:
    // 0x80800AC4: beq         $v0, $zero, L_80800AD4
    if (ctx->r2 == 0) {
        // 0x80800AC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AD4;
    }
L_80800AC8:
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ACC: jal         0x80102424
    // 0x80800AD0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_71;
    // 0x80800AD0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_71:
L_80800AD4:
    // 0x80800AD4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800AD8:
    // 0x80800AD8: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800ADC: b           L_80800B80
    // 0x80800AE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80800B80;
    // 0x80800AE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80800AE4:
    // 0x80800AE4: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80800AE8: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80800AEC: bgez        $t9, L_80800B6C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800AF0: nop
    
            goto L_80800B6C;
    }
    // 0x80800AF0: nop

    // 0x80800AF4: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800AF8: andi        $t0, $a0, 0x1FF
    ctx->r8 = ctx->r4 & 0X1FF;
    // 0x80800AFC: jal         0x800D0CC8
    // 0x80800B00: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800D0CC8(rdram, ctx);
        goto after_72;
    // 0x80800B00: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_72:
    // 0x80800B04: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B10: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x80800B14: bgez        $t3, L_80800B4C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800B18: nop
    
            goto L_80800B4C;
    }
    // 0x80800B18: nop

    // 0x80800B1C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80800B20: jal         0x800F82D4
    // 0x80800B24: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    func_800F82D4(rdram, ctx);
        goto after_73;
    // 0x80800B24: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_73:
    // 0x80800B28: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800B2C: addiu       $a0, $zero, 0x6D0
    ctx->r4 = ADD32(0, 0X6D0);
    // 0x80800B30: jal         0x800DA7A8
    // 0x80800B34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800DA7A8(rdram, ctx);
        goto after_74;
    // 0x80800B34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_74:
    // 0x80800B38: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    // 0x80800B3C: jal         0x800887D8
    // 0x80800B40: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_75;
    // 0x80800B40: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    after_75:
    // 0x80800B44: b           L_80800B58
    // 0x80800B48: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
        goto L_80800B58;
    // 0x80800B48: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
L_80800B4C:
    // 0x80800B4C: jal         0x8080102C
    // 0x80800B50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080102C_chjinjo(rdram, ctx);
        goto after_76;
    // 0x80800B50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_76:
    // 0x80800B54: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
L_80800B58:
    // 0x80800B58: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800B5C: andi        $t5, $t4, 0xFFBF
    ctx->r13 = ctx->r12 & 0XFFBF;
    // 0x80800B60: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x80800B64: sb          $t5, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r13;
    // 0x80800B68: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_80800B6C:
    // 0x80800B6C: jal         0x800FFAB0
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_77;
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_77:
    // 0x80800B74: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800B78: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x80800B7C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80800B80:
    // 0x80800B80: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80800B84: beq         $at, $zero, L_80800BCC
    if (ctx->r1 == 0) {
        // 0x80800B88: lwc1        $f10, 0x54($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
            goto L_80800BCC;
    }
    // 0x80800B88: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800B8C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800B90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B94: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B9C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800BA0: nop

    // 0x80800BA4: bc1t        L_80800BC4
    if (c1cs) {
        // 0x80800BA8: nop
    
            goto L_80800BC4;
    }
    // 0x80800BA8: nop

    // 0x80800BAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800BB0: nop

    // 0x80800BB4: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80800BB8: nop

    // 0x80800BBC: bc1fl       L_80800BD0
    if (!c1cs) {
        // 0x80800BC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800BD0;
    }
    goto skip_14;
    // 0x80800BC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_14:
L_80800BC4:
    // 0x80800BC4: jal         0x80102424
    // 0x80800BC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_78;
    // 0x80800BC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_78:
L_80800BCC:
    // 0x80800BCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BD0:
    // 0x80800BD0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800BD4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80800BD8: jr          $ra
    // 0x80800BDC: nop

    return;
    // 0x80800BDC: nop

;}
RECOMP_FUNC void _chcoderoombits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086290: syscall     299
    recomp_syscall_handler(rdram, ctx, 0x80086290);
    return;
    // 0x80086294: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chflysaucerdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D18: syscall     448
    recomp_syscall_handler(rdram, ctx, 0x80086D18);
    return;
    // 0x80086D1C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800184E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800184E8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800184EC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800184F0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800184F4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800184F8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800184FC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80018500: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80018504: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80018508: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001850C: jal         0x80016934
    // 0x80018510: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80016934(rdram, ctx);
        goto after_0;
    // 0x80018510: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80018514: jal         0x80016928
    // 0x80018518: nop

    func_80016928(rdram, ctx);
        goto after_1;
    // 0x80018518: nop

    after_1:
    // 0x8001851C: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80018520: addiu       $s3, $s3, -0x50F4
    ctx->r19 = ADD32(ctx->r19, -0X50F4);
    // 0x80018524: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80018528: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8001852C: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80018530: addiu       $s2, $s2, -0x4D14
    ctx->r18 = ADD32(ctx->r18, -0X4D14);
    // 0x80018534: addiu       $s1, $s1, -0x4D30
    ctx->r17 = ADD32(ctx->r17, -0X4D30);
    // 0x80018538: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001853C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x80018540: addiu       $s5, $zero, 0xB
    ctx->r21 = ADD32(0, 0XB);
    // 0x80018544: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_80018548:
    // 0x80018548: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8001854C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80018550: jal         0x80030A10
    // 0x80018554: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_2;
    // 0x80018554: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80018558: beq         $v0, $s4, L_80018568
    if (ctx->r2 == ctx->r20) {
        // 0x8001855C: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80018568;
    }
    // 0x8001855C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80018560: bnel        $v0, $s5, L_80018578
    if (ctx->r2 != ctx->r21) {
        // 0x80018564: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80018578;
    }
    goto skip_0;
    // 0x80018564: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
L_80018568:
    // 0x80018568: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8001856C: jal         0x800308B4
    // 0x80018570: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80018570: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80018574: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80018578:
    // 0x80018578: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8001857C: addiu       $s1, $s1, 0x84
    ctx->r17 = ADD32(ctx->r17, 0X84);
    // 0x80018580: addiu       $s2, $s2, 0x84
    ctx->r18 = ADD32(ctx->r18, 0X84);
    // 0x80018584: sw          $v1, -0x84($s1)
    MEM_W(-0X84, ctx->r17) = ctx->r3;
    // 0x80018588: bne         $s0, $s6, L_80018548
    if (ctx->r16 != ctx->r22) {
        // 0x8001858C: sw          $v1, -0x80($s1)
        MEM_W(-0X80, ctx->r17) = ctx->r3;
            goto L_80018548;
    }
    // 0x8001858C: sw          $v1, -0x80($s1)
    MEM_W(-0X80, ctx->r17) = ctx->r3;
    // 0x80018590: jal         0x80016934
    // 0x80018594: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80016934(rdram, ctx);
        goto after_4;
    // 0x80018594: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80018598: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8001859C: addiu       $s0, $s0, -0x5110
    ctx->r16 = ADD32(ctx->r16, -0X5110);
    // 0x800185A0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800185A4: addiu       $a1, $a1, -0x50F8
    ctx->r5 = ADD32(ctx->r5, -0X50F8);
    // 0x800185A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800185AC: jal         0x8002E070
    // 0x800185B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x800185B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800185B4: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x800185B8: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800185BC: addiu       $s1, $s1, -0x50F0
    ctx->r17 = ADD32(ctx->r17, -0X50F0);
    // 0x800185C0: addiu       $t6, $t6, -0x4D30
    ctx->r14 = ADD32(ctx->r14, -0X4D30);
    // 0x800185C4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800185C8: lui         $a3, 0x8002
    ctx->r7 = S32(0X8002 << 16);
    // 0x800185CC: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
    // 0x800185D0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800185D4: addiu       $a3, $a3, -0x7E84
    ctx->r7 = ADD32(ctx->r7, -0X7E84);
    // 0x800185D8: addiu       $a1, $a1, -0x4F40
    ctx->r5 = ADD32(ctx->r5, -0X4F40);
    // 0x800185DC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800185E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800185E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800185E8: jal         0x8001DCB0
    // 0x800185EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001DCB0(rdram, ctx);
        goto after_6;
    // 0x800185EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x800185F0: jal         0x8002E510
    // 0x800185F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_7;
    // 0x800185F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x800185F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800185FC: jal         0x80014F64
    // 0x80018600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80014F64(rdram, ctx);
        goto after_8;
    // 0x80018600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80018604: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80018608: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001860C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80018610: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80018614: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80018618: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8001861C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80018620: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80018624: jr          $ra
    // 0x80018628: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80018628: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8001559C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001559C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800155A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800155A4: jal         0x8002FBB0
    // 0x800155A8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    osViBlack_recomp(rdram, ctx);
        goto after_0;
    // 0x800155A8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_0:
    // 0x800155AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800155B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800155B4: jr          $ra
    // 0x800155B8: nop

    return;
    // 0x800155B8: nop

;}
RECOMP_FUNC void func_80800AB0_chpufferfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800AB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800AB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800ABC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800AC0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800AC4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80800AC8: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x80800ACC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AD0: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x80800AD4: srl         $t6, $a1, 26
    ctx->r14 = S32(U32(ctx->r5) >> 26);
    // 0x80800AD8: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80800ADC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80800AE0: jal         0x800CC63C
    // 0x80800AE4: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_0;
    // 0x80800AE4: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    after_0:
    // 0x80800AE8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800AEC: lh          $t7, 0xE($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE);
    // 0x80800AF0: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800AF4: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800AF8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800AFC: nop

    // 0x80800B00: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800B04: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80800B08: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80800B0C: nop

    // 0x80800B10: bc1f        L_80800B34
    if (!c1cs) {
        // 0x80800B14: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80800B34;
    }
    // 0x80800B14: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800B18: lui         $a1, 0x43B1
    ctx->r5 = S32(0X43B1 << 16);
    // 0x80800B1C: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80800B20: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800B24: jal         0x80102950
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102950(rdram, ctx);
        goto after_1;
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B2C: b           L_80800B6C
    // 0x80800B30: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
        goto L_80800B6C;
    // 0x80800B30: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
L_80800B34:
    // 0x80800B34: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80800B38: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B40: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80800B44: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80800B48: nop

    // 0x80800B4C: bc1fl       L_80800B68
    if (!c1cs) {
        // 0x80800B50: sw          $zero, 0x40($sp)
        MEM_W(0X40, ctx->r29) = 0;
            goto L_80800B68;
    }
    goto skip_0;
    // 0x80800B50: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    skip_0:
    // 0x80800B54: jal         0x80102950
    // 0x80800B58: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    func_80102950(rdram, ctx);
        goto after_2;
    // 0x80800B58: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    after_2:
    // 0x80800B5C: b           L_80800B6C
    // 0x80800B60: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
        goto L_80800B6C;
    // 0x80800B60: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80800B64: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80800B68:
    // 0x80800B68: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
L_80800B6C:
    // 0x80800B6C: andi        $t1, $t0, 0x6
    ctx->r9 = ctx->r8 & 0X6;
    // 0x80800B70: beq         $t1, $zero, L_80800C50
    if (ctx->r9 == 0) {
        // 0x80800B74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C50;
    }
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B78: jal         0x8010CE28
    // 0x80800B7C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_8010CE28(rdram, ctx);
        goto after_3;
    // 0x80800B7C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_3:
    // 0x80800B80: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80800B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B88: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800B8C: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80800B90: beq         $t3, $zero, L_80800BA8
    if (ctx->r11 == 0) {
        // 0x80800B94: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800BA8;
    }
    // 0x80800B94: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800B98: jal         0x80102924
    // 0x80800B9C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_80102924(rdram, ctx);
        goto after_4;
    // 0x80800B9C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x80800BA0: b           L_80800BC4
    // 0x80800BA4: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
        goto L_80800BC4;
    // 0x80800BA4: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
L_80800BA8:
    // 0x80800BA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800BAC: jal         0x800136E4
    // 0x80800BB0: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x80800BB0: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    after_5:
    // 0x80800BB4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BB8: jal         0x80102924
    // 0x80800BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102924(rdram, ctx);
        goto after_6;
    // 0x80800BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800BC0: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
L_80800BC4:
    // 0x80800BC4: jal         0x800136E4
    // 0x80800BC8: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x80800BC8: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    after_7:
    // 0x80800BCC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800BD0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800BD4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800BD8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800BDC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE4: bc1f        L_80800C0C
    if (!c1cs) {
        // 0x80800BE8: nop
    
            goto L_80800C0C;
    }
    // 0x80800BE8: nop

    // 0x80800BEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800BF0: nop

    // 0x80800BF4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800BF8: nop

    // 0x80800BFC: bc1f        L_80800C0C
    if (!c1cs) {
        // 0x80800C00: nop
    
            goto L_80800C0C;
    }
    // 0x80800C00: nop

    // 0x80800C04: b           L_80800C44
    // 0x80800C08: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_80800C44;
    // 0x80800C08: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_80800C0C:
    // 0x80800C0C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X113C) << 16);
    // 0x80800C10: lwc1        $f12, 0x113C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X113C));
    // 0x80800C14: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800C18: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80800C1C: nop

    // 0x80800C20: bc1fl       L_80800C48
    if (!c1cs) {
        // 0x80800C24: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_80800C48;
    }
    goto skip_1;
    // 0x80800C24: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_1:
    // 0x80800C28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C2C: nop

    // 0x80800C30: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800C34: nop

    // 0x80800C38: bc1fl       L_80800C48
    if (!c1cs) {
        // 0x80800C3C: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_80800C48;
    }
    goto skip_2;
    // 0x80800C3C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_2:
    // 0x80800C40: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_80800C44:
    // 0x80800C44: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_80800C48:
    // 0x80800C48: jal         0x80102950
    // 0x80800C4C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    func_80102950(rdram, ctx);
        goto after_8;
    // 0x80800C4C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    after_8:
L_80800C50:
    // 0x80800C50: jal         0x800D90A4
    // 0x80800C54: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    func_800D90A4(rdram, ctx);
        goto after_9;
    // 0x80800C54: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    after_9:
    // 0x80800C58: beq         $v0, $zero, L_80800CF8
    if (ctx->r2 == 0) {
        // 0x80800C5C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80800CF8;
    }
    // 0x80800C5C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800C60: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C64: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800C68: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C6C: jal         0x800DC178
    // 0x80800C70: nop

    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x80800C70: nop

    after_10:
    // 0x80800C74: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800C78: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80800C7C: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800C80: jal         0x800DC178
    // 0x80800C84: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80800C84: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    after_11:
    // 0x80800C88: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800C8C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80800C90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1140) << 16);
    // 0x80800C94: bnel        $t4, $zero, L_80800CBC
    if (ctx->r12 != 0) {
        // 0x80800C98: lw          $t5, 0x54($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X54);
            goto L_80800CBC;
    }
    goto skip_3;
    // 0x80800C98: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x80800C9C: lwc1        $f12, 0x1140($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1140));
    // 0x80800CA0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1144) << 16);
    // 0x80800CA4: jal         0x800DC178
    // 0x80800CA8: lwc1        $f14, 0x1144($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1144));
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80800CA8: lwc1        $f14, 0x1144($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1144));
    after_12:
    // 0x80800CAC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800CB0: jal         0x80102950
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102950(rdram, ctx);
        goto after_13;
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800CB8: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
L_80800CBC:
    // 0x80800CBC: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x80800CC0: andi        $t6, $t5, 0x5
    ctx->r14 = ctx->r13 & 0X5;
    // 0x80800CC4: beql        $t6, $zero, L_80800CFC
    if (ctx->r14 == 0) {
        // 0x80800CC8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80800CFC;
    }
    goto skip_4;
    // 0x80800CC8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_4:
    // 0x80800CCC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800CD0: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80800CD4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800CD8: jal         0x800DC178
    // 0x80800CDC: nop

    func_800DC178(rdram, ctx);
        goto after_14;
    // 0x80800CDC: nop

    after_14:
    // 0x80800CE0: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800CEC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800CF0: jal         0x80102924
    // 0x80800CF4: nop

    func_80102924(rdram, ctx);
        goto after_15;
    // 0x80800CF4: nop

    after_15:
L_80800CF8:
    // 0x80800CF8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_80800CFC:
    // 0x80800CFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800D00: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800D04: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800D08: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800D0C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800D10: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D18: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800D1C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800D20: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800D24: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800D28: jal         0x8008A4E8
    // 0x80800D2C: nop

    _subaddieDll_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80800D2C: nop

    after_16:
    // 0x80800D30: bne         $v0, $zero, L_80800D6C
    if (ctx->r2 != 0) {
        // 0x80800D34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D6C;
    }
    // 0x80800D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D38: jal         0x80102D78
    // 0x80800D3C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80102D78(rdram, ctx);
        goto after_17;
    // 0x80800D3C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_17:
    // 0x80800D40: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800D44: jal         0x80102924
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102924(rdram, ctx);
        goto after_18;
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800D4C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800D50: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800D54: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800D58: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800D5C: jal         0x800DC178
    // 0x80800D60: nop

    func_800DC178(rdram, ctx);
        goto after_19;
    // 0x80800D60: nop

    after_19:
    // 0x80800D64: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800D68: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_80800D6C:
    // 0x80800D6C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800D70: jal         0x800F1DCC
    // 0x80800D74: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    func_800F1DCC(rdram, ctx);
        goto after_20;
    // 0x80800D74: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    after_20:
    // 0x80800D78: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80800D7C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800D80: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800D84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800D88: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800D8C: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x80800D90: lui         $a3, 0xC170
    ctx->r7 = S32(0XC170 << 16);
    // 0x80800D94: jal         0x800F10B4
    // 0x80800D98: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_21;
    // 0x80800D98: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_21:
    // 0x80800D9C: jal         0x800136E4
    // 0x80800DA0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_22;
    // 0x80800DA0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_22:
    // 0x80800DA4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1148) << 16);
    // 0x80800DA8: lwc1        $f2, 0x1148($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1148));
    // 0x80800DAC: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80800DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DB4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800DB8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800DBC: jal         0x80102BAC
    // 0x80800DC0: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    func_80102BAC(rdram, ctx);
        goto after_23;
    // 0x80800DC0: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    after_23:
    // 0x80800DC4: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80800DC8: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80800DCC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800DD0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD8: jal         0x80102C58
    // 0x80800DDC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    func_80102C58(rdram, ctx);
        goto after_24;
    // 0x80800DDC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_24:
    // 0x80800DE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X114C) << 16);
    // 0x80800DE4: lwc1        $f4, 0x114C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X114C));
    // 0x80800DE8: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800DEC: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800DF0: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80800DF4: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x80800DF8: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800DFC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800E00: jal         0x800F1FF0
    // 0x80800E04: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_25;
    // 0x80800E04: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_25:
    // 0x80800E08: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80800E0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800E10: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E14: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800E18: jr          $ra
    // 0x80800E1C: nop

    return;
    // 0x80800E1C: nop

;}
RECOMP_FUNC void func_80800324_chdinofamilymissing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800324: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800328: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080032C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800330: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800334: jal         0x800EA05C
    // 0x80800338: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800338: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080033C: addiu       $at, $zero, 0x114
    ctx->r1 = ADD32(0, 0X114);
    // 0x80800340: beq         $v0, $at, L_80800358
    if (ctx->r2 == ctx->r1) {
        // 0x80800344: addiu       $at, $zero, 0x118
        ctx->r1 = ADD32(0, 0X118);
            goto L_80800358;
    }
    // 0x80800344: addiu       $at, $zero, 0x118
    ctx->r1 = ADD32(0, 0X118);
    // 0x80800348: beq         $v0, $at, L_8080038C
    if (ctx->r2 == ctx->r1) {
        // 0x8080034C: nop
    
            goto L_8080038C;
    }
    // 0x8080034C: nop

    // 0x80800350: b           L_80800404
    // 0x80800354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800404;
    // 0x80800354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800358:
    // 0x80800358: jal         0x80088840
    // 0x8080035C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x8080035C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_1:
    // 0x80800360: beq         $v0, $zero, L_80800400
    if (ctx->r2 == 0) {
        // 0x80800364: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800400;
    }
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: jal         0x80102424
    // 0x8080036C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x8080036C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800370: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800378: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8080037C: jal         0x80085708
    // 0x80800380: addiu       $a3, $zero, 0x2831
    ctx->r7 = ADD32(0, 0X2831);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800380: addiu       $a3, $zero, 0x2831
    ctx->r7 = ADD32(0, 0X2831);
    after_3:
    // 0x80800384: b           L_80800404
    // 0x80800388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800404;
    // 0x80800388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080038C:
    // 0x8080038C: jal         0x80088840
    // 0x80800390: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800390: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_4:
    // 0x80800394: beq         $v0, $zero, L_808003D0
    if (ctx->r2 == 0) {
        // 0x80800398: nop
    
            goto L_808003D0;
    }
    // 0x80800398: nop

    // 0x8080039C: jal         0x80105494
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105494(rdram, ctx);
        goto after_5;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808003A4: beq         $v0, $zero, L_808003D0
    if (ctx->r2 == 0) {
        // 0x808003A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D0;
    }
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x80102424
    // 0x808003B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808003B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808003B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003BC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808003C0: jal         0x80085708
    // 0x808003C4: addiu       $a3, $zero, 0x2831
    ctx->r7 = ADD32(0, 0X2831);
    _capod_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x808003C4: addiu       $a3, $zero, 0x2831
    ctx->r7 = ADD32(0, 0X2831);
    after_7:
    // 0x808003C8: b           L_80800404
    // 0x808003CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800404;
    // 0x808003CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003D0:
    // 0x808003D0: jal         0x80088840
    // 0x808003D4: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_8;
    // 0x808003D4: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_8:
    // 0x808003D8: beql        $v0, $zero, L_80800404
    if (ctx->r2 == 0) {
        // 0x808003DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800404;
    }
    goto skip_0;
    // 0x808003DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808003E0: jal         0x80105494
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105494(rdram, ctx);
        goto after_9;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003E8: beql        $v0, $zero, L_80800404
    if (ctx->r2 == 0) {
        // 0x808003EC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800404;
    }
    goto skip_1;
    // 0x808003EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x808003F0: jal         0x800FFAB0
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808003F8: b           L_80800404
    // 0x808003FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800404;
    // 0x808003FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800400:
    // 0x80800400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800404:
    // 0x80800404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800408: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080040C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800410: jr          $ra
    // 0x80800414: nop

    return;
    // 0x80800414: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_47(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E10: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087E10);
    return;
    // 0x80087E14: addi        $t0, $zero, 0xBC
    ctx->r8 = ADD32(0, 0XBC);
;}
RECOMP_FUNC void func_808088AC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808088AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808088B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808088B4: jal         0x80808B40
    // 0x808088B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80808B40_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x808088B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808088BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808088C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808088C4: jr          $ra
    // 0x808088C8: nop

    return;
    // 0x808088C8: nop

;}
RECOMP_FUNC void ncbafly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808000C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000D0: jal         0x80110840
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000D8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E0: jal         0x8011607C
    // 0x808000E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8011607C(rdram, ctx);
        goto after_1;
    // 0x808000E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: jal         0x801107F0
    // 0x808000F0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_801107F0(rdram, ctx);
        goto after_2;
    // 0x808000F0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_2:
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: jal         0x808000A4
    // 0x808000FC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_808000A4_ncbafly(rdram, ctx);
        goto after_3;
    // 0x808000FC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_3:
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800104: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80800108: jal         0x80115444
    // 0x8080010C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_80115444(rdram, ctx);
        goto after_4;
    // 0x8080010C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x80800110: jal         0x800F5AE0
    // 0x80800114: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800F5AE0(rdram, ctx);
        goto after_5;
    // 0x80800114: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80800118: jal         0x80013728
    // 0x8080011C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_6;
    // 0x8080011C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x80800120: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800124: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800128: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8080012C: nop

    // 0x80800130: bc1f        L_8080016C
    if (!c1cs) {
        // 0x80800134: lui         $at, 0xC1F0
        ctx->r1 = S32(0XC1F0 << 16);
            goto L_8080016C;
    }
    // 0x80800134: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800138: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080013C: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x80800140: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800144: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800148: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    // 0x8080014C: jal         0x800F10B4
    // 0x80800150: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800150: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80800154: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800158: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080015C: jal         0x80115828
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80115828(rdram, ctx);
        goto after_8;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800164: b           L_80800180
    // 0x80800168: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
        goto L_80800180;
    // 0x80800168: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_8080016C:
    // 0x8080016C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800170: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80800174: jal         0x80115828
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80115828(rdram, ctx);
        goto after_9;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080017C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_80800180:
    // 0x80800180: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80800184: jal         0x800EFB24
    // 0x80800188: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_800EFB24(rdram, ctx);
        goto after_10;
    // 0x80800188: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_10:
    // 0x8080018C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800190: jal         0x800F1A88
    // 0x80800194: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800F1A88(rdram, ctx);
        goto after_11;
    // 0x80800194: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_11:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: jal         0x80115750
    // 0x808001A0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80115750(rdram, ctx);
        goto after_12;
    // 0x808001A0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_12:
    // 0x808001A4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808001A8: jal         0x801112B0
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801112B0(rdram, ctx);
        goto after_13;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001B0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808001B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001B8: jal         0x800136E4
    // 0x808001BC: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_14;
    // 0x808001BC: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    after_14:
    // 0x808001C0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x808001C4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808001C8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808001CC: jal         0x800EEBF0
    // 0x808001D0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    func_800EEBF0(rdram, ctx);
        goto after_15;
    // 0x808001D0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_15:
    // 0x808001D4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x808001D8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x808001DC: jal         0x800EE780
    // 0x808001E0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EE780(rdram, ctx);
        goto after_16;
    // 0x808001E0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_16:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x80111CC8
    // 0x808001EC: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_80111CC8(rdram, ctx);
        goto after_17;
    // 0x808001EC: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_17:
    // 0x808001F0: beql        $v0, $zero, L_80800204
    if (ctx->r2 == 0) {
        // 0x808001F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800204;
    }
    goto skip_0;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001F8: jal         0x801138F4
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_18;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800204:
    // 0x80800204: jal         0x80112524
    // 0x80800208: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80112524(rdram, ctx);
        goto after_19;
    // 0x80800208: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_19:
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800214: jal         0x80110A68
    // 0x80800218: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_80110A68(rdram, ctx);
        goto after_20;
    // 0x80800218: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_20:
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: jal         0x80110790
    // 0x80800224: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80110790(rdram, ctx);
        goto after_21;
    // 0x80800224: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_21:
    // 0x80800228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080022C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800230: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80800234: jr          $ra
    // 0x80800238: nop

    return;
    // 0x80800238: nop

;}
RECOMP_FUNC void func_808006F8_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808006FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800700: slti        $at, $a1, 0x58
    ctx->r1 = SIGNED(ctx->r5) < 0X58 ? 1 : 0;
    // 0x80800704: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800708: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080070C: bne         $at, $zero, L_80800728
    if (ctx->r1 != 0) {
        // 0x80800710: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_80800728;
    }
    // 0x80800710: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80800714: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800718: beq         $a1, $at, L_80800844
    if (ctx->r5 == ctx->r1) {
        // 0x8080071C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800844;
    }
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800720: b           L_80800A70
    // 0x80800724: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A70;
    // 0x80800724: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800728:
    // 0x80800728: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x8080072C: bne         $at, $zero, L_80800754
    if (ctx->r1 != 0) {
        // 0x80800730: addiu       $t6, $a1, -0x2E
        ctx->r14 = ADD32(ctx->r5, -0X2E);
            goto L_80800754;
    }
    // 0x80800730: addiu       $t6, $a1, -0x2E
    ctx->r14 = ADD32(ctx->r5, -0X2E);
    // 0x80800734: sltiu       $at, $t6, 0x2A
    ctx->r1 = ctx->r14 < 0X2A ? 1 : 0;
    // 0x80800738: beq         $at, $zero, L_80800760
    if (ctx->r1 == 0) {
        // 0x8080073C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800760;
    }
    // 0x8080073C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800740: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1860, 0X1110) << 16);
    // 0x80800744: addu        $at, $at, $t6
    gpr jr_addend_8080074C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800748: lw          $t6, 0x1110($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1860, 0X1110));
    // 0x8080074C: jr          $t6
    // 0x80800750: nop

    switch (jr_addend_8080074C >> 2) {
        case 0: goto L_80800778; break;
        case 1: goto L_80800760; break;
        case 2: goto L_80800760; break;
        case 3: goto L_80800760; break;
        case 4: goto L_80800A24; break;
        case 5: goto L_80800760; break;
        case 6: goto L_80800760; break;
        case 7: goto L_80800760; break;
        case 8: goto L_80800760; break;
        case 9: goto L_80800760; break;
        case 10: goto L_80800760; break;
        case 11: goto L_80800760; break;
        case 12: goto L_80800760; break;
        case 13: goto L_80800760; break;
        case 14: goto L_80800760; break;
        case 15: goto L_80800768; break;
        case 16: goto L_80800760; break;
        case 17: goto L_80800760; break;
        case 18: goto L_80800760; break;
        case 19: goto L_80800760; break;
        case 20: goto L_80800760; break;
        case 21: goto L_80800760; break;
        case 22: goto L_80800760; break;
        case 23: goto L_80800760; break;
        case 24: goto L_80800760; break;
        case 25: goto L_80800760; break;
        case 26: goto L_80800760; break;
        case 27: goto L_80800760; break;
        case 28: goto L_80800760; break;
        case 29: goto L_80800760; break;
        case 30: goto L_80800760; break;
        case 31: goto L_80800760; break;
        case 32: goto L_80800760; break;
        case 33: goto L_80800760; break;
        case 34: goto L_80800760; break;
        case 35: goto L_80800760; break;
        case 36: goto L_808007C4; break;
        case 37: goto L_80800760; break;
        case 38: goto L_80800760; break;
        case 39: goto L_80800760; break;
        case 40: goto L_80800760; break;
        case 41: goto L_80800808; break;
        default: switch_error(__func__, 0x8080074C, 0x80801110);
    }
    // 0x80800750: nop

L_80800754:
    // 0x80800754: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800758: beq         $a1, $at, L_80800794
    if (ctx->r5 == ctx->r1) {
        // 0x8080075C: lw          $t7, 0x50($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X50);
            goto L_80800794;
    }
    // 0x8080075C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
L_80800760:
    // 0x80800760: b           L_80800A70
    // 0x80800764: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A70;
    // 0x80800764: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800768:
    // 0x80800768: jal         0x80801060
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801060_chamazongoldhordeofficial(rdram, ctx);
        goto after_0;
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800770: b           L_80800A70
    // 0x80800774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A70;
    // 0x80800774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800778:
    // 0x80800778: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x8080077C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800780: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800784: jal         0x80800CD8
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CD8_chamazongoldhordeofficial(rdram, ctx);
        goto after_1;
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080078C: b           L_80800A70
    // 0x80800790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A70;
    // 0x80800790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800794:
    // 0x80800794: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800798: bne         $t7, $at, L_808007BC
    if (ctx->r15 != ctx->r1) {
        // 0x8080079C: nop
    
            goto L_808007BC;
    }
    // 0x8080079C: nop

    // 0x808007A0: jal         0x80085710
    // 0x808007A4: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x808007A4: nop

    after_2:
    // 0x808007A8: addiu       $a0, $zero, 0x119
    ctx->r4 = ADD32(0, 0X119);
    // 0x808007AC: jal         0x800887D8
    // 0x808007B0: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808007B0: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_3:
    // 0x808007B4: b           L_80800A70
    // 0x808007B8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800A70;
    // 0x808007B8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808007BC:
    // 0x808007BC: b           L_80800A70
    // 0x808007C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800A70;
    // 0x808007C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808007C4:
    // 0x808007C4: jal         0x8010CD28
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_4;
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808007CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808007D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808007D4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808007D8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808007DC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808007E0: jal         0x800EFA4C
    // 0x808007E4: nop

    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x808007E4: nop

    after_5:
    // 0x808007E8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1860, 0X11C0) << 16);
    // 0x808007EC: addiu       $a0, $a0, 0x11C0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1860, 0X11C0));
    // 0x808007F0: jal         0x80088090
    // 0x808007F4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808007F4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x808007F8: jal         0x800880A0
    // 0x808007FC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x808007FC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x80800800: b           L_80800A70
    // 0x80800804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A70;
    // 0x80800804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800808:
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080080C: jal         0x80100094
    // 0x80800810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x80800810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800814: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80800818: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8080081C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800820: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x80800824: and         $t9, $a3, $at
    ctx->r25 = ctx->r7 & ctx->r1;
    // 0x80800828: srl         $a3, $t9, 16
    ctx->r7 = S32(U32(ctx->r25) >> 16);
    // 0x8080082C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800834: jal         0x8008A2B8
    // 0x80800838: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800838: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    after_9:
    // 0x8080083C: b           L_80800A74
    // 0x80800840: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800A74;
    // 0x80800840: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800844:
    // 0x80800844: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800848: jal         0x800897C0
    // 0x8080084C: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x8080084C: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    after_10:
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: jal         0x80100094
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8080085C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800860: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800864: jal         0x800897E8
    // 0x80800868: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_12;
    // 0x80800868: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_12:
    // 0x8080086C: jal         0x800DA298
    // 0x80800870: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80800870: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_13:
    // 0x80800874: bnel        $v0, $zero, L_8080088C
    if (ctx->r2 != 0) {
        // 0x80800878: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080088C;
    }
    goto skip_0;
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080087C: jal         0x80088848
    // 0x80800880: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_14;
    // 0x80800880: nop

    after_14:
    // 0x80800884: beq         $v0, $zero, L_80800914
    if (ctx->r2 == 0) {
        // 0x80800888: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800914;
    }
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080088C:
    // 0x8080088C: jal         0x80102424
    // 0x80800890: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x80800890: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_15:
    // 0x80800894: jal         0x80088848
    // 0x80800898: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_16;
    // 0x80800898: nop

    after_16:
    // 0x8080089C: bne         $v0, $zero, L_808008AC
    if (ctx->r2 != 0) {
        // 0x808008A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008AC;
    }
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A4: jal         0x80108B04
    // 0x808008A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_17;
    // 0x808008A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
L_808008AC:
    // 0x808008AC: jal         0x800DA298
    // 0x808008B0: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_800DA298(rdram, ctx);
        goto after_18;
    // 0x808008B0: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_18:
    // 0x808008B4: bnel        $v0, $zero, L_80800A70
    if (ctx->r2 != 0) {
        // 0x808008B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800A70;
    }
    goto skip_1;
    // 0x808008B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808008BC: jal         0x80088848
    // 0x808008C0: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_19;
    // 0x808008C0: nop

    after_19:
    // 0x808008C4: bne         $v0, $zero, L_80800A6C
    if (ctx->r2 != 0) {
        // 0x808008C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A6C;
    }
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008CC: jal         0x80100094
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_20;
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x808008D4: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x808008D8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E0: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    // 0x808008E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808008E8: jal         0x8008A2C8
    // 0x808008EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_21;
    // 0x808008EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_21:
    // 0x808008F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808008F4: addiu       $t2, $zero, 0x31
    ctx->r10 = ADD32(0, 0X31);
    // 0x808008F8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808008FC: addiu       $a1, $zero, 0xF59
    ctx->r5 = ADD32(0, 0XF59);
    // 0x80800900: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800904: jal         0x8008A208
    // 0x80800908: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_22;
    // 0x80800908: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_22:
    // 0x8080090C: b           L_80800A70
    // 0x80800910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A70;
    // 0x80800910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800914:
    // 0x80800914: jal         0x80800C18
    // 0x80800918: nop

    func_80800C18_chamazongoldhordeofficial(rdram, ctx);
        goto after_23;
    // 0x80800918: nop

    after_23:
    // 0x8080091C: beq         $v0, $zero, L_80800954
    if (ctx->r2 == 0) {
        // 0x80800920: nop
    
            goto L_80800954;
    }
    // 0x80800920: nop

    // 0x80800924: jal         0x8008FD48
    // 0x80800928: nop

    func_8008FD48(rdram, ctx);
        goto after_24;
    // 0x80800928: nop

    after_24:
    // 0x8080092C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800930: bne         $v0, $at, L_80800954
    if (ctx->r2 != ctx->r1) {
        // 0x80800934: nop
    
            goto L_80800954;
    }
    // 0x80800934: nop

    // 0x80800938: jal         0x80800690
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800690_chamazongoldhordeofficial(rdram, ctx);
        goto after_25;
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800944: jal         0x80102424
    // 0x80800948: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x80800948: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_26:
    // 0x8080094C: b           L_80800A70
    // 0x80800950: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A70;
    // 0x80800950: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800954:
    // 0x80800954: jal         0x800EA090
    // 0x80800958: nop

    func_800EA090(rdram, ctx);
        goto after_27;
    // 0x80800958: nop

    after_27:
    // 0x8080095C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800960: bne         $v0, $at, L_80800A14
    if (ctx->r2 != ctx->r1) {
        // 0x80800964: nop
    
            goto L_80800A14;
    }
    // 0x80800964: nop

    // 0x80800968: jal         0x800DA298
    // 0x8080096C: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_800DA298(rdram, ctx);
        goto after_28;
    // 0x8080096C: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_28:
    // 0x80800970: bne         $v0, $zero, L_80800A14
    if (ctx->r2 != 0) {
        // 0x80800974: nop
    
            goto L_80800A14;
    }
    // 0x80800974: nop

    // 0x80800978: jal         0x8008FD48
    // 0x8080097C: nop

    func_8008FD48(rdram, ctx);
        goto after_29;
    // 0x8080097C: nop

    after_29:
    // 0x80800980: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800984: bne         $v0, $at, L_80800A14
    if (ctx->r2 != ctx->r1) {
        // 0x80800988: nop
    
            goto L_80800A14;
    }
    // 0x80800988: nop

    // 0x8080098C: jal         0x80800690
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800690_chamazongoldhordeofficial(rdram, ctx);
        goto after_30;
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800994: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800998: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080099C: jal         0x800EEB9C
    // 0x808009A0: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_31;
    // 0x808009A0: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_31:
    // 0x808009A4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808009A8: jal         0x800EF04C
    // 0x808009AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_32;
    // 0x808009AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_32:
    // 0x808009B0: jal         0x8008F8B0
    // 0x808009B4: nop

    func_8008F8B0(rdram, ctx);
        goto after_33;
    // 0x808009B4: nop

    after_33:
    // 0x808009B8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x808009BC: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x808009C0: jal         0x8008F904
    // 0x808009C4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8008F904(rdram, ctx);
        goto after_34;
    // 0x808009C4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_34:
    // 0x808009C8: jal         0x8008F8D8
    // 0x808009CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_35;
    // 0x808009CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x808009D0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808009D4: jal         0x8008F990
    // 0x808009D8: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_8008F990(rdram, ctx);
        goto after_36;
    // 0x808009D8: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_36:
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E0: jal         0x80100094
    // 0x808009E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_37;
    // 0x808009E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009EC: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    // 0x808009F0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808009F4: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x808009F8: jal         0x8008A2D0
    // 0x808009FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_38;
    // 0x808009FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_38:
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A04: jal         0x80102424
    // 0x80800A08: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_39;
    // 0x80800A08: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_39:
    // 0x80800A0C: b           L_80800A70
    // 0x80800A10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A70;
    // 0x80800A10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A14:
    // 0x80800A14: jal         0x80800E18
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E18_chamazongoldhordeofficial(rdram, ctx);
        goto after_40;
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80800A1C: b           L_80800A70
    // 0x80800A20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A70;
    // 0x80800A20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A24:
    // 0x80800A24: jal         0x800904C8
    // 0x80800A28: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800904C8(rdram, ctx);
        goto after_41;
    // 0x80800A28: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_41:
    // 0x80800A2C: lhu         $t3, 0x72($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X72);
    // 0x80800A30: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800A34: addiu       $a1, $zero, 0xF0D
    ctx->r5 = ADD32(0, 0XF0D);
    // 0x80800A38: srl         $t4, $t3, 10
    ctx->r12 = S32(U32(ctx->r11) >> 10);
    // 0x80800A3C: bne         $t4, $at, L_80800A64
    if (ctx->r12 != ctx->r1) {
        // 0x80800A40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A64;
    }
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800A48: addiu       $t5, $zero, 0x31
    ctx->r13 = ADD32(0, 0X31);
    // 0x80800A4C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800A50: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800A54: jal         0x8008A208
    // 0x80800A58: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_42;
    // 0x80800A58: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_42:
    // 0x80800A5C: b           L_80800A70
    // 0x80800A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A70;
    // 0x80800A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A64:
    // 0x80800A64: jal         0x80102424
    // 0x80800A68: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80102424(rdram, ctx);
        goto after_43;
    // 0x80800A68: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_43:
L_80800A6C:
    // 0x80800A6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A70:
    // 0x80800A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A74:
    // 0x80800A74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800A7C: jr          $ra
    // 0x80800A80: nop

    return;
    // 0x80800A80: nop

;}
RECOMP_FUNC void func_80802938_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802938: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080293C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802940: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802944: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802948: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080294C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80802950: jal         0x80100094
    // 0x80802954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802958: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x8080295C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80802960: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802964: beq         $v1, $zero, L_80802988
    if (ctx->r3 == 0) {
        // 0x80802968: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80802988;
    }
    // 0x80802968: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080296C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802970: beq         $v1, $at, L_8080299C
    if (ctx->r3 == ctx->r1) {
        // 0x80802974: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080299C;
    }
    // 0x80802974: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802978: beql        $v1, $at, L_80802998
    if (ctx->r3 == ctx->r1) {
        // 0x8080297C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80802998;
    }
    goto skip_0;
    // 0x8080297C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x80802980: b           L_808029BC
    // 0x80802984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808029BC;
    // 0x80802984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802988:
    // 0x80802988: jal         0x80802778
    // 0x8080298C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80802778_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x8080298C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80802990: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80802994: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80802998:
    // 0x80802998: sh          $t6, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r14;
L_8080299C:
    // 0x8080299C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808029A0: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x808029A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808029A8: or          $t7, $a2, $at
    ctx->r15 = ctx->r6 | ctx->r1;
    // 0x808029AC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x808029B0: jal         0x800856D0
    // 0x808029B4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808029B4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808029B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808029BC:
    // 0x808029BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808029C0: jr          $ra
    // 0x808029C4: nop

    return;
    // 0x808029C4: nop

;}
RECOMP_FUNC void badrone_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80800110: jr          $ra
    // 0x80800114: lbu         $v0, 0x4($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X4);
    return;
    // 0x80800114: lbu         $v0, 0x4($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X4);
;}
RECOMP_FUNC void func_80800194_basetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808001A0: jal         0x800A3274
    // 0x808001A4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x808001A4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x808001A8: jal         0x800EA05C
    // 0x808001AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x808001AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001B0: jal         0x800EA090
    // 0x808001B4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800EA090(rdram, ctx);
        goto after_2;
    // 0x808001B4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x808001B8: jal         0x800DB9B0
    // 0x808001BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DB9B0(rdram, ctx);
        goto after_3;
    // 0x808001BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x808001C0: bne         $v0, $zero, L_80800210
    if (ctx->r2 != 0) {
        // 0x808001C4: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800210;
    }
    // 0x808001C4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808001CC: addiu       $at, $zero, 0x112
    ctx->r1 = ADD32(0, 0X112);
    // 0x808001D0: bne         $v0, $at, L_808001DC
    if (ctx->r2 != ctx->r1) {
        // 0x808001D4: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_808001DC;
    }
    // 0x808001D4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x808001D8: beq         $v1, $at, L_808001F0
    if (ctx->r3 == ctx->r1) {
        // 0x808001DC: addiu       $at, $zero, 0x116
        ctx->r1 = ADD32(0, 0X116);
            goto L_808001F0;
    }
L_808001DC:
    // 0x808001DC: addiu       $at, $zero, 0x116
    ctx->r1 = ADD32(0, 0X116);
    // 0x808001E0: bne         $v0, $at, L_80800210
    if (ctx->r2 != ctx->r1) {
        // 0x808001E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800210;
    }
    // 0x808001E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001E8: bnel        $v1, $at, L_80800214
    if (ctx->r3 != ctx->r1) {
        // 0x808001EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800214;
    }
    goto skip_0;
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_808001F0:
    // 0x808001F0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808001F4: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x808001F8: bnel        $t6, $at, L_80800214
    if (ctx->r14 != ctx->r1) {
        // 0x808001FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800214;
    }
    goto skip_1;
    // 0x808001FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800200: jal         0x80800140
    // 0x80800204: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80800140_basetup(rdram, ctx);
        goto after_4;
    // 0x80800204: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800208: jal         0x80800140
    // 0x8080020C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800140_basetup(rdram, ctx);
        goto after_5;
    // 0x8080020C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
L_80800210:
    // 0x80800210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800214:
    // 0x80800214: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800218: jr          $ra
    // 0x8080021C: nop

    return;
    // 0x8080021C: nop

;}
RECOMP_FUNC void func_808012A4_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012AC: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808012B0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808012B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808012B8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808012BC: bne         $t7, $at, L_8080134C
    if (ctx->r15 != ctx->r1) {
        // 0x808012C0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080134C;
    }
    // 0x808012C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808012C4: jal         0x800DA298
    // 0x808012C8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808012C8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808012CC: bne         $v0, $zero, L_8080134C
    if (ctx->r2 != 0) {
        // 0x808012D0: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080134C;
    }
    // 0x808012D0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808012D4: lbu         $v0, 0x79($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X79);
    // 0x808012D8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x808012DC: addiu       $a1, $zero, 0x6D60
    ctx->r5 = ADD32(0, 0X6D60);
    // 0x808012E0: srl         $t8, $v0, 4
    ctx->r24 = S32(U32(ctx->r2) >> 4);
    // 0x808012E4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x808012E8: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x808012EC: andi        $t2, $v0, 0xFF0F
    ctx->r10 = ctx->r2 & 0XFF0F;
    // 0x808012F0: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x808012F4: sb          $t3, 0x79($a2)
    MEM_B(0X79, ctx->r6) = ctx->r11;
    // 0x808012F8: jal         0x800FC63C
    // 0x808012FC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800FC63C(rdram, ctx);
        goto after_1;
    // 0x808012FC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80801300: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801304: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(748, 0X193E) << 16);
    // 0x80801308: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080130C: lhu         $t6, 0x76($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X76);
    // 0x80801310: lbu         $t4, 0x79($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X79);
    // 0x80801314: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801318: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080131C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80801320: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80801324: lh          $t9, 0x193E($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(748, 0X193E));
    // 0x80801328: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x8080132C: bne         $t5, $t9, L_80801344
    if (ctx->r13 != ctx->r25) {
        // 0x80801330: nop
    
            goto L_80801344;
    }
    // 0x80801330: nop

    // 0x80801334: jal         0x80800E80
    // 0x80801338: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800E80_chlagoonufoint(rdram, ctx);
        goto after_2;
    // 0x80801338: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8080133C: b           L_80801350
    // 0x80801340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801350;
    // 0x80801340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801344:
    // 0x80801344: jal         0x80800E80
    // 0x80801348: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800E80_chlagoonufoint(rdram, ctx);
        goto after_3;
    // 0x80801348: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_8080134C:
    // 0x8080134C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801350:
    // 0x80801350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801354: jr          $ra
    // 0x80801358: nop

    return;
    // 0x80801358: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084290: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084290);
    return;
    // 0x80084294: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808001A0_chpickups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808001A4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808001A8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x808001AC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808001B0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808001B4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808001B8: jal         0x80106790
    // 0x808001BC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808001BC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001C4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808001C8: jal         0x800EE904
    // 0x808001CC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_800EE904(rdram, ctx);
        goto after_1;
    // 0x808001CC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_1:
    // 0x808001D0: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x808001D4: addiu       $at, $zero, 0x4B7
    ctx->r1 = ADD32(0, 0X4B7);
    // 0x808001D8: sll         $t6, $v1, 11
    ctx->r14 = S32(ctx->r3 << 11);
    // 0x808001DC: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x808001E0: beq         $t7, $at, L_80800218
    if (ctx->r15 == ctx->r1) {
        // 0x808001E4: addiu       $at, $zero, 0x4E2
        ctx->r1 = ADD32(0, 0X4E2);
            goto L_80800218;
    }
    // 0x808001E4: addiu       $at, $zero, 0x4E2
    ctx->r1 = ADD32(0, 0X4E2);
    // 0x808001E8: beq         $t7, $at, L_80800218
    if (ctx->r15 == ctx->r1) {
        // 0x808001EC: addiu       $at, $zero, 0x4E3
        ctx->r1 = ADD32(0, 0X4E3);
            goto L_80800218;
    }
    // 0x808001EC: addiu       $at, $zero, 0x4E3
    ctx->r1 = ADD32(0, 0X4E3);
    // 0x808001F0: beq         $t7, $at, L_80800218
    if (ctx->r15 == ctx->r1) {
        // 0x808001F4: addiu       $at, $zero, 0x4E4
        ctx->r1 = ADD32(0, 0X4E4);
            goto L_80800218;
    }
    // 0x808001F4: addiu       $at, $zero, 0x4E4
    ctx->r1 = ADD32(0, 0X4E4);
    // 0x808001F8: beq         $t7, $at, L_80800218
    if (ctx->r15 == ctx->r1) {
        // 0x808001FC: addiu       $at, $zero, 0x515
        ctx->r1 = ADD32(0, 0X515);
            goto L_80800218;
    }
    // 0x808001FC: addiu       $at, $zero, 0x515
    ctx->r1 = ADD32(0, 0X515);
    // 0x80800200: beq         $t7, $at, L_80800218
    if (ctx->r15 == ctx->r1) {
        // 0x80800204: addiu       $at, $zero, 0x516
        ctx->r1 = ADD32(0, 0X516);
            goto L_80800218;
    }
    // 0x80800204: addiu       $at, $zero, 0x516
    ctx->r1 = ADD32(0, 0X516);
    // 0x80800208: beql        $t7, $at, L_8080021C
    if (ctx->r15 == ctx->r1) {
        // 0x8080020C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080021C;
    }
    goto skip_0;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800210: jal         0x800900D0
    // 0x80800214: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800900D0(rdram, ctx);
        goto after_2;
    // 0x80800214: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
L_80800218:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080021C:
    // 0x8080021C: jal         0x80101FDC
    // 0x80800220: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800220: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800224: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800228: jal         0x800EE7F8
    // 0x8080022C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080022C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_4:
    // 0x80800230: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80800234: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800238: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8080023C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80800240: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800244: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800248: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080024C: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800250: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800254: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800258: mov.s       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.fl = ctx->f20.fl;
    // 0x8080025C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800260: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800264: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x80800268: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8080026C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800270: nop

    // 0x80800274: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800278: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8080027C: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x80800280: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80800284: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80800288: nop

    // 0x8080028C: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800290: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80800294: nop

    // 0x80800298: bc1fl       L_808002B0
    if (!c1cs) {
        // 0x8080029C: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_808002B0;
    }
    goto skip_1;
    // 0x8080029C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_1:
    // 0x808002A0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808002A4: nop

    // 0x808002A8: bc1t        L_808002EC
    if (c1cs) {
        // 0x808002AC: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_808002EC;
    }
    // 0x808002AC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_808002B0:
    // 0x808002B0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808002B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002B8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808002BC: sub.s       $f0, $f14, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f22.fl;
    // 0x808002C0: add.s       $f16, $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x808002C4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x808002C8: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x808002CC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x808002D0: nop

    // 0x808002D4: bc1fl       L_808002B0
    if (!c1cs) {
        // 0x808002D8: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_808002B0;
    }
    goto skip_2;
    // 0x808002D8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_2:
    // 0x808002DC: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808002E0: nop

    // 0x808002E4: bc1fl       L_808002B0
    if (!c1cs) {
        // 0x808002E8: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_808002B0;
    }
    goto skip_3;
    // 0x808002E8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_3:
L_808002EC:
    // 0x808002EC: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808002F0: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808002F4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808002F8: div.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x808002FC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800300: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800304: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800308: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080030C: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    // 0x80800310: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x80800314: jal         0x800EF334
    // 0x80800318: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    func_800EF334(rdram, ctx);
        goto after_5;
    // 0x80800318: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x8080031C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800320: mul.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80800324: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80800328: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080032C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800330: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800334: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800338: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080033C: jr          $ra
    // 0x80800340: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800340: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void chfactorytwinklies_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1308, 0X2260) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x2260
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X2260));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x2260
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X2260));
;}
RECOMP_FUNC void func_80800278_bskazwingwhack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800278: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080027C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800280: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800284: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800288: jal         0x8009C984
    // 0x8080028C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    yaw_get(rdram, ctx);
        goto after_0;
    // 0x8080028C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_0:
    // 0x80800290: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800294: jal         0x8009B9C0
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_1;
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080029C: jal         0x8008CAC8
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_2;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808002B0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808002B4: nop

    // 0x808002B8: bc1f        L_808002E8
    if (!c1cs) {
        // 0x808002BC: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_808002E8;
    }
    // 0x808002BC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808002C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002C4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002C8: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x808002CC: lw          $a3, 0x170($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X170);
    // 0x808002D0: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x808002D4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808002D8: jal         0x800F10B4
    // 0x808002DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808002DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x808002E0: b           L_80800314
    // 0x808002E4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800314;
    // 0x808002E4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_808002E8:
    // 0x808002E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(300, 0X8F0) << 16);
    // 0x808002EC: lwc1        $f14, 0x8F0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X8F0));
    // 0x808002F0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808002F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002F8: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x808002FC: lw          $a3, 0x170($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X170);
    // 0x80800300: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x80800304: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800308: jal         0x800F10B4
    // 0x8080030C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x8080030C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80800310: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800314:
    // 0x80800314: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: jal         0x8009E55C
    // 0x80800320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E55C(rdram, ctx);
        goto after_5;
    // 0x80800320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800324: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80800328: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080032C: jal         0x8008CB10
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800334: beq         $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x80800338: lui         $a2, 0x3F8C
        ctx->r6 = S32(0X3F8C << 16);
            goto L_80800350;
    }
    // 0x80800338: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x8080033C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x80800348: jal         0x8009DF94
    // 0x8080034C: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    func_8009DF94(rdram, ctx);
        goto after_7;
    // 0x8080034C: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    after_7:
L_80800350:
    // 0x80800350: lui         $a1, 0x3E75
    ctx->r5 = S32(0X3E75 << 16);
    // 0x80800354: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x80800358: jal         0x8008CB10
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800360: beq         $v0, $zero, L_80800378
    if (ctx->r2 == 0) {
        // 0x80800364: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800378;
    }
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x8080036C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800370: jal         0x8009DF94
    // 0x80800374: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    func_8009DF94(rdram, ctx);
        goto after_9;
    // 0x80800374: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    after_9:
L_80800378:
    // 0x80800378: lui         $a1, 0x3EF5
    ctx->r5 = S32(0X3EF5 << 16);
    // 0x8080037C: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x80800380: jal         0x8008CB10
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_10;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800388: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x8080038C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A4;
    }
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800394: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800398: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x8080039C: jal         0x8009DF94
    // 0x808003A0: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    func_8009DF94(rdram, ctx);
        goto after_11;
    // 0x808003A0: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    after_11:
L_808003A4:
    // 0x808003A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(300, 0X8F4) << 16);
    // 0x808003A8: lwc1        $f10, 0x8F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X8F4));
    // 0x808003AC: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808003B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(300, 0X8F8) << 16);
    // 0x808003B4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x808003B8: nop

    // 0x808003BC: bc1fl       L_80800424
    if (!c1cs) {
        // 0x808003C0: lui         $a1, 0x3F23
        ctx->r5 = S32(0X3F23 << 16);
            goto L_80800424;
    }
    goto skip_0;
    // 0x808003C0: lui         $a1, 0x3F23
    ctx->r5 = S32(0X3F23 << 16);
    skip_0:
    // 0x808003C4: lwc1        $f18, 0x8F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X8F8));
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808003D0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808003D4: nop

    // 0x808003D8: bc1fl       L_80800424
    if (!c1cs) {
        // 0x808003DC: lui         $a1, 0x3F23
        ctx->r5 = S32(0X3F23 << 16);
            goto L_80800424;
    }
    goto skip_1;
    // 0x808003DC: lui         $a1, 0x3F23
    ctx->r5 = S32(0X3F23 << 16);
    skip_1:
    // 0x808003E0: jal         0x800F3BD0
    // 0x808003E4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800F3BD0(rdram, ctx);
        goto after_12;
    // 0x808003E4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_12:
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808003F0: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    // 0x808003F4: jal         0x80800000
    // 0x808003F8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_80800000_bskazwingwhack(rdram, ctx);
        goto after_13;
    // 0x808003F8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_13:
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800400: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800404: jal         0x800F3BD0
    // 0x80800408: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800F3BD0(rdram, ctx);
        goto after_14;
    // 0x80800408: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_14:
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800414: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    // 0x80800418: jal         0x80800000
    // 0x8080041C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_80800000_bskazwingwhack(rdram, ctx);
        goto after_15;
    // 0x8080041C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_15:
    // 0x80800420: lui         $a1, 0x3F23
    ctx->r5 = S32(0X3F23 << 16);
L_80800424:
    // 0x80800424: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800428: jal         0x8008CB10
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_16;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800430: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x80800434: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080044C;
    }
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800438: jal         0x8008DF8C
    // 0x8080043C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8008DF8C(rdram, ctx);
        goto after_17;
    // 0x8080043C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_17:
    // 0x80800440: bne         $v0, $zero, L_8080044C
    if (ctx->r2 != 0) {
        // 0x80800444: addiu       $t6, $zero, 0xDF
        ctx->r14 = ADD32(0, 0XDF);
            goto L_8080044C;
    }
    // 0x80800444: addiu       $t6, $zero, 0xDF
    ctx->r14 = ADD32(0, 0XDF);
    // 0x80800448: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_8080044C:
    // 0x8080044C: jal         0x8008CAEC
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_18;
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800454: beq         $v0, $zero, L_80800460
    if (ctx->r2 == 0) {
        // 0x80800458: addiu       $t7, $zero, 0xDF
        ctx->r15 = ADD32(0, 0XDF);
            goto L_80800460;
    }
    // 0x80800458: addiu       $t7, $zero, 0xDF
    ctx->r15 = ADD32(0, 0XDF);
    // 0x8080045C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_80800460:
    // 0x80800460: jal         0x80097D9C
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_feathery_flap(rdram, ctx);
        goto after_19;
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800468: beq         $v0, $zero, L_80800478
    if (ctx->r2 == 0) {
        // 0x8080046C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800478;
    }
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: addiu       $t8, $zero, 0x15C
    ctx->r24 = ADD32(0, 0X15C);
    // 0x80800474: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_80800478:
    // 0x80800478: jal         0x8009E5C8
    // 0x8080047C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    bs_setState(rdram, ctx);
        goto after_20;
    // 0x8080047C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_20:
    // 0x80800480: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800484: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800488: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080048C: jr          $ra
    // 0x80800490: nop

    return;
    // 0x80800490: nop

;}
RECOMP_FUNC void sufade_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8080012C: lw          $a0, 0x7EF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF4);
    // 0x80800130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: beql        $a0, $zero, L_80800154
    if (ctx->r4 == 0) {
        // 0x8080013C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800154;
    }
    goto skip_0;
    // 0x8080013C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800140: jal         0x800B2D28
    // 0x80800144: nop

    vector_free(rdram, ctx);
        goto after_0;
    // 0x80800144: nop

    after_0:
    // 0x80800148: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8080014C: sw          $zero, 0x7EF4($at)
    MEM_W(0X7EF4, ctx->r1) = 0;
    // 0x80800150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800154:
    // 0x80800154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800158: jr          $ra
    // 0x8080015C: nop

    return;
    // 0x8080015C: nop

;}
RECOMP_FUNC void func_808002C0_chboggykidshome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C0: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x808002C4: addiu       $at, $zero, 0x41D
    ctx->r1 = ADD32(0, 0X41D);
    // 0x808002C8: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x808002CC: srl         $v0, $t6, 20
    ctx->r2 = S32(U32(ctx->r14) >> 20);
    // 0x808002D0: bnel        $v0, $at, L_808002E4
    if (ctx->r2 != ctx->r1) {
        // 0x808002D4: addiu       $at, $zero, 0x3E4
        ctx->r1 = ADD32(0, 0X3E4);
            goto L_808002E4;
    }
    goto skip_0;
    // 0x808002D4: addiu       $at, $zero, 0x3E4
    ctx->r1 = ADD32(0, 0X3E4);
    skip_0:
    // 0x808002D8: jr          $ra
    // 0x808002DC: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    return;
    // 0x808002DC: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    // 0x808002E0: addiu       $at, $zero, 0x3E4
    ctx->r1 = ADD32(0, 0X3E4);
L_808002E4:
    // 0x808002E4: bnel        $v0, $at, L_808002F8
    if (ctx->r2 != ctx->r1) {
        // 0x808002E8: addiu       $v0, $zero, 0x3D
        ctx->r2 = ADD32(0, 0X3D);
            goto L_808002F8;
    }
    goto skip_1;
    // 0x808002E8: addiu       $v0, $zero, 0x3D
    ctx->r2 = ADD32(0, 0X3D);
    skip_1:
    // 0x808002EC: jr          $ra
    // 0x808002F0: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    return;
    // 0x808002F0: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x808002F4: addiu       $v0, $zero, 0x3D
    ctx->r2 = ADD32(0, 0X3D);
L_808002F8:
    // 0x808002F8: jr          $ra
    // 0x808002FC: nop

    return;
    // 0x808002FC: nop

;}
RECOMP_FUNC void func_808009C0_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808009CC: jal         0x800DA298
    // 0x808009D0: addiu       $a0, $zero, 0x449
    ctx->r4 = ADD32(0, 0X449);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808009D0: addiu       $a0, $zero, 0x449
    ctx->r4 = ADD32(0, 0X449);
    after_0:
    // 0x808009D4: beq         $v0, $zero, L_808009F4
    if (ctx->r2 == 0) {
        // 0x808009D8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808009F4;
    }
    // 0x808009D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808009DC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(740, 0X19A0) << 16);
    // 0x808009E0: lhu         $t6, 0x19A0($t6)
    ctx->r14 = MEM_HU(ctx->r14, (int16_t)RELOC_LO16(740, 0X19A0));
    // 0x808009E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X19A0) << 16);
    // 0x808009E8: ori         $t7, $t6, 0x42
    ctx->r15 = ctx->r14 | 0X42;
    // 0x808009EC: b           L_80800A08
    // 0x808009F0: sh          $t7, 0x19A0($at)
    MEM_H((int16_t)RELOC_LO16(740, 0X19A0), ctx->r1) = ctx->r15;
        goto L_80800A08;
    // 0x808009F0: sh          $t7, 0x19A0($at)
    MEM_H((int16_t)RELOC_LO16(740, 0X19A0), ctx->r1) = ctx->r15;
L_808009F4:
    // 0x808009F4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(740, 0X19A0) << 16);
    // 0x808009F8: lhu         $t8, 0x19A0($t8)
    ctx->r24 = MEM_HU(ctx->r24, (int16_t)RELOC_LO16(740, 0X19A0));
    // 0x808009FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X19A0) << 16);
    // 0x80800A00: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x80800A04: sh          $t9, 0x19A0($at)
    MEM_H((int16_t)RELOC_LO16(740, 0X19A0), ctx->r1) = ctx->r25;
L_80800A08:
    // 0x80800A08: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(740, 0X198C) << 16);
    // 0x80800A0C: addiu       $a2, $a2, 0x198C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(740, 0X198C));
    // 0x80800A10: jal         0x8008A1E8
    // 0x80800A14: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800A14: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A20: jr          $ra
    // 0x80800A24: nop

    return;
    // 0x80800A24: nop

;}
RECOMP_FUNC void bsclimb_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808007E8: jal         0x8009CC68
    // 0x808007EC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_8009CC68(rdram, ctx);
        goto after_0;
    // 0x808007EC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808007F0: bne         $v0, $zero, L_808007FC
    if (ctx->r2 != 0) {
        // 0x808007F4: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808007FC;
    }
    // 0x808007F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808007F8: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
L_808007FC:
    // 0x808007FC: jal         0x8009E5C8
    // 0x80800800: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80800800: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080080C: jr          $ra
    // 0x80800810: nop

    return;
    // 0x80800810: nop

;}
RECOMP_FUNC void func_808000A8_chboggygirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808000AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808000B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808000B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B8: jal         0x80100094
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000C0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x808000C4: jal         0x800DA298
    // 0x808000C8: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808000C8: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    after_1:
    // 0x808000CC: beql        $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000D0: addiu       $t8, $s0, 0x4
        ctx->r24 = ADD32(ctx->r16, 0X4);
            goto L_80800104;
    }
    goto skip_0;
    // 0x808000D0: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x808000D4: jal         0x80800B5C
    // 0x808000D8: addiu       $a0, $zero, 0x3CB
    ctx->r4 = ADD32(0, 0X3CB);
    func_80800B5C_chboggygirl(rdram, ctx);
        goto after_2;
    // 0x808000D8: addiu       $a0, $zero, 0x3CB
    ctx->r4 = ADD32(0, 0X3CB);
    after_2:
    // 0x808000DC: beq         $v0, $zero, L_80800100
    if (ctx->r2 == 0) {
        // 0x808000E0: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800100;
    }
    // 0x808000E0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000E4: jal         0x8010CAC0
    // 0x808000E8: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    func_8010CAC0(rdram, ctx);
        goto after_3;
    // 0x808000E8: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_3:
    // 0x808000EC: bnel        $v0, $zero, L_80800104
    if (ctx->r2 != 0) {
        // 0x808000F0: addiu       $t8, $s0, 0x4
        ctx->r24 = ADD32(ctx->r16, 0X4);
            goto L_80800104;
    }
    goto skip_1;
    // 0x808000F0: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x808000F4: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    // 0x808000F8: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x808000FC: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
L_80800100:
    // 0x80800100: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
L_80800104:
    // 0x80800104: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80800108: jal         0x800D90A4
    // 0x8080010C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x8080010C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_4:
    // 0x80800110: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800118: jal         0x80100094
    // 0x8080011C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x8080011C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800120: beq         $v0, $zero, L_80800140
    if (ctx->r2 == 0) {
        // 0x80800124: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800140;
    }
    // 0x80800124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800128: jal         0x80100094
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800130: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800134: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800138: jal         0x800897D8
    // 0x8080013C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x8080013C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
L_80800140:
    // 0x80800140: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80800144: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800148: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8080014C: sltiu       $at, $t1, 0xF
    ctx->r1 = ctx->r9 < 0XF ? 1 : 0;
    // 0x80800150: beq         $at, $zero, L_808004E0
    if (ctx->r1 == 0) {
        // 0x80800154: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_808004E0;
    }
    // 0x80800154: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800158: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1536, 0XBB0) << 16);
    // 0x8080015C: addu        $at, $at, $t1
    gpr jr_addend_80800164 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80800160: lw          $t1, 0xBB0($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1536, 0XBB0));
    // 0x80800164: jr          $t1
    // 0x80800168: nop

    switch (jr_addend_80800164 >> 2) {
        case 0: goto L_8080016C; break;
        case 1: goto L_80800278; break;
        case 2: goto L_808001FC; break;
        case 3: goto L_808001E4; break;
        case 4: goto L_808003BC; break;
        case 5: goto L_80800418; break;
        case 6: goto L_808004E0; break;
        case 7: goto L_808004E0; break;
        case 8: goto L_808004E0; break;
        case 9: goto L_808004E0; break;
        case 10: goto L_808004E0; break;
        case 11: goto L_808004E0; break;
        case 12: goto L_808004E0; break;
        case 13: goto L_808004E0; break;
        case 14: goto L_808004A0; break;
        default: switch_error(__func__, 0x80800164, 0x80800BB0);
    }
    // 0x80800168: nop

L_8080016C:
    // 0x8080016C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1536, 0XD38) << 16);
    // 0x80800170: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1536, 0XC50) << 16);
    // 0x80800174: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80800178: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080017C: addiu       $a3, $a3, 0xC50
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1536, 0XC50));
    // 0x80800180: addiu       $a2, $a2, 0xD38
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1536, 0XD38));
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x8008A1F0
    // 0x8080018C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x8080018C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x80800190: bne         $v0, $zero, L_808004E0
    if (ctx->r2 != 0) {
        // 0x80800194: lw          $t3, 0x60($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60);
            goto L_808004E0;
    }
    // 0x80800194: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80800198: beq         $t3, $zero, L_808004E0
    if (ctx->r11 == 0) {
        // 0x8080019C: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_808004E0;
    }
    // 0x8080019C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808001A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001A4: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x808001A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001AC: jal         0x800DC178
    // 0x808001B0: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x808001B0: nop

    after_9:
    // 0x808001B4: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808001C0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808001C4: jal         0x80102924
    // 0x808001C8: nop

    func_80102924(rdram, ctx);
        goto after_10;
    // 0x808001C8: nop

    after_10:
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80102424
    // 0x808001D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x808001D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x808001D8: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x808001DC: b           L_808004E0
    // 0x808001E0: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
        goto L_808004E0;
    // 0x808001E0: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
L_808001E4:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808001EC: jal         0x8010CE70
    // 0x808001F0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_8010CE70(rdram, ctx);
        goto after_12;
    // 0x808001F0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_12:
    // 0x808001F4: b           L_808004E4
    // 0x808001F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_808004E4;
    // 0x808001F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_808001FC:
    // 0x808001FC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800200: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x8080020C: jal         0x80102BF8
    // 0x80800210: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_13;
    // 0x80800210: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_13:
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x80102CF4
    // 0x8080021C: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    func_80102CF4(rdram, ctx);
        goto after_14;
    // 0x8080021C: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    after_14:
    // 0x80800220: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x80800224: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8080024C;
    }
    // 0x80800224: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800228: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080022C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80800230: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800234: jal         0x800DC178
    // 0x80800238: nop

    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x80800238: nop

    after_15:
    // 0x8080023C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x80102424
    // 0x80800248: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x80800248: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_16:
L_8080024C:
    // 0x8080024C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1536, 0XD38) << 16);
    // 0x80800250: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1536, 0XC50) << 16);
    // 0x80800254: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80800258: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080025C: addiu       $a3, $a3, 0xC50
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1536, 0XC50));
    // 0x80800260: addiu       $a2, $a2, 0xD38
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1536, 0XD38));
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: jal         0x8008A1F0
    // 0x8080026C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_17;
    // 0x8080026C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_17:
    // 0x80800270: b           L_808004E4
    // 0x80800274: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_808004E4;
    // 0x80800274: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80800278:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x80105230
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_18;
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80800284: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1536, 0XD38) << 16);
    // 0x80800288: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1536, 0XC50) << 16);
    // 0x8080028C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800290: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800294: addiu       $a3, $a3, 0xC50
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1536, 0XC50));
    // 0x80800298: addiu       $a2, $a2, 0xD38
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1536, 0XD38));
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: jal         0x8008A1F0
    // 0x808002A4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_19;
    // 0x808002A4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_19:
    // 0x808002A8: bne         $v0, $zero, L_808004E0
    if (ctx->r2 != 0) {
        // 0x808002AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E0;
    }
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x808002B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1536, 0XBEC) << 16);
    // 0x808002B8: lwc1        $f8, 0xBEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1536, 0XBEC));
    // 0x808002BC: lh          $a2, 0x14($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X14);
    // 0x808002C0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x808002C4: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x808002C8: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x808002CC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808002D0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808002D4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808002D8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x808002DC: jal         0x80089F88
    // 0x808002E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_20;
    // 0x808002E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x808002E4: jal         0x80089F78
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808002EC: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x808002F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800324;
    }
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808002F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002FC: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800300: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80800304: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x80800308: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8080030C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800310: jal         0x80089F90
    // 0x80800314: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_22;
    // 0x80800314: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x80800318: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8080031C: lhu         $t1, 0xE($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XE);
    // 0x80800320: sh          $t1, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r9;
L_80800324:
    // 0x80800324: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800328: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800330: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x80800334: jal         0x80102BF8
    // 0x80800338: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_23;
    // 0x80800338: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_23:
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x8010B990
    // 0x80800344: addiu       $a1, $zero, 0x1305
    ctx->r5 = ADD32(0, 0X1305);
    func_8010B990(rdram, ctx);
        goto after_24;
    // 0x80800344: addiu       $a1, $zero, 0x1305
    ctx->r5 = ADD32(0, 0X1305);
    after_24:
    // 0x80800348: andi        $t2, $v0, 0x4
    ctx->r10 = ctx->r2 & 0X4;
    // 0x8080034C: beq         $t2, $zero, L_8080038C
    if (ctx->r10 == 0) {
        // 0x80800350: lw          $t4, 0x60($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X60);
            goto L_8080038C;
    }
    // 0x80800350: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80800354: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800358: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080035C: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800368: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080036C: jal         0x80102924
    // 0x80800370: nop

    func_80102924(rdram, ctx);
        goto after_25;
    // 0x80800370: nop

    after_25:
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: jal         0x80102424
    // 0x8080037C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x8080037C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_26:
    // 0x80800380: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80800384: b           L_808004E0
    // 0x80800388: sh          $zero, 0x14($t3)
    MEM_H(0X14, ctx->r11) = 0;
        goto L_808004E0;
    // 0x80800388: sh          $zero, 0x14($t3)
    MEM_H(0X14, ctx->r11) = 0;
L_8080038C:
    // 0x8080038C: beq         $t4, $zero, L_808004E0
    if (ctx->r12 == 0) {
        // 0x80800390: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E0;
    }
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: jal         0x80102424
    // 0x80800398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_27;
    // 0x80800398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x8080039C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808003A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808003A4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808003A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003AC: jal         0x800DC178
    // 0x808003B0: nop

    func_800DC178(rdram, ctx);
        goto after_28;
    // 0x808003B0: nop

    after_28:
    // 0x808003B4: b           L_808004E0
    // 0x808003B8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808004E0;
    // 0x808003B8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_808003BC:
    // 0x808003BC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808003C0: jal         0x800EE88C
    // 0x808003C4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_800EE88C(rdram, ctx);
        goto after_29;
    // 0x808003C4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_29:
    // 0x808003C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808003CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003D0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x808003D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808003E0: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x808003E4: jal         0x801028C4
    // 0x808003E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_801028C4(rdram, ctx);
        goto after_30;
    // 0x808003E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_30:
    // 0x808003EC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808003F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808003FC: nop

    // 0x80800400: bc1fl       L_808004E4
    if (!c1cs) {
        // 0x80800404: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808004E4;
    }
    goto skip_2;
    // 0x80800404: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_2:
    // 0x80800408: jal         0x80102424
    // 0x8080040C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_31;
    // 0x8080040C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_31:
    // 0x80800410: b           L_808004E4
    // 0x80800414: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_808004E4;
    // 0x80800414: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80800418:
    // 0x80800418: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080041C: jal         0x800EE88C
    // 0x80800420: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_800EE88C(rdram, ctx);
        goto after_32;
    // 0x80800420: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_32:
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: jal         0x80102D78
    // 0x8080042C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_80102D78(rdram, ctx);
        goto after_33;
    // 0x8080042C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_33:
    // 0x80800430: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800434: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800438: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x80800444: jal         0x80102BF8
    // 0x80800448: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_34;
    // 0x80800448: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_34:
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: jal         0x8010B990
    // 0x80800454: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    func_8010B990(rdram, ctx);
        goto after_35;
    // 0x80800454: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    after_35:
    // 0x80800458: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080045C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800460: jal         0x800F0064
    // 0x80800464: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_800F0064(rdram, ctx);
        goto after_36;
    // 0x80800464: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_36:
    // 0x80800468: beq         $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x8080046C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E0;
    }
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80800474: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80800478: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080047C: jal         0x801058C4
    // 0x80800480: lh          $a1, 0x6($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X6);
    func_801058C4(rdram, ctx);
        goto after_37;
    // 0x80800480: lh          $a1, 0x6($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X6);
    after_37:
    // 0x80800484: jal         0x80105BAC
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105BAC(rdram, ctx);
        goto after_38;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800490: jal         0x80102424
    // 0x80800494: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_39;
    // 0x80800494: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_39:
    // 0x80800498: b           L_808004E4
    // 0x8080049C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_808004E4;
    // 0x8080049C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_808004A0:
    // 0x808004A0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004AC: jal         0x80089FE8
    // 0x808004B0: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    _subaddieitem_entrypoint_3(rdram, ctx);
        goto after_40;
    // 0x808004B0: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    after_40:
    // 0x808004B4: beq         $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x808004B8: addiu       $a1, $zero, 0x1090
        ctx->r5 = ADD32(0, 0X1090);
            goto L_808004E0;
    }
    // 0x808004B8: addiu       $a1, $zero, 0x1090
    ctx->r5 = ADD32(0, 0X1090);
    // 0x808004BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004C0: addiu       $t6, $zero, 0x3B
    ctx->r14 = ADD32(0, 0X3B);
    // 0x808004C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808004C8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808004CC: jal         0x8008A208
    // 0x808004D0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_41;
    // 0x808004D0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_41:
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D8: jal         0x80102424
    // 0x808004DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_42;
    // 0x808004DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_42:
L_808004E0:
    // 0x808004E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_808004E4:
    // 0x808004E4: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x808004E8: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x808004EC: jal         0x80089F18
    // 0x808004F0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_43;
    // 0x808004F0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_43:
    // 0x808004F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808004F8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808004FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800500: jr          $ra
    // 0x80800504: nop

    return;
    // 0x80800504: nop

;}
RECOMP_FUNC void func_80802764_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080276C: jal         0x80104248
    // 0x80802770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80802770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802774: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802778: jal         0x8008AED4
    // 0x8080277C: addiu       $a1, $zero, 0x10B
    ctx->r5 = ADD32(0, 0X10B);
    anctrl_setIndex(rdram, ctx);
        goto after_1;
    // 0x8080277C: addiu       $a1, $zero, 0x10B
    ctx->r5 = ADD32(0, 0X10B);
    after_1:
    // 0x80802780: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80802784: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80802788: jal         0x80101CDC
    // 0x8080278C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101CDC(rdram, ctx);
        goto after_2;
    // 0x8080278C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80802790: jal         0x808026D0
    // 0x80802794: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808026D0_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x80802794: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80802798: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080279C: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x808027A0: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x808027A4: bgezl       $t9, L_808027B8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808027A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808027B8;
    }
    goto skip_0;
    // 0x808027A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808027AC: jal         0x808000B8
    // 0x808027B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_808000B8_chdodgemcontrol(rdram, ctx);
        goto after_4;
    // 0x808027B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x808027B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808027B8:
    // 0x808027B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808027BC: jr          $ra
    // 0x808027C0: nop

    return;
    // 0x808027C0: nop

;}
RECOMP_FUNC void func_800EC0EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC0EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EC0F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800EC0F4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800EC0F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC0FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800EC100: jal         0x800EE904
    // 0x800EC104: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x800EC104: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800EC108: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800EC10C: jal         0x800EC058
    // 0x800EC110: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EC058(rdram, ctx);
        goto after_1;
    // 0x800EC110: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800EC114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EC118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800EC11C: jr          $ra
    // 0x800EC120: nop

    return;
    // 0x800EC120: nop

;}
RECOMP_FUNC void freelist_defrag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B32E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B32E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B32EC: jal         0x8001BAFC
    // 0x800B32F0: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800B32F0: nop

    after_0:
    // 0x800B32F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B32F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B32FC: jr          $ra
    // 0x800B3300: nop

    return;
    // 0x800B3300: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_39(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D18: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083D18);
    return;
    // 0x80083D1C: addi        $t0, $zero, 0x9C
    ctx->r8 = ADD32(0, 0X9C);
;}
RECOMP_FUNC void func_80012548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012548: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001254C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80012550: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80012554: addiu       $t6, $t6, 0x5788
    ctx->r14 = ADD32(ctx->r14, 0X5788);
    // 0x80012558: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001255C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80012560: lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // 0x80012564: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80012568: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8001256C: addiu       $a3, $a3, 0x24EC
    ctx->r7 = ADD32(ctx->r7, 0X24EC);
    // 0x80012570: addiu       $a1, $a1, 0x5938
    ctx->r5 = ADD32(ctx->r5, 0X5938);
    // 0x80012574: addiu       $a0, $a0, 0x5788
    ctx->r4 = ADD32(ctx->r4, 0X5788);
    // 0x80012578: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8001257C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80012580: jal         0x8001DD28
    // 0x80012584: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8001DD28(rdram, ctx);
        goto after_0;
    // 0x80012584: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x80012588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001258C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80012590: jr          $ra
    // 0x80012594: nop

    return;
    // 0x80012594: nop

;}
RECOMP_FUNC void func_80800378_bsblongleg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080037C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800380: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800384: jal         0x8008CABC
    // 0x80800388: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800388: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080038C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800390: jal         0x8008AF24
    // 0x80800394: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800394: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x8008B1A0
    // 0x808003A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x808003A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: jal         0x8008AED4
    // 0x808003AC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x808003AC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_3:
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: jal         0x8008B1BC
    // 0x808003B8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x808003B8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_4:
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: jal         0x8008B134
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808003C8: jal         0x8008B064
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003D0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808003D4: sw          $zero, 0x15C($t6)
    MEM_W(0X15C, ctx->r14) = 0;
    // 0x808003D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003E4: jr          $ra
    // 0x808003E8: nop

    return;
    // 0x808003E8: nop

;}
RECOMP_FUNC void func_800165F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800165F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800165F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800165F8: jal         0x80016934
    // 0x800165FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80016934(rdram, ctx);
        goto after_0;
    // 0x800165FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80016600: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80016604: lbu         $t6, -0x646D($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X646D);
    // 0x80016608: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001660C: bnel        $t6, $zero, L_80016620
    if (ctx->r14 != 0) {
        // 0x80016610: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016620;
    }
    goto skip_0;
    // 0x80016610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80016614: jal         0x80030014
    // 0x80016618: addiu       $a0, $a0, -0x64C0
    ctx->r4 = ADD32(ctx->r4, -0X64C0);
    osContGetReadData_recomp(rdram, ctx);
        goto after_1;
    // 0x80016618: addiu       $a0, $a0, -0x64C0
    ctx->r4 = ADD32(ctx->r4, -0X64C0);
    after_1:
    // 0x8001661C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80016620:
    // 0x80016620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80016624: jr          $ra
    // 0x80016628: nop

    return;
    // 0x80016628: nop

;}
RECOMP_FUNC void _chcrashmat_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087750: syscall     618
    recomp_syscall_handler(rdram, ctx, 0x80087750);
    return;
    // 0x80087754: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800F65D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F65D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800F65D4: lbu         $t6, 0x762C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X762C);
    // 0x800F65D8: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800F65DC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F65E0: bne         $t6, $at, L_800F65F0
    if (ctx->r14 != ctx->r1) {
        // 0x800F65E4: nop
    
            goto L_800F65F0;
    }
    // 0x800F65E4: nop

    // 0x800F65E8: jr          $ra
    // 0x800F65EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800F65EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F65F0:
    // 0x800F65F0: lw          $t7, 0x54DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X54DC);
    // 0x800F65F4: xor         $v1, $a0, $t7
    ctx->r3 = ctx->r4 ^ ctx->r15;
    // 0x800F65F8: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800F65FC: jr          $ra
    // 0x800F6600: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800F6600: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800D952C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D952C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D9530: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800D9534: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x800D9538: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x800D953C: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x800D9540: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800D9544: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D9548: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800D954C: lwc1        $f20, 0x4($a1)
    ctx->f20.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800D9550: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800D9554: lwc1        $f22, 0x8($a1)
    ctx->f22.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800D9558: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800D955C: sw          $ra, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r31;
    // 0x800D9560: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800D9564: jal         0x800137AC
    // 0x800D9568: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    func_800137AC(rdram, ctx);
        goto after_0;
    // 0x800D9568: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D956C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800D9570: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800D9574: jal         0x800137AC
    // 0x800D9578: mov.s       $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
    func_800137AC(rdram, ctx);
        goto after_1;
    // 0x800D9578: mov.s       $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
    after_1:
    // 0x800D957C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800D9580: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800D9584: jal         0x800137AC
    // 0x800D9588: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    func_800137AC(rdram, ctx);
        goto after_2;
    // 0x800D9588: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    after_2:
    // 0x800D958C: mul.s       $f4, $f24, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800D9590: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x800D9594: mul.s       $f8, $f26, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x800D9598: lw          $ra, 0x4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4);
    // 0x800D959C: mul.s       $f6, $f24, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x800D95A0: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800D95A4: mul.s       $f10, $f26, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f22.fl);
    // 0x800D95A8: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x800D95AC: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800D95B0: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x800D95B4: mul.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800D95B8: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x800D95BC: mul.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800D95C0: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800D95C4: mul.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800D95C8: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x800D95CC: mul.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800D95D0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D95D4: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D95D8: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x800D95DC: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800D95E0: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800D95E4: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800D95E8: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x800D95EC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D95F0: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x800D95F4: jr          $ra
    // 0x800D95F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D95F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D95FC: nop

;}
RECOMP_FUNC void chfactorytoxicpools_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1156, 0X988) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x988
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1156, 0X988));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x988
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1156, 0X988));
;}
RECOMP_FUNC void dbvpl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800050: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800054: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800058: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8080005C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800064: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800068: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x8080006C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800070: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800074: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800078: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080007C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800080: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80800084: jal         0x800B2324
    // 0x80800088: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800B2324(rdram, ctx);
        goto after_0;
    // 0x80800088: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x8080008C: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80800090: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800094: addiu       $s5, $zero, 0x7FFF
    ctx->r21 = ADD32(0, 0X7FFF);
    // 0x80800098: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x8080009C: sltu        $at, $s2, $t6
    ctx->r1 = ctx->r18 < ctx->r14 ? 1 : 0;
    // 0x808000A0: beq         $at, $zero, L_80800158
    if (ctx->r1 == 0) {
        // 0x808000A4: addiu       $s1, $zero, 0x3
        ctx->r17 = ADD32(0, 0X3);
            goto L_80800158;
    }
    // 0x808000A4: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x808000A8: lhu         $a3, 0x6($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X6);
L_808000AC:
    // 0x808000AC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808000B0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x808000B4: andi        $t7, $a3, 0x7FFF
    ctx->r15 = ctx->r7 & 0X7FFF;
    // 0x808000B8: beq         $t7, $s5, L_80800144
    if (ctx->r15 == ctx->r21) {
        // 0x808000BC: or          $a3, $t7, $zero
        ctx->r7 = ctx->r15 | 0;
            goto L_80800144;
    }
    // 0x808000BC: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x808000C0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x808000C4: sll         $t5, $a3, 4
    ctx->r13 = S32(ctx->r7 << 4);
    // 0x808000C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808000CC: bne         $s4, $t8, L_808000E8
    if (ctx->r20 != ctx->r24) {
        // 0x808000D0: addu        $s0, $t5, $s6
        ctx->r16 = ADD32(ctx->r13, ctx->r22);
            goto L_808000E8;
    }
    // 0x808000D0: addu        $s0, $t5, $s6
    ctx->r16 = ADD32(ctx->r13, ctx->r22);
    // 0x808000D4: lw          $t9, 0x4($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X4);
    // 0x808000D8: bnel        $s4, $t9, L_808000EC
    if (ctx->r20 != ctx->r25) {
        // 0x808000DC: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_808000EC;
    }
    goto skip_0;
    // 0x808000DC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    skip_0:
    // 0x808000E0: lw          $t0, 0x8($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X8);
    // 0x808000E4: beq         $s4, $t0, L_80800118
    if (ctx->r20 == ctx->r8) {
        // 0x808000E8: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_80800118;
    }
L_808000E8:
    // 0x808000E8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_808000EC:
    // 0x808000EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_808000F0:
    // 0x808000F0: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x808000F4: lbu         $t2, 0xC($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XC);
    // 0x808000F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808000FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800100: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800104: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800108: mflo        $t3
    ctx->r11 = lo;
    // 0x8080010C: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x80800110: bne         $v1, $s1, L_808000F0
    if (ctx->r3 != ctx->r17) {
        // 0x80800114: sb          $t4, 0xB($v0)
        MEM_B(0XB, ctx->r2) = ctx->r12;
            goto L_808000F0;
    }
    // 0x80800114: sb          $t4, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r12;
L_80800118:
    // 0x80800118: jal         0x80019E70
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    aligned8_memcpy(rdram, ctx);
        goto after_1;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800120: lhu         $t6, 0x6($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6);
    // 0x80800124: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x80800128: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x8080012C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80800130: subu        $t0, $s2, $t9
    ctx->r8 = SUB32(ctx->r18, ctx->r25);
    // 0x80800134: sra         $t1, $t0, 4
    ctx->r9 = S32(SIGNED(ctx->r8) >> 4);
    // 0x80800138: andi        $t2, $t1, 0x7FFF
    ctx->r10 = ctx->r9 & 0X7FFF;
    // 0x8080013C: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x80800140: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
L_80800144:
    // 0x80800144: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80800148: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x8080014C: sltu        $at, $s2, $t4
    ctx->r1 = ctx->r18 < ctx->r12 ? 1 : 0;
    // 0x80800150: bnel        $at, $zero, L_808000AC
    if (ctx->r1 != 0) {
        // 0x80800154: lhu         $a3, 0x6($s2)
        ctx->r7 = MEM_HU(ctx->r18, 0X6);
            goto L_808000AC;
    }
    goto skip_1;
    // 0x80800154: lhu         $a3, 0x6($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X6);
    skip_1:
L_80800158:
    // 0x80800158: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080015C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800160: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800164: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800168: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080016C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800170: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800174: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800178: jr          $ra
    // 0x8080017C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8080017C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _gcmapsects_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F40: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F40);
    return;
    // 0x80087F44: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void chfiregen_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C08: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X1804) << 16);
    // 0x80800C0C: jr          $ra
    // 0x80800C10: addiu       $v0, $v0, 0x1804
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1804));
    return;
    // 0x80800C10: addiu       $v0, $v0, 0x1804
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1804));
;}
RECOMP_FUNC void _bswalk_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841E8: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x800841E8);
    return;
    // 0x800841EC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void gccubeDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080088C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800890: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800894: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800898: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080089C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x808008A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808008A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808008A8: blezl       $t6, L_808008D8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808008AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808008D8;
    }
    goto skip_0;
    // 0x808008AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808008B0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_808008B4:
    // 0x808008B4: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x808008B8: jal         0x80088050
    // 0x808008BC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    _gccollectDll_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808008BC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x808008C0: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x808008C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808008C8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808008CC: bnel        $at, $zero, L_808008B4
    if (ctx->r1 != 0) {
        // 0x808008D0: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_808008B4;
    }
    goto skip_1;
    // 0x808008D0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x808008D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008D8:
    // 0x808008D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808008DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808008E0: jr          $ra
    // 0x808008E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808008E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void chnicecavemen_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1096, 0X1A5C) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1A5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1096, 0X1A5C));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1A5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1096, 0X1A5C));
;}
RECOMP_FUNC void func_80800158_bsbbilldrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080015C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800160: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800164: jal         0x800B5BE4
    // 0x80800168: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800168: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_0:
    // 0x8080016C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(61, 0XAC8) << 16);
    // 0x80800170: addiu       $t6, $t6, 0xAC8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(61, 0XAC8));
    // 0x80800174: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080017C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800180: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800184: jal         0x800BABB8
    // 0x80800188: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800188: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8080018C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800194: jr          $ra
    // 0x80800198: nop

    return;
    // 0x80800198: nop

;}
RECOMP_FUNC void _bamovespline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E98: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084E98);
    return;
    // 0x80084E9C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chidgoldhorde_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A08: syscall     187
    recomp_syscall_handler(rdram, ctx, 0x80085A08);
    return;
    // 0x80085A0C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _suexpressmorph_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B38: syscall     803
    recomp_syscall_handler(rdram, ctx, 0x80089B38);
    return;
    // 0x80089B3C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
