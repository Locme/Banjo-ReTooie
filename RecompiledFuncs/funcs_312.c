#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsfirstp_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084318: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084318);
    return;
    // 0x8008431C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_80800158_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080015C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800160: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800168: beq         $a1, $at, L_808001E4
    if (ctx->r5 == ctx->r1) {
        // 0x8080016C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_808001E4;
    }
    // 0x8080016C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800170: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800174: beq         $a1, $at, L_808001A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800178: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_808001A8;
    }
    // 0x80800178: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080017C: beq         $a1, $at, L_80800198
    if (ctx->r5 == ctx->r1) {
        // 0x80800180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800198;
    }
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800188: beql        $a1, $at, L_80800234
    if (ctx->r5 == ctx->r1) {
        // 0x8080018C: lw          $t1, 0x3C($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X3C);
            goto L_80800234;
    }
    goto skip_0;
    // 0x8080018C: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    skip_0:
    // 0x80800190: b           L_80800260
    // 0x80800194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800260;
    // 0x80800194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800198:
    // 0x80800198: jal         0x80800680
    // 0x8080019C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800680_chhellterskelter(rdram, ctx);
        goto after_0;
    // 0x8080019C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808001A0: b           L_80800260
    // 0x808001A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x808001A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001A8:
    // 0x808001A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001AC: bne         $a2, $at, L_808001DC
    if (ctx->r6 != ctx->r1) {
        // 0x808001B0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(964, 0X7A0) << 16);
            goto L_808001DC;
    }
    // 0x808001B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(964, 0X7A0) << 16);
    // 0x808001B4: jal         0x80085728
    // 0x808001B8: lwc1        $f12, 0x7A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(964, 0X7A0));
    _capod_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x808001B8: lwc1        $f12, 0x7A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(964, 0X7A0));
    after_1:
    // 0x808001BC: beq         $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001C0: nop
    
            goto L_808001DC;
    }
    // 0x808001C0: nop

    // 0x808001C4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: addiu       $a1, $zero, 0x210
    ctx->r5 = ADD32(0, 0X210);
    // 0x808001D0: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808001D4: jal         0x80108B04
    // 0x808001D8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x808001D8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_2:
L_808001DC:
    // 0x808001DC: b           L_80800260
    // 0x808001E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800260;
    // 0x808001E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808001E4:
    // 0x808001E4: addiu       $a0, $zero, 0x6A1
    ctx->r4 = ADD32(0, 0X6A1);
    // 0x808001E8: jal         0x800DA9E4
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_3;
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808001F0: bne         $v0, $zero, L_80800210
    if (ctx->r2 != 0) {
        // 0x808001F4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800210;
    }
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800200: jal         0x80085708
    // 0x80800204: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800204: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_4:
    // 0x80800208: b           L_80800260
    // 0x8080020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x8080020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800210:
    // 0x80800210: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: addiu       $a1, $zero, 0x210
    ctx->r5 = ADD32(0, 0X210);
    // 0x8080021C: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800220: jal         0x80108B04
    // 0x80800224: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x80800224: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_5:
    // 0x80800228: b           L_80800260
    // 0x8080022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x8080022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800230: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
L_80800234:
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: addiu       $a1, $zero, 0x210
    ctx->r5 = ADD32(0, 0X210);
    // 0x8080023C: bnel        $t1, $zero, L_80800260
    if (ctx->r9 != 0) {
        // 0x80800240: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800260;
    }
    goto skip_1;
    // 0x80800240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800244: jal         0x80089C70
    // 0x80800248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiefind_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8080024C: b           L_80800260
    // 0x80800250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x80800250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800254: b           L_80800260
    // 0x80800258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800260;
    // 0x80800258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080025C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800260:
    // 0x80800260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void _chmolehill_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086928: syscall     397
    recomp_syscall_handler(rdram, ctx, 0x80086928);
    return;
    // 0x8008692C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chegggrenade_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087218: syscall     537
    recomp_syscall_handler(rdram, ctx, 0x80087218);
    return;
    // 0x8008721C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080511C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080511C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80805120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80805124: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80805128: jal         0x80082FE0
    // 0x8080512C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080512C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80805130: jal         0x80807BB8
    // 0x80805134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80805134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80805138: jal         0x800A3404
    // 0x8080513C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_2;
    // 0x8080513C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80805140: beql        $v0, $zero, L_80805154
    if (ctx->r2 == 0) {
        // 0x80805144: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805154;
    }
    goto skip_0;
    // 0x80805144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80805148: jal         0x80807F24
    // 0x8080514C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807F24_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x8080514C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80805150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80805154:
    // 0x80805154: addiu       $a1, $zero, 0x30E
    ctx->r5 = ADD32(0, 0X30E);
    // 0x80805158: jal         0x8008CBB0
    // 0x8080515C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_playForDuration_loop(rdram, ctx);
        goto after_4;
    // 0x8080515C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_4:
    // 0x80805160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805164: jal         0x8008C990
    // 0x80805168: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_8008C990(rdram, ctx);
        goto after_5;
    // 0x80805168: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_5:
    // 0x8080516C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805170: addiu       $a1, $zero, 0x312
    ctx->r5 = ADD32(0, 0X312);
    // 0x80805174: jal         0x80800488
    // 0x80805178: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    func_80800488_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80805178: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_6:
    // 0x8080517C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805180: jal         0x80800264
    // 0x80805184: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80800264_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80805184: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_7:
    // 0x80805188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080518C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80805190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80805194: jr          $ra
    // 0x80805198: nop

    return;
    // 0x80805198: nop

;}
RECOMP_FUNC void bsledge_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808008C4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(304, 0X1358) << 16);
    // 0x808008C8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808008CC: jr          $ra
    // 0x808008D0: lw          $v0, 0x1358($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X1358));
    return;
    // 0x808008D0: lw          $v0, 0x1358($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X1358));
;}
RECOMP_FUNC void func_808005D4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005E0: lbu         $t9, 0x79($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X79);
    // 0x808005E4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808005E8: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x808005EC: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x808005F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808005F4: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808005F8: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x808005FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800600: beq         $t2, $v1, L_80800614
    if (ctx->r10 == ctx->r3) {
        // 0x80800604: sb          $t1, 0x79($a0)
        MEM_B(0X79, ctx->r4) = ctx->r9;
            goto L_80800614;
    }
    // 0x80800604: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
    // 0x80800608: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080060C: bnel        $t2, $at, L_80800690
    if (ctx->r10 != ctx->r1) {
        // 0x80800610: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800690;
    }
    goto skip_0;
    // 0x80800610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80800614:
    // 0x80800614: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x80800618: srl         $t3, $a0, 4
    ctx->r11 = S32(U32(ctx->r4) >> 4);
    // 0x8080061C: beq         $t3, $zero, L_80800634
    if (ctx->r11 == 0) {
        // 0x80800620: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_80800634;
    }
    // 0x80800620: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80800624: beq         $t3, $v1, L_80800634
    if (ctx->r11 == ctx->r3) {
        // 0x80800628: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800634;
    }
    // 0x80800628: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080062C: bne         $t3, $at, L_80800644
    if (ctx->r11 != ctx->r1) {
        // 0x80800630: nop
    
            goto L_80800644;
    }
    // 0x80800630: nop

L_80800634:
    // 0x80800634: jal         0x80803678
    // 0x80800638: nop

    func_80803678_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80800638: nop

    after_0:
    // 0x8080063C: b           L_80800650
    // 0x80800640: lbu         $t4, 0x79($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X79);
        goto L_80800650;
    // 0x80800640: lbu         $t4, 0x79($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X79);
L_80800644:
    // 0x80800644: jal         0x808036B8
    // 0x80800648: nop

    func_808036B8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80800648: nop

    after_1:
    // 0x8080064C: lbu         $t4, 0x79($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X79);
L_80800650:
    // 0x80800650: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(804, 0X7DB0) << 16);
    // 0x80800654: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x80800658: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x8080065C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80800660: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80800664: lh          $a1, 0x7DB0($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(804, 0X7DB0));
    // 0x80800668: jal         0x80802640
    // 0x8080066C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802640_chgameselect(rdram, ctx);
        goto after_2;
    // 0x8080066C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800670: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x80800674: srl         $t7, $a0, 4
    ctx->r15 = S32(U32(ctx->r4) >> 4);
    // 0x80800678: jal         0x80803DCC
    // 0x8080067C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80803DCC_chgameselect(rdram, ctx);
        goto after_3;
    // 0x8080067C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_3:
    // 0x80800680: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x80800684: jal         0x808026C8
    // 0x80800688: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808026C8_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80800688: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8080068C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800690:
    // 0x80800690: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800698: jr          $ra
    // 0x8080069C: nop

    return;
    // 0x8080069C: nop

;}
RECOMP_FUNC void func_80807790_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807790: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80807794: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80807798: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8080779C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808077A0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808077A4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808077A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808077AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808077B0: jal         0x80100094
    // 0x808077B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808077B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808077B8: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
    // 0x808077BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808077C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808077C4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808077C8: beql        $t7, $zero, L_80807808
    if (ctx->r15 == 0) {
        // 0x808077CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80807808;
    }
    goto skip_0;
    // 0x808077CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_808077D0:
    // 0x808077D0: jal         0x80087AF8
    // 0x808077D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808077D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x808077D8: beql        $v0, $s3, L_808077EC
    if (ctx->r2 == ctx->r19) {
        // 0x808077DC: lw          $t8, 0x6C($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X6C);
            goto L_808077EC;
    }
    goto skip_1;
    // 0x808077DC: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
    skip_1:
    // 0x808077E0: b           L_80807808
    // 0x808077E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80807808;
    // 0x808077E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808077E8: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
L_808077EC:
    // 0x808077EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808077F0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808077F4: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x808077F8: sltu        $at, $s0, $t9
    ctx->r1 = ctx->r16 < ctx->r25 ? 1 : 0;
    // 0x808077FC: bne         $at, $zero, L_808077D0
    if (ctx->r1 != 0) {
        // 0x80807800: nop
    
            goto L_808077D0;
    }
    // 0x80807800: nop

    // 0x80807804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80807808:
    // 0x80807808: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080780C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80807810: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80807814: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80807818: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080781C: jr          $ra
    // 0x80807820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80807820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bakey_func_8009191C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009191C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091924: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80091928: jal         0x800BCCFC
    // 0x8009192C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BCCFC(rdram, ctx);
        goto after_0;
    // 0x8009192C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80091930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091938: jr          $ra
    // 0x8009193C: nop

    return;
    // 0x8009193C: nop

;}
RECOMP_FUNC void _cheggfire_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871F0: syscall     535
    recomp_syscall_handler(rdram, ctx, 0x800871F0);
    return;
    // 0x800871F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800F5184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F518C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800F5190: jal         0x800F47C0
    // 0x800F5194: addiu       $a0, $a0, 0x3528
    ctx->r4 = ADD32(ctx->r4, 0X3528);
    func_800F47C0(rdram, ctx);
        goto after_0;
    // 0x800F5194: addiu       $a0, $a0, 0x3528
    ctx->r4 = ADD32(ctx->r4, 0X3528);
    after_0:
    // 0x800F5198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F519C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F51A0: jr          $ra
    // 0x800F51A4: nop

    return;
    // 0x800F51A4: nop

;}
RECOMP_FUNC void func_800E7828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7828: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E782C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7830: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800E7834: jal         0x800F2EFC
    // 0x800E7838: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800F2EFC(rdram, ctx);
        goto after_0;
    // 0x800E7838: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800E783C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E7840: addiu       $a0, $a0, -0x2A80
    ctx->r4 = ADD32(ctx->r4, -0X2A80);
    // 0x800E7844: jal         0x800F371C
    // 0x800E7848: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F371C(rdram, ctx);
        goto after_1;
    // 0x800E7848: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x800E784C: bne         $v0, $zero, L_800E78B8
    if (ctx->r2 != 0) {
        // 0x800E7850: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800E78B8;
    }
    // 0x800E7850: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E7854: addiu       $a0, $a0, -0x2A80
    ctx->r4 = ADD32(ctx->r4, -0X2A80);
    // 0x800E7858: jal         0x800F2E7C
    // 0x800E785C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F2E7C(rdram, ctx);
        goto after_2;
    // 0x800E785C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x800E7860: jal         0x800E765C
    // 0x800E7864: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800E765C(rdram, ctx);
        goto after_3;
    // 0x800E7864: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800E7868: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800E786C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800E7870: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x800E7874: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800E7878: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x800E787C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800E7880: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800E7884: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800E7888: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800E788C: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800E7890: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800E7894: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x800E7898: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x800E789C: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x800E78A0: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800E78A4: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x800E78A8: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800E78AC: or          $t8, $t4, $t6
    ctx->r24 = ctx->r12 | ctx->r14;
    // 0x800E78B0: or          $t0, $t8, $t2
    ctx->r8 = ctx->r24 | ctx->r10;
    // 0x800E78B4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
L_800E78B8:
    // 0x800E78B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E78BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800E78C0: jr          $ra
    // 0x800E78C4: nop

    return;
    // 0x800E78C4: nop

;}
RECOMP_FUNC void ncbaspline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800118: jal         0x8080002C
    // 0x8080011C: nop

    func_8080002C_ncbaspline(rdram, ctx);
        goto after_0;
    // 0x8080011C: nop

    after_0:
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void chjrinnlight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2080, 0XF0) << 16);
    // 0x808000E0: jr          $ra
    // 0x808000E4: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2080, 0XF0));
    return;
    // 0x808000E4: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2080, 0XF0));
    // 0x808000E8: nop

    // 0x808000EC: nop

;}
RECOMP_FUNC void chfactorycrusher_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1136, 0XA98) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xA98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1136, 0XA98));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xA98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1136, 0XA98));
;}
RECOMP_FUNC void bsdie_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800930: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800934: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(156, 0X980) << 16);
    // 0x80800938: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080093C: jr          $ra
    // 0x80800940: lw          $v0, 0x980($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(156, 0X980));
    return;
    // 0x80800940: lw          $v0, 0x980($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(156, 0X980));
    // 0x80800944: nop

    // 0x80800948: nop

    // 0x8080094C: nop

;}
RECOMP_FUNC void func_800E2630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2630: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E2634: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E2638: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800E263C: addiu       $s0, $s0, -0x2B90
    ctx->r16 = ADD32(ctx->r16, -0X2B90);
    // 0x800E2640: lh          $t6, 0x1C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1C);
    // 0x800E2644: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E2648: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E264C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E2650: beq         $a2, $t6, L_800E26A8
    if (ctx->r6 == ctx->r14) {
        // 0x800E2654: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_800E26A8;
    }
    // 0x800E2654: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800E2658: sh          $a2, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r6;
    // 0x800E265C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E2660: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800E2664: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800E2668: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800E266C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800E2670: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x800E2674: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800E2678: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800E267C: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800E2680: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800E2684: lh          $t0, 0x1C($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1C);
    // 0x800E2688: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800E268C: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x800E2690: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x800E2694: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800E2698: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x800E269C: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x800E26A0: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x800E26A4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_800E26A8:
    // 0x800E26A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E26AC: jal         0x800E204C
    // 0x800E26B0: lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X80);
    func_800E204C(rdram, ctx);
        goto after_0;
    // 0x800E26B0: lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X80);
    after_0:
    // 0x800E26B4: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    // 0x800E26B8: jal         0x800AF5FC
    // 0x800E26BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800AF5FC(rdram, ctx);
        goto after_1;
    // 0x800E26BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x800E26C0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800E26C4: jal         0x800AF5F0
    // 0x800E26C8: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    func_800AF5F0(rdram, ctx);
        goto after_2;
    // 0x800E26C8: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    after_2:
    // 0x800E26CC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800E26D0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800E26D4: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x800E26D8: lh          $t4, 0x4($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X4);
    // 0x800E26DC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800E26E0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800E26E4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800E26E8: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x800E26EC: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x800E26F0: jal         0x8002E330
    // 0x800E26F4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800E26F4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x800E26F8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800E26FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E2700: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x800E2704: jal         0x800E2260
    // 0x800E2708: lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X80);
    func_800E2260(rdram, ctx);
        goto after_4;
    // 0x800E2708: lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X80);
    after_4:
    // 0x800E270C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E2710: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E2714: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E2718: jr          $ra
    // 0x800E271C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800E271C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bskazjump_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083448: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083448);
    return;
    // 0x8008344C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void gcnewoption_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CB0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80800CB4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800CB8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800CBC: bnel        $t6, $at, L_80800CD0
    if (ctx->r14 != ctx->r1) {
        // 0x80800CC0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800CD0;
    }
    goto skip_0;
    // 0x80800CC0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x80800CC4: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x80800CC8: beq         $t7, $zero, L_80800CDC
    if (ctx->r15 == 0) {
        // 0x80800CCC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800CDC;
    }
    // 0x80800CCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80800CD0:
    // 0x80800CD0: jal         0x8080103C
    // 0x80800CD4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8080103C_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80800CD4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800CD8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_80800CDC:
    // 0x80800CDC: jal         0x80088728
    // 0x80800CE0: lh          $a0, 0x240($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X240);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800CE0: lh          $a0, 0x240($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X240);
    after_1:
    // 0x80800CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CEC: jr          $ra
    // 0x80800CF0: nop

    return;
    // 0x80800CF0: nop

;}
RECOMP_FUNC void cothemedll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: jal         0x800FE890
    // 0x808000C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800FE890(rdram, ctx);
        goto after_0;
    // 0x808000C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000C4: bnel        $v0, $zero, L_80800108
    if (ctx->r2 != 0) {
        // 0x808000C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800108;
    }
    goto skip_0;
    // 0x808000C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000CC: jal         0x80800000
    // 0x808000D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_cothemedll(rdram, ctx);
        goto after_1;
    // 0x808000D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000D4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808000D8: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x808000DC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x808000E0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2508, 0X732) << 16);
    // 0x808000E4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x808000E8: lh          $a0, 0x732($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(2508, 0X732));
    // 0x808000EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000F0: sra         $t7, $a0, 2
    ctx->r15 = S32(SIGNED(ctx->r4) >> 2);
    // 0x808000F4: beq         $t7, $at, L_80800104
    if (ctx->r15 == ctx->r1) {
        // 0x808000F8: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_80800104;
    }
    // 0x808000F8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x808000FC: jal         0x80016DA0
    // 0x80800100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016DA0(rdram, ctx);
        goto after_2;
    // 0x80800100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800104:
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800108:
    // 0x80800108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_800F8F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8F3C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F8F40: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800F8F44: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800F8F48: addiu       $s1, $s1, 0x54F8
    ctx->r17 = ADD32(ctx->r17, 0X54F8);
    // 0x800F8F4C: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x800F8F50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F8F54: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800F8F58: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800F8F5C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800F8F60: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800F8F64: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800F8F68: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800F8F6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F8F70: bne         $t6, $at, L_800F9044
    if (ctx->r14 != ctx->r1) {
        // 0x800F8F74: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_800F9044;
    }
    // 0x800F8F74: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800F8F78: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F8F7C: addiu       $s0, $s0, 0x54F0
    ctx->r16 = ADD32(ctx->r16, 0X54F0);
    // 0x800F8F80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800F8F84: beql        $a0, $zero, L_800F9048
    if (ctx->r4 == 0) {
        // 0x800F8F88: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800F9048;
    }
    goto skip_0;
    // 0x800F8F88: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x800F8F8C: jal         0x800B28C4
    // 0x800F8F90: nop

    vector_begin(rdram, ctx);
        goto after_0;
    // 0x800F8F90: nop

    after_0:
    // 0x800F8F94: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800F8F98: jal         0x800B296C
    // 0x800F8F9C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_end(rdram, ctx);
        goto after_1;
    // 0x800F8F9C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x800F8FA0: sltu        $at, $s2, $v0
    ctx->r1 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x800F8FA4: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800F8FA8: beq         $at, $zero, L_800F9044
    if (ctx->r1 == 0) {
        // 0x800F8FAC: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800F9044;
    }
    // 0x800F8FAC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800F8FB0: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800F8FB4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800F8FB8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800F8FBC: addiu       $s3, $s3, 0x5500
    ctx->r19 = ADD32(ctx->r19, 0X5500);
    // 0x800F8FC0: addiu       $s5, $s5, 0x5510
    ctx->r21 = ADD32(ctx->r21, 0X5510);
    // 0x800F8FC4: addiu       $s4, $zero, 0xB
    ctx->r20 = ADD32(0, 0XB);
    // 0x800F8FC8: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x800F8FCC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_800F8FD0:
    // 0x800F8FD0: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x800F8FD4: bne         $s2, $v0, L_800F9008
    if (ctx->r18 != ctx->r2) {
        // 0x800F8FD8: nop
    
            goto L_800F9008;
    }
    // 0x800F8FD8: nop

    // 0x800F8FDC: jal         0x800EE7F8
    // 0x800F8FE0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800F8FE0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x800F8FE4: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x800F8FE8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800F8FEC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800F8FF0: sh          $t7, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r15;
    // 0x800F8FF4: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x800F8FF8: jal         0x800EFA4C
    // 0x800F8FFC: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x800F8FFC: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_3:
    // 0x800F9000: b           L_800F9038
    // 0x800F9004: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
        goto L_800F9038;
    // 0x800F9004: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
L_800F9008:
    // 0x800F9008: bne         $s4, $v0, L_800F9034
    if (ctx->r20 != ctx->r2) {
        // 0x800F900C: addiu       $a0, $s0, 0x24
        ctx->r4 = ADD32(ctx->r16, 0X24);
            goto L_800F9034;
    }
    // 0x800F900C: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x800F9010: jal         0x800EE7F8
    // 0x800F9014: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x800F9014: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x800F9018: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x800F901C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800F9020: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800F9024: sh          $t8, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r24;
    // 0x800F9028: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x800F902C: jal         0x800EFA4C
    // 0x800F9030: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x800F9030: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_5:
L_800F9034:
    // 0x800F9034: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
L_800F9038:
    // 0x800F9038: sltu        $at, $s0, $s6
    ctx->r1 = ctx->r16 < ctx->r22 ? 1 : 0;
    // 0x800F903C: bnel        $at, $zero, L_800F8FD0
    if (ctx->r1 != 0) {
        // 0x800F9040: lbu         $v0, 0x0($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X0);
            goto L_800F8FD0;
    }
    goto skip_1;
    // 0x800F9040: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    skip_1:
L_800F9044:
    // 0x800F9044: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800F9048:
    // 0x800F9048: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800F904C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F9050: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800F9054: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800F9058: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800F905C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800F9060: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800F9064: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800F9068: jr          $ra
    // 0x800F906C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800F906C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _ncpod_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895C8: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800895C8);
    return;
    // 0x800895CC: addi        $t0, $zero, 0x84
    ctx->r8 = ADD32(0, 0X84);
;}
RECOMP_FUNC void func_8002A0CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A0CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A0D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A0D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002A0D8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002A0DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8002A0E0: lbu         $t7, 0x36($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X36);
    // 0x8002A0E4: blez        $t7, L_8002A138
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8002A0E8: nop
    
            goto L_8002A138;
    }
    // 0x8002A0E8: nop

L_8002A0EC:
    // 0x8002A0EC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002A0F0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A0F4: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x8002A0F8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8002A0FC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8002A100: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002A104: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8002A108: sb          $zero, 0x33($t2)
    MEM_B(0X33, ctx->r10) = 0;
    // 0x8002A10C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002A110: jal         0x8002A150
    // 0x8002A114: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002A150(rdram, ctx);
        goto after_0;
    // 0x8002A114: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x8002A118: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A11C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8002A120: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8002A124: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8002A128: lbu         $t6, 0x36($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X36);
    // 0x8002A12C: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002A130: bne         $at, $zero, L_8002A0EC
    if (ctx->r1 != 0) {
        // 0x8002A134: nop
    
            goto L_8002A0EC;
    }
    // 0x8002A134: nop

L_8002A138:
    // 0x8002A138: b           L_8002A140
    // 0x8002A13C: nop

        goto L_8002A140;
    // 0x8002A13C: nop

L_8002A140:
    // 0x8002A140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A144: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002A148: jr          $ra
    // 0x8002A14C: nop

    return;
    // 0x8002A14C: nop

;}
RECOMP_FUNC void _gctransitionDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881C0: syscall     674
    recomp_syscall_handler(rdram, ctx, 0x800881C0);
    return;
    // 0x800881C4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _glsplineDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884E8: syscall     689
    recomp_syscall_handler(rdram, ctx, 0x800884E8);
    return;
    // 0x800884EC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bainput_should_exit_first_person(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097BB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097BBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097BC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097BC4: jal         0x80091A58
    // 0x80097BC8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097BC8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x80097BCC: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097BD0: beq         $t6, $zero, L_80097BEC
    if (ctx->r14 == 0) {
        // 0x80097BD4: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097BEC;
    }
    // 0x80097BD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097BD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80097BDC: jal         0x80098024
    // 0x80097BE0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    bainput_isEnabled(rdram, ctx);
        goto after_1;
    // 0x80097BE0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80097BE4: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097BE8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80097BEC:
    // 0x80097BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097BF4: jr          $ra
    // 0x80097BF8: nop

    return;
    // 0x80097BF8: nop

;}
RECOMP_FUNC void func_80800E30_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800E3C: jal         0x80085808
    // 0x80800E40: addiu       $a1, $zero, 0xD4
    ctx->r5 = ADD32(0, 0XD4);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800E40: addiu       $a1, $zero, 0xD4
    ctx->r5 = ADD32(0, 0XD4);
    after_0:
    // 0x80800E44: jal         0x80085818
    // 0x80800E48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800E48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E54: jr          $ra
    // 0x80800E58: nop

    return;
    // 0x80800E58: nop

    // 0x80800E5C: nop

;}
RECOMP_FUNC void chbanjocurrent_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(756, 0X7D0) << 16);
    // 0x8080002C: jr          $ra
    // 0x80800030: addiu       $v0, $v0, 0x7D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(756, 0X7D0));
    return;
    // 0x80800030: addiu       $v0, $v0, 0x7D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(756, 0X7D0));
;}
RECOMP_FUNC void func_80800184_chtntblockage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800188: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080018C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800190: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800194: jal         0x80101080
    // 0x80800198: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800198: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080019C: jal         0x80106790
    // 0x808001A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808001A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808001A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001AC: jal         0x800866B8
    // 0x808001B0: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808001B0: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_2:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: lui         $a1, 0x4496
    ctx->r5 = S32(0X4496 << 16);
    // 0x808001BC: jal         0x80086688
    // 0x808001C0: lui         $a2, 0x44AF
    ctx->r6 = S32(0X44AF << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808001C0: lui         $a2, 0x44AF
    ctx->r6 = S32(0X44AF << 16);
    after_3:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x800866C0
    // 0x808001CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x808001CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x808001D0: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808001D4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: jal         0x800866D0
    // 0x808001E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x808001E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808001E4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(900, 0X29C) << 16);
    // 0x808001E8: addiu       $t6, $t6, 0x29C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(900, 0X29C));
    // 0x808001EC: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    // 0x808001F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001F8: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x808001FC: jal         0x800BABB8
    // 0x80800200: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800200: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_6:
    // 0x80800204: jal         0x808000A8
    // 0x80800208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808000A8_chtntblockage(rdram, ctx);
        goto after_7;
    // 0x80800208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8080020C: jal         0x800DA544
    // 0x80800210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x80800210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800218: jal         0x80101FDC
    // 0x8080021C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x8080021C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800224: jal         0x80103110
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_10;
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8080022C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800230: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800234: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800238: jr          $ra
    // 0x8080023C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080023C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_801054D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801054D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801054D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801054DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801054E0: jal         0x80105494
    // 0x801054E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x801054E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x801054E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801054EC: jal         0x800D7DE8
    // 0x801054F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D7DE8(rdram, ctx);
        goto after_1;
    // 0x801054F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801054F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801054F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801054FC: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x80105500: jal         0x800D8588
    // 0x80105504: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    func_800D8588(rdram, ctx);
        goto after_2;
    // 0x80105504: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    after_2:
    // 0x80105508: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8010550C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80105510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105514: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80105518: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8010551C: beql        $t8, $zero, L_80105530
    if (ctx->r24 == 0) {
        // 0x80105520: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80105530;
    }
    goto skip_0;
    // 0x80105520: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80105524: jal         0x8010B990
    // 0x80105528: addiu       $a1, $zero, 0x6000
    ctx->r5 = ADD32(0, 0X6000);
    func_8010B990(rdram, ctx);
        goto after_3;
    // 0x80105528: addiu       $a1, $zero, 0x6000
    ctx->r5 = ADD32(0, 0X6000);
    after_3:
    // 0x8010552C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_80105530:
    // 0x80105530: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x80105534: sll         $t2, $t0, 26
    ctx->r10 = S32(ctx->r8 << 26);
    // 0x80105538: bgezl       $t2, L_8010555C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8010553C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8010555C;
    }
    goto skip_1;
    // 0x8010553C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80105540: jal         0x80105A5C
    // 0x80105544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_4;
    // 0x80105544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80105548: beql        $v0, $zero, L_8010555C
    if (ctx->r2 == 0) {
        // 0x8010554C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8010555C;
    }
    goto skip_2;
    // 0x8010554C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80105550: jal         0x800FFAB0
    // 0x80105554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80105554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80105558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010555C:
    // 0x8010555C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80105560: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80105564: jr          $ra
    // 0x80105568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80105568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8008B2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B2E8: lbu         $t9, 0x1B($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1B);
    // 0x8008B2EC: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x8008B2F0: andi        $t8, $t7, 0x18
    ctx->r24 = ctx->r15 & 0X18;
    // 0x8008B2F4: andi        $t0, $t9, 0xFFE7
    ctx->r8 = ctx->r25 & 0XFFE7;
    // 0x8008B2F8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8008B2FC: jr          $ra
    // 0x8008B300: sb          $t1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r9;
    return;
    // 0x8008B300: sb          $t1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void _glintrosyncDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885D8: syscall     695
    recomp_syscall_handler(rdram, ctx, 0x800885D8);
    return;
    // 0x800885DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void badrone_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800584: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080058C: jal         0x8080004C
    // 0x80800590: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    badrone_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800590: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800594: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80800598: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8080059C: beql        $v0, $zero, L_808005B8
    if (ctx->r2 == 0) {
        // 0x808005A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005B8;
    }
    goto skip_0;
    // 0x808005A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808005A4: jal         0x8008E35C
    // 0x808005A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    player_inWater(rdram, ctx);
        goto after_1;
    // 0x808005A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808005AC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808005B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x808005B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005B8:
    // 0x808005B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005BC: jr          $ra
    // 0x808005C0: nop

    return;
    // 0x808005C0: nop

;}
RECOMP_FUNC void func_80800104_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800108: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800114: jal         0x8009E74C
    // 0x80800118: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800118: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x8080011C: bne         $v0, $zero, L_80800194
    if (ctx->r2 != 0) {
        // 0x80800120: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800194;
    }
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: jal         0x8009BF5C
    // 0x80800128: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x80800128: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: jal         0x8009C4CC
    // 0x80800134: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x80800134: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800138: jal         0x8009BC34
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BC34(rdram, ctx);
        goto after_3;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: jal         0x800A0CF4
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_4;
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x800961AC
    // 0x80800154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_5;
    // 0x80800154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x80093360
    // 0x80800160: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_6;
    // 0x80800160: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x80085298
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _baswim_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800170: jal         0x8009E6F8
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_8;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800178: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x8080017C: beq         $v0, $at, L_8080018C
    if (ctx->r2 == ctx->r1) {
        // 0x80800180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080018C;
    }
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x80085558
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baairbar_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_8080018C:
    // 0x8080018C: jal         0x80085288
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80800194:
    // 0x80800194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080019C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void func_80803DC4_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803DC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80803DC8: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80803DCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803DD0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80803DD4: beq         $a1, $at, L_80803DF0
    if (ctx->r5 == ctx->r1) {
        // 0x80803DD8: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80803DF0;
    }
    // 0x80803DD8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80803DDC: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80803DE0: beq         $a1, $at, L_80803EA4
    if (ctx->r5 == ctx->r1) {
        // 0x80803DE4: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80803EA4;
    }
    // 0x80803DE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80803DE8: b           L_80803EEC
    // 0x80803DEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803EEC;
    // 0x80803DEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803DF0:
    // 0x80803DF0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1852, 0X5740) << 16);
    // 0x80803DF4: addiu       $t6, $t6, 0x5740
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1852, 0X5740));
    // 0x80803DF8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80803DFC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80803E00: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80803E04: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80803E08: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80803E0C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80803E10: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80803E14: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x80803E18: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80803E1C: jal         0x800EF934
    // 0x80803E20: lw          $a2, 0x48($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X48);
    func_800EF934(rdram, ctx);
        goto after_0;
    // 0x80803E20: lw          $a2, 0x48($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X48);
    after_0:
    // 0x80803E24: addiu       $a0, $zero, 0x37A
    ctx->r4 = ADD32(0, 0X37A);
    // 0x80803E28: jal         0x801084B0
    // 0x80803E2C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x80803E2C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80803E30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5344) << 16);
    // 0x80803E34: lwc1        $f4, 0x5344($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5344));
    // 0x80803E38: lui         $at, 0x427E
    ctx->r1 = S32(0X427E << 16);
    // 0x80803E3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803E40: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x80803E44: lbu         $t5, 0x79($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X79);
    // 0x80803E48: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
    // 0x80803E4C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80803E50: andi        $t7, $t5, 0xFF0F
    ctx->r15 = ctx->r13 & 0XFF0F;
    // 0x80803E54: lhu         $t3, 0x76($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X76);
    // 0x80803E58: lbu         $t1, 0x79($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X79);
    // 0x80803E5C: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80803E60: andi        $t5, $t3, 0x7F
    ctx->r13 = ctx->r11 & 0X7F;
    // 0x80803E64: srl         $t2, $t1, 4
    ctx->r10 = S32(U32(ctx->r9) >> 4);
    // 0x80803E68: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x80803E6C: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x80803E70: sb          $t6, 0x79($v0)
    MEM_B(0X79, ctx->r2) = ctx->r14;
    // 0x80803E74: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80803E78: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80803E7C: lhu         $t9, 0x76($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X76);
    // 0x80803E80: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x80803E84: sll         $t2, $t0, 7
    ctx->r10 = S32(ctx->r8 << 7);
    // 0x80803E88: or          $t4, $t2, $t5
    ctx->r12 = ctx->r10 | ctx->r13;
    // 0x80803E8C: sh          $t4, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r12;
    // 0x80803E90: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80803E94: jal         0x800EE780
    // 0x80803E98: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x80803E98: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80803E9C: b           L_80803EEC
    // 0x80803EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803EEC;
    // 0x80803EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803EA4:
    // 0x80803EA4: jal         0x8008A340
    // 0x80803EA8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    _sueggmisc_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80803EA8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_3:
    // 0x80803EAC: beq         $v0, $zero, L_80803EE8
    if (ctx->r2 == 0) {
        // 0x80803EB0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80803EE8;
    }
    // 0x80803EB0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80803EB4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80803EB8: jal         0x8010114C
    // 0x80803EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_4;
    // 0x80803EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80803EC0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80803EC4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80803EC8: lw          $a1, 0x24($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X24);
    // 0x80803ECC: srl         $t6, $a1, 22
    ctx->r14 = S32(U32(ctx->r5) >> 22);
    // 0x80803ED0: jal         0x808037B0
    // 0x80803ED4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_808037B0_chdragonbrothers(rdram, ctx);
        goto after_5;
    // 0x80803ED4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_5:
    // 0x80803ED8: b           L_80803EEC
    // 0x80803EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803EEC;
    // 0x80803EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80803EE0: b           L_80803EEC
    // 0x80803EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803EEC;
    // 0x80803EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803EE8:
    // 0x80803EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803EEC:
    // 0x80803EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803EF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80803EF4: jr          $ra
    // 0x80803EF8: nop

    return;
    // 0x80803EF8: nop

;}
RECOMP_FUNC void bskazpaddle_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800804: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800808: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(268, 0XA70) << 16);
    // 0x8080080C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800810: jr          $ra
    // 0x80800814: lw          $v0, 0xA70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(268, 0XA70));
    return;
    // 0x80800814: lw          $v0, 0xA70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(268, 0XA70));
;}
RECOMP_FUNC void func_8080093C_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080093C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800940: slti        $at, $a1, 0x58
    ctx->r1 = SIGNED(ctx->r5) < 0X58 ? 1 : 0;
    // 0x80800944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800948: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080094C: bne         $at, $zero, L_80800968
    if (ctx->r1 != 0) {
        // 0x80800950: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800968;
    }
    // 0x80800950: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800954: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800958: beql        $a1, $at, L_80800AA8
    if (ctx->r5 == ctx->r1) {
        // 0x8080095C: lhu         $t1, 0x76($a3)
        ctx->r9 = MEM_HU(ctx->r7, 0X76);
            goto L_80800AA8;
    }
    goto skip_0;
    // 0x8080095C: lhu         $t1, 0x76($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X76);
    skip_0:
    // 0x80800960: b           L_80800B54
    // 0x80800964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B54;
    // 0x80800964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800968:
    // 0x80800968: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x8080096C: bne         $at, $zero, L_80800994
    if (ctx->r1 != 0) {
        // 0x80800970: addiu       $t6, $a1, -0x2E
        ctx->r14 = ADD32(ctx->r5, -0X2E);
            goto L_80800994;
    }
    // 0x80800970: addiu       $t6, $a1, -0x2E
    ctx->r14 = ADD32(ctx->r5, -0X2E);
    // 0x80800974: sltiu       $at, $t6, 0x2A
    ctx->r1 = ctx->r14 < 0X2A ? 1 : 0;
    // 0x80800978: beq         $at, $zero, L_80800B50
    if (ctx->r1 == 0) {
        // 0x8080097C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800B50;
    }
    // 0x8080097C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800980: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2DB8) << 16);
    // 0x80800984: addu        $at, $at, $t6
    gpr jr_addend_8080098C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800988: lw          $t6, 0x2DB8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2DB8));
    // 0x8080098C: jr          $t6
    // 0x80800990: nop

    switch (jr_addend_8080098C >> 2) {
        case 0: goto L_808009A8; break;
        case 1: goto L_808009C4; break;
        case 2: goto L_808009DC; break;
        case 3: goto L_80800B50; break;
        case 4: goto L_80800B50; break;
        case 5: goto L_80800B50; break;
        case 6: goto L_80800B50; break;
        case 7: goto L_80800B50; break;
        case 8: goto L_80800B50; break;
        case 9: goto L_80800B50; break;
        case 10: goto L_80800B50; break;
        case 11: goto L_80800B50; break;
        case 12: goto L_80800B50; break;
        case 13: goto L_80800B50; break;
        case 14: goto L_80800B50; break;
        case 15: goto L_808009F8; break;
        case 16: goto L_80800B50; break;
        case 17: goto L_80800B50; break;
        case 18: goto L_80800B50; break;
        case 19: goto L_80800B50; break;
        case 20: goto L_80800B50; break;
        case 21: goto L_80800B50; break;
        case 22: goto L_80800B50; break;
        case 23: goto L_80800B50; break;
        case 24: goto L_80800B50; break;
        case 25: goto L_80800B50; break;
        case 26: goto L_80800B50; break;
        case 27: goto L_80800B50; break;
        case 28: goto L_80800B50; break;
        case 29: goto L_80800B50; break;
        case 30: goto L_80800B50; break;
        case 31: goto L_80800B50; break;
        case 32: goto L_80800B50; break;
        case 33: goto L_80800B50; break;
        case 34: goto L_80800B50; break;
        case 35: goto L_80800B50; break;
        case 36: goto L_80800A28; break;
        case 37: goto L_80800B50; break;
        case 38: goto L_80800B50; break;
        case 39: goto L_80800B50; break;
        case 40: goto L_80800B50; break;
        case 41: goto L_80800A50; break;
        default: switch_error(__func__, 0x8080098C, 0x80802DB8);
    }
    // 0x80800990: nop

L_80800994:
    // 0x80800994: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800998: beq         $a1, $at, L_80800A0C
    if (ctx->r5 == ctx->r1) {
        // 0x8080099C: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80800A0C;
    }
    // 0x8080099C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808009A0: b           L_80800B54
    // 0x808009A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B54;
    // 0x808009A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009A8:
    // 0x808009A8: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x808009AC: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808009B0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808009B4: jal         0x8080134C
    // 0x808009B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8080134C_chtrashcangame(rdram, ctx);
        goto after_0;
    // 0x808009B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x808009BC: b           L_80800B54
    // 0x808009C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B54;
    // 0x808009C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009C4:
    // 0x808009C4: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x808009C8: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x808009CC: jal         0x80108B04
    // 0x808009D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80108B04(rdram, ctx);
        goto after_1;
    // 0x808009D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x808009D4: b           L_80800B54
    // 0x808009D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B54;
    // 0x808009D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009DC:
    // 0x808009DC: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x808009E0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808009E4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808009E8: jal         0x80801558
    // 0x808009EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80801558_chtrashcangame(rdram, ctx);
        goto after_2;
    // 0x808009EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x808009F0: b           L_80800B58
    // 0x808009F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B58;
    // 0x808009F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009F8:
    // 0x808009F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808009FC: jal         0x808019EC
    // 0x80800A00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_808019EC_chtrashcangame(rdram, ctx);
        goto after_3;
    // 0x80800A00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800A04: b           L_80800B54
    // 0x80800A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B54;
    // 0x80800A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A0C:
    // 0x80800A0C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800A10: bne         $t7, $at, L_80800A20
    if (ctx->r15 != ctx->r1) {
        // 0x80800A14: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800A20;
    }
    // 0x80800A14: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800A18: jal         0x808003D0
    // 0x80800A1C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_4;
    // 0x80800A1C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_4:
L_80800A20:
    // 0x80800A20: b           L_80800B54
    // 0x80800A24: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800B54;
    // 0x80800A24: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800A28:
    // 0x80800A28: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    // 0x80800A2C: jal         0x80088098
    // 0x80800A30: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800A30: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_5:
    // 0x80800A34: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800A38: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2384, 0X30AC) << 16);
    // 0x80800A3C: addiu       $a0, $a0, 0x30AC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2384, 0X30AC));
    // 0x80800A40: jal         0x80088090
    // 0x80800A44: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800A44: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_6:
    // 0x80800A48: b           L_80800B54
    // 0x80800A4C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800B54;
    // 0x80800A4C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800A50:
    // 0x80800A50: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800A54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A58: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800A5C: and         $t9, $a2, $at
    ctx->r25 = ctx->r6 & ctx->r1;
    // 0x80800A60: srl         $a1, $t9, 16
    ctx->r5 = S32(U32(ctx->r25) >> 16);
    // 0x80800A64: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x80800A68: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80800A6C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80800A70: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80800A74: jal         0x80088078
    // 0x80800A78: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800A78: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_7:
    // 0x80800A7C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800A80: beq         $v0, $zero, L_80800A9C
    if (ctx->r2 == 0) {
        // 0x80800A84: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800A9C;
    }
    // 0x80800A84: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800A88: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800A8C: jal         0x80801740
    // 0x80800A90: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80801740_chtrashcangame(rdram, ctx);
        goto after_8;
    // 0x80800A90: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_8:
    // 0x80800A94: b           L_80800B54
    // 0x80800A98: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800B54;
    // 0x80800A98: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800A9C:
    // 0x80800A9C: b           L_80800B54
    // 0x80800AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B54;
    // 0x80800AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800AA4: lhu         $t1, 0x76($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X76);
L_80800AA8:
    // 0x80800AA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800AAC: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x80800AB0: sh          $t2, 0x76($a3)
    MEM_H(0X76, ctx->r7) = ctx->r10;
    // 0x80800AB4: swc1        $f4, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f4.u32l;
    // 0x80800AB8: jal         0x80088848
    // 0x80800ABC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_9;
    // 0x80800ABC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_9:
    // 0x80800AC0: beq         $v0, $zero, L_80800ADC
    if (ctx->r2 == 0) {
        // 0x80800AC4: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800ADC;
    }
    // 0x80800AC4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800AC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800ACC: jal         0x808003D0
    // 0x80800AD0: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_10;
    // 0x80800AD0: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_10:
    // 0x80800AD4: b           L_80800B40
    // 0x80800AD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80800B40;
    // 0x80800AD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80800ADC:
    // 0x80800ADC: jal         0x800D395C
    // 0x80800AE0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800D395C(rdram, ctx);
        goto after_11;
    // 0x80800AE0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_11:
    // 0x80800AE4: beq         $v0, $zero, L_80800B00
    if (ctx->r2 == 0) {
        // 0x80800AE8: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800B00;
    }
    // 0x80800AE8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800AEC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800AF0: jal         0x808003D0
    // 0x80800AF4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_12;
    // 0x80800AF4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_12:
    // 0x80800AF8: b           L_80800B40
    // 0x80800AFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80800B40;
    // 0x80800AFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80800B00:
    // 0x80800B00: jal         0x800F54E4
    // 0x80800B04: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x80800B04: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_13:
    // 0x80800B08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B0C: jal         0x800F64A4
    // 0x80800B10: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800F64A4(rdram, ctx);
        goto after_14;
    // 0x80800B10: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_14:
    // 0x80800B14: bne         $v0, $zero, L_80800B30
    if (ctx->r2 != 0) {
        // 0x80800B18: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800B30;
    }
    // 0x80800B18: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800B1C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800B20: jal         0x808003D0
    // 0x80800B24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_15;
    // 0x80800B24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800B28: b           L_80800B40
    // 0x80800B2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80800B40;
    // 0x80800B2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80800B30:
    // 0x80800B30: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800B34: jal         0x808003D0
    // 0x80800B38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_16;
    // 0x80800B38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_16:
    // 0x80800B3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80800B40:
    // 0x80800B40: jal         0x800BF744
    // 0x80800B44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_17;
    // 0x80800B44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800B48: b           L_80800B54
    // 0x80800B4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B54;
    // 0x80800B4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B50:
    // 0x80800B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B54:
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B58:
    // 0x80800B58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B5C: jr          $ra
    // 0x80800B60: nop

    return;
    // 0x80800B60: nop

;}
RECOMP_FUNC void func_80800168_chwitchyentrygates(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080016C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800174: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800178: bne         $a1, $at, L_808001C0
    if (ctx->r5 != ctx->r1) {
        // 0x8080017C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_808001C0;
    }
    // 0x8080017C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800180: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800184: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80800188: addiu       $v0, $zero, 0x96D
    ctx->r2 = ADD32(0, 0X96D);
    // 0x8080018C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800190: bne         $t7, $at, L_808001A0
    if (ctx->r15 != ctx->r1) {
        // 0x80800194: nop
    
            goto L_808001A0;
    }
    // 0x80800194: nop

    // 0x80800198: b           L_808001A0
    // 0x8080019C: addiu       $v0, $zero, 0x96C
    ctx->r2 = ADD32(0, 0X96C);
        goto L_808001A0;
    // 0x8080019C: addiu       $v0, $zero, 0x96C
    ctx->r2 = ADD32(0, 0X96C);
L_808001A0:
    // 0x808001A0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x808001A4: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x808001A8: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    // 0x808001AC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x808001B0: jal         0x80103140
    // 0x808001B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x808001B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001BC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_808001C0:
    // 0x808001C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808001C4: jal         0x80086248
    // 0x808001C8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808001C8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808001CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001D4: jr          $ra
    // 0x808001D8: nop

    return;
    // 0x808001D8: nop

;}
RECOMP_FUNC void func_808018D0_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018D8: jal         0x8009BC6C
    // 0x808018DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x808018DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808018E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018E4: jal         0x8009BF5C
    // 0x808018E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x808018E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x808018EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018F0: jal         0x8009C4CC
    // 0x808018F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x808018F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808018F8: jal         0x80800E54
    // 0x808018FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstnt_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808018FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80801900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801908: jr          $ra
    // 0x8080190C: nop

    return;
    // 0x8080190C: nop

;}
RECOMP_FUNC void bsclaw_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808003D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(140, 0X400) << 16);
    // 0x808003D4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808003D8: jr          $ra
    // 0x808003DC: lw          $v0, 0x400($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(140, 0X400));
    return;
    // 0x808003DC: lw          $v0, 0x400($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(140, 0X400));
;}
RECOMP_FUNC void func_800C940C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C940C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C9410: lbu         $v0, -0x54AC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X54AC);
    // 0x800C9414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C941C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9420: beq         $v0, $zero, L_800C9474
    if (ctx->r2 == 0) {
        // 0x800C9424: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C9474;
    }
    // 0x800C9424: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C9428: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C942C: blez        $v0, L_800C9474
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C9430: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800C9474;
    }
    // 0x800C9430: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C9434: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C9438: addiu       $a0, $a0, -0x54C0
    ctx->r4 = ADD32(ctx->r4, -0X54C0);
    // 0x800C943C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_800C9440:
    // 0x800C9440: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x800C9444: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C9448: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C944C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800C9450: bne         $v0, $a3, L_800C946C
    if (ctx->r2 != ctx->r7) {
        // 0x800C9454: nop
    
            goto L_800C946C;
    }
    // 0x800C9454: nop

    // 0x800C9458: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800C945C: jal         0x800881A8
    // 0x800C9460: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _gctransitionDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800C9460: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800C9464: b           L_800C9478
    // 0x800C9468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C9478;
    // 0x800C9468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C946C:
    // 0x800C946C: bne         $at, $zero, L_800C9440
    if (ctx->r1 != 0) {
        // 0x800C9470: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800C9440;
    }
    // 0x800C9470: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800C9474:
    // 0x800C9474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9478:
    // 0x800C9478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C947C: jr          $ra
    // 0x800C9480: nop

    return;
    // 0x800C9480: nop

;}
RECOMP_FUNC void func_80800D08_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800D18: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800D1C: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800D20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800D28: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800D2C: beq         $t6, $zero, L_80800D50
    if (ctx->r14 == 0) {
        // 0x80800D30: addiu       $a1, $zero, 0x19
        ctx->r5 = ADD32(0, 0X19);
            goto L_80800D50;
    }
    // 0x80800D30: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80800D34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D38: beq         $t6, $at, L_80800D58
    if (ctx->r14 == ctx->r1) {
        // 0x80800D3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800D58;
    }
    // 0x80800D3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D40: beql        $t6, $at, L_80800D9C
    if (ctx->r14 == ctx->r1) {
        // 0x80800D44: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800D9C;
    }
    goto skip_0;
    // 0x80800D44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800D48: b           L_80800DA8
    // 0x80800D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800DA8;
    // 0x80800D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D50:
    // 0x80800D50: jal         0x800856B0
    // 0x80800D54: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800D54: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_80800D58:
    // 0x80800D58: jal         0x800856E0
    // 0x80800D5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800D5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800D60: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800D64: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(868, 0XE50) << 16);
    // 0x80800D68: addiu       $a0, $a0, 0xE50
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(868, 0XE50));
    // 0x80800D6C: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800D70: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80800D74: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
    // 0x80800D78: jal         0x80088090
    // 0x80800D7C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800D7C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80800D80: jal         0x80088098
    // 0x80800D84: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800D84: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800D88: jal         0x800880A0
    // 0x80800D8C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800D8C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x80800D90: jal         0x800880B8
    // 0x80800D94: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800D94: nop

    after_5:
    // 0x80800D98: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80800D9C:
    // 0x80800D9C: jal         0x800856D8
    // 0x80800DA0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800DA0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800DA8:
    // 0x80800DA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800DAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DB0: jr          $ra
    // 0x80800DB4: nop

    return;
    // 0x80800DB4: nop

    // 0x80800DB8: nop

    // 0x80800DBC: nop

;}
RECOMP_FUNC void func_8010AAC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AAC0: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8010AAC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AAC8: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x8010AACC: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x8010AAD0: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x8010AAD4: jal         0x8010A698
    // 0x8010AAD8: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    func_8010A698(rdram, ctx);
        goto after_0;
    // 0x8010AAD8: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010AADC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8010AAE0: jal         0x8010A624
    // 0x8010AAE4: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    func_8010A624(rdram, ctx);
        goto after_1;
    // 0x8010AAE4: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    after_1:
    // 0x8010AAE8: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x8010AAEC: jal         0x800EC708
    // 0x8010AAF0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800EC708(rdram, ctx);
        goto after_2;
    // 0x8010AAF0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x8010AAF4: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x8010AAF8: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8010AAFC: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8010AB00: andi        $t7, $v0, 0xF000
    ctx->r15 = ctx->r2 & 0XF000;
    // 0x8010AB04: beq         $t7, $at, L_8010AB28
    if (ctx->r15 == ctx->r1) {
        // 0x8010AB08: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8010AB28;
    }
    // 0x8010AB08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010AB0C: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8010AB10: beq         $t7, $at, L_8010AB28
    if (ctx->r15 == ctx->r1) {
        // 0x8010AB14: addiu       $at, $zero, 0x5000
        ctx->r1 = ADD32(0, 0X5000);
            goto L_8010AB28;
    }
    // 0x8010AB14: addiu       $at, $zero, 0x5000
    ctx->r1 = ADD32(0, 0X5000);
    // 0x8010AB18: beq         $t7, $at, L_8010AB28
    if (ctx->r15 == ctx->r1) {
        // 0x8010AB1C: addiu       $at, $zero, 0x6000
        ctx->r1 = ADD32(0, 0X6000);
            goto L_8010AB28;
    }
    // 0x8010AB1C: addiu       $at, $zero, 0x6000
    ctx->r1 = ADD32(0, 0X6000);
    // 0x8010AB20: bne         $t7, $at, L_8010AB2C
    if (ctx->r15 != ctx->r1) {
        // 0x8010AB24: nop
    
            goto L_8010AB2C;
    }
    // 0x8010AB24: nop

L_8010AB28:
    // 0x8010AB28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8010AB2C:
    // 0x8010AB2C: beq         $v1, $zero, L_8010AB98
    if (ctx->r3 == 0) {
        // 0x8010AB30: nop
    
            goto L_8010AB98;
    }
    // 0x8010AB30: nop

    // 0x8010AB34: jal         0x8010A40C
    // 0x8010AB38: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    func_8010A40C(rdram, ctx);
        goto after_3;
    // 0x8010AB38: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    after_3:
    // 0x8010AB3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010AB40: lwc1        $f6, 0x6510($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6510);
    // 0x8010AB44: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010AB48: lw          $v0, 0xB0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB0);
    // 0x8010AB4C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010AB50: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8010AB54: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010AB58: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8010AB5C: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8010AB60: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8010AB64: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8010AB68: lh          $t9, 0x20($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X20);
    // 0x8010AB6C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8010AB70: nop

    // 0x8010AB74: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8010AB78: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8010AB7C: nop

    // 0x8010AB80: bc1f        L_8010AB90
    if (!c1cs) {
        // 0x8010AB84: nop
    
            goto L_8010AB90;
    }
    // 0x8010AB84: nop

    // 0x8010AB88: b           L_8010AC00
    // 0x8010AB8C: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
        goto L_8010AC00;
    // 0x8010AB8C: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
L_8010AB90:
    // 0x8010AB90: b           L_8010AC00
    // 0x8010AB94: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
        goto L_8010AC00;
    // 0x8010AB94: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
L_8010AB98:
    // 0x8010AB98: jal         0x8010A40C
    // 0x8010AB9C: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    func_8010A40C(rdram, ctx);
        goto after_4;
    // 0x8010AB9C: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    after_4:
    // 0x8010ABA0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010ABA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010ABA8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010ABAC: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x8010ABB0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8010ABB4: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8010ABB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010ABBC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8010ABC0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010ABC4: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8010ABC8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8010ABCC: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8010ABD0: lh          $t2, 0x20($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X20);
    // 0x8010ABD4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8010ABD8: nop

    // 0x8010ABDC: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8010ABE0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8010ABE4: nop

    // 0x8010ABE8: bc1fl       L_8010ABFC
    if (!c1cs) {
        // 0x8010ABEC: swc1        $f2, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
            goto L_8010ABFC;
    }
    goto skip_0;
    // 0x8010ABEC: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    skip_0:
    // 0x8010ABF0: b           L_8010AC00
    // 0x8010ABF4: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
        goto L_8010AC00;
    // 0x8010ABF4: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x8010ABF8: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
L_8010ABFC:
    // 0x8010ABFC: lw          $v0, 0xB0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB0);
L_8010AC00:
    // 0x8010AC00: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x8010AC04: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x8010AC08: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8010AC0C: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8010AC10: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8010AC14: sb          $zero, 0x70($sp)
    MEM_B(0X70, ctx->r29) = 0;
    // 0x8010AC18: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8010AC1C: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x8010AC20: sb          $zero, 0xAC($sp)
    MEM_B(0XAC, ctx->r29) = 0;
    // 0x8010AC24: sb          $zero, 0xAD($sp)
    MEM_B(0XAD, ctx->r29) = 0;
    // 0x8010AC28: sb          $zero, 0xAE($sp)
    MEM_B(0XAE, ctx->r29) = 0;
    // 0x8010AC2C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8010AC30: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8010AC34: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8010AC38: jal         0x800EFB24
    // 0x8010AC3C: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x8010AC3C: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    after_5:
    // 0x8010AC40: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8010AC44: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x8010AC48: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8010AC4C: jal         0x800D4584
    // 0x8010AC50: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    func_800D4584(rdram, ctx);
        goto after_6;
    // 0x8010AC50: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_6:
    // 0x8010AC54: lbu         $v0, 0xAD($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XAD);
    // 0x8010AC58: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010AC5C: addiu       $a0, $a0, 0x6F30
    ctx->r4 = ADD32(ctx->r4, 0X6F30);
    // 0x8010AC60: beq         $v0, $zero, L_8010ACB0
    if (ctx->r2 == 0) {
        // 0x8010AC64: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8010ACB0;
    }
    // 0x8010AC64: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8010AC68: jal         0x800EE7F8
    // 0x8010AC6C: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8010AC6C: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_7:
    // 0x8010AC70: lbu         $t4, 0xAC($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XAC);
    // 0x8010AC74: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8010AC78: bnel        $t4, $zero, L_8010ACB4
    if (ctx->r12 != 0) {
        // 0x8010AC7C: lw          $a0, 0xB0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XB0);
            goto L_8010ACB4;
    }
    goto skip_1;
    // 0x8010AC7C: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    skip_1:
    // 0x8010AC80: jal         0x800EF410
    // 0x8010AC84: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EF410(rdram, ctx);
        goto after_8;
    // 0x8010AC84: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_8:
    // 0x8010AC88: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x8010AC8C: jal         0x800EEAA4
    // 0x8010AC90: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EEAA4(rdram, ctx);
        goto after_9;
    // 0x8010AC90: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x8010AC94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010AC98: lwc1        $f4, 0x6514($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6514);
    // 0x8010AC9C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8010ACA0: nop

    // 0x8010ACA4: bc1fl       L_8010ACB4
    if (!c1cs) {
        // 0x8010ACA8: lw          $a0, 0xB0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XB0);
            goto L_8010ACB4;
    }
    goto skip_2;
    // 0x8010ACA8: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    skip_2:
    // 0x8010ACAC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8010ACB0:
    // 0x8010ACB0: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
L_8010ACB4:
    // 0x8010ACB4: jal         0x8010A654
    // 0x8010ACB8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_8010A654(rdram, ctx);
        goto after_10;
    // 0x8010ACB8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_10:
    // 0x8010ACBC: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8010ACC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010ACC4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x8010ACC8: beq         $t5, $zero, L_8010ACD8
    if (ctx->r13 == 0) {
        // 0x8010ACCC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8010ACD8;
    }
    // 0x8010ACCC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010ACD0: b           L_8010ACD8
    // 0x8010ACD4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8010ACD8;
    // 0x8010ACD4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8010ACD8:
    // 0x8010ACD8: jr          $ra
    // 0x8010ACDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8010ACDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void gctransitionDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080097C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800980: jal         0x800EA05C
    // 0x80800984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800988: jal         0x8080004C
    // 0x8080098C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8080004C_gctransitionDll(rdram, ctx);
        goto after_1;
    // 0x8080098C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800990: jal         0x80800000
    // 0x80800994: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    func_80800000_gctransitionDll(rdram, ctx);
        goto after_2;
    // 0x80800994: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    after_2:
    // 0x80800998: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080099C: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x808009A0: jal         0x808000D8
    // 0x808009A4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_808000D8_gctransitionDll(rdram, ctx);
        goto after_3;
    // 0x808009A4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x808009A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009B0: jr          $ra
    // 0x808009B4: nop

    return;
    // 0x808009B4: nop

;}
RECOMP_FUNC void suchase_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8001211C
    // 0x8080000C: nop

    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3214, 0X1D0) << 16);
    // 0x80800014: addiu       $a2, $a2, 0x1D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3214, 0X1D0));
    // 0x80800018: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8080001C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80800020: beql        $v0, $t6, L_80800058
    if (ctx->r2 == ctx->r14) {
        // 0x80800024: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800058;
    }
    goto skip_0;
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800028: jal         0x8010D254
    // 0x8080002C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x8080002C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800030: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800034: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3214, 0X1D0) << 16);
    // 0x80800038: addiu       $a0, $a2, 0x1D0
    ctx->r4 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3214, 0X1D0));
    // 0x8080003C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80800040: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800044: jal         0x808000A8
    // 0x80800048: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    func_808000A8_suchase(rdram, ctx);
        goto after_2;
    // 0x80800048: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    after_2:
    // 0x8080004C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3214, 0X1D0) << 16);
    // 0x80800050: addiu       $a2, $a2, 0x1D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3214, 0X1D0));
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x8080005C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void fxleaves_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800494: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800498: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8080049C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x808004A0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808004A4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x808004A8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x808004AC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808004B0: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808004B4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808004B8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808004BC: jal         0x800D8FF8
    // 0x808004C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808004C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x808004C4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808004C8: jal         0x8008FE68
    // 0x808004CC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    func_8008FE68(rdram, ctx);
        goto after_1;
    // 0x808004CC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    after_1:
    // 0x808004D0: addiu       $a0, $s2, 0xC
    ctx->r4 = ADD32(ctx->r18, 0XC);
    // 0x808004D4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x808004D8: jal         0x800EFB24
    // 0x808004DC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x808004DC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x808004E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004E4: jal         0x800EE7F8
    // 0x808004E8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808004E8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_3:
    // 0x808004EC: jal         0x800A5490
    // 0x808004F0: nop

    func_800A5490(rdram, ctx);
        goto after_4;
    // 0x808004F0: nop

    after_4:
    // 0x808004F4: beql        $v0, $zero, L_80800508
    if (ctx->r2 == 0) {
        // 0x808004F8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80800508;
    }
    goto skip_0;
    // 0x808004F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    skip_0:
    // 0x808004FC: jal         0x800B28B8
    // 0x80800500: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    vector_clear(rdram, ctx);
        goto after_5;
    // 0x80800500: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    after_5:
    // 0x80800504: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80800508:
    // 0x80800508: jal         0x800B2928
    // 0x8080050C: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    vector_size(rdram, ctx);
        goto after_6;
    // 0x8080050C: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    after_6:
    // 0x80800510: blez        $v0, L_808006A4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800514: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_808006A4;
    }
    // 0x80800514: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800518: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8080051C: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x80800520: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800524: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800528: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8080052C: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80800530: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800534: nop

    // 0x80800538: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
L_8080053C:
    // 0x8080053C: jal         0x800B28CC
    // 0x80800540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    vector_at(rdram, ctx);
        goto after_7;
    // 0x80800540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80800544: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80800548: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8080054C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80800550: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800554: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800558: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080055C: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80800560: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80800564: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    // 0x80800568: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8080056C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800570: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80800574: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800578: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8080057C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80800580: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80800584: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80800588: jal         0x800DC178
    // 0x8080058C: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x8080058C: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    after_8:
    // 0x80800590: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800594: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800598: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x8080059C: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    // 0x808005A0: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x808005A4: jal         0x800DC178
    // 0x808005A8: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x808005A8: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    after_9:
    // 0x808005AC: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x808005B0: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808005B4: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808005B8: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808005BC: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808005C0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x808005C4: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x808005C8: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x808005CC: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808005D0: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x808005D4: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x808005D8: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808005DC: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808005E0: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x808005E4: mul.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x808005E8: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808005EC: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x808005F0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x808005F4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808005F8: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x808005FC: jal         0x800DC178
    // 0x80800600: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x80800600: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    after_10:
    // 0x80800604: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800608: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080060C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800610: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80800614: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800618: jal         0x800DC178
    // 0x8080061C: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x8080061C: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    after_11:
    // 0x80800620: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800624: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800628: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8080062C: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80800630: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800634: jal         0x800DC178
    // 0x80800638: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80800638: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    after_12:
    // 0x8080063C: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800640: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800644: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800648: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080064C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800650: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800654: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x80800658: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8080065C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800660: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80800664: nop

    // 0x80800668: bc1fl       L_80800690
    if (!c1cs) {
        // 0x8080066C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800690;
    }
    goto skip_1;
    // 0x8080066C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80800670: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x80800674: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800678: bnel        $t6, $zero, L_80800690
    if (ctx->r14 != 0) {
        // 0x8080067C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800690;
    }
    goto skip_2;
    // 0x8080067C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80800680: jal         0x800B2E30
    // 0x80800684: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    vector_erase(rdram, ctx);
        goto after_13;
    // 0x80800684: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    after_13:
    // 0x80800688: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8080068C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800690:
    // 0x80800690: jal         0x800B2928
    // 0x80800694: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    vector_size(rdram, ctx);
        goto after_14;
    // 0x80800694: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    after_14:
    // 0x80800698: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080069C: bnel        $at, $zero, L_8080053C
    if (ctx->r1 != 0) {
        // 0x808006A0: lw          $a0, 0x1C($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X1C);
            goto L_8080053C;
    }
    goto skip_3;
    // 0x808006A0: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    skip_3:
L_808006A4:
    // 0x808006A4: lw          $t7, 0x18($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X18);
    // 0x808006A8: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    // 0x808006AC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x808006B0: jal         0x800B2928
    // 0x808006B4: sw          $t8, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r24;
    vector_size(rdram, ctx);
        goto after_15;
    // 0x808006B4: sw          $t8, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r24;
    after_15:
    // 0x808006B8: lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X18);
    // 0x808006BC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808006C0: beql        $at, $zero, L_80800710
    if (ctx->r1 == 0) {
        // 0x808006C4: sw          $zero, 0x18($s2)
        MEM_W(0X18, ctx->r18) = 0;
            goto L_80800710;
    }
    goto skip_4;
    // 0x808006C4: sw          $zero, 0x18($s2)
    MEM_W(0X18, ctx->r18) = 0;
    skip_4:
    // 0x808006C8: jal         0x800B28CC
    // 0x808006CC: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    vector_at(rdram, ctx);
        goto after_16;
    // 0x808006CC: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    after_16:
    // 0x808006D0: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x808006D4: jal         0x800EEAD4
    // 0x808006D8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EEAD4(rdram, ctx);
        goto after_17;
    // 0x808006D8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_17:
    // 0x808006DC: lui         $at, 0x44A5
    ctx->r1 = S32(0X44A5 << 16);
    // 0x808006E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006E4: nop

    // 0x808006E8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808006EC: nop

    // 0x808006F0: bc1fl       L_80800714
    if (!c1cs) {
        // 0x808006F4: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_80800714;
    }
    goto skip_5;
    // 0x808006F4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_5:
    // 0x808006F8: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    // 0x808006FC: jal         0x800B2E30
    // 0x80800700: lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X18);
    vector_erase(rdram, ctx);
        goto after_18;
    // 0x80800700: lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X18);
    after_18:
    // 0x80800704: b           L_80800714
    // 0x80800708: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
        goto L_80800714;
    // 0x80800708: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080070C: sw          $zero, 0x18($s2)
    MEM_W(0X18, ctx->r18) = 0;
L_80800710:
    // 0x80800710: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_80800714:
    // 0x80800714: jal         0x800F1574
    // 0x80800718: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    func_800F1574(rdram, ctx);
        goto after_19;
    // 0x80800718: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    after_19:
    // 0x8080071C: beql        $v0, $zero, L_8080075C
    if (ctx->r2 == 0) {
        // 0x80800720: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8080075C;
    }
    goto skip_6;
    // 0x80800720: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_6:
    // 0x80800724: lbu         $t9, 0x22($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X22);
    // 0x80800728: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080072C: bne         $t9, $at, L_8080074C
    if (ctx->r25 != ctx->r1) {
        // 0x80800730: nop
    
            goto L_8080074C;
    }
    // 0x80800730: nop

    // 0x80800734: jal         0x800A5490
    // 0x80800738: nop

    func_800A5490(rdram, ctx);
        goto after_20;
    // 0x80800738: nop

    after_20:
    // 0x8080073C: bne         $v0, $zero, L_8080074C
    if (ctx->r2 != 0) {
        // 0x80800740: nop
    
            goto L_8080074C;
    }
    // 0x80800740: nop

    // 0x80800744: jal         0x80800000
    // 0x80800748: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800000_fxleaves(rdram, ctx);
        goto after_21;
    // 0x80800748: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_21:
L_8080074C:
    // 0x8080074C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2802, 0X794) << 16);
    // 0x80800750: lwc1        $f8, 0x794($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2802, 0X794));
    // 0x80800754: swc1        $f8, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->f8.u32l;
    // 0x80800758: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8080075C:
    // 0x8080075C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800760: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800764: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800768: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080076C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800770: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80800774: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80800778: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8080077C: jr          $ra
    // 0x80800780: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800780: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800784: nop

    // 0x80800788: nop

    // 0x8080078C: nop

;}
RECOMP_FUNC void _subaddieDll_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4F0: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A4F0);
    return;
    // 0x8008A4F4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void bafly_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800200: lw          $t6, 0x8C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8C);
    // 0x80800204: jr          $ra
    // 0x80800208: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800208: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_8080762C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080762C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80807630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80807634: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807638: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x8080763C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80807640: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80807644: beq         $at, $zero, L_80807784
    if (ctx->r1 == 0) {
        // 0x80807648: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80807784;
    }
    // 0x80807648: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080764C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA560) << 16);
    // 0x80807650: addu        $at, $at, $t6
    gpr jr_addend_80807658 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80807654: lw          $t6, -0x5AA0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(439, 0XA560));
    // 0x80807658: jr          $t6
    // 0x8080765C: nop

    switch (jr_addend_80807658 >> 2) {
        case 0: goto L_80807660; break;
        case 1: goto L_80807690; break;
        case 2: goto L_80807660; break;
        case 3: goto L_808076B8; break;
        case 4: goto L_8080775C; break;
        default: switch_error(__func__, 0x80807658, 0x8080A560);
    }
    // 0x8080765C: nop

L_80807660:
    // 0x80807660: jal         0x808072C8
    // 0x80807664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808072C8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80807664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80807668: jal         0x80807328
    // 0x8080766C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807328_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x8080766C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80807670: jal         0x800839E8
    // 0x80807674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80807674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80807678: beql        $v0, $zero, L_80807788
    if (ctx->r2 == 0) {
        // 0x8080767C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80807788;
    }
    goto skip_0;
    // 0x8080767C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80807680: jal         0x80807F5C
    // 0x80807684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807F5C_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80807684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80807688: b           L_80807788
    // 0x8080768C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80807788;
    // 0x8080768C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807690:
    // 0x80807690: jal         0x80807328
    // 0x80807694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807328_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80807694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80807698: jal         0x800839E8
    // 0x8080769C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x8080769C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808076A0: beql        $v0, $zero, L_80807788
    if (ctx->r2 == 0) {
        // 0x808076A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80807788;
    }
    goto skip_1;
    // 0x808076A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808076A8: jal         0x80807F5C
    // 0x808076AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807F5C_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x808076AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808076B0: b           L_80807788
    // 0x808076B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80807788;
    // 0x808076B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808076B8:
    // 0x808076B8: lui         $a1, 0x3DDD
    ctx->r5 = S32(0X3DDD << 16);
    // 0x808076BC: ori         $a1, $a1, 0x6388
    ctx->r5 = ctx->r5 | 0X6388;
    // 0x808076C0: jal         0x8008CB10
    // 0x808076C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_7;
    // 0x808076C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808076C8: beq         $v0, $zero, L_808076D8
    if (ctx->r2 == 0) {
        // 0x808076CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808076D8;
    }
    // 0x808076CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808076D0: jal         0x800936E8
    // 0x808076D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800936E8(rdram, ctx);
        goto after_8;
    // 0x808076D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_808076D8:
    // 0x808076D8: jal         0x8008CAEC
    // 0x808076DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_9;
    // 0x808076DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808076E0: beq         $v0, $zero, L_8080774C
    if (ctx->r2 == 0) {
        // 0x808076E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080774C;
    }
    // 0x808076E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808076E8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x808076EC: ori         $a3, $a3, 0xEBEE
    ctx->r7 = ctx->r7 | 0XEBEE;
    // 0x808076F0: addiu       $a1, $zero, 0x30D
    ctx->r5 = ADD32(0, 0X30D);
    // 0x808076F4: jal         0x8008CC34
    // 0x808076F8: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_loopStartingAt(rdram, ctx);
        goto after_10;
    // 0x808076F8: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_10:
    // 0x808076FC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80807700: ori         $a3, $a3, 0xEBEE
    ctx->r7 = ctx->r7 | 0XEBEE;
    // 0x80807704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807708: addiu       $a1, $zero, 0x311
    ctx->r5 = ADD32(0, 0X311);
    // 0x8080770C: jal         0x808002CC
    // 0x80807710: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_808002CC_bsfirstp(rdram, ctx);
        goto after_11;
    // 0x80807710: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_11:
    // 0x80807714: jal         0x8008CABC
    // 0x80807718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_12;
    // 0x80807718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080771C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80807720: jal         0x8008B1C8
    // 0x80807724: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_8008B1C8(rdram, ctx);
        goto after_13;
    // 0x80807724: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_13:
    // 0x80807728: jal         0x8008D04C
    // 0x8080772C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D04C(rdram, ctx);
        goto after_14;
    // 0x8080772C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80807730: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80807734: jal         0x8008B1C8
    // 0x80807738: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_8008B1C8(rdram, ctx);
        goto after_15;
    // 0x80807738: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_15:
    // 0x8080773C: jal         0x800839C8
    // 0x80807740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_16;
    // 0x80807740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80807744: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80807748: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_8080774C:
    // 0x8080774C: jal         0x80807328
    // 0x80807750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807328_bsfirstp(rdram, ctx);
        goto after_17;
    // 0x80807750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80807754: b           L_80807788
    // 0x80807758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80807788;
    // 0x80807758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080775C:
    // 0x8080775C: jal         0x80807328
    // 0x80807760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807328_bsfirstp(rdram, ctx);
        goto after_18;
    // 0x80807760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80807764: jal         0x800839E8
    // 0x80807768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_19;
    // 0x80807768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080776C: beql        $v0, $zero, L_80807788
    if (ctx->r2 == 0) {
        // 0x80807770: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80807788;
    }
    goto skip_2;
    // 0x80807770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80807774: jal         0x80807EEC
    // 0x80807778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807EEC_bsfirstp(rdram, ctx);
        goto after_20;
    // 0x80807778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080777C: jal         0x80807F5C
    // 0x80807780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807F5C_bsfirstp(rdram, ctx);
        goto after_21;
    // 0x80807780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
L_80807784:
    // 0x80807784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807788:
    // 0x80807788: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080778C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80807790: jr          $ra
    // 0x80807794: nop

    return;
    // 0x80807794: nop

;}
RECOMP_FUNC void func_808000C0_basnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: jal         0x800A1718
    // 0x808000CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800A1718(rdram, ctx);
        goto after_0;
    // 0x808000CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000D8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x808000DC: jal         0x80800098
    // 0x808000E0: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    func_80800098_basnowball(rdram, ctx);
        goto after_1;
    // 0x808000E0: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x808000E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808000EC: jal         0x800959C8
    // 0x808000F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800959C8(rdram, ctx);
        goto after_2;
    // 0x808000F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808000F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000F8: jal         0x8009590C
    // 0x808000FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009590C(rdram, ctx);
        goto after_3;
    // 0x808000FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800104: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
