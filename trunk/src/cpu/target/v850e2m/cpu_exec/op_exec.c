#include "cpu_exec/op_exec.h"

OpExecType op_exec_table[OP_EXEC_TABLE_NUM] = {
	{ op_exec_add_1 },		/* OpCodeId_ADD_1 */
	{ op_exec_add_2 },		/* OpCodeId_ADD_2 */
	{ op_exec_addi_6 },		/* OpCodeId_ADDI_6 */
	{ op_exec_adf_11 },		/* OpCodeId_ADF_11 */
	{ op_exec_and_1 },		/* OpCodeId_AND_1 */
	{ op_exec_andi_6 },		/* OpCodeId_ANDI_6 */
	{ op_exec_bsh_12 },		/* OpCodeId_BSH_12 */
	{ op_exec_bsw_12 },		/* OpCodeId_BSW_12 */
	{ op_exec_bcond_3 },		/* OpCodeId_Bcond_3 */
	{ op_exec_callt_2 },		/* OpCodeId_CALLT_2 */
	{ op_exec_caxi_11 },		/* OpCodeId_CAXI_11 */
	{ op_exec_clr1_8 },		/* OpCodeId_CLR1_8 */
	{ op_exec_clr1_9 },		/* OpCodeId_CLR1_9 */
	{ op_exec_cmov_12 },		/* OpCodeId_CMOV_12 */
	{ op_exec_cmov_11 },		/* OpCodeId_CMOV_11 */
	{ op_exec_cmp_1 },		/* OpCodeId_CMP_1 */
	{ op_exec_cmp_2 },		/* OpCodeId_CMP_2 */
	{ op_exec_ctret_10 },		/* OpCodeId_CTRET_10 */
	{ op_exec_di_10 },		/* OpCodeId_DI_10 */
	{ op_exec_dispose_13 },		/* OpCodeId_DISPOSE_13 */
	{ op_exec_div_11 },		/* OpCodeId_DIV_11 */
	{ op_exec_divh_1 },		/* OpCodeId_DIVH_1 */
	{ op_exec_divh_11 },		/* OpCodeId_DIVH_11 */
	{ op_exec_divhu_11 },		/* OpCodeId_DIVHU_11 */
	{ op_exec_divq_11 },		/* OpCodeId_DIVQ_11 */
	{ op_exec_divqu_11 },		/* OpCodeId_DIVQU_11 */
	{ op_exec_divu_11 },		/* OpCodeId_DIVU_11 */
	{ op_exec_ei_10 },		/* OpCodeId_EI_10 */
	{ op_exec_eiret_10 },		/* OpCodeId_EIRET_10 */
	{ op_exec_feret_10 },		/* OpCodeId_FERET_10 */
	{ op_exec_fetrap_1 },		/* OpCodeId_FETRAP_1 */
	{ op_exec_halt_10 },		/* OpCodeId_HALT_10 */
	{ op_exec_hsh_12 },		/* OpCodeId_HSH_12 */
	{ op_exec_hsw_12 },		/* OpCodeId_HSW_12 */
	{ op_exec_jarl_6 },		/* OpCodeId_JARL_6 */
	{ op_exec_jarl_5 },		/* OpCodeId_JARL_5 */
	{ op_exec_jmp_1 },		/* OpCodeId_JMP_1 */
	{ op_exec_jmp_6 },		/* OpCodeId_JMP_6 */
	{ op_exec_jr_6 },		/* OpCodeId_JR_6 */
	{ op_exec_jr_5 },		/* OpCodeId_JR_5 */
	{ op_exec_ldsr_9 },		/* OpCodeId_LDSR_9 */
	{ op_exec_ld_b_7 },		/* OpCodeId_LD_B_7 */
	{ op_exec_ld_b_14 },		/* OpCodeId_LD_B_14 */
	{ op_exec_ld_bu_7 },		/* OpCodeId_LD_BU_7 */
	{ op_exec_ld_bu_14 },		/* OpCodeId_LD_BU_14 */
	{ op_exec_ld_h_7 },		/* OpCodeId_LD_H_7 */
	{ op_exec_ld_h_14 },		/* OpCodeId_LD_H_14 */
	{ op_exec_ld_hu_14 },		/* OpCodeId_LD_HU_14 */
	{ op_exec_ld_hu_7 },		/* OpCodeId_LD_HU_7 */
	{ op_exec_ld_w_7 },		/* OpCodeId_LD_W_7 */
	{ op_exec_ld_w_14 },		/* OpCodeId_LD_W_14 */
	{ op_exec_mac_11 },		/* OpCodeId_MAC_11 */
	{ op_exec_macu_11 },		/* OpCodeId_MACU_11 */
	{ op_exec_mov_1 },		/* OpCodeId_MOV_1 */
	{ op_exec_mov_2 },		/* OpCodeId_MOV_2 */
	{ op_exec_mov_6 },		/* OpCodeId_MOV_6 */
	{ op_exec_movea_6 },		/* OpCodeId_MOVEA_6 */
	{ op_exec_movhi_6 },		/* OpCodeId_MOVHI_6 */
	{ op_exec_mul_11 },		/* OpCodeId_MUL_11 */
	{ op_exec_mul_12 },		/* OpCodeId_MUL_12 */
	{ op_exec_mulh_1 },		/* OpCodeId_MULH_1 */
	{ op_exec_mulh_2 },		/* OpCodeId_MULH_2 */
	{ op_exec_mulhi_6 },		/* OpCodeId_MULHI_6 */
	{ op_exec_mulu_11 },		/* OpCodeId_MULU_11 */
	{ op_exec_mulu_12 },		/* OpCodeId_MULU_12 */
	{ op_exec_nop_1 },		/* OpCodeId_NOP_1 */
	{ op_exec_not_1 },		/* OpCodeId_NOT_1 */
	{ op_exec_not1_8 },		/* OpCodeId_NOT1_8 */
	{ op_exec_not1_9 },		/* OpCodeId_NOT1_9 */
	{ op_exec_or_1 },		/* OpCodeId_OR_1 */
	{ op_exec_ori_6 },		/* OpCodeId_ORI_6 */
	{ op_exec_prepare_13 },		/* OpCodeId_PREPARE_13 */
	{ op_exec_reti_10 },		/* OpCodeId_RETI_10 */
	{ op_exec_rie_1 },		/* OpCodeId_RIE_1 */
	{ op_exec_rie_10 },		/* OpCodeId_RIE_10 */
	{ op_exec_sar_2 },		/* OpCodeId_SAR_2 */
	{ op_exec_sar_9 },		/* OpCodeId_SAR_9 */
	{ op_exec_sar_11 },		/* OpCodeId_SAR_11 */
	{ op_exec_sasf_9 },		/* OpCodeId_SASF_9 */
	{ op_exec_satadd_1 },		/* OpCodeId_SATADD_1 */
	{ op_exec_satadd_2 },		/* OpCodeId_SATADD_2 */
	{ op_exec_satadd_11 },		/* OpCodeId_SATADD_11 */
	{ op_exec_satsub_1 },		/* OpCodeId_SATSUB_1 */
	{ op_exec_satsub_11 },		/* OpCodeId_SATSUB_11 */
	{ op_exec_satsubi_6 },		/* OpCodeId_SATSUBI_6 */
	{ op_exec_satsubr_1 },		/* OpCodeId_SATSUBR_1 */
	{ op_exec_sbf_11 },		/* OpCodeId_SBF_11 */
	{ op_exec_sch0l_9 },		/* OpCodeId_SCH0L_9 */
	{ op_exec_sch0r_9 },		/* OpCodeId_SCH0R_9 */
	{ op_exec_sch1l_9 },		/* OpCodeId_SCH1L_9 */
	{ op_exec_sch1r_9 },		/* OpCodeId_SCH1R_9 */
	{ op_exec_set1_8 },		/* OpCodeId_SET1_8 */
	{ op_exec_set1_9 },		/* OpCodeId_SET1_9 */
	{ op_exec_setf_9 },		/* OpCodeId_SETF_9 */
	{ op_exec_shl_2 },		/* OpCodeId_SHL_2 */
	{ op_exec_shl_9 },		/* OpCodeId_SHL_9 */
	{ op_exec_shl_11 },		/* OpCodeId_SHL_11 */
	{ op_exec_shr_2 },		/* OpCodeId_SHR_2 */
	{ op_exec_shr_9 },		/* OpCodeId_SHR_9 */
	{ op_exec_shr_11 },		/* OpCodeId_SHR_11 */
	{ op_exec_sld_b_4 },		/* OpCodeId_SLD_B_4 */
	{ op_exec_sld_bu_4 },		/* OpCodeId_SLD_BU_4 */
	{ op_exec_sld_h_4 },		/* OpCodeId_SLD_H_4 */
	{ op_exec_sld_hu_4 },		/* OpCodeId_SLD_HU_4 */
	{ op_exec_sld_w_4 },		/* OpCodeId_SLD_W_4 */
	{ op_exec_sst_b_4 },		/* OpCodeId_SST_B_4 */
	{ op_exec_sst_h_4 },		/* OpCodeId_SST_H_4 */
	{ op_exec_sst_w_4 },		/* OpCodeId_SST_W_4 */
	{ op_exec_stsr_9 },		/* OpCodeId_STSR_9 */
	{ op_exec_st_b_7 },		/* OpCodeId_ST_B_7 */
	{ op_exec_st_b_14 },		/* OpCodeId_ST_B_14 */
	{ op_exec_st_h_7 },		/* OpCodeId_ST_H_7 */
	{ op_exec_st_h_14 },		/* OpCodeId_ST_H_14 */
	{ op_exec_st_w_7 },		/* OpCodeId_ST_W_7 */
	{ op_exec_st_w_14 },		/* OpCodeId_ST_W_14 */
	{ op_exec_sub_1 },		/* OpCodeId_SUB_1 */
	{ op_exec_subr_1 },		/* OpCodeId_SUBR_1 */
	{ op_exec_switch_1 },		/* OpCodeId_SWITCH_1 */
	{ op_exec_sxb_1 },		/* OpCodeId_SXB_1 */
	{ op_exec_sxh_1 },		/* OpCodeId_SXH_1 */
	{ op_exec_synce_1 },		/* OpCodeId_SYNCE_1 */
	{ op_exec_syncm_1 },		/* OpCodeId_SYNCM_1 */
	{ op_exec_syncp_1 },		/* OpCodeId_SYNCP_1 */
	{ op_exec_syscall_10 },		/* OpCodeId_SYSCALL_10 */
	{ op_exec_trap_10 },		/* OpCodeId_TRAP_10 */
	{ op_exec_tst_1 },		/* OpCodeId_TST_1 */
	{ op_exec_tst1_8 },		/* OpCodeId_TST1_8 */
	{ op_exec_tst1_9 },		/* OpCodeId_TST1_9 */
	{ op_exec_xor_1 },		/* OpCodeId_XOR_1 */
	{ op_exec_xori_6 },		/* OpCodeId_XORI_6 */
	{ op_exec_zxb_1 },		/* OpCodeId_ZXB_1 */
	{ op_exec_zxh_1 },		/* OpCodeId_ZXH_1 */
};
