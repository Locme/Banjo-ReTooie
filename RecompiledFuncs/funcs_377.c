#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _gccubesearch_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882C8: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882C8);
    return;
    // 0x800882CC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _ncpod_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089530: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089530);
    return;
    // 0x80089534: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void chhellterskeltermouth_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(976, 0X330) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x330
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(976, 0X330));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x330
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(976, 0X330));
;}
RECOMP_FUNC void _bsdronewaitbabykaz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831A8: syscall     49
    recomp_syscall_handler(rdram, ctx, 0x800831A8);
    return;
    // 0x800831AC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080108C_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080108C: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x80801090: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1264, 0X110C) << 16);
    // 0x80801094: addiu       $t8, $t8, 0x110C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1264, 0X110C));
    // 0x80801098: srl         $t6, $v1, 7
    ctx->r14 = S32(U32(ctx->r3) >> 7);
    // 0x8080109C: addiu       $v1, $t6, -0x32
    ctx->r3 = ADD32(ctx->r14, -0X32);
    // 0x808010A0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x808010A4: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x808010A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808010AC: jr          $ra
    // 0x808010B0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x808010B0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x808010B4: nop

    // 0x808010B8: nop

    // 0x808010BC: nop

;}
RECOMP_FUNC void func_808042A4_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808042A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808042A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808042AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808042B0: jal         0x80106790
    // 0x808042B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808042B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808042B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808042BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808042C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808042C4: beq         $a1, $zero, L_808043E0
    if (ctx->r5 == 0) {
        // 0x808042C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808043E0;
    }
    // 0x808042C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808042CC: beq         $a1, $at, L_808043F0
    if (ctx->r5 == ctx->r1) {
        // 0x808042D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808043F0;
    }
    // 0x808042D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808042D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808042D8: beq         $a1, $at, L_808042F0
    if (ctx->r5 == ctx->r1) {
        // 0x808042DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808042F0;
    }
    // 0x808042DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808042E0: beql        $a1, $at, L_80804380
    if (ctx->r5 == ctx->r1) {
        // 0x808042E4: lw          $v1, 0x6C($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X6C);
            goto L_80804380;
    }
    goto skip_0;
    // 0x808042E4: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x808042E8: b           L_808043FC
    // 0x808042EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808043FC;
    // 0x808042EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808042F0:
    // 0x808042F0: lw          $v1, 0x6C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6C);
    // 0x808042F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808042F8: addiu       $a1, $zero, 0x10BB
    ctx->r5 = ADD32(0, 0X10BB);
    // 0x808042FC: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x80804300: beq         $t6, $at, L_80804328
    if (ctx->r14 == ctx->r1) {
        // 0x80804304: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80804328;
    }
    // 0x80804304: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80804308: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080430C: beq         $t6, $at, L_80804344
    if (ctx->r14 == ctx->r1) {
        // 0x80804310: addiu       $a1, $zero, 0x10BD
        ctx->r5 = ADD32(0, 0X10BD);
            goto L_80804344;
    }
    // 0x80804310: addiu       $a1, $zero, 0x10BD
    ctx->r5 = ADD32(0, 0X10BD);
    // 0x80804314: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80804318: beq         $t6, $at, L_80804364
    if (ctx->r14 == ctx->r1) {
        // 0x8080431C: addiu       $a1, $zero, 0x10BC
        ctx->r5 = ADD32(0, 0X10BC);
            goto L_80804364;
    }
    // 0x8080431C: addiu       $a1, $zero, 0x10BC
    ctx->r5 = ADD32(0, 0X10BC);
    // 0x80804320: b           L_80804380
    // 0x80804324: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
        goto L_80804380;
    // 0x80804324: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
L_80804328:
    // 0x80804328: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080432C: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x80804330: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80804334: jal         0x8008A208
    // 0x80804338: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80804338: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x8080433C: b           L_80804380
    // 0x80804340: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
        goto L_80804380;
    // 0x80804340: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
L_80804344:
    // 0x80804344: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80804348: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x8080434C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80804350: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80804354: jal         0x8008A208
    // 0x80804358: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80804358: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x8080435C: b           L_80804380
    // 0x80804360: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
        goto L_80804380;
    // 0x80804360: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
L_80804364:
    // 0x80804364: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80804368: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x8080436C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80804370: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80804374: jal         0x8008A208
    // 0x80804378: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80804378: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x8080437C: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
L_80804380:
    // 0x80804380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804388: andi        $t0, $v1, 0x1FF
    ctx->r8 = ctx->r3 & 0X1FF;
    // 0x8080438C: beq         $t0, $at, L_808043B0
    if (ctx->r8 == ctx->r1) {
        // 0x80804390: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808043B0;
    }
    // 0x80804390: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804394: beq         $t0, $at, L_808043C0
    if (ctx->r8 == ctx->r1) {
        // 0x80804398: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808043C0;
    }
    // 0x80804398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080439C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808043A0: beq         $t0, $at, L_808043D0
    if (ctx->r8 == ctx->r1) {
        // 0x808043A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808043D0;
    }
    // 0x808043A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808043A8: b           L_808043FC
    // 0x808043AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808043FC;
    // 0x808043AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808043B0:
    // 0x808043B0: jal         0x8080422C
    // 0x808043B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080422C_chdodgemcontrol(rdram, ctx);
        goto after_4;
    // 0x808043B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x808043B8: b           L_808043FC
    // 0x808043BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808043FC;
    // 0x808043BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808043C0:
    // 0x808043C0: jal         0x8080422C
    // 0x808043C4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8080422C_chdodgemcontrol(rdram, ctx);
        goto after_5;
    // 0x808043C4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x808043C8: b           L_808043FC
    // 0x808043CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808043FC;
    // 0x808043CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808043D0:
    // 0x808043D0: jal         0x8080422C
    // 0x808043D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080422C_chdodgemcontrol(rdram, ctx);
        goto after_6;
    // 0x808043D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_6:
    // 0x808043D8: b           L_808043FC
    // 0x808043DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808043FC;
    // 0x808043DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808043E0:
    // 0x808043E0: jal         0x8080422C
    // 0x808043E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080422C_chdodgemcontrol(rdram, ctx);
        goto after_7;
    // 0x808043E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808043E8: b           L_808043FC
    // 0x808043EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808043FC;
    // 0x808043EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808043F0:
    // 0x808043F0: jal         0x8080422C
    // 0x808043F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080422C_chdodgemcontrol(rdram, ctx);
        goto after_8;
    // 0x808043F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x808043F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808043FC:
    // 0x808043FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80804400: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80804404: jr          $ra
    // 0x80804408: nop

    return;
    // 0x80804408: nop

;}
RECOMP_FUNC void badata_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BB4: jal         0x80800000
    // 0x80800BB8: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800BB8: nop

    after_0:
    // 0x80800BBC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800BC0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BC8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800BCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(473, 0X10D0) << 16);
    // 0x80800BD0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800BD4: lwc1        $f0, 0x10D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(473, 0X10D0));
    // 0x80800BD8: jr          $ra
    // 0x80800BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bssplitup_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AE0: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AE0);
    return;
    // 0x80083AE4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80116F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116F30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80116F34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80116F38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80116F3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_80116F40:
    // 0x80116F40: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x80116F44: beq         $s4, $at, L_80116F5C
    if (ctx->r20 == ctx->r1) {
        // 0x80116F48: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_80116F5C;
    }
    // 0x80116F48: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80116F4C: beq         $s4, $at, L_801170B4
    if (ctx->r20 == ctx->r1) {
        // 0x80116F50: nop
    
            goto L_801170B4;
    }
    // 0x80116F50: nop

    // 0x80116F54: j           L_80117214
    // 0x80116F58: nop

        goto L_80117214;
    // 0x80116F58: nop

L_80116F5C:
    // 0x80116F5C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80116F60: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x80116F64: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x80116F68: sw          $v1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r3;
    // 0x80116F6C: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x80116F70: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x80116F74: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x80116F78: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80116F7C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80116F80: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80116F84: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80116F88: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80116F8C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80116F90: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x80116F94: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80116F98: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80116F9C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80116FA0: jal         0x800132BC
    // 0x80116FA4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    func_800132BC(rdram, ctx);
        goto after_0;
    // 0x80116FA4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    after_0:
    // 0x80116FA8: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x80116FAC: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80116FB0: lw          $v1, 0x8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8);
    // 0x80116FB4: lw          $a0, 0xC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC);
    // 0x80116FB8: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x80116FBC: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x80116FC0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80116FC4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80116FC8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80116FCC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80116FD0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80116FD4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80116FD8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80116FDC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80116FE0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80116FE4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80116FE8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80116FEC: beq         $s2, $zero, L_80117214
    if (ctx->r18 == 0) {
        // 0x80116FF0: addiu       $sp, $sp, 0x48
        ctx->r29 = ADD32(ctx->r29, 0X48);
            goto L_80117214;
    }
    // 0x80116FF0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80116FF4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80116FF8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80116FFC: slti        $at, $a2, 0x800
    ctx->r1 = SIGNED(ctx->r6) < 0X800 ? 1 : 0;
    // 0x80117000: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80117004: bne         $at, $zero, L_80117010
    if (ctx->r1 != 0) {
        // 0x80117008: lw          $a1, 0x4A8C($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4A8C);
            goto L_80117010;
    }
    // 0x80117008: lw          $a1, 0x4A8C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4A8C);
    // 0x8011700C: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_80117010:
    // 0x80117010: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80117014: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x80117018: addu        $s3, $s3, $a2
    ctx->r19 = ADD32(ctx->r19, ctx->r6);
    // 0x8011701C: subu        $s2, $s2, $a2
    ctx->r18 = SUB32(ctx->r18, ctx->r6);
    // 0x80117020: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x80117024: sw          $v1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r3;
    // 0x80117028: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x8011702C: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x80117030: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x80117034: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80117038: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8011703C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80117040: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80117044: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80117048: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8011704C: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x80117050: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80117054: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80117058: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8011705C: jal         0x80013224
    // 0x80117060: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    func_80013224(rdram, ctx);
        goto after_1;
    // 0x80117060: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    after_1:
    // 0x80117064: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x80117068: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8011706C: lw          $v1, 0x8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8);
    // 0x80117070: lw          $a0, 0xC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC);
    // 0x80117074: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x80117078: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x8011707C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80117080: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80117084: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80117088: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8011708C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80117090: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80117094: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80117098: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8011709C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x801170A0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x801170A4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x801170A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801170AC: j           L_80117214
    // 0x801170B0: nop

        goto L_80117214;
    // 0x801170B0: nop

L_801170B4:
    // 0x801170B4: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x801170B8: lw          $fp, 0x4A8C($fp)
    ctx->r30 = MEM_W(ctx->r30, 0X4A8C);
    // 0x801170BC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801170C0: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x801170C4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801170C8: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x801170CC: sw          $v1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r3;
    // 0x801170D0: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x801170D4: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x801170D8: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x801170DC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x801170E0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801170E4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801170E8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801170EC: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801170F0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x801170F4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x801170F8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801170FC: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80117100: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80117104: jal         0x800132BC
    // 0x80117108: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    func_800132BC(rdram, ctx);
        goto after_2;
    // 0x80117108: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    after_2:
    // 0x8011710C: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x80117110: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80117114: lw          $v1, 0x8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8);
    // 0x80117118: lw          $a0, 0xC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC);
    // 0x8011711C: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x80117120: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x80117124: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80117128: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8011712C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80117130: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80117134: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80117138: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8011713C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80117140: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80117144: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80117148: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8011714C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80117150: beq         $s2, $zero, L_80117214
    if (ctx->r18 == 0) {
        // 0x80117154: addiu       $sp, $sp, 0x48
        ctx->r29 = ADD32(ctx->r29, 0X48);
            goto L_80117214;
    }
    // 0x80117154: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80117158: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8011715C: lw          $a1, 0x4A8C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4A8C);
    // 0x80117160: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80117164: slti        $at, $a2, 0x800
    ctx->r1 = SIGNED(ctx->r6) < 0X800 ? 1 : 0;
    // 0x80117168: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8011716C: bne         $at, $zero, L_80117178
    if (ctx->r1 != 0) {
        // 0x80117170: addiu       $a1, $a1, 0x800
        ctx->r5 = ADD32(ctx->r5, 0X800);
            goto L_80117178;
    }
    // 0x80117170: addiu       $a1, $a1, 0x800
    ctx->r5 = ADD32(ctx->r5, 0X800);
    // 0x80117174: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_80117178:
    // 0x80117178: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8011717C: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x80117180: addu        $s3, $s3, $a2
    ctx->r19 = ADD32(ctx->r19, ctx->r6);
    // 0x80117184: subu        $s2, $s2, $a2
    ctx->r18 = SUB32(ctx->r18, ctx->r6);
    // 0x80117188: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8011718C: sw          $v1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r3;
    // 0x80117190: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x80117194: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x80117198: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x8011719C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x801171A0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801171A4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801171A8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801171AC: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801171B0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x801171B4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x801171B8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801171BC: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x801171C0: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801171C4: jal         0x80013224
    // 0x801171C8: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    func_80013224(rdram, ctx);
        goto after_3;
    // 0x801171C8: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    after_3:
    // 0x801171CC: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x801171D0: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x801171D4: lw          $v1, 0x8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8);
    // 0x801171D8: lw          $a0, 0xC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC);
    // 0x801171DC: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x801171E0: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x801171E4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801171E8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801171EC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x801171F0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x801171F4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x801171F8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x801171FC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80117200: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80117204: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80117208: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8011720C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80117210: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
L_80117214:
    // 0x80117214: lbu         $v0, 0x0($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X0);
    // 0x80117218: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8011721C: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80117220: sllv        $v0, $v0, $s5
    ctx->r2 = S32(ctx->r2 << (ctx->r21 & 31));
    // 0x80117224: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80117228: slt         $at, $s5, $s0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8011722C: bne         $at, $zero, L_80116F40
    if (ctx->r1 != 0) {
        // 0x80117230: or          $s6, $s6, $v0
        ctx->r22 = ctx->r22 | ctx->r2;
            goto L_80116F40;
    }
    // 0x80117230: or          $s6, $s6, $v0
    ctx->r22 = ctx->r22 | ctx->r2;
    // 0x80117234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80117238: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8011723C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80117240: jr          $ra
    // 0x80117244: nop

    return;
    // 0x80117244: nop

;}
RECOMP_FUNC void func_800F8268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8268: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F826C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8270: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8278: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F827C: jal         0x800A38F0
    // 0x800F8280: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A38F0(rdram, ctx);
        goto after_0;
    // 0x800F8280: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F8284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F828C: jr          $ra
    // 0x800F8290: nop

    return;
    // 0x800F8290: nop

;}
RECOMP_FUNC void func_80800400_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800408: jal         0x8009BC90
    // 0x8080040C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_0;
    // 0x8080040C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800410: jal         0x8009BC6C
    // 0x80800414: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x80800414: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800418: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080041C: jal         0x800961AC
    // 0x80800420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_2;
    // 0x80800420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080042C: jr          $ra
    // 0x80800430: nop

    return;
    // 0x80800430: nop

;}
RECOMP_FUNC void _suspline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D80: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089D80);
    return;
    // 0x80089D84: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8009E474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E47C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009E480: lw          $a0, 0x114($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X114);
    // 0x8009E484: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8009E488: jal         0x8001BBA0
    // 0x8009E48C: addiu       $a1, $a0, 0x78
    ctx->r5 = ADD32(ctx->r4, 0X78);
    rare_memcpy(rdram, ctx);
        goto after_0;
    // 0x8009E48C: addiu       $a1, $a0, 0x78
    ctx->r5 = ADD32(ctx->r4, 0X78);
    after_0:
    // 0x8009E490: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8009E494: lw          $t8, 0x114($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X114);
    // 0x8009E498: sb          $zero, 0xF0($t8)
    MEM_B(0XF0, ctx->r24) = 0;
    // 0x8009E49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E4A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E4A4: jr          $ra
    // 0x8009E4A8: nop

    return;
    // 0x8009E4A8: nop

;}
RECOMP_FUNC void bsdronevanish_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003F0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x808003F4: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x808003F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800400: lbu         $v0, 0x18($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X18);
    // 0x80800404: beq         $v0, $at, L_80800424
    if (ctx->r2 == ctx->r1) {
        // 0x80800408: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800424;
    }
    // 0x80800408: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080040C: beq         $v0, $at, L_80800450
    if (ctx->r2 == ctx->r1) {
        // 0x80800410: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800450;
    }
    // 0x80800410: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800414: beq         $v0, $at, L_808004CC
    if (ctx->r2 == ctx->r1) {
        // 0x80800418: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004CC;
    }
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: b           L_808004EC
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808004EC;
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800424:
    // 0x80800424: jal         0x808002A4
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002A4_bsdronevanish(rdram, ctx);
        goto after_0;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: jal         0x800852F0
    // 0x80800434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_1;
    // 0x80800434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800438: beq         $v0, $zero, L_808004E8
    if (ctx->r2 == 0) {
        // 0x8080043C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E8;
    }
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: jal         0x80800000
    // 0x80800444: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_bsdronevanish(rdram, ctx);
        goto after_2;
    // 0x80800444: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800448: b           L_808004EC
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808004EC;
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800450:
    // 0x80800450: jal         0x808002A4
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002A4_bsdronevanish(rdram, ctx);
        goto after_3;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: jal         0x800852F0
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_4;
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800464: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: jal         0x80085300
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_5;
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800474: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800478: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8080047C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800480: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800484: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800488: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080048C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800490: jal         0x800F10B4
    // 0x80800494: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800494: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800498: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808004A4: jal         0x80092EBC
    // 0x808004A8: nop

    func_80092EBC(rdram, ctx);
        goto after_7;
    // 0x808004A8: nop

    after_7:
    // 0x808004AC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B4: beql        $t8, $zero, L_808004EC
    if (ctx->r24 == 0) {
        // 0x808004B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004EC;
    }
    goto skip_0;
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808004BC: jal         0x80800000
    // 0x808004C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800000_bsdronevanish(rdram, ctx);
        goto after_8;
    // 0x808004C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x808004C4: b           L_808004EC
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808004EC;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004CC:
    // 0x808004CC: jal         0x800852F0
    // 0x808004D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_9;
    // 0x808004D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808004D4: beql        $v0, $zero, L_808004EC
    if (ctx->r2 == 0) {
        // 0x808004D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004EC;
    }
    goto skip_1;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808004DC: jal         0x80084750
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_34(rdram, ctx);
        goto after_10;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808004E4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_808004E8:
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004EC:
    // 0x808004EC: jal         0x8009E5C8
    // 0x808004F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x808004F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x808004F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800500: jr          $ra
    // 0x80800504: nop

    return;
    // 0x80800504: nop

;}
RECOMP_FUNC void func_80800F34_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F40: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800F44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F48: jal         0x80100094
    // 0x80800F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F50: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800F54: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80800F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F5C: jal         0x80102424
    // 0x80800F60: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800F60: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800F64: jal         0x80802594
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802594_chboilerboss(rdram, ctx);
        goto after_2;
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800F6C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F70: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80800F74: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x80800F78: beq         $at, $zero, L_808010CC
    if (ctx->r1 == 0) {
        // 0x80800F7C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808010CC;
    }
    // 0x80800F7C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800F80: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A0C) << 16);
    // 0x80800F84: addu        $at, $at, $t7
    gpr jr_addend_80800F8C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800F88: lw          $t7, 0x2A0C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A0C));
    // 0x80800F8C: jr          $t7
    // 0x80800F90: nop

    switch (jr_addend_80800F8C >> 2) {
        case 0: goto L_8080105C; break;
        case 1: goto L_808010CC; break;
        case 2: goto L_808010CC; break;
        case 3: goto L_8080103C; break;
        case 4: goto L_808010B4; break;
        case 5: goto L_80800F94; break;
        case 6: goto L_80800FCC; break;
        case 7: goto L_80801004; break;
        case 8: goto L_80801050; break;
        case 9: goto L_808010CC; break;
        case 10: goto L_808010C0; break;
        default: switch_error(__func__, 0x80800F8C, 0x80802A0C);
    }
    // 0x80800F90: nop

L_80800F94:
    // 0x80800F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F98: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800F9C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80800FA0: jal         0x808027E4
    // 0x80800FA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808027E4_chboilerboss(rdram, ctx);
        goto after_3;
    // 0x80800FA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80800FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FAC: addiu       $a1, $zero, 0xF99
    ctx->r5 = ADD32(0, 0XF99);
    // 0x80800FB0: jal         0x8080238C
    // 0x80800FB4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8080238C_chboilerboss(rdram, ctx);
        goto after_4;
    // 0x80800FB4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_4:
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FBC: jal         0x80109FE8
    // 0x80800FC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_5;
    // 0x80800FC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800FC4: b           L_808010D0
    // 0x80800FC8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
        goto L_808010D0;
    // 0x80800FC8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
L_80800FCC:
    // 0x80800FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800FD4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80800FD8: jal         0x808027E4
    // 0x80800FDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808027E4_chboilerboss(rdram, ctx);
        goto after_6;
    // 0x80800FDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE4: addiu       $a1, $zero, 0xF9A
    ctx->r5 = ADD32(0, 0XF9A);
    // 0x80800FE8: jal         0x8080238C
    // 0x80800FEC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8080238C_chboilerboss(rdram, ctx);
        goto after_7;
    // 0x80800FEC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_7:
    // 0x80800FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FF4: jal         0x80109FE8
    // 0x80800FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_8;
    // 0x80800FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800FFC: b           L_808010D0
    // 0x80801000: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
        goto L_808010D0;
    // 0x80801000: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
L_80801004:
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801008: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8080100C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80801010: jal         0x808027E4
    // 0x80801014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808027E4_chboilerboss(rdram, ctx);
        goto after_9;
    // 0x80801014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080101C: addiu       $a1, $zero, 0xF9B
    ctx->r5 = ADD32(0, 0XF9B);
    // 0x80801020: jal         0x8080238C
    // 0x80801024: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8080238C_chboilerboss(rdram, ctx);
        goto after_10;
    // 0x80801024: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_10:
    // 0x80801028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080102C: jal         0x80109FE8
    // 0x80801030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_11;
    // 0x80801030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80801034: b           L_808010D0
    // 0x80801038: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
        goto L_808010D0;
    // 0x80801038: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
L_8080103C:
    // 0x8080103C: jal         0x80801EB4
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801EB4_chboilerboss(rdram, ctx);
        goto after_12;
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801044: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801048: b           L_808010CC
    // 0x8080104C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_808010CC;
    // 0x8080104C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_80801050:
    // 0x80801050: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80801054: b           L_808010CC
    // 0x80801058: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
        goto L_808010CC;
    // 0x80801058: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_8080105C:
    // 0x8080105C: lui         $a1, 0x3FCC
    ctx->r5 = S32(0X3FCC << 16);
    // 0x80801060: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801064: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801068: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x8080106C: jal         0x800187B4
    // 0x80801070: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_800187B4(rdram, ctx);
        goto after_13;
    // 0x80801070: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_13:
    // 0x80801074: jal         0x808024B8
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808024B8_chboilerboss(rdram, ctx);
        goto after_14;
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801084: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80801088: jal         0x808027E4
    // 0x8080108C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808027E4_chboilerboss(rdram, ctx);
        goto after_15;
    // 0x8080108C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x80801090: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x80801094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801098: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080109C: jal         0x800861A0
    // 0x808010A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x808010A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_16:
    // 0x808010A4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x808010A8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808010AC: b           L_808010CC
    // 0x808010B0: sw          $t0, 0x60($t1)
    MEM_W(0X60, ctx->r9) = ctx->r8;
        goto L_808010CC;
    // 0x808010B0: sw          $t0, 0x60($t1)
    MEM_W(0X60, ctx->r9) = ctx->r8;
L_808010B4:
    // 0x808010B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808010B8: b           L_808010CC
    // 0x808010BC: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
        goto L_808010CC;
    // 0x808010BC: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
L_808010C0:
    // 0x808010C0: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808010C4: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x808010C8: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_808010CC:
    // 0x808010CC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
L_808010D0:
    // 0x808010D0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808010D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010D8: jal         0x808024DC
    // 0x808010DC: sb          $t5, 0x58($t6)
    MEM_B(0X58, ctx->r14) = ctx->r13;
    func_808024DC_chboilerboss(rdram, ctx);
        goto after_17;
    // 0x808010DC: sb          $t5, 0x58($t6)
    MEM_B(0X58, ctx->r14) = ctx->r13;
    after_17:
    // 0x808010E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808010E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808010EC: jr          $ra
    // 0x808010F0: nop

    return;
    // 0x808010F0: nop

;}
RECOMP_FUNC void func_800E96E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E96E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E96E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E96E8: jal         0x800EA3A0
    // 0x800E96EC: nop

    func_800EA3A0(rdram, ctx);
        goto after_0;
    // 0x800E96EC: nop

    after_0:
    // 0x800E96F0: jal         0x800EBB6C
    // 0x800E96F4: nop

    func_800EBB6C(rdram, ctx);
        goto after_1;
    // 0x800E96F4: nop

    after_1:
    // 0x800E96F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E96FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9700: jr          $ra
    // 0x800E9704: nop

    return;
    // 0x800E9704: nop

;}
RECOMP_FUNC void func_8010AA54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AA54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AA58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AA5C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010AA60: jal         0x800EE7F8
    // 0x8010AA64: addiu       $a1, $a1, 0x6F30
    ctx->r5 = ADD32(ctx->r5, 0X6F30);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8010AA64: addiu       $a1, $a1, 0x6F30
    ctx->r5 = ADD32(ctx->r5, 0X6F30);
    after_0:
    // 0x8010AA68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AA6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AA70: jr          $ra
    // 0x8010AA74: nop

    return;
    // 0x8010AA74: nop

;}
RECOMP_FUNC void func_8008C1C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1C0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008C1C4: jr          $ra
    // 0x8008C1C8: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x8008C1C8: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void bsdronefired_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800134: jal         0x80084608
    // 0x80800138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80800138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080013C: beql        $v0, $zero, L_8080015C
    if (ctx->r2 == 0) {
        // 0x80800140: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080015C;
    }
    goto skip_0;
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800144: jal         0x80084700
    // 0x80800148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badata_entrypoint_24(rdram, ctx);
        goto after_1;
    // 0x80800148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080014C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800150: jal         0x8009E5C8
    // 0x80800154: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800154: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080015C:
    // 0x8080015C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

    // 0x80800168: nop

    // 0x8080016C: nop

;}
RECOMP_FUNC void bskazcrouch_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808003C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003CC: jal         0x8008CABC
    // 0x808003D0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808003D0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x808003D4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: jal         0x800852F0
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_1;
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: jal         0x800852F0
    // 0x808003EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x808003EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: jal         0x80085300
    // 0x808003F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_3;
    // 0x808003F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808003FC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800400: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800404: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800408: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8080040C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800410: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800414: jal         0x800F10B4
    // 0x80800418: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800418: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8080041C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800420: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800424: jal         0x8009B9B0
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080042C: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80800430: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800434: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800438: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8080043C: nop

    // 0x80800440: bc1fl       L_80800454
    if (!c1cs) {
        // 0x80800444: lui         $at, 0x4320
        ctx->r1 = S32(0X4320 << 16);
            goto L_80800454;
    }
    goto skip_0;
    // 0x80800444: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    skip_0:
    // 0x80800448: jal         0x80084A10
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800450: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
L_80800454:
    // 0x80800454: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800458: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080045C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800460: nop

    // 0x80800464: bc1f        L_80800474
    if (!c1cs) {
        // 0x80800468: nop
    
            goto L_80800474;
    }
    // 0x80800468: nop

    // 0x8080046C: jal         0x8009D658
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_7;
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80800474:
    // 0x80800474: jal         0x8009EF04
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_8;
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080047C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800480: nop

    // 0x80800484: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x80800488: nop

    // 0x8080048C: bc1f        L_808004A8
    if (!c1cs) {
        // 0x80800490: nop
    
            goto L_808004A8;
    }
    // 0x80800490: nop

    // 0x80800494: jal         0x8009C984
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_9;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080049C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004A0: jal         0x8009C914
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_10;
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_808004A8:
    // 0x808004A8: jal         0x8009C990
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_11;
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808004B0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808004B4: jal         0x8009C984
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_12;
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808004BC: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808004C0: jal         0x800F1DCC
    // 0x808004C4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_13;
    // 0x808004C4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_13:
    // 0x808004C8: jal         0x800F2100
    // 0x808004CC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_14;
    // 0x808004CC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_14:
    // 0x808004D0: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x808004D4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808004D8: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x808004DC: beq         $at, $zero, L_808006E8
    if (ctx->r1 == 0) {
        // 0x808004E0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808006E8;
    }
    // 0x808004E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808004E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(224, 0X7A8) << 16);
    // 0x808004E8: addu        $at, $at, $t6
    gpr jr_addend_808004F0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808004EC: lw          $t6, 0x7A8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(224, 0X7A8));
    // 0x808004F0: jr          $t6
    // 0x808004F4: nop

    switch (jr_addend_808004F0 >> 2) {
        case 0: goto L_808004F8; break;
        case 1: goto L_8080052C; break;
        case 2: goto L_80800580; break;
        case 3: goto L_80800660; break;
        case 4: goto L_808005C8; break;
        default: switch_error(__func__, 0x808004F0, 0x808007A8);
    }
    // 0x808004F4: nop

L_808004F8:
    // 0x808004F8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808004FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800508: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8080050C: nop

    // 0x80800510: bc1f        L_808006E8
    if (!c1cs) {
        // 0x80800514: nop
    
            goto L_808006E8;
    }
    // 0x80800514: nop

    // 0x80800518: jal         0x80085338
    // 0x8080051C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    _batimer_set(rdram, ctx);
        goto after_15;
    // 0x8080051C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_15:
    // 0x80800520: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800524: b           L_808006E8
    // 0x80800528: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_808006E8;
    // 0x80800528: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_8080052C:
    // 0x8080052C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80800538: nop

    // 0x8080053C: bc1t        L_80800554
    if (c1cs) {
        // 0x80800540: nop
    
            goto L_80800554;
    }
    // 0x80800540: nop

    // 0x80800544: jal         0x80800000
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazcrouch(rdram, ctx);
        goto after_16;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080054C: b           L_808006E8
    // 0x80800550: nop

        goto L_808006E8;
    // 0x80800550: nop

L_80800554:
    // 0x80800554: jal         0x800852F0
    // 0x80800558: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_decrement(rdram, ctx);
        goto after_17;
    // 0x80800558: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800560: jal         0x80085330
    // 0x80800564: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_isZero(rdram, ctx);
        goto after_18;
    // 0x80800564: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x80800568: beq         $v0, $zero, L_808006E8
    if (ctx->r2 == 0) {
        // 0x8080056C: nop
    
            goto L_808006E8;
    }
    // 0x8080056C: nop

    // 0x80800570: jal         0x80800034
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800034_bskazcrouch(rdram, ctx);
        goto after_19;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800578: b           L_808006E8
    // 0x8080057C: nop

        goto L_808006E8;
    // 0x8080057C: nop

L_80800580:
    // 0x80800580: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800584: nop

    // 0x80800588: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x8080058C: nop

    // 0x80800590: bc1t        L_808005A8
    if (c1cs) {
        // 0x80800594: nop
    
            goto L_808005A8;
    }
    // 0x80800594: nop

    // 0x80800598: jal         0x80800000
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazcrouch(rdram, ctx);
        goto after_20;
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808005A0: b           L_808006E8
    // 0x808005A4: nop

        goto L_808006E8;
    // 0x808005A4: nop

L_808005A8:
    // 0x808005A8: jal         0x8008B324
    // 0x808005AC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_isStopped(rdram, ctx);
        goto after_21;
    // 0x808005AC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_21:
    // 0x808005B0: beq         $v0, $zero, L_808006E8
    if (ctx->r2 == 0) {
        // 0x808005B4: nop
    
            goto L_808006E8;
    }
    // 0x808005B4: nop

    // 0x808005B8: jal         0x80800068
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800068_bskazcrouch(rdram, ctx);
        goto after_22;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808005C0: b           L_808006E8
    // 0x808005C4: nop

        goto L_808006E8;
    // 0x808005C4: nop

L_808005C8:
    // 0x808005C8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808005CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808005D0: jal         0x808000B4
    // 0x808005D4: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_808000B4_bskazcrouch(rdram, ctx);
        goto after_23;
    // 0x808005D4: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_23:
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: jal         0x808000FC
    // 0x808005E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_808000FC_bskazcrouch(rdram, ctx);
        goto after_24;
    // 0x808005E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_24:
    // 0x808005E4: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808005E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808005EC: nop

    // 0x808005F0: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x808005F4: nop

    // 0x808005F8: bc1f        L_808006E8
    if (!c1cs) {
        // 0x808005FC: nop
    
            goto L_808006E8;
    }
    // 0x808005FC: nop

    // 0x80800600: jal         0x8008B2B4
    // 0x80800604: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_25;
    // 0x80800604: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_25:
    // 0x80800608: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080060C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800610: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800614: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800618: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8080061C: nop

    // 0x80800620: bc1f        L_80800640
    if (!c1cs) {
        // 0x80800624: nop
    
            goto L_80800640;
    }
    // 0x80800624: nop

    // 0x80800628: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8080062C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800630: jal         0x8008B1D4
    // 0x80800634: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_26;
    // 0x80800634: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_26:
    // 0x80800638: b           L_8080064C
    // 0x8080063C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_8080064C;
    // 0x8080063C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_80800640:
    // 0x80800640: jal         0x8008B1D4
    // 0x80800644: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_27;
    // 0x80800644: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_27:
    // 0x80800648: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_8080064C:
    // 0x8080064C: jal         0x8008B134
    // 0x80800650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_28;
    // 0x80800650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x80800654: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800658: b           L_808006E8
    // 0x8080065C: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_808006E8;
    // 0x8080065C: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_80800660:
    // 0x80800660: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800664: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800668: jal         0x808000B4
    // 0x8080066C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_808000B4_bskazcrouch(rdram, ctx);
        goto after_29;
    // 0x8080066C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_29:
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800674: jal         0x808000FC
    // 0x80800678: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_808000FC_bskazcrouch(rdram, ctx);
        goto after_30;
    // 0x80800678: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_30:
    // 0x8080067C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800680: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800684: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800688: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080068C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800690: nop

    // 0x80800694: bc1t        L_808006BC
    if (c1cs) {
        // 0x80800698: nop
    
            goto L_808006BC;
    }
    // 0x80800698: nop

    // 0x8080069C: jal         0x8008B1D4
    // 0x808006A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_31;
    // 0x808006A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_31:
    // 0x808006A4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808006A8: jal         0x8008B134
    // 0x808006AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_32;
    // 0x808006AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x808006B0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x808006B4: b           L_808006E8
    // 0x808006B8: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
        goto L_808006E8;
    // 0x808006B8: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
L_808006BC:
    // 0x808006BC: jal         0x8008B324
    // 0x808006C0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_isStopped(rdram, ctx);
        goto after_33;
    // 0x808006C0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_33:
    // 0x808006C4: beq         $v0, $zero, L_808006E8
    if (ctx->r2 == 0) {
        // 0x808006C8: nop
    
            goto L_808006E8;
    }
    // 0x808006C8: nop

    // 0x808006CC: jal         0x8009C984
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_34;
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x808006D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808006D8: jal         0x8009C914
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_35;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808006E0: jal         0x80800068
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800068_bskazcrouch(rdram, ctx);
        goto after_36;
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
L_808006E8:
    // 0x808006E8: jal         0x8008DF18
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_37;
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x808006F0: beql        $v0, $zero, L_80800708
    if (ctx->r2 == 0) {
        // 0x808006F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800708;
    }
    goto skip_1;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808006F8: jal         0x800848B0
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_38;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80800700: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800708:
    // 0x80800708: jal         0x80800140
    // 0x8080070C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    bskazcrouch_entrypoint_0(rdram, ctx);
        goto after_39;
    // 0x8080070C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_39:
    // 0x80800710: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x80800714: bne         $v0, $at, L_80800734
    if (ctx->r2 != ctx->r1) {
        // 0x80800718: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_80800734;
    }
    // 0x80800718: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800720: jal         0x80085328
    // 0x80800724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_isNonzero(rdram, ctx);
        goto after_40;
    // 0x80800724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x80800728: beq         $v0, $zero, L_80800734
    if (ctx->r2 == 0) {
        // 0x8080072C: nop
    
            goto L_80800734;
    }
    // 0x8080072C: nop

    // 0x80800730: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80800734:
    // 0x80800734: jal         0x8008E35C
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_41;
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x8080073C: beq         $v0, $zero, L_8080074C
    if (ctx->r2 == 0) {
        // 0x80800740: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080074C;
    }
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800744: addiu       $t0, $zero, 0x15D
    ctx->r8 = ADD32(0, 0X15D);
    // 0x80800748: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
L_8080074C:
    // 0x8080074C: jal         0x8009E5C8
    // 0x80800750: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    bs_setState(rdram, ctx);
        goto after_42;
    // 0x80800750: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_42:
    // 0x80800754: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800758: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080075C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800760: jr          $ra
    // 0x80800764: nop

    return;
    // 0x80800764: nop

;}
RECOMP_FUNC void _ncbakaztorp_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089738: syscall     791
    recomp_syscall_handler(rdram, ctx, 0x80089738);
    return;
    // 0x8008973C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bsblongleg_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A58: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A58);
    return;
    // 0x80082A5C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_8080000C_chconga(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x800DA298
    // 0x8080001C: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    after_0:
    // 0x80800020: jal         0x800F54E4
    // 0x80800024: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800024: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800028: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080002C: jal         0x800F64A4
    // 0x80800030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_2;
    // 0x80800030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800034: jal         0x800D395C
    // 0x80800038: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800D395C(rdram, ctx);
        goto after_3;
    // 0x80800038: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x8080003C: jal         0x80088848
    // 0x80800040: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800040: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800044: beq         $v0, $zero, L_8080005C
    if (ctx->r2 == 0) {
        // 0x80800048: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080005C;
    }
    // 0x80800048: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080004C: jal         0x80102424
    // 0x80800050: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800050: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80800054: b           L_808000D4
    // 0x80800058: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_808000D4;
    // 0x80800058: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_8080005C:
    // 0x8080005C: jal         0x800DA298
    // 0x80800060: addiu       $a0, $zero, 0x9C
    ctx->r4 = ADD32(0, 0X9C);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800060: addiu       $a0, $zero, 0x9C
    ctx->r4 = ADD32(0, 0X9C);
    after_6:
    // 0x80800064: beq         $v0, $zero, L_8080007C
    if (ctx->r2 == 0) {
        // 0x80800068: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8080007C;
    }
    // 0x80800068: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080006C: jal         0x800FFAB0
    // 0x80800070: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x80800070: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80800074: b           L_8080010C
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080010C;
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080007C:
    // 0x8080007C: beq         $t6, $zero, L_808000A8
    if (ctx->r14 == 0) {
        // 0x80800080: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_808000A8;
    }
    // 0x80800080: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800084: bne         $t7, $zero, L_808000A8
    if (ctx->r15 != 0) {
        // 0x80800088: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808000A8;
    }
    // 0x80800088: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080008C: jal         0x80102424
    // 0x80800090: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800090: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80800094: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800098: jal         0x80105A9C
    // 0x8080009C: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    func_80105A9C(rdram, ctx);
        goto after_9;
    // 0x8080009C: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_9:
    // 0x808000A0: b           L_808000D4
    // 0x808000A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_808000D4;
    // 0x808000A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_808000A8:
    // 0x808000A8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808000AC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808000B0: beql        $t8, $zero, L_808000D4
    if (ctx->r24 == 0) {
        // 0x808000B4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808000D4;
    }
    goto skip_0;
    // 0x808000B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x808000B8: beql        $t9, $zero, L_808000D4
    if (ctx->r25 == 0) {
        // 0x808000BC: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808000D4;
    }
    goto skip_1;
    // 0x808000BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x808000C0: jal         0x800FFAB0
    // 0x808000C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808000C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x808000C8: b           L_8080010C
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080010C;
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_808000D4:
    // 0x808000D4: jal         0x80100094
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x808000DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000E0: addiu       $a1, $zero, 0x4E2
    ctx->r5 = ADD32(0, 0X4E2);
    // 0x808000E4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x808000E8: jal         0x80089FD0
    // 0x808000EC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddieitem_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x808000EC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_12:
    // 0x808000F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000F4: jal         0x80100094
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_13;
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x808000FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800100: jal         0x80089FD8
    // 0x80800104: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _subaddieitem_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x80800104: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080010C:
    // 0x8080010C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void func_80800780_bskazstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800780: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800788: jal         0x800832E0
    // 0x8080078C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080078C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800790: jal         0x80082FE0
    // 0x80800794: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800794: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080079C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007A0: jr          $ra
    // 0x808007A4: nop

    return;
    // 0x808007A4: nop

;}
RECOMP_FUNC void _bsdrone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FE0: syscall     38
    recomp_syscall_handler(rdram, ctx, 0x80082FE0);
    return;
    // 0x80082FE4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800DAFC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAFC4: jr          $ra
    // 0x800DAFC8: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x800DAFC8: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800B0D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0D58: jr          $ra
    // 0x800B0D5C: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    return;
    // 0x800B0D5C: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
;}
RECOMP_FUNC void func_800B8FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8FE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B8FE4: jr          $ra
    // 0x800B8FE8: sw          $zero, 0x712C($at)
    MEM_W(0X712C, ctx->r1) = 0;
    return;
    // 0x800B8FE8: sw          $zero, 0x712C($at)
    MEM_W(0X712C, ctx->r1) = 0;
;}
RECOMP_FUNC void _bskazhatch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083408: syscall     60
    recomp_syscall_handler(rdram, ctx, 0x80083408);
    return;
    // 0x8008340C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chminegrill2switches_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087140: syscall     522
    recomp_syscall_handler(rdram, ctx, 0x80087140);
    return;
    // 0x80087144: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void sukickball_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080107C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801084: jal         0x80100094
    // 0x80801088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080108C: lbu         $v1, 0x39($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X39);
    // 0x80801090: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801094: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    // 0x80801098: beq         $v1, $zero, L_808010C0
    if (ctx->r3 == 0) {
        // 0x8080109C: nop
    
            goto L_808010C0;
    }
    // 0x8080109C: nop

    // 0x808010A0: beq         $v1, $at, L_808010C0
    if (ctx->r3 == ctx->r1) {
        // 0x808010A4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808010C0;
    }
    // 0x808010A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808010A8: beq         $v1, $at, L_808010C0
    if (ctx->r3 == ctx->r1) {
        // 0x808010AC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808010C0;
    }
    // 0x808010AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808010B0: beq         $v1, $at, L_808010D0
    if (ctx->r3 == ctx->r1) {
        // 0x808010B4: addiu       $a0, $zero, 0xC3
        ctx->r4 = ADD32(0, 0XC3);
            goto L_808010D0;
    }
    // 0x808010B4: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    // 0x808010B8: b           L_808010DC
    // 0x808010BC: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
        goto L_808010DC;
    // 0x808010BC: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
L_808010C0:
    // 0x808010C0: jal         0x800D2748
    // 0x808010C4: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    func_800D2748(rdram, ctx);
        goto after_1;
    // 0x808010C4: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_1:
    // 0x808010C8: b           L_808010DC
    // 0x808010CC: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
        goto L_808010DC;
    // 0x808010CC: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
L_808010D0:
    // 0x808010D0: jal         0x800D2748
    // 0x808010D4: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    func_800D2748(rdram, ctx);
        goto after_2;
    // 0x808010D4: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_2:
    // 0x808010D8: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
L_808010DC:
    // 0x808010DC: jal         0x800D2748
    // 0x808010E0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800D2748(rdram, ctx);
        goto after_3;
    // 0x808010E0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_3:
    // 0x808010E4: addiu       $a0, $zero, 0xC5
    ctx->r4 = ADD32(0, 0XC5);
    // 0x808010E8: jal         0x800D2748
    // 0x808010EC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    func_800D2748(rdram, ctx);
        goto after_4;
    // 0x808010EC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_4:
    // 0x808010F0: addiu       $a0, $zero, 0xC6
    ctx->r4 = ADD32(0, 0XC6);
    // 0x808010F4: jal         0x800D2748
    // 0x808010F8: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_800D2748(rdram, ctx);
        goto after_5;
    // 0x808010F8: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_5:
    // 0x808010FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801104: jr          $ra
    // 0x80801108: nop

    return;
    // 0x80801108: nop

;}
RECOMP_FUNC void func_808000D8_gctransitionDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808000EC: lw          $a3, 0x2C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X2C);
    // 0x808000F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000F4: beql        $a3, $zero, L_8080010C
    if (ctx->r7 == 0) {
        // 0x808000F8: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8080010C;
    }
    goto skip_0;
    // 0x808000F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x808000FC: jal         0x8008ADBC
    // 0x80800100: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8008ADBC(rdram, ctx);
        goto after_0;
    // 0x80800100: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80800104: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80800108: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8080010C:
    // 0x8080010C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80800110: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800114: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80800118: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080011C: beq         $t6, $zero, L_80800134
    if (ctx->r14 == 0) {
        // 0x80800120: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80800134;
    }
    // 0x80800120: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80800124: jal         0x8001BBC8
    // 0x80800128: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    aligned4_memcpy(rdram, ctx);
        goto after_1;
    // 0x80800128: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_1:
    // 0x8080012C: b           L_8080013C
    // 0x80800130: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_8080013C;
    // 0x80800130: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80800134:
    // 0x80800134: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // 0x80800138: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_8080013C:
    // 0x8080013C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800140: addiu       $t8, $zero, 0xB45
    ctx->r24 = ADD32(0, 0XB45);
    // 0x80800144: bne         $t7, $at, L_80800154
    if (ctx->r15 != ctx->r1) {
        // 0x80800148: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80800154;
    }
    // 0x80800148: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8080014C: b           L_80800184
    // 0x80800150: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
        goto L_80800184;
    // 0x80800150: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
L_80800154:
    // 0x80800154: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800158: bne         $t9, $at, L_8080016C
    if (ctx->r25 != ctx->r1) {
        // 0x8080015C: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_8080016C;
    }
    // 0x8080015C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800160: addiu       $t0, $zero, 0xB46
    ctx->r8 = ADD32(0, 0XB46);
    // 0x80800164: b           L_80800184
    // 0x80800168: sw          $t0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r8;
        goto L_80800184;
    // 0x80800168: sw          $t0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r8;
L_8080016C:
    // 0x8080016C: beql        $t1, $zero, L_80800188
    if (ctx->r9 == 0) {
        // 0x80800170: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_80800188;
    }
    goto skip_1;
    // 0x80800170: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80800174: lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X8);
    // 0x80800178: beql        $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x8080017C: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_80800188;
    }
    goto skip_2;
    // 0x8080017C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80800180: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_80800184:
    // 0x80800184: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
L_80800188:
    // 0x80800188: beql        $t2, $zero, L_80800230
    if (ctx->r10 == 0) {
        // 0x8080018C: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80800230;
    }
    goto skip_3;
    // 0x8080018C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800190: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80800194: beql        $t3, $zero, L_80800230
    if (ctx->r11 == 0) {
        // 0x80800198: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80800230;
    }
    goto skip_4;
    // 0x80800198: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8080019C: jal         0x8008AD80
    // 0x808001A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8008AD80(rdram, ctx);
        goto after_2;
    // 0x808001A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x808001A4: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x808001A8: jal         0x8008AF24
    // 0x808001AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_3;
    // 0x808001AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808001B0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x808001B4: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x808001B8: jal         0x8008AED4
    // 0x808001BC: lw          $a1, 0xC($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x808001BC: lw          $a1, 0xC($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC);
    after_4:
    // 0x808001C0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x808001C4: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x808001C8: jal         0x8008B1BC
    // 0x808001CC: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x808001CC: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    after_5:
    tooie_transition_anim_length(rdram, ctx);
    // 0x808001D0: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x808001D4: jal         0x8008B134
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808001DC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808001E0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808001E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001E8: bne         $t6, $at, L_80800210
    if (ctx->r14 != ctx->r1) {
        // 0x808001EC: nop
    
            goto L_80800210;
    }
    // 0x808001EC: nop

    // 0x808001F0: jal         0x8008B188
    // 0x808001F4: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_8008B188(rdram, ctx);
        goto after_7;
    // 0x808001F4: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_7:
    // 0x808001F8: jal         0x80090684
    // 0x808001FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090684(rdram, ctx);
        goto after_8;
    // 0x808001FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80800200: jal         0x800EA334
    // 0x80800204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800EA334(rdram, ctx);
        goto after_9;
    // 0x80800204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80800208: b           L_80800224
    // 0x8080020C: nop

        goto L_80800224;
    // 0x8080020C: nop

L_80800210:
    // 0x80800210: jal         0x8002FBB0
    // 0x80800214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_10;
    // 0x80800214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x80800218: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x8080021C: jal         0x8008B10C
    // 0x80800220: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_8008B10C(rdram, ctx);
        goto after_11;
    // 0x80800220: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_11:
L_80800224:
    // 0x80800224: jal         0x8008B064
    // 0x80800228: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    anctrl_start(rdram, ctx);
        goto after_12;
    // 0x80800228: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_12:
    // 0x8080022C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80800230:
    // 0x80800230: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800234: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800238: bnel        $t7, $at, L_8080027C
    if (ctx->r15 != ctx->r1) {
        // 0x8080023C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8080027C;
    }
    goto skip_5;
    // 0x8080023C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_5:
    // 0x80800240: jal         0x800FC6B0
    // 0x80800244: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800FC6B0(rdram, ctx);
        goto after_13;
    // 0x80800244: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_13:
    // 0x80800248: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x8080024C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800250: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80800254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800258: jal         0x800FCB54
    // 0x8080025C: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    func_800FCB54(rdram, ctx);
        goto after_14;
    // 0x8080025C: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    after_14:
    // 0x80800260: jal         0x800FCA90
    // 0x80800264: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800FCA90(rdram, ctx);
        goto after_15;
    // 0x80800264: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_15:
    // 0x80800268: jal         0x800FC8EC
    // 0x8080026C: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800FC8EC(rdram, ctx);
        goto after_16;
    // 0x8080026C: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_16:
    // 0x80800270: b           L_80800308
    // 0x80800274: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
        goto L_80800308;
    // 0x80800274: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80800278: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_8080027C:
    // 0x8080027C: bne         $t8, $at, L_808002DC
    if (ctx->r24 != ctx->r1) {
        // 0x80800280: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_808002DC;
    }
    // 0x80800280: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800284: lbu         $t9, 0x8($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X8);
    // 0x80800288: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080028C: bne         $t9, $at, L_808002A4
    if (ctx->r25 != ctx->r1) {
        // 0x80800290: nop
    
            goto L_808002A4;
    }
    // 0x80800290: nop

    // 0x80800294: jal         0x800880D0
    // 0x80800298: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800298: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x8080029C: b           L_80800308
    // 0x808002A0: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
        goto L_80800308;
    // 0x808002A0: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
L_808002A4:
    // 0x808002A4: jal         0x800FC6B0
    // 0x808002A8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800FC6B0(rdram, ctx);
        goto after_18;
    // 0x808002A8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_18:
    // 0x808002AC: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x808002B0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808002B4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x808002B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002BC: jal         0x800FCB54
    // 0x808002C0: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    func_800FCB54(rdram, ctx);
        goto after_19;
    // 0x808002C0: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    after_19:
    // 0x808002C4: jal         0x800FCA90
    // 0x808002C8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800FCA90(rdram, ctx);
        goto after_20;
    // 0x808002C8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_20:
    // 0x808002CC: jal         0x800FC8EC
    // 0x808002D0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800FC8EC(rdram, ctx);
        goto after_21;
    // 0x808002D0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_21:
    // 0x808002D4: b           L_80800308
    // 0x808002D8: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
        goto L_80800308;
    // 0x808002D8: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
L_808002DC:
    // 0x808002DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002E0: bnel        $t0, $at, L_80800308
    if (ctx->r8 != ctx->r1) {
        // 0x808002E4: sw          $zero, 0x30($s0)
        MEM_W(0X30, ctx->r16) = 0;
            goto L_80800308;
    }
    goto skip_6;
    // 0x808002E4: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    skip_6:
    // 0x808002E8: lbu         $t1, 0x1C($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1C);
    // 0x808002EC: beql        $t1, $zero, L_80800308
    if (ctx->r9 == 0) {
        // 0x808002F0: sw          $zero, 0x30($s0)
        MEM_W(0X30, ctx->r16) = 0;
            goto L_80800308;
    }
    goto skip_7;
    // 0x808002F0: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    skip_7:
    // 0x808002F4: jal         0x800C9214
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C9214(rdram, ctx);
        goto after_22;
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808002FC: b           L_80800314
    // 0x80800300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800314;
    // 0x80800300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800304: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
L_80800308:
    // 0x80800308: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8080030C: sb          $t2, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r10;
    // 0x80800310: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800314:
    // 0x80800314: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800318: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080031C: jr          $ra
    // 0x80800320: nop

    return;
    // 0x80800320: nop

;}
RECOMP_FUNC void subaddiepalette_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808001C4: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x808001C8: andi        $t6, $a2, 0xFFFF
    ctx->r14 = ctx->r6 & 0XFFFF;
    // 0x808001CC: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x808001D0: bne         $t6, $v1, L_808001E0
    if (ctx->r14 != ctx->r3) {
        // 0x808001D4: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_808001E0;
    }
    // 0x808001D4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x808001D8: jr          $ra
    // 0x808001DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808001DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001E0:
    // 0x808001E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808001E4: sh          $t7, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r15;
    // 0x808001E8: swc1        $f12, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f12.u32l;
    // 0x808001EC: swc1        $f12, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f12.u32l;
    // 0x808001F0: sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // 0x808001F4: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
    // 0x808001F8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800200: sh          $a2, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r6;
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

;}
RECOMP_FUNC void func_8080042C_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080042C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800430: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800434: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800438: lui         $a2, 0x3F1E
    ctx->r6 = S32(0X3F1E << 16);
    // 0x8080043C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800440: ori         $a2, $a2, 0xB852
    ctx->r6 = ctx->r6 | 0XB852;
    // 0x80800444: jal         0x8008CB3C
    // 0x80800448: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80800448: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_0:
    // 0x8080044C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800450: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080045C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800460: jal         0x8009FFD8
    // 0x80800464: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800464: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: jal         0x80095738
    // 0x80800470: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x80800470: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x80800474: beq         $v0, $zero, L_8080048C
    if (ctx->r2 == 0) {
        // 0x80800478: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080048C;
    }
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: jal         0x8009B9B0
    // 0x80800480: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800480: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800484: b           L_80800498
    // 0x80800488: nop

        goto L_80800498;
    // 0x80800488: nop

L_8080048C:
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800490: jal         0x8009B9B0
    // 0x80800494: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800494: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    after_4:
L_80800498:
    // 0x80800498: jal         0x8009C990
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_5;
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808004A0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808004A4: jal         0x8009BB00
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808004AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B4: jal         0x8009BA68
    // 0x808004B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x808004B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x808004BC: jal         0x8009C990
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_8;
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808004C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004C8: jal         0x8009B9C0
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_9;
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: jal         0x800A0CF4
    // 0x808004D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_10;
    // 0x808004D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: jal         0x8009BCB4
    // 0x808004E4: lui         $a1, 0xC396
    ctx->r5 = S32(0XC396 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_11;
    // 0x808004E4: lui         $a1, 0xC396
    ctx->r5 = S32(0XC396 << 16);
    after_11:
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: jal         0x8009BCC4
    // 0x808004F0: lui         $a1, 0xC248
    ctx->r5 = S32(0XC248 << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_12;
    // 0x808004F0: lui         $a1, 0xC248
    ctx->r5 = S32(0XC248 << 16);
    after_12:
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: jal         0x800A4DA4
    // 0x808004FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800A4DA4(rdram, ctx);
        goto after_13;
    // 0x808004FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x80800500: jal         0x80800128
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800128_bskazfly(rdram, ctx);
        goto after_14;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800508: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080050C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800510: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x8080051C: lw          $t8, 0x188($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X188);
    // 0x80800520: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800524: jal         0x80084C60
    // 0x80800528: sb          $zero, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = 0;
    _bafly_entrypoint_19(rdram, ctx);
        goto after_15;
    // 0x80800528: sb          $zero, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = 0;
    after_15:
    // 0x8080052C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800530: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800534: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void _chphlegm_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086010: syscall     271
    recomp_syscall_handler(rdram, ctx, 0x80086010);
    return;
    // 0x80086014: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chfactoryworkerdirty_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2168, 0XEF8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xEF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2168, 0XEF8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xEF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2168, 0XEF8));
;}
RECOMP_FUNC void func_80081D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081D80: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80081D84: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80081D88: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80081D8C: lw          $v0, 0x2540($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2540);
    // 0x80081D90: lui         $at, 0xFC00
    ctx->r1 = S32(0XFC00 << 16);
    // 0x80081D94: ori         $at, $at, 0x3F
    ctx->r1 = ctx->r1 | 0X3F;
    // 0x80081D98: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80081D9C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80081DA0: bne         $t7, $at, L_80081DC4
    if (ctx->r15 != ctx->r1) {
        // 0x80081DA4: sll         $v1, $v0, 6
        ctx->r3 = S32(ctx->r2 << 6);
            goto L_80081DC4;
    }
    // 0x80081DA4: sll         $v1, $v0, 6
    ctx->r3 = S32(ctx->r2 << 6);
    // 0x80081DA8: sll         $t9, $v0, 6
    ctx->r25 = S32(ctx->r2 << 6);
    // 0x80081DAC: bltz        $t9, L_80081DBC
    if (SIGNED(ctx->r25) < 0) {
        // 0x80081DB0: nop
    
            goto L_80081DBC;
    }
    // 0x80081DB0: nop

    // 0x80081DB4: jr          $ra
    // 0x80081DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80081DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80081DBC:
    // 0x80081DBC: jr          $ra
    // 0x80081DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80081DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80081DC4:
    // 0x80081DC4: sra         $t0, $v1, 6
    ctx->r8 = S32(SIGNED(ctx->r3) >> 6);
    // 0x80081DC8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80081DCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081DD0: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80081DD4: addiu       $v1, $t2, -0x10
    ctx->r3 = ADD32(ctx->r10, -0X10);
    // 0x80081DD8: lh          $t3, 0x32($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X32);
    // 0x80081DDC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80081DE0: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80081DE4: bne         $at, $zero, L_80081DF4
    if (ctx->r1 != 0) {
        // 0x80081DE8: nop
    
            goto L_80081DF4;
    }
    // 0x80081DE8: nop

    // 0x80081DEC: jr          $ra
    // 0x80081DF0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80081DF0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80081DF4:
    // 0x80081DF4: jr          $ra
    // 0x80081DF8: nop

    return;
    // 0x80081DF8: nop

    // 0x80081DFC: nop

;}
RECOMP_FUNC void func_80800114_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80800118: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8080011C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800120: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1608, 0X5038) << 16);
    // 0x80800124: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800128: jr          $ra
    // 0x8080012C: lw          $v0, 0x5038($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1608, 0X5038));
    return;
    // 0x8080012C: lw          $v0, 0x5038($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1608, 0X5038));
;}
RECOMP_FUNC void _bsjump_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083268: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083268);
    return;
    // 0x8008326C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800200_bsbwhirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800204: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800208: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080020C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800210: jal         0x8009C128
    // 0x80800214: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800214: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80800218: jal         0x8009C984
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800220: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800224: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800228: jal         0x800EFCD8
    // 0x8080022C: lui         $a2, 0x4240
    ctx->r6 = S32(0X4240 << 16);
    func_800EFCD8(rdram, ctx);
        goto after_2;
    // 0x8080022C: lui         $a2, 0x4240
    ctx->r6 = S32(0X4240 << 16);
    after_2:
    // 0x80800230: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800234: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800238: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8080023C: jal         0x800EF04C
    // 0x80800240: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80800240: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800244: jal         0x800B5BE4
    // 0x80800248: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800B5BE4(rdram, ctx);
        goto after_4;
    // 0x80800248: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_4:
    // 0x8080024C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(128, 0XF5C) << 16);
    // 0x80800250: addiu       $t6, $t6, 0xF5C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(128, 0XF5C));
    // 0x80800254: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800258: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080025C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800260: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800264: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800268: jal         0x800BABB8
    // 0x8080026C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x8080026C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: jal         0x8009BB24
    // 0x80800278: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_8009BB24(rdram, ctx);
        goto after_6;
    // 0x80800278: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_6:
    // 0x8080027C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800280: lw          $a1, 0x170($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X170);
    // 0x80800284: jal         0x800EFCD8
    // 0x80800288: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    func_800EFCD8(rdram, ctx);
        goto after_7;
    // 0x80800288: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    after_7:
    // 0x8080028C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800290: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800294: lwc1        $f6, 0x170($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X170);
    // 0x80800298: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080029C: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    // 0x808002A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808002A4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808002A8: jal         0x800EFCD8
    // 0x808002AC: nop

    func_800EFCD8(rdram, ctx);
        goto after_8;
    // 0x808002AC: nop

    after_8:
    // 0x808002B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808002B4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808002B8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808002BC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x808002C0: jal         0x800EF04C
    // 0x808002C4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x808002C4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x808002C8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808002CC: jal         0x800EF04C
    // 0x808002D0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x808002D0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_10:
    // 0x808002D4: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808002D8: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808002DC: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808002E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808002E4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x808002E8: nop

    // 0x808002EC: bc1fl       L_80800300
    if (!c1cs) {
        // 0x808002F0: lwc1        $f2, 0x50($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
            goto L_80800300;
    }
    goto skip_0;
    // 0x808002F0: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x808002F4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x808002F8: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x808002FC: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
L_80800300:
    // 0x80800300: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800304: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80800308: nop

    // 0x8080030C: bc1fl       L_80800320
    if (!c1cs) {
        // 0x80800310: lwc1        $f16, 0x170($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X170);
            goto L_80800320;
    }
    goto skip_1;
    // 0x80800310: lwc1        $f16, 0x170($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X170);
    skip_1:
    // 0x80800314: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x80800318: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x8080031C: lwc1        $f16, 0x170($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X170);
L_80800320:
    // 0x80800320: jal         0x800136E4
    // 0x80800324: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    func_800136E4(rdram, ctx);
        goto after_11;
    // 0x80800324: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_11:
    // 0x80800328: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x8080032C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800330: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800334: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800338: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080033C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800340: addiu       $t5, $zero, 0xFA
    ctx->r13 = ADD32(0, 0XFA);
    // 0x80800344: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800348: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080034C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80800350: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800354: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800358: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8080035C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800360: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80800364: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x80800368: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8080036C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800370: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80800374: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800378: addiu       $a2, $zero, 0xFA
    ctx->r6 = ADD32(0, 0XFA);
    // 0x8080037C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800380: jal         0x800BA930
    // 0x80800384: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_800BA930(rdram, ctx);
        goto after_12;
    // 0x80800384: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_12:
    // 0x80800388: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080038C: jal         0x800BA22C
    // 0x80800390: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BA22C(rdram, ctx);
        goto after_13;
    // 0x80800390: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x80800394: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800398: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080039C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void _chdippy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086478: syscall     327
    recomp_syscall_handler(rdram, ctx, 0x80086478);
    return;
    // 0x8008647C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808006B0_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006BC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808006C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006C4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x808006C8: jal         0x80100094
    // 0x808006CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006D0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808006D4: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x808006E0: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x808006E4: beq         $at, $zero, L_808007DC
    if (ctx->r1 == 0) {
        // 0x808006E8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808007DC;
    }
    // 0x808006E8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808006EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1516, 0XF1C) << 16);
    // 0x808006F0: addu        $at, $at, $t6
    gpr jr_addend_808006F8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808006F4: lw          $t6, 0xF1C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1516, 0XF1C));
    // 0x808006F8: jr          $t6
    // 0x808006FC: nop

    switch (jr_addend_808006F8 >> 2) {
        case 0: goto L_80800700; break;
        case 1: goto L_80800720; break;
        case 2: goto L_80800734; break;
        case 3: goto L_80800754; break;
        case 4: goto L_8080078C; break;
        case 5: goto L_808007AC; break;
        default: switch_error(__func__, 0x808006F8, 0x80800F1C);
    }
    // 0x808006FC: nop

L_80800700:
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: jal         0x80102424
    // 0x80800708: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800708: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: jal         0x808007F8
    // 0x80800714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808007F8_chnewshovel(rdram, ctx);
        goto after_2;
    // 0x80800714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800718: b           L_808007E8
    // 0x8080071C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007E8;
    // 0x8080071C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800720:
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800724: jal         0x80102424
    // 0x80800728: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800728: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x8080072C: b           L_808007E8
    // 0x80800730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007E8;
    // 0x80800730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800734:
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800738: jal         0x80102424
    // 0x8080073C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x8080073C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800744: jal         0x808007F8
    // 0x80800748: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808007F8_chnewshovel(rdram, ctx);
        goto after_5;
    // 0x80800748: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080074C: b           L_808007E8
    // 0x80800750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007E8;
    // 0x80800750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800754:
    // 0x80800754: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80800758: jal         0x8010D290
    // 0x8080075C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8010D290(rdram, ctx);
        goto after_6;
    // 0x8080075C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_6:
    // 0x80800760: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800764: jal         0x800F5A00
    // 0x80800768: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800F5A00(rdram, ctx);
        goto after_7;
    // 0x80800768: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_7:
    // 0x8080076C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800770: jal         0x80102424
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080077C: jal         0x808007F8
    // 0x80800780: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808007F8_chnewshovel(rdram, ctx);
        goto after_9;
    // 0x80800780: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800784: b           L_808007E8
    // 0x80800788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007E8;
    // 0x80800788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080078C:
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800790: jal         0x80102424
    // 0x80800794: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x80800794: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_10:
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080079C: jal         0x808007F8
    // 0x808007A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808007F8_chnewshovel(rdram, ctx);
        goto after_11;
    // 0x808007A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x808007A4: b           L_808007E8
    // 0x808007A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007E8;
    // 0x808007A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007AC:
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808007B4: jal         0x80107B70
    // 0x808007B8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80107B70(rdram, ctx);
        goto after_12;
    // 0x808007B8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_12:
    // 0x808007BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808007C0: jal         0x80102424
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007CC: jal         0x808007F8
    // 0x808007D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808007F8_chnewshovel(rdram, ctx);
        goto after_14;
    // 0x808007D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x808007D4: b           L_808007E8
    // 0x808007D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007E8;
    // 0x808007D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007DC:
    // 0x808007DC: jal         0x80102424
    // 0x808007E0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x808007E0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_15:
    // 0x808007E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007E8:
    // 0x808007E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007F0: jr          $ra
    // 0x808007F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808007F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800175A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800175A0: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800175A4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800175A8: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x800175AC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800175B0: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800175B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800175B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800175BC: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x800175C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800175C4: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800175C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800175CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800175D0: addiu       $t8, $t8, -0x6060
    ctx->r24 = ADD32(ctx->r24, -0X6060);
    // 0x800175D4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800175D8: jal         0x80025668
    // 0x800175DC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    func_80025668(rdram, ctx);
        goto after_0;
    // 0x800175DC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x800175E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800175E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800175E8: jr          $ra
    // 0x800175EC: nop

    return;
    // 0x800175EC: nop

;}
RECOMP_FUNC void func_80112E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112E84: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x80112E88: jr          $ra
    // 0x80112E8C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    return;
    // 0x80112E8C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
;}
RECOMP_FUNC void func_80800D90_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D94: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800D98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D9C: bne         $a1, $at, L_80800DB4
    if (ctx->r5 != ctx->r1) {
        // 0x80800DA0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800DB4;
    }
    // 0x80800DA0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800DA4: jal         0x80800DC8
    // 0x80800DA8: nop

    func_80800DC8_chfactorysparkroom(rdram, ctx);
        goto after_0;
    // 0x80800DA8: nop

    after_0:
    // 0x80800DAC: b           L_80800DB8
    // 0x80800DB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DB8;
    // 0x80800DB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DB4:
    // 0x80800DB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DB8:
    // 0x80800DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DC0: jr          $ra
    // 0x80800DC4: nop

    return;
    // 0x80800DC4: nop

;}
RECOMP_FUNC void _chdiggerbossshell_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086800: syscall     380
    recomp_syscall_handler(rdram, ctx, 0x80086800);
    return;
    // 0x80086804: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800AADEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AADEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800AADF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AADF4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800AADF8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800AADFC: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800AAE00: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800AAE04: jal         0x800EFB24
    // 0x800AAE08: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800AAE08: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x800AAE0C: jal         0x800EEFD4
    // 0x800AAE10: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EEFD4(rdram, ctx);
        goto after_1;
    // 0x800AAE10: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x800AAE14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AAE18: lwc1        $f4, 0x5610($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5610);
    // 0x800AAE1C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800AAE20: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800AAE24: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800AAE28: nop

    // 0x800AAE2C: bc1f        L_800AAE60
    if (!c1cs) {
        // 0x800AAE30: nop
    
            goto L_800AAE60;
    }
    // 0x800AAE30: nop

    // 0x800AAE34: jal         0x800EEB40
    // 0x800AAE38: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800EEB40(rdram, ctx);
        goto after_2;
    // 0x800AAE38: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x800AAE3C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800AAE40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AAE44: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800AAE48: nop

    // 0x800AAE4C: bc1fl       L_800AAEE8
    if (!c1cs) {
        // 0x800AAE50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AAEE8;
    }
    goto skip_0;
    // 0x800AAE50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800AAE54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AAE58: b           L_800AAEE8
    // 0x800AAE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AAEE8;
    // 0x800AAE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AAE60:
    // 0x800AAE60: jal         0x8002DCA0
    // 0x800AAE64: nop

    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800AAE64: nop

    after_3:
    // 0x800AAE68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AAE6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AAE70: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800AAE74: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AAE78: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800AAE7C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800AAE80: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800AAE84: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800AAE88: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800AAE8C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800AAE90: nop

    // 0x800AAE94: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800AAE98: nop

    // 0x800AAE9C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800AAEA0: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x800AAEA4: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800AAEA8: jal         0x800EFB24
    // 0x800AAEAC: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x800AAEAC: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x800AAEB0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800AAEB4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800AAEB8: jal         0x800EE97C
    // 0x800AAEBC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800EE97C(rdram, ctx);
        goto after_5;
    // 0x800AAEBC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x800AAEC0: jal         0x800EEFD4
    // 0x800AAEC4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EEFD4(rdram, ctx);
        goto after_6;
    // 0x800AAEC4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x800AAEC8: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800AAECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AAED0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800AAED4: nop

    // 0x800AAED8: bc1fl       L_800AAEE8
    if (!c1cs) {
        // 0x800AAEDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AAEE8;
    }
    goto skip_1;
    // 0x800AAEDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800AAEE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AAEE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AAEE8:
    // 0x800AAEE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800AAEEC: jr          $ra
    // 0x800AAEF0: nop

    return;
    // 0x800AAEF0: nop

;}
RECOMP_FUNC void _chjigsawbitcont_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B30: syscall     418
    recomp_syscall_handler(rdram, ctx, 0x80086B30);
    return;
    // 0x80086B34: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800DD8_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DE0: jal         0x80100094
    // 0x80800DE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800DEC: addiu       $a0, $zero, 0x9CD
    ctx->r4 = ADD32(0, 0X9CD);
    // 0x80800DF0: jal         0x800DA564
    // 0x80800DF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x80800DF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800DF8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DFC: lh          $v1, 0x2C($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X2C);
    // 0x80800E00: xor         $v0, $v0, $v1
    ctx->r2 = ctx->r2 ^ ctx->r3;
    // 0x80800E04: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800E08: beql        $v0, $zero, L_80800E24
    if (ctx->r2 == 0) {
        // 0x80800E0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800E24;
    }
    goto skip_0;
    // 0x80800E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800E10: jal         0x800DA298
    // 0x80800E14: addiu       $a0, $v1, 0x65C
    ctx->r4 = ADD32(ctx->r3, 0X65C);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800E14: addiu       $a0, $v1, 0x65C
    ctx->r4 = ADD32(ctx->r3, 0X65C);
    after_2:
    // 0x80800E18: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800E1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E24:
    // 0x80800E24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E28: jr          $ra
    // 0x80800E2C: nop

    return;
    // 0x80800E2C: nop

;}
RECOMP_FUNC void _mlwave_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FE0: syscall     754
    recomp_syscall_handler(rdram, ctx, 0x80088FE0);
    return;
    // 0x80088FE4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
