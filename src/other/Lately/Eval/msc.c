/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   mcs.c - [Private]

Project:

   Robust Assembler (RASM)
   
Abstract:

   Machine code set

------
   AUTHOR: HyunJun Jeong  2015-01-07

***************************************************************************/


#define HASH_BEFORE_SMALL_A \
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

static const char _dummy_firstx_all[123] = {
	HASH_BEFORE_SMALL_A
	0,  /* 'a' */	// aaa, aad, aam, aas, adc, add, and, arpl \
				"" addps, addss, andnps, andps "" addpd, addsd, andnpd, andpd "" addsubpd, addsubps \
				"" aesdec, aesdeclast, aesenc, aesimc, aeskeygenassist
	0,  /* 'b' */	// bound, bsf, bsr, bswap, bt, btc, btr, bts "" blendpd, blendps, blendvpd, \
				blendvps
	0,  /* 'c' */	// call, cbw, cdq, clc, cld, cli, clts, cmc, cmp, [cmps, cmpsb, cmpsw, cmpsd], \
				cmpxchg, cpuid, cwd, cwde "" cmovcc, fcmovcc, fcomi, fxrstor, fxsave "" cmpps, comiss, \
				cvtpi2ps, cvtpi2pi, cvtsi2ss, cvtss2si, cvttp2pi, cvttps2pi, cvttss2si "" cmppd, cmpsd, \
				comisd, cvtpi2pd, cvtpd2pi, cvtsi2sd, cvtsd2si, cvttpd2pi, cvttsd2si, cvtpd2ps, cvtps2pd, \
				cvtsd2ss, cvtss2sd, cvtpd2dq, cvttpd2dq, cvtdq2pd, cvtps2dq, cvttps2dq, cvtdq2ps "" clflush \
				"" crc32 \
				64~ \
				cmovcc, cvtsd2si, cvtsi2ss, cvtsi2sd, cvtss2si, cvttss2si
	0,  /* 'd' */	// daa, das, dec, div "" divps, divss "" divpd, divsd "" dppd, dpps
	0,  /* 'e' */	// "" emms "" extractps
	0,  /* 'f' */	// "" fisttp \
				float~ \
				f2xm1, fabs, fadd, faddp, fbld, fbstp, fchs, fclex, fcom, fcomp, fcmpp, fcomip, fcos, fdecstp, \
				fdiv, fdivp, fdivr, fdivrp, ffree, fiadd, ficom, ficmp, fidiv, fidivr, fild, fimul, fincstp, \
				finit, fist, fistp, fisub, fisubr, fld, fld1, fldcw, fldenv, fldl2e, fldl2t, fldlg2, fldln2, \
				fldpi, fldz, fmul, fmulp, fnop, fpatan, fprem, fprem1, fptan, frndint, frstor, fsave, fscale, \
				fsin, fsincos, fsqrt, fst, fstcw, fstenv, fstp, fstsw, fstsw, fsub, fsubp, fsubr, fsubrp, \
				ftst, fucom, fucomp, fucompp, fucomi, fucomip, fxam, fxch, fxtract, fyl2x, fyl2xp1, fwait
	0,  /* 'g' */
	0,  /* 'h' */	// hlt "" haddpd, haddps, hsubpd, hsubps
	0,  /* 'i' */	// idiv, imul, in, inc, ins, int, into, invb, invlpg, invpcid, iret, iretd \
				"" insertps "" invept, invvpid
	0,  /* 'j' */	// jcc, jcxz, jecxz, jmp
	0,  /* 'k' */
	0,  /* 'l' */	// lahf, lar, lsd, lea, leave, les, lfs, lgdt, lgs, lidt, lldt, lmsw, lock, \
				[lods, lodsb, lodsw, lodsb], loop, loppz, loope, loopnz, loopne, lsl, lss, ltr \
				"" ldmxcsr "" lfence "" lddqu
	0,  /* 'm' */	// mov, movbe, [movs, movsb, movsw, movsd], movsx, movzx, mul "" movd, movq \
				"" maxps, maxss, minps, minss, movaps, movhlps, movhps, movlhps, movlps, movmskps, \
				movss, movups, mulps, mulss "" maskmovq, movntps, movntq "" maxpd, maxsd, minpd, minsd \
				movapd, movhpd, movlpd, movmskpd, movsd, movupd, mulpd, mulsd "" movd, movdqa, \
				movdqu, movq2dq, movdq2q, movq "" maskmovdqu, movntpd, movntdq, movnti, mfence \
				"" monitor, mwait "" movddup, movshdup, movsldup "" movntdqa,  mpsqdbw\
				64~ \
				movd, movq, movmskps
	0,  /* 'n' */	// neg, nop
	0,  /* 'o' */	// or, out, outs "" orps "" orpd
	0,  /* 'p' */	// pop,popa, popad, popf, popfd, push, pusha, pushad, pushf, pushfd \
				"" packssdw, packsswb, packuswb, padd, padds, papddus, pand, pandn, pcmpeq, pcmpgt, \
				pmaddwd, pmulhuw, pmulhw, pmullw, por, psll, psra, psrl, psub, psubs, psubus, punpckh \
				punpckl, pxor "" pavgb, pavgw, pextrw, pinsrw, pmaxsu, pmaxub, pminsw, pminub, pmovmskb, \
				pmulhuw, psadbw, pshufw "" prefetcht0, perfectcht1, perfectcht2, perfectchnta \
				"" packssdw, packsswb, packuswb, paddq, padd, padds, paddus, pand, pandn, pavgb, pavgw, \
				pcmpeq, pcmpgt, pextrw, pinsrw, pmaddwd, pmaxsw, pmaxub, pminsw, pminub, pmovmskb, pmulhuw, \
				pmulhw, pmullw, pmuludq, por, psadbw, pshuflw, pshufhw, pshufd, pslldq, psll, psra, psrldq, \
				psrl, psubq, psub, psubs, psubus, punpckh, punpckhqdq, punpckl, punpcklqdq, pxor, "" pause \
				"" pabsb, pabsd, pabsw, palignr, phaddd, phaddsw, phaddw, phsubd, phsubsw, phsubw, pmaddubsw, \
				pmulhrsw, pshufb, psignb, psignd, psignw "" pclmulqdq "" packusdw, pblendvb, pblendw, \
				pcmpeqq, pextrb, pextrd, pextrq, pextrw, phminposuw, pinsrb, pinsrd, pinsrq, pmaxsb, pmaxsd, \
				pmaxud, pmaxuw, pminsb, pminsd, pminud, pminuw, pmovsxbd, pmovsxbq, pmovsxbw, pmovsxwd, \
				pmovsxwq, pmovsxdq, pmovzxbd, pmovzxbq, pmovzxbw, pmovzxwd, pmovzxwq, pmovzxdq, pmuldq, \
				pmulld, ptest, "" pcmpestri, pcmpestrm, pcmpistri, pcmpistrm, pcmpgtq, popcnt\
				64~ \
				pextrw, pinsrw, pmovmskb
	0,  /* 'q' */
	0,  /* 'r' */	// rcl, rcr, rdmsr, rdpmc, rdtsc, rdtscp, rep {ins, lodx, movs, outs, stos, cmps, scas}, \
				repne {cmps, scas}, ret, ror, rsm "" rcpps, rcpss, rsqrtps, rsqrtss, "" roundpd, roundps, \
				roundsd, roundss
	0,  /* 's' */	// sahf, sal, sar, sbb, [scas, scasb, scasw, scasd], setcc, sgdt, shl, shld, \
				shr, shrd, sidt, sldt, smsw, stc, std, sti, [stos, stosb, stosw, stosd], str, sub, swapgs, syscall, sysret \
				"" sysenterm, sysexit "" shufps, sqrtps, sqrtss, stmxcsr, subps, subss "" sfence "" shufpd, \
				sqrtpd, sqrtsd, subpd, sudsd
	0,  /* 't' */	// test
	0,  /* 'u' */	// ud2 "" ucomiss, unpckhps, unpcklps "" ucomisd, unpckhpd, unpcklpd
	0,  /* 'v' */	// verr, verw "" vmcall, vmclear, vmfunc, vmlaunch, vmresume, vmptrld, vmptrst, \
				vmreadm, vmwrite, vmxoff, vmxon
	0,  /* 'w' */	// wait, wbinvb, wrmsr
	0,  /* 'x' */	// xadd, xchg, xlat, xlatb, xor "" xgetbv, xrstor, xsave, xsetbv "" xorps "" xorpd
	0,  /* 'y' */
	0,  /* 'z' */
};

static const char _dummy_firstx_usual[123] = {
	HASH_BEFORE_SMALL_A
	0,  /* 'a' */	// aaa, aad, aam, aas, adc, add, and, arpl
	0,  /* 'b' */	// bound, bsf, bsr, bswap, bt, btc, btr, bts
	0,  /* 'c' */	// call, cbw, cdq, clc, cld, cli, clts, cmc, cmp, [cmps, cmpsb, cmpsw, cmpsd], \
				cmpxchg, cpuid, cwd, cwde
	0,  /* 'd' */	// daa, das, dec, div
	0,  /* 'e' */
	0,  /* 'f' */	// float~ \
				f2xm1, fabs, fadd, faddp, fbld, fbstp, fchs, fclex, fcom, fcomp, fcmpp, fcomip, fcos, fdecstp, \
				fdiv, fdivp, fdivr, fdivrp, ffree, fiadd, ficom, ficmp, fidiv, fidivr, fild, fimul, fincstp, \
				finit, fist, fistp, fisub, fisubr, fld, fld1, fldcw, fldenv, fldl2e, fldl2t, fldlg2, fldln2, \
				fldpi, fldz, fmul, fmulp, fnop, fpatan, fprem, fprem1, fptan, frndint, frstor, fsave, fscale, \
				fsin, fsincos, fsqrt, fst, fstcw, fstenv, fstp, fstsw, fstsw, fsub, fsubp, fsubr, fsubrp, \
				ftst, fucom, fucomp, fucompp, fucomi, fucomip, fxam, fxch, fxtract, fyl2x, fyl2xp1, fwait
	0,  /* 'g' */
	0,  /* 'h' */
	0,  /* 'i' */	// idiv, imul, in, inc, ins, int, into, invb, invlpg, invpcid, iret, iretd
	0,  /* 'j' */	// jcc, jcxz, jecxz, jmp
	0,  /* 'k' */
	0,  /* 'l' */	// lahf, lar, lsd, lea, leave, les, lfs, lgdt, lgs, lidt, lldt, lmsw, lock, \
				[lods, lodsb, lodsw, lodsb], loop, loppz, loope, loopnz, loopne, lsl, lss, ltr
	0,  /* 'm' */	// mov, movbe, [movs, movsb, movsw, movsd], movsx, movzx, mul
	0,  /* 'n' */	// neg, nop
	0,  /* 'o' */	// or, out, outs
	0,  /* 'p' */	// pop,popa, popad, popf, popfd, push, pusha, pushad, pushf, pushfd
	0,  /* 'q' */
	0,  /* 'r' */	// rcl, rcr, rdmsr, rdpmc, rdtsc, rdtscp, rep {ins, lodx, movs, outs, stos, cmps, scas}, \
				repne {cmps, scas}, ret, ror, rsm
	0,  /* 's' */	// sahf, sal, sar, sbb, [scas, scasb, scasw, scasd], setcc, sgdt, shl, shld, \
				shr, shrd, sidt, sldt, smsw, stc, std, sti, [stos, stosb, stosw, stosd], str, sub, swapgs, syscall, sysret
	0,  /* 't' */	// test
	0,  /* 'u' */
	0,  /* 'v' */
	0,  /* 'w' */	// wait, wbinvb, wrmsr
	0,  /* 'x' */	// xadd, xchg, xlat, xlatb, xor
	0,  /* 'y' */
	0,  /* 'z' */
};