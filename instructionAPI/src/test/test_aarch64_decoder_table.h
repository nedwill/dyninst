struct aarch64_mask_entry;
struct aarch64_insn_entry;

typedef void (*operandFactory)();
//using operandFactory = void (*)();
typedef std::vector<operandFactory> operandSpec;
typedef std::vector<aarch64_insn_entry> aarch64_insn_table;
typedef std::map<unsigned int, unsigned int> branchMap;
typedef std::map<unsigned int, aarch64_mask_entry> aarch64_decoder_table;

typedef enum {
  aarch64_op_INVALID,
  aarch64_op_extended,
  aarch64_op_adc,
  aarch64_op_adcs,
  aarch64_op_add_addsub_ext,
  aarch64_op_add_addsub_imm,
  aarch64_op_add_addsub_shift,
  aarch64_op_adds_addsub_ext,
  aarch64_op_adds_addsub_imm,
  aarch64_op_adds_addsub_shift,
  aarch64_op_adr,
  aarch64_op_adrp,
  aarch64_op_and_log_imm,
  aarch64_op_and_log_shift,
  aarch64_op_ands_log_imm,
  aarch64_op_ands_log_shift,
  aarch64_op_asr_asrv,
  aarch64_op_asr_sbfm,
  aarch64_op_asrv,
  aarch64_op_at_sys,
  aarch64_op_b_cond,
  aarch64_op_b_uncond,
  aarch64_op_bfi_bfm,
  aarch64_op_bfm,
  aarch64_op_bfxil_bfm,
  aarch64_op_bic_log_shift,
  aarch64_op_bics,
  aarch64_op_bl,
  aarch64_op_blr,
  aarch64_op_br,
  aarch64_op_brk,
  aarch64_op_cbnz,
  aarch64_op_cbz,
  aarch64_op_ccmn_imm,
  aarch64_op_ccmn_reg,
  aarch64_op_ccmp_imm,
  aarch64_op_ccmp_reg,
  aarch64_op_cinc_csinc,
  aarch64_op_cinv_csinv,
  aarch64_op_clrex,
  aarch64_op_cls_int,
  aarch64_op_clz_int,
  aarch64_op_cmn_adds_addsub_ext,
  aarch64_op_cmn_adds_addsub_imm,
  aarch64_op_cmn_adds_addsub_shift,
  aarch64_op_cmp_subs_addsub_ext,
  aarch64_op_cmp_subs_addsub_imm,
  aarch64_op_cmp_subs_addsub_shift,
  aarch64_op_cneg_csneg,
  aarch64_op_crc32,
  aarch64_op_crc32c,
  aarch64_op_csel,
  aarch64_op_cset_csinc,
  aarch64_op_csetm_csinv,
  aarch64_op_csinc,
  aarch64_op_csinv,
  aarch64_op_csneg,
  aarch64_op_dc_sys,
  aarch64_op_dcps1,
  aarch64_op_dcps2,
  aarch64_op_dcps3,
  aarch64_op_dmb,
  aarch64_op_drps,
  aarch64_op_dsb,
  aarch64_op_eon,
  aarch64_op_eor_log_imm,
  aarch64_op_eor_log_shift,
  aarch64_op_eret,
  aarch64_op_extr,
  aarch64_op_hint,
  aarch64_op_hlt,
  aarch64_op_hvc,
  aarch64_op_ic_sys,
  aarch64_op_isb,
  aarch64_op_ldar,
  aarch64_op_ldarb,
  aarch64_op_ldarh,
  aarch64_op_ldaxp,
  aarch64_op_ldaxr,
  aarch64_op_ldaxrb,
  aarch64_op_ldaxrh,
  aarch64_op_ldnp_gen,
  aarch64_op_ldp_gen,
  aarch64_op_ldpsw,
  aarch64_op_ldr_imm_gen,
  aarch64_op_ldr_lit_gen,
  aarch64_op_ldr_reg_gen,
  aarch64_op_ldrb_imm,
  aarch64_op_ldrb_reg,
  aarch64_op_ldrh_imm,
  aarch64_op_ldrh_reg,
  aarch64_op_ldrsb_imm,
  aarch64_op_ldrsb_reg,
  aarch64_op_ldrsh_imm,
  aarch64_op_ldrsh_reg,
  aarch64_op_ldrsw_imm,
  aarch64_op_ldrsw_lit,
  aarch64_op_ldrsw_reg,
  aarch64_op_ldtr,
  aarch64_op_ldtrb,
  aarch64_op_ldtrh,
  aarch64_op_ldtrsb,
  aarch64_op_ldtrsh,
  aarch64_op_ldtrsw,
  aarch64_op_ldur_gen,
  aarch64_op_ldurb,
  aarch64_op_ldurh,
  aarch64_op_ldursb,
  aarch64_op_ldursh,
  aarch64_op_ldursw,
  aarch64_op_ldxp,
  aarch64_op_ldxr,
  aarch64_op_ldxrb,
  aarch64_op_ldxrh,
  aarch64_op_lsl_lslv,
  aarch64_op_lsl_ubfm,
  aarch64_op_lslv,
  aarch64_op_lsr_lsrv,
  aarch64_op_lsr_ubfm,
  aarch64_op_lsrv,
  aarch64_op_madd,
  aarch64_op_mneg_msub,
  aarch64_op_mov_add_addsub_imm,
  aarch64_op_mov_movn,
  aarch64_op_mov_movz,
  aarch64_op_mov_orr_log_imm,
  aarch64_op_mov_orr_log_shift,
  aarch64_op_movk,
  aarch64_op_movn,
  aarch64_op_movz,
  aarch64_op_mrs,
  aarch64_op_msr_imm,
  aarch64_op_msr_reg,
  aarch64_op_msub,
  aarch64_op_mul_madd,
  aarch64_op_mvn_orn_log_shift,
  aarch64_op_neg_sub_addsub_shift,
  aarch64_op_negs_subs_addsub_shift,
  aarch64_op_ngc_sbc,
  aarch64_op_ngcs_sbcs,
  aarch64_op_nop_hint,
  aarch64_op_orn_log_shift,
  aarch64_op_orr_log_imm,
  aarch64_op_orr_log_shift,
  aarch64_op_prfm_imm,
  aarch64_op_prfm_lit,
  aarch64_op_prfm_reg,
  aarch64_op_prfum,
  aarch64_op_rbit_int,
  aarch64_op_ret,
  aarch64_op_rev,
  aarch64_op_rev16_int,
  aarch64_op_rev32_int,
  aarch64_op_ror_extr,
  aarch64_op_ror_rorv,
  aarch64_op_rorv,
  aarch64_op_sbc,
  aarch64_op_sbcs,
  aarch64_op_sbfiz_sbfm,
  aarch64_op_sbfm,
  aarch64_op_sbfx_sbfm,
  aarch64_op_sdiv,
  aarch64_op_sev_hint,
  aarch64_op_sevl_hint,
  aarch64_op_smaddl,
  aarch64_op_smc,
  aarch64_op_smnegl_smsubl,
  aarch64_op_smsubl,
  aarch64_op_smulh,
  aarch64_op_smull_smaddl,
  aarch64_op_stlr,
  aarch64_op_stlrb,
  aarch64_op_stlrh,
  aarch64_op_stlxp,
  aarch64_op_stlxr,
  aarch64_op_stlxrb,
  aarch64_op_stlxrh,
  aarch64_op_stnp_gen,
  aarch64_op_stp_gen,
  aarch64_op_str_imm_gen,
  aarch64_op_str_reg_gen,
  aarch64_op_strb_imm,
  aarch64_op_strb_reg,
  aarch64_op_strh_imm,
  aarch64_op_strh_reg,
  aarch64_op_sttr,
  aarch64_op_sttrb,
  aarch64_op_sttrh,
  aarch64_op_stur_gen,
  aarch64_op_sturb,
  aarch64_op_sturh,
  aarch64_op_stxp,
  aarch64_op_stxr,
  aarch64_op_stxrb,
  aarch64_op_stxrh,
  aarch64_op_sub_addsub_ext,
  aarch64_op_sub_addsub_imm,
  aarch64_op_sub_addsub_shift,
  aarch64_op_subs_addsub_ext,
  aarch64_op_subs_addsub_imm,
  aarch64_op_subs_addsub_shift,
  aarch64_op_svc,
  aarch64_op_sxtb_sbfm,
  aarch64_op_sxth_sbfm,
  aarch64_op_sxtw_sbfm,
  aarch64_op_sys,
  aarch64_op_sysl,
  aarch64_op_tbnz,
  aarch64_op_tbz,
  aarch64_op_tlbi_sys,
  aarch64_op_tst_ands_log_imm,
  aarch64_op_tst_ands_log_shift,
  aarch64_op_ubfiz_ubfm,
  aarch64_op_ubfm,
  aarch64_op_ubfx_ubfm,
  aarch64_op_udiv,
  aarch64_op_umaddl,
  aarch64_op_umnegl_umsubl,
  aarch64_op_umsubl,
  aarch64_op_umulh,
  aarch64_op_umull_umaddl,
  aarch64_op_unallocated,
  aarch64_op_uxtb_ubfm,
  aarch64_op_uxth_ubfm,
  aarch64_op_wfe_hint,
  aarch64_op_wfi_hint,
  aarch64_op_yield_hint,
} entryID;

struct aarch64_insn_entry
{
	aarch64_insn_entry(entryID o, const char* m, operandSpec ops):
	op(o), mnemonic(m), operands(ops)
	{
	}

	aarch64_insn_entry():
	op(aarch64_op_INVALID), mnemonic("INVALID")
	{
		// TODO: why 5?
		// TODO: Is this needed here?
		operands.reserve(5);
	}

	aarch64_insn_entry(const aarch64_insn_entry& o) :
	op(o.op), mnemonic(o.mnemonic), operands(o.operands)
	{
	}

	const aarch64_insn_entry& operator=(const aarch64_insn_entry& rhs)
	{
		operands.reserve(rhs.operands.size());
		op = rhs.op;
		mnemonic = rhs.mnemonic;
		operands = rhs.operands;

		return *this;
	}

	entryID op;
	const char* mnemonic;
	operandSpec operands;

	static void buildInsnTable();
	static bool built_insn_table;

	static aarch64_insn_table main_insn_table;
};

struct aarch64_mask_entry
{
	aarch64_mask_entry(unsigned int m, branchMap bm, int tabIndex):
	mask(m), nodeBranches(bm), insnTableIndex(tabIndex)
	{
	}

	aarch64_mask_entry():
	mask(0), nodeBranches(branchMap()), insnTableIndex(-1)
	{
	}

	aarch64_mask_entry(const aarch64_mask_entry& e):
	mask(e.mask), nodeBranches(e.nodeBranches), insnTableIndex(e.insnTableIndex)
	{
	}

	const aarch64_mask_entry& operator=(const aarch64_mask_entry& rhs)
	{
		mask = rhs.mask;
		nodeBranches = rhs.nodeBranches;
		insnTableIndex = rhs.insnTableIndex;

		return *this;
	}

	unsigned int mask;
	branchMap nodeBranches;
	int insnTableIndex;

	static void buildDecoderTable();
	static bool built_decoder_table;
	static aarch64_decoder_table main_decoder_table;
};

aarch64_decoder_table aarch64_mask_entry::main_decoder_table;
aarch64_insn_table aarch64_insn_entry::main_insn_table;

void Rt(){ }
void op1(){ }
void op2(){ }
void Rs(){ }
void imm26(){ }
void Rd(){ }
void b5(){ }
void immhi(){ }
void cond(){ }
void Ra(){ }
void Rm(){ }
void Rn(){ }
void b40(){ }
void Rt2(){ }
void imms(){ }
void immr(){ }
void CRn(){ }
void CRm(){ }
void imm12(){ }
void option(){ }
void imm16(){ }
void imm19(){ }
void immlo(){ }
void hw(){ }
void N(){ }
void S(){ }
void imm14(){ }
void sz(){ }
void shift(){ }
void nzcv(){ }
void imm9(){ }
void imm3(){ }
void o0(){ }
void imm5(){ }
void sf(){ }
void imm7(){ }
void imm6(){ }


void aarch64_mask_entry::buildDecoderTable()
{
	main_decoder_table[0]=aarch64_mask_entry(0x18000000, map_list_of(0,1)(1,2)(2,3)(3,4),-1);
	main_decoder_table[1]=aarch64_mask_entry(0x0, branchMap(),0);
	main_decoder_table[2]=aarch64_mask_entry(0x27000000, map_list_of(0,5)(2,6)(3,7)(8,8)(9,9)(10,10)(11,11),-1);
	main_decoder_table[5]=aarch64_mask_entry(0x80e08000, map_list_of(0,12)(1,13)(4,14)(5,15)(9,16)(13,17)(16,18)(17,19)(18,20)(19,21)(20,22)(21,23)(22,24)(23,25)(25,26)(29,27),-1);
	main_decoder_table[12]=aarch64_mask_entry(0x40000000, map_list_of(0,28)(1,29),-1);
	main_decoder_table[28]=aarch64_mask_entry(0x0, branchMap(),216);
	main_decoder_table[29]=aarch64_mask_entry(0x0, branchMap(),217);
	main_decoder_table[13]=aarch64_mask_entry(0x40000000, map_list_of(0,30)(1,31),-1);
	main_decoder_table[30]=aarch64_mask_entry(0x0, branchMap(),190);
	main_decoder_table[31]=aarch64_mask_entry(0x0, branchMap(),191);
	main_decoder_table[14]=aarch64_mask_entry(0x40000000, map_list_of(0,32)(1,33),-1);
	main_decoder_table[32]=aarch64_mask_entry(0x0, branchMap(),127);
	main_decoder_table[33]=aarch64_mask_entry(0x0, branchMap(),128);
	main_decoder_table[15]=aarch64_mask_entry(0x40000000, map_list_of(0,34)(1,35),-1);
	main_decoder_table[34]=aarch64_mask_entry(0x0, branchMap(),78);
	main_decoder_table[35]=aarch64_mask_entry(0x0, branchMap(),79);
	main_decoder_table[16]=aarch64_mask_entry(0x40000000, map_list_of(0,36)(1,37),-1);
	main_decoder_table[36]=aarch64_mask_entry(0x0, branchMap(),186);
	main_decoder_table[37]=aarch64_mask_entry(0x0, branchMap(),187);
	main_decoder_table[17]=aarch64_mask_entry(0x40000000, map_list_of(0,38)(1,39),-1);
	main_decoder_table[38]=aarch64_mask_entry(0x0, branchMap(),74);
	main_decoder_table[39]=aarch64_mask_entry(0x0, branchMap(),75);
	main_decoder_table[18]=aarch64_mask_entry(0x0, branchMap(),215);
	main_decoder_table[19]=aarch64_mask_entry(0x0, branchMap(),189);
	main_decoder_table[20]=aarch64_mask_entry(0x0, branchMap(),214);
	main_decoder_table[21]=aarch64_mask_entry(0x0, branchMap(),188);
	main_decoder_table[22]=aarch64_mask_entry(0x0, branchMap(),126);
	main_decoder_table[23]=aarch64_mask_entry(0x0, branchMap(),77);
	main_decoder_table[24]=aarch64_mask_entry(0x0, branchMap(),125);
	main_decoder_table[25]=aarch64_mask_entry(0x0, branchMap(),76);
	main_decoder_table[26]=aarch64_mask_entry(0x0, branchMap(),185);
	main_decoder_table[27]=aarch64_mask_entry(0x0, branchMap(),73);
	main_decoder_table[6]=aarch64_mask_entry(0x40200000, map_list_of(0,40)(1,41)(2,42)(3,43),-1);
	main_decoder_table[40]=aarch64_mask_entry(0x0, branchMap(),12);
	main_decoder_table[41]=aarch64_mask_entry(0x0, branchMap(),24);
	main_decoder_table[42]=aarch64_mask_entry(0x0, branchMap(),65);
	main_decoder_table[43]=aarch64_mask_entry(0x0, branchMap(),63);
	main_decoder_table[7]=aarch64_mask_entry(0x40200000, map_list_of(0,44)(1,45)(2,46)(3,47),-1);
	main_decoder_table[44]=aarch64_mask_entry(0x0, branchMap(),5);
	main_decoder_table[45]=aarch64_mask_entry(0x0, branchMap(),3);
	main_decoder_table[46]=aarch64_mask_entry(0x0, branchMap(),151);
	main_decoder_table[47]=aarch64_mask_entry(0x0, branchMap(),218);
	main_decoder_table[8]=aarch64_mask_entry(0x40c00000, map_list_of(0,48)(1,49)(2,50)(3,51)(7,52),-1);
	main_decoder_table[48]=aarch64_mask_entry(0x0, branchMap(),192);
	main_decoder_table[49]=aarch64_mask_entry(0x0, branchMap(),80);
	main_decoder_table[50]=aarch64_mask_entry(0x0, branchMap(),193);
	main_decoder_table[51]=aarch64_mask_entry(0x0, branchMap(),81);
	main_decoder_table[52]=aarch64_mask_entry(0x0, branchMap(),84);
	main_decoder_table[9]=aarch64_mask_entry(0x40c00000, map_list_of(0,53)(1,54)(2,55)(3,56)(5,57)(7,58),-1);
	main_decoder_table[53]=aarch64_mask_entry(0x0, branchMap(),195);
	main_decoder_table[54]=aarch64_mask_entry(0x0, branchMap(),83);
	main_decoder_table[55]=aarch64_mask_entry(0x0, branchMap(),194);
	main_decoder_table[56]=aarch64_mask_entry(0x0, branchMap(),82);
	main_decoder_table[57]=aarch64_mask_entry(0x0, branchMap(),86);
	main_decoder_table[58]=aarch64_mask_entry(0x0, branchMap(),85);
	main_decoder_table[10]=aarch64_mask_entry(0x40200000, map_list_of(0,59)(1,60)(2,61)(3,62),-1);
	main_decoder_table[59]=aarch64_mask_entry(0x0, branchMap(),141);
	main_decoder_table[60]=aarch64_mask_entry(0x0, branchMap(),150);
	main_decoder_table[61]=aarch64_mask_entry(0x0, branchMap(),14);
	main_decoder_table[62]=aarch64_mask_entry(0x0, branchMap(),25);
	main_decoder_table[11]=aarch64_mask_entry(0x40200000, map_list_of(0,63)(1,64)(2,65)(3,66),-1);
	main_decoder_table[63]=aarch64_mask_entry(0x0, branchMap(),8);
	main_decoder_table[64]=aarch64_mask_entry(0xc00000, map_list_of(0,67),-1);
	main_decoder_table[67]=aarch64_mask_entry(0x0, branchMap(),6);
	main_decoder_table[65]=aarch64_mask_entry(0x0, branchMap(),46);
	main_decoder_table[66]=aarch64_mask_entry(0xc00000, map_list_of(0,68),-1);
	main_decoder_table[68]=aarch64_mask_entry(0x0, branchMap(),44);
	main_decoder_table[3]=aarch64_mask_entry(0x4000000, map_list_of(0,69)(1,70),-1);
	main_decoder_table[69]=aarch64_mask_entry(0x3000000, map_list_of(0,71)(1,72)(2,73)(3,74),-1);
	main_decoder_table[71]=aarch64_mask_entry(0x80000000, map_list_of(0,75)(1,76),-1);
	main_decoder_table[75]=aarch64_mask_entry(0x0, branchMap(),9);
	main_decoder_table[76]=aarch64_mask_entry(0x0, branchMap(),10);
	main_decoder_table[72]=aarch64_mask_entry(0x60000000, map_list_of(0,77)(1,78)(2,79)(3,80),-1);
	main_decoder_table[77]=aarch64_mask_entry(0x0, branchMap(),4);
	main_decoder_table[78]=aarch64_mask_entry(0x0, branchMap(),7);
	main_decoder_table[79]=aarch64_mask_entry(0x0, branchMap(),219);
	main_decoder_table[80]=aarch64_mask_entry(0x0, branchMap(),45);
	main_decoder_table[73]=aarch64_mask_entry(0x60800000, map_list_of(0,81)(1,82)(2,83)(4,84)(5,85)(6,86)(7,87),-1);
	main_decoder_table[81]=aarch64_mask_entry(0x0, branchMap(),11);
	main_decoder_table[82]=aarch64_mask_entry(0x0, branchMap(),138);
	main_decoder_table[83]=aarch64_mask_entry(0x0, branchMap(),140);
	main_decoder_table[84]=aarch64_mask_entry(0x0, branchMap(),64);
	main_decoder_table[85]=aarch64_mask_entry(0x0, branchMap(),139);
	main_decoder_table[86]=aarch64_mask_entry(0x0, branchMap(),13);
	main_decoder_table[87]=aarch64_mask_entry(0x0, branchMap(),142);
	main_decoder_table[74]=aarch64_mask_entry(0x60800000, map_list_of(0,88)(1,89)(2,90)(4,91),-1);
	main_decoder_table[88]=aarch64_mask_entry(0x0, branchMap(),16);
	main_decoder_table[89]=aarch64_mask_entry(0x200000, map_list_of(0,92),-1);
	main_decoder_table[92]=aarch64_mask_entry(0x0, branchMap(),67);
	main_decoder_table[90]=aarch64_mask_entry(0x0, branchMap(),21);
	main_decoder_table[91]=aarch64_mask_entry(0x0, branchMap(),130);
	main_decoder_table[70]=aarch64_mask_entry(0x60000000, map_list_of(0,93)(1,94)(2,95),-1);
	main_decoder_table[93]=aarch64_mask_entry(0x80000000, map_list_of(0,96)(1,97),-1);
	main_decoder_table[96]=aarch64_mask_entry(0x0, branchMap(),20);
	main_decoder_table[97]=aarch64_mask_entry(0x0, branchMap(),26);
	main_decoder_table[94]=aarch64_mask_entry(0x3000000, map_list_of(0,98)(1,99)(2,100)(3,101),-1);
	main_decoder_table[98]=aarch64_mask_entry(0x0, branchMap(),31);
	main_decoder_table[99]=aarch64_mask_entry(0x0, branchMap(),30);
	main_decoder_table[100]=aarch64_mask_entry(0x0, branchMap(),231);
	main_decoder_table[101]=aarch64_mask_entry(0x0, branchMap(),230);
	main_decoder_table[95]=aarch64_mask_entry(0x83000000, map_list_of(0,102)(4,103)(5,104)(6,105),-1);
	main_decoder_table[102]=aarch64_mask_entry(0x0, branchMap(),19);
	main_decoder_table[103]=aarch64_mask_entry(0xe0001f, map_list_of(1,106)(2,107)(3,108)(32,109)(64,110)(161,111)(162,112)(163,113),-1);
	main_decoder_table[106]=aarch64_mask_entry(0x0, branchMap(),224);
	main_decoder_table[107]=aarch64_mask_entry(0x0, branchMap(),70);
	main_decoder_table[108]=aarch64_mask_entry(0x0, branchMap(),180);
	main_decoder_table[109]=aarch64_mask_entry(0x0, branchMap(),29);
	main_decoder_table[110]=aarch64_mask_entry(0x0, branchMap(),69);
	main_decoder_table[111]=aarch64_mask_entry(0x0, branchMap(),57);
	main_decoder_table[112]=aarch64_mask_entry(0x0, branchMap(),58);
	main_decoder_table[113]=aarch64_mask_entry(0x0, branchMap(),59);
	main_decoder_table[104]=aarch64_mask_entry(0xf00000, map_list_of(0,114)(1,115)(2,116)(3,117),-1);
	main_decoder_table[114]=aarch64_mask_entry(0x80000, map_list_of(0,118)(1,119),-1);
	main_decoder_table[118]=aarch64_mask_entry(0xf01f, map_list_of(95,120)(127,121)(159,122),-1);
	main_decoder_table[120]=aarch64_mask_entry(0x70000, map_list_of(3,123),-1);
	main_decoder_table[123]=aarch64_mask_entry(0x0, branchMap(),68);
	main_decoder_table[121]=aarch64_mask_entry(0x700e0, map_list_of(26,124)(28,125)(29,126)(30,127),-1);
	main_decoder_table[124]=aarch64_mask_entry(0x0, branchMap(),38);
	main_decoder_table[125]=aarch64_mask_entry(0x0, branchMap(),62);
	main_decoder_table[126]=aarch64_mask_entry(0x0, branchMap(),60);
	main_decoder_table[127]=aarch64_mask_entry(0x0, branchMap(),72);
	main_decoder_table[122]=aarch64_mask_entry(0x0, branchMap(),146);
	main_decoder_table[119]=aarch64_mask_entry(0x0, branchMap(),18);
	main_decoder_table[115]=aarch64_mask_entry(0x0, branchMap(),147);
	main_decoder_table[116]=aarch64_mask_entry(0x0, branchMap(),229);
	main_decoder_table[117]=aarch64_mask_entry(0x0, branchMap(),145);
	main_decoder_table[105]=aarch64_mask_entry(0xfffc1f, map_list_of(63488,128)(129024,129)(194560,130)(325632,131)(391168,132),-1);
	main_decoder_table[128]=aarch64_mask_entry(0x0, branchMap(),28);
	main_decoder_table[129]=aarch64_mask_entry(0x0, branchMap(),27);
	main_decoder_table[130]=aarch64_mask_entry(0x0, branchMap(),164);
	main_decoder_table[131]=aarch64_mask_entry(0x0, branchMap(),66);
	main_decoder_table[132]=aarch64_mask_entry(0x0, branchMap(),61);
	main_decoder_table[4]=aarch64_mask_entry(0x27000000, map_list_of(0,133)(2,134)(3,135)(8,136)(9,137)(10,138),-1);
	main_decoder_table[133]=aarch64_mask_entry(0x80000000, map_list_of(0,139)(1,140),-1);
	main_decoder_table[139]=aarch64_mask_entry(0x0, branchMap(),90);
	main_decoder_table[140]=aarch64_mask_entry(0x40000000, map_list_of(0,141)(1,142),-1);
	main_decoder_table[141]=aarch64_mask_entry(0x0, branchMap(),111);
	main_decoder_table[142]=aarch64_mask_entry(0x0, branchMap(),160);
	main_decoder_table[134]=aarch64_mask_entry(0x40e00000, map_list_of(0,143)(4,144)(6,145)(8,146)(12,147)(14,148),-1);
	main_decoder_table[143]=aarch64_mask_entry(0x0, branchMap(),1);
	main_decoder_table[144]=aarch64_mask_entry(0xc00, map_list_of(0,149)(1,150),-1);
	main_decoder_table[149]=aarch64_mask_entry(0x0, branchMap(),50);
	main_decoder_table[150]=aarch64_mask_entry(0x0, branchMap(),36);
	main_decoder_table[145]=aarch64_mask_entry(0xf000, map_list_of(0,151)(2,152)(4,153)(5,154),-1);
	main_decoder_table[151]=aarch64_mask_entry(0xc00, map_list_of(2,155)(3,156),-1);
	main_decoder_table[155]=aarch64_mask_entry(0x0, branchMap(),238);
	main_decoder_table[156]=aarch64_mask_entry(0x0, branchMap(),176);
	main_decoder_table[152]=aarch64_mask_entry(0xc00, map_list_of(0,157)(1,158)(2,159)(3,160),-1);
	main_decoder_table[157]=aarch64_mask_entry(0x0, branchMap(),129);
	main_decoder_table[158]=aarch64_mask_entry(0x0, branchMap(),132);
	main_decoder_table[159]=aarch64_mask_entry(0x0, branchMap(),15);
	main_decoder_table[160]=aarch64_mask_entry(0x0, branchMap(),169);
	main_decoder_table[153]=aarch64_mask_entry(0x0, branchMap(),48);
	main_decoder_table[154]=aarch64_mask_entry(0x0, branchMap(),49);
	main_decoder_table[146]=aarch64_mask_entry(0xfc00, map_list_of(0,161),-1);
	main_decoder_table[161]=aarch64_mask_entry(0x0, branchMap(),153);
	main_decoder_table[147]=aarch64_mask_entry(0xc00, map_list_of(0,162)(1,163),-1);
	main_decoder_table[162]=aarch64_mask_entry(0x0, branchMap(),37);
	main_decoder_table[163]=aarch64_mask_entry(0x0, branchMap(),47);
	main_decoder_table[148]=aarch64_mask_entry(0x1ff800, map_list_of(0,164)(1,165)(2,166),-1);
	main_decoder_table[164]=aarch64_mask_entry(0x400, map_list_of(0,167)(1,168),-1);
	main_decoder_table[167]=aarch64_mask_entry(0x0, branchMap(),163);
	main_decoder_table[168]=aarch64_mask_entry(0x0, branchMap(),166);
	main_decoder_table[165]=aarch64_mask_entry(0x0, branchMap(),165);
	main_decoder_table[166]=aarch64_mask_entry(0x400, map_list_of(0,169)(1,170),-1);
	main_decoder_table[169]=aarch64_mask_entry(0x0, branchMap(),40);
	main_decoder_table[170]=aarch64_mask_entry(0x0, branchMap(),39);
	main_decoder_table[135]=aarch64_mask_entry(0x40e08000, map_list_of(0,171)(1,172)(2,173)(3,174)(4,175)(10,176)(11,177)(12,178),-1);
	main_decoder_table[171]=aarch64_mask_entry(0x0, branchMap(),135);
	main_decoder_table[172]=aarch64_mask_entry(0x0, branchMap(),136);
	main_decoder_table[173]=aarch64_mask_entry(0x80000000, map_list_of(1,179),-1);
	main_decoder_table[179]=aarch64_mask_entry(0x0, branchMap(),179);
	main_decoder_table[174]=aarch64_mask_entry(0x80000000, map_list_of(1,180),-1);
	main_decoder_table[180]=aarch64_mask_entry(0x0, branchMap(),181);
	main_decoder_table[175]=aarch64_mask_entry(0x0, branchMap(),183);
	main_decoder_table[176]=aarch64_mask_entry(0x80000000, map_list_of(1,181),-1);
	main_decoder_table[181]=aarch64_mask_entry(0x0, branchMap(),239);
	main_decoder_table[177]=aarch64_mask_entry(0x80000000, map_list_of(1,182),-1);
	main_decoder_table[182]=aarch64_mask_entry(0x0, branchMap(),240);
	main_decoder_table[178]=aarch64_mask_entry(0x0, branchMap(),242);
	main_decoder_table[136]=aarch64_mask_entry(0x80a00c00, map_list_of(0,183)(1,184)(2,185)(3,186)(6,187)(8,188)(9,189)(10,190)(11,191)(14,192)(16,193)(17,194)(18,195)(19,196)(22,197)(24,198)(25,199)(26,200)(27,201)(30,202),-1);
	main_decoder_table[183]=aarch64_mask_entry(0x40400000, map_list_of(0,203)(1,204)(2,205)(3,206),-1);
	main_decoder_table[203]=aarch64_mask_entry(0x0, branchMap(),212);
	main_decoder_table[204]=aarch64_mask_entry(0x0, branchMap(),120);
	main_decoder_table[205]=aarch64_mask_entry(0x0, branchMap(),213);
	main_decoder_table[206]=aarch64_mask_entry(0x0, branchMap(),121);
	main_decoder_table[184]=aarch64_mask_entry(0x40400000, map_list_of(0,207)(1,208)(2,209)(3,210),-1);
	main_decoder_table[207]=aarch64_mask_entry(0x0, branchMap(),200);
	main_decoder_table[208]=aarch64_mask_entry(0x0, branchMap(),92);
	main_decoder_table[209]=aarch64_mask_entry(0x0, branchMap(),204);
	main_decoder_table[210]=aarch64_mask_entry(0x0, branchMap(),96);
	main_decoder_table[185]=aarch64_mask_entry(0x40400000, map_list_of(0,211)(1,212)(2,213)(3,214),-1);
	main_decoder_table[211]=aarch64_mask_entry(0x0, branchMap(),209);
	main_decoder_table[212]=aarch64_mask_entry(0x0, branchMap(),114);
	main_decoder_table[213]=aarch64_mask_entry(0x0, branchMap(),210);
	main_decoder_table[214]=aarch64_mask_entry(0x0, branchMap(),115);
	main_decoder_table[186]=aarch64_mask_entry(0x40400000, map_list_of(0,215)(1,216)(2,217)(3,218),-1);
	main_decoder_table[215]=aarch64_mask_entry(0x0, branchMap(),201);
	main_decoder_table[216]=aarch64_mask_entry(0x0, branchMap(),93);
	main_decoder_table[217]=aarch64_mask_entry(0x0, branchMap(),205);
	main_decoder_table[218]=aarch64_mask_entry(0x0, branchMap(),97);
	main_decoder_table[187]=aarch64_mask_entry(0x40400000, map_list_of(0,219)(1,220)(2,221)(3,222),-1);
	main_decoder_table[219]=aarch64_mask_entry(0x0, branchMap(),203);
	main_decoder_table[220]=aarch64_mask_entry(0x0, branchMap(),95);
	main_decoder_table[221]=aarch64_mask_entry(0x0, branchMap(),207);
	main_decoder_table[222]=aarch64_mask_entry(0x0, branchMap(),99);
	main_decoder_table[188]=aarch64_mask_entry(0x40000000, map_list_of(0,223)(1,224),-1);
	main_decoder_table[223]=aarch64_mask_entry(0x0, branchMap(),122);
	main_decoder_table[224]=aarch64_mask_entry(0x0, branchMap(),123);
	main_decoder_table[189]=aarch64_mask_entry(0x40000000, map_list_of(0,225)(1,226),-1);
	main_decoder_table[225]=aarch64_mask_entry(0x0, branchMap(),100);
	main_decoder_table[226]=aarch64_mask_entry(0x0, branchMap(),104);
	main_decoder_table[190]=aarch64_mask_entry(0x40000000, map_list_of(0,227)(1,228),-1);
	main_decoder_table[227]=aarch64_mask_entry(0x0, branchMap(),116);
	main_decoder_table[228]=aarch64_mask_entry(0x0, branchMap(),117);
	main_decoder_table[191]=aarch64_mask_entry(0x40000000, map_list_of(0,229)(1,230),-1);
	main_decoder_table[229]=aarch64_mask_entry(0x0, branchMap(),101);
	main_decoder_table[230]=aarch64_mask_entry(0x0, branchMap(),105);
	main_decoder_table[192]=aarch64_mask_entry(0x40000000, map_list_of(0,231)(1,232),-1);
	main_decoder_table[231]=aarch64_mask_entry(0x0, branchMap(),103);
	main_decoder_table[232]=aarch64_mask_entry(0x0, branchMap(),107);
	main_decoder_table[193]=aarch64_mask_entry(0x400000, map_list_of(0,233)(1,234),-1);
	main_decoder_table[233]=aarch64_mask_entry(0x0, branchMap(),211);
	main_decoder_table[234]=aarch64_mask_entry(0x0, branchMap(),119);
	main_decoder_table[194]=aarch64_mask_entry(0x400000, map_list_of(0,235)(1,236),-1);
	main_decoder_table[235]=aarch64_mask_entry(0x0, branchMap(),196);
	main_decoder_table[236]=aarch64_mask_entry(0x0, branchMap(),87);
	main_decoder_table[195]=aarch64_mask_entry(0x400000, map_list_of(0,237)(1,238),-1);
	main_decoder_table[237]=aarch64_mask_entry(0x0, branchMap(),208);
	main_decoder_table[238]=aarch64_mask_entry(0x0, branchMap(),113);
	main_decoder_table[196]=aarch64_mask_entry(0x400000, map_list_of(0,239)(1,240),-1);
	main_decoder_table[239]=aarch64_mask_entry(0x0, branchMap(),197);
	main_decoder_table[240]=aarch64_mask_entry(0x0, branchMap(),88);
	main_decoder_table[197]=aarch64_mask_entry(0x400000, map_list_of(0,241)(1,242),-1);
	main_decoder_table[241]=aarch64_mask_entry(0x0, branchMap(),199);
	main_decoder_table[242]=aarch64_mask_entry(0x0, branchMap(),91);
	main_decoder_table[198]=aarch64_mask_entry(0x40400000, map_list_of(0,243)(2,244),-1);
	main_decoder_table[243]=aarch64_mask_entry(0x0, branchMap(),124);
	main_decoder_table[244]=aarch64_mask_entry(0x0, branchMap(),162);
	main_decoder_table[199]=aarch64_mask_entry(0x0, branchMap(),108);
	main_decoder_table[200]=aarch64_mask_entry(0x0, branchMap(),118);
	main_decoder_table[201]=aarch64_mask_entry(0x0, branchMap(),109);
	main_decoder_table[202]=aarch64_mask_entry(0x40400000, map_list_of(0,245)(2,246),-1);
	main_decoder_table[245]=aarch64_mask_entry(0x0, branchMap(),112);
	main_decoder_table[246]=aarch64_mask_entry(0x0, branchMap(),161);
	main_decoder_table[137]=aarch64_mask_entry(0x80800000, map_list_of(0,247)(1,248)(2,249)(3,250),-1);
	main_decoder_table[247]=aarch64_mask_entry(0x40400000, map_list_of(0,251)(1,252)(2,253)(3,254),-1);
	main_decoder_table[251]=aarch64_mask_entry(0x0, branchMap(),202);
	main_decoder_table[252]=aarch64_mask_entry(0x0, branchMap(),94);
	main_decoder_table[253]=aarch64_mask_entry(0x0, branchMap(),206);
	main_decoder_table[254]=aarch64_mask_entry(0x0, branchMap(),98);
	main_decoder_table[248]=aarch64_mask_entry(0x40000000, map_list_of(0,255)(1,256),-1);
	main_decoder_table[255]=aarch64_mask_entry(0x0, branchMap(),102);
	main_decoder_table[256]=aarch64_mask_entry(0x0, branchMap(),106);
	main_decoder_table[249]=aarch64_mask_entry(0x400000, map_list_of(0,257)(1,258),-1);
	main_decoder_table[257]=aarch64_mask_entry(0x0, branchMap(),198);
	main_decoder_table[258]=aarch64_mask_entry(0x0, branchMap(),89);
	main_decoder_table[250]=aarch64_mask_entry(0x40400000, map_list_of(0,259)(2,260),-1);
	main_decoder_table[259]=aarch64_mask_entry(0x0, branchMap(),110);
	main_decoder_table[260]=aarch64_mask_entry(0x0, branchMap(),159);
	main_decoder_table[138]=aarch64_mask_entry(0x40e00c00, map_list_of(0,261)(8,262)(10,263)(32,264)(40,265)(42,266),-1);
	main_decoder_table[261]=aarch64_mask_entry(0x0, branchMap(),2);
	main_decoder_table[262]=aarch64_mask_entry(0x0, branchMap(),33);
	main_decoder_table[263]=aarch64_mask_entry(0x0, branchMap(),32);
	main_decoder_table[264]=aarch64_mask_entry(0xf000, map_list_of(0,267),-1);
	main_decoder_table[267]=aarch64_mask_entry(0x0, branchMap(),154);
	main_decoder_table[265]=aarch64_mask_entry(0x0, branchMap(),35);
	main_decoder_table[266]=aarch64_mask_entry(0x0, branchMap(),34);
}

void aarch64_insn_entry::buildInsnTable()
{
    /*
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_adc, 	"adc"	,list_of(Rd)(Rm) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_adcs, 	"adcs"	,operandSpec() ));
    */
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_unallocated, 	"unallocated"	,operandSpec() ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_adc, 	"adc"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_adcs, 	"adcs"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_add_addsub_ext, 	"add"	,list_of(sf)(Rm)(option)(imm3)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_add_addsub_imm, 	"add"	,list_of(sf)(shift)(imm12)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_add_addsub_shift, 	"add"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_adds_addsub_ext, 	"adds"	,list_of(sf)(Rm)(option)(imm3)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_adds_addsub_imm, 	"adds"	,list_of(sf)(shift)(imm12)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_adds_addsub_shift, 	"adds"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_adr, 	"adr"	,list_of(immlo)(immhi)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_adrp, 	"adrp"	,list_of(immlo)(immhi)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_and_log_imm, 	"and"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_and_log_shift, 	"and"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ands_log_imm, 	"ands"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ands_log_shift, 	"ands"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_asr_asrv, 	"asr"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_asr_sbfm, 	"asr"	,list_of(sf)(N)(immr)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_asrv, 	"asrv"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_at_sys, 	"at"	,list_of(op1)(op2)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_b_cond, 	"b"	,list_of(imm19)(cond) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_b_uncond, 	"b"	,list_of(imm26) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_bfi_bfm, 	"bfi"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_bfm, 	"bfm"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_bfxil_bfm, 	"bfxil"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_bic_log_shift, 	"bic"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_bics, 	"bics"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_bl, 	"bl"	,list_of(imm26) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_blr, 	"blr"	,list_of(Rn) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_br, 	"br"	,list_of(Rn) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_brk, 	"brk"	,list_of(imm16) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cbnz, 	"cbnz"	,list_of(sf)(imm19)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cbz, 	"cbz"	,list_of(sf)(imm19)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ccmn_imm, 	"ccmn"	,list_of(sf)(imm5)(cond)(Rn)(nzcv) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ccmn_reg, 	"ccmn"	,list_of(sf)(Rm)(cond)(Rn)(nzcv) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ccmp_imm, 	"ccmp"	,list_of(sf)(imm5)(cond)(Rn)(nzcv) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ccmp_reg, 	"ccmp"	,list_of(sf)(Rm)(cond)(Rn)(nzcv) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cinc_csinc, 	"cinc"	,list_of(sf)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cinv_csinv, 	"cinv"	,list_of(sf)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_clrex, 	"clrex"	,list_of(CRm) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cls_int, 	"cls"	,list_of(sf)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_clz_int, 	"clz"	,list_of(sf)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cmn_adds_addsub_ext, 	"cmn"	,list_of(sf)(Rm)(option)(imm3)(Rn) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cmn_adds_addsub_imm, 	"cmn"	,list_of(sf)(shift)(imm12)(Rn) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cmn_adds_addsub_shift, 	"cmn"	,list_of(sf)(shift)(Rm)(imm6)(Rn) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cmp_subs_addsub_ext, 	"cmp"	,list_of(sf)(Rm)(option)(imm3)(Rn) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cmp_subs_addsub_imm, 	"cmp"	,list_of(sf)(shift)(imm12)(Rn) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cmp_subs_addsub_shift, 	"cmp"	,list_of(sf)(shift)(Rm)(imm6)(Rn) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cneg_csneg, 	"cneg"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_crc32, 	"crc32"	,list_of(sf)(Rm)(sz)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_crc32c, 	"crc32c"	,list_of(sf)(Rm)(sz)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_csel, 	"csel"	,list_of(sf)(Rm)(cond)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_cset_csinc, 	"cset"	,list_of(sf)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_csetm_csinv, 	"csetm"	,list_of(sf)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_csinc, 	"csinc"	,list_of(sf)(Rm)(cond)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_csinv, 	"csinv"	,list_of(sf)(Rm)(cond)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_csneg, 	"csneg"	,list_of(sf)(Rm)(cond)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_dc_sys, 	"dc"	,list_of(op1)(CRm)(op2)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_dcps1, 	"dcps1"	,list_of(imm16) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_dcps2, 	"dcps2"	,list_of(imm16) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_dcps3, 	"dcps3"	,list_of(imm16) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_dmb, 	"dmb"	,list_of(CRm) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_drps, 	"drps"	,operandSpec() ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_dsb, 	"dsb"	,list_of(CRm) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_eon, 	"eon"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_eor_log_imm, 	"eor"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_eor_log_shift, 	"eor"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_eret, 	"eret"	,operandSpec() ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_extr, 	"extr"	,list_of(sf)(N)(Rm)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_hint, 	"hint"	,list_of(CRm)(op2) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_hlt, 	"hlt"	,list_of(imm16) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_hvc, 	"hvc"	,list_of(imm16) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ic_sys, 	"ic"	,list_of(op1)(CRm)(op2)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_isb, 	"isb"	,list_of(CRm) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldar, 	"ldar"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldarb, 	"ldarb"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldarh, 	"ldarh"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldaxp, 	"ldaxp"	,list_of(sz)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldaxr, 	"ldaxr"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldaxrb, 	"ldaxrb"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldaxrh, 	"ldaxrh"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldnp_gen, 	"ldnp"	,list_of(imm7)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldp_gen, 	"ldp"	,list_of(imm7)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldp_gen, 	"ldp"	,list_of(imm7)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldp_gen, 	"ldp"	,list_of(imm7)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldpsw, 	"ldpsw"	,list_of(imm7)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldpsw, 	"ldpsw"	,list_of(imm7)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldpsw, 	"ldpsw"	,list_of(imm7)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldr_imm_gen, 	"ldr"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldr_imm_gen, 	"ldr"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldr_imm_gen, 	"ldr"	,list_of(imm12)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldr_lit_gen, 	"ldr"	,list_of(imm19)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldr_reg_gen, 	"ldr"	,list_of(Rm)(option)(S)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrb_imm, 	"ldrb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrb_imm, 	"ldrb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrb_imm, 	"ldrb"	,list_of(imm12)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrb_reg, 	"ldrb"	,list_of(Rm)(option)(S)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrh_imm, 	"ldrh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrh_imm, 	"ldrh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrh_imm, 	"ldrh"	,list_of(imm12)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrh_reg, 	"ldrh"	,list_of(Rm)(option)(S)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsb_imm, 	"ldrsb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsb_imm, 	"ldrsb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsb_imm, 	"ldrsb"	,list_of(imm12)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsb_reg, 	"ldrsb"	,list_of(Rm)(option)(S)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsh_imm, 	"ldrsh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsh_imm, 	"ldrsh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsh_imm, 	"ldrsh"	,list_of(imm12)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsh_reg, 	"ldrsh"	,list_of(Rm)(option)(S)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsw_imm, 	"ldrsw"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsw_imm, 	"ldrsw"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsw_imm, 	"ldrsw"	,list_of(imm12)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsw_lit, 	"ldrsw"	,list_of(imm19)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldrsw_reg, 	"ldrsw"	,list_of(Rm)(option)(S)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldtr, 	"ldtr"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldtrb, 	"ldtrb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldtrh, 	"ldtrh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldtrsb, 	"ldtrsb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldtrsh, 	"ldtrsh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldtrsw, 	"ldtrsw"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldur_gen, 	"ldur"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldurb, 	"ldurb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldurh, 	"ldurh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldursb, 	"ldursb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldursh, 	"ldursh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldursw, 	"ldursw"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldxp, 	"ldxp"	,list_of(sz)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldxr, 	"ldxr"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldxrb, 	"ldxrb"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ldxrh, 	"ldxrh"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_lsl_lslv, 	"lsl"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_lsl_ubfm, 	"lsl"	,list_of(sf)(N)(immr)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_lslv, 	"lslv"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_lsr_lsrv, 	"lsr"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_lsr_ubfm, 	"lsr"	,list_of(sf)(N)(immr)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_lsrv, 	"lsrv"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_madd, 	"madd"	,list_of(sf)(Rm)(Ra)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_mneg_msub, 	"mneg"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_mov_add_addsub_imm, 	"mov"	,list_of(sf)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_mov_movn, 	"mov"	,list_of(sf)(hw)(imm16)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_mov_movz, 	"mov"	,list_of(sf)(hw)(imm16)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_mov_orr_log_imm, 	"mov"	,list_of(sf)(N)(immr)(imms)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_mov_orr_log_shift, 	"mov"	,list_of(sf)(Rm)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_movk, 	"movk"	,list_of(sf)(hw)(imm16)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_movn, 	"movn"	,list_of(sf)(hw)(imm16)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_movz, 	"movz"	,list_of(sf)(hw)(imm16)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_mrs, 	"mrs"	,list_of(o0)(op1)(CRn)(CRm)(op2)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_msr_imm, 	"msr"	,list_of(op1)(CRm)(op2) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_msr_reg, 	"msr"	,list_of(o0)(op1)(CRn)(CRm)(op2)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_msub, 	"msub"	,list_of(sf)(Rm)(Ra)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_mul_madd, 	"mul"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_mvn_orn_log_shift, 	"mvn"	,list_of(sf)(shift)(Rm)(imm6)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_neg_sub_addsub_shift, 	"neg"	,list_of(sf)(shift)(Rm)(imm6)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_negs_subs_addsub_shift, 	"negs"	,list_of(sf)(shift)(Rm)(imm6)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ngc_sbc, 	"ngc"	,list_of(sf)(Rm)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ngcs_sbcs, 	"ngcs"	,list_of(sf)(Rm)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_nop_hint, 	"nop"	,operandSpec() ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_orn_log_shift, 	"orn"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_orr_log_imm, 	"orr"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_orr_log_shift, 	"orr"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_prfm_imm, 	"prfm"	,list_of(imm12)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_prfm_lit, 	"prfm"	,list_of(imm19)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_prfm_reg, 	"prfm"	,list_of(Rm)(option)(S)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_prfum, 	"prfum"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_rbit_int, 	"rbit"	,list_of(sf)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ret, 	"ret"	,list_of(Rn) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_rev, 	"rev"	,list_of(sf)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_rev16_int, 	"rev16"	,list_of(sf)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_rev32_int, 	"rev32"	,list_of(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ror_extr, 	"ror"	,list_of(sf)(N)(Rm)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ror_rorv, 	"ror"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_rorv, 	"rorv"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sbc, 	"sbc"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sbcs, 	"sbcs"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sbfiz_sbfm, 	"sbfiz"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sbfm, 	"sbfm"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sbfx_sbfm, 	"sbfx"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sdiv, 	"sdiv"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sev_hint, 	"sev"	,operandSpec() ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sevl_hint, 	"sevl"	,operandSpec() ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_smaddl, 	"smaddl"	,list_of(Rm)(Ra)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_smc, 	"smc"	,list_of(imm16) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_smnegl_smsubl, 	"smnegl"	,list_of(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_smsubl, 	"smsubl"	,list_of(Rm)(Ra)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_smulh, 	"smulh"	,list_of(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_smull_smaddl, 	"smull"	,list_of(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stlr, 	"stlr"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stlrb, 	"stlrb"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stlrh, 	"stlrh"	,list_of(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stlxp, 	"stlxp"	,list_of(sz)(Rs)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stlxr, 	"stlxr"	,list_of(Rs)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stlxrb, 	"stlxrb"	,list_of(Rs)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stlxrh, 	"stlxrh"	,list_of(Rs)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stnp_gen, 	"stnp"	,list_of(imm7)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stp_gen, 	"stp"	,list_of(imm7)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stp_gen, 	"stp"	,list_of(imm7)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stp_gen, 	"stp"	,list_of(imm7)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_str_imm_gen, 	"str"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_str_imm_gen, 	"str"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_str_imm_gen, 	"str"	,list_of(imm12)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_str_reg_gen, 	"str"	,list_of(Rm)(option)(S)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_strb_imm, 	"strb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_strb_imm, 	"strb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_strb_imm, 	"strb"	,list_of(imm12)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_strb_reg, 	"strb"	,list_of(Rm)(option)(S)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_strh_imm, 	"strh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_strh_imm, 	"strh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_strh_imm, 	"strh"	,list_of(imm12)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_strh_reg, 	"strh"	,list_of(Rm)(option)(S)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sttr, 	"sttr"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sttrb, 	"sttrb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sttrh, 	"sttrh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stur_gen, 	"stur"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sturb, 	"sturb"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sturh, 	"sturh"	,list_of(imm9)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stxp, 	"stxp"	,list_of(sz)(Rs)(Rt2)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stxr, 	"stxr"	,list_of(Rs)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stxrb, 	"stxrb"	,list_of(Rs)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_stxrh, 	"stxrh"	,list_of(Rs)(Rn)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sub_addsub_ext, 	"sub"	,list_of(sf)(Rm)(option)(imm3)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sub_addsub_imm, 	"sub"	,list_of(sf)(shift)(imm12)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sub_addsub_shift, 	"sub"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_subs_addsub_ext, 	"subs"	,list_of(sf)(Rm)(option)(imm3)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_subs_addsub_imm, 	"subs"	,list_of(sf)(shift)(imm12)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_subs_addsub_shift, 	"subs"	,list_of(sf)(shift)(Rm)(imm6)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_svc, 	"svc"	,list_of(imm16) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sxtb_sbfm, 	"sxtb"	,list_of(sf)(N)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sxth_sbfm, 	"sxth"	,list_of(sf)(N)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sxtw_sbfm, 	"sxtw"	,list_of(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sys, 	"sys"	,list_of(op1)(CRn)(CRm)(op2)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_sysl, 	"sysl"	,list_of(op1)(CRn)(CRm)(op2)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_tbnz, 	"tbnz"	,list_of(b5)(b40)(imm14)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_tbz, 	"tbz"	,list_of(b5)(b40)(imm14)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_tlbi_sys, 	"tlbi"	,list_of(op1)(CRm)(op2)(Rt) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_tst_ands_log_imm, 	"tst"	,list_of(sf)(N)(immr)(imms)(Rn) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_tst_ands_log_shift, 	"tst"	,list_of(sf)(shift)(Rm)(imm6)(Rn) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ubfiz_ubfm, 	"ubfiz"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ubfm, 	"ubfm"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_ubfx_ubfm, 	"ubfx"	,list_of(sf)(N)(immr)(imms)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_udiv, 	"udiv"	,list_of(sf)(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_umaddl, 	"umaddl"	,list_of(Rm)(Ra)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_umnegl_umsubl, 	"umnegl"	,list_of(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_umsubl, 	"umsubl"	,list_of(Rm)(Ra)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_umulh, 	"umulh"	,list_of(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_umull_umaddl, 	"umull"	,list_of(Rm)(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_uxtb_ubfm, 	"uxtb"	,list_of(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_uxth_ubfm, 	"uxth"	,list_of(Rn)(Rd) ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_wfe_hint, 	"wfe"	,operandSpec() ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_wfi_hint, 	"wfi"	,operandSpec() ));
	main_insn_table.push_back(aarch64_insn_entry(aarch64_op_yield_hint, 	"yield"	,operandSpec() ));
}
