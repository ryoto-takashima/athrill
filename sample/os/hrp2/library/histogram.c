/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2006-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ��������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: histogram.c 587 2012-01-15 23:28:23Z ertl-hiro $
 */

/*
 *		�¹Ի���ʬ�۽��ץ⥸�塼��
 */

#include <kernel.h>
#include <t_syslog.h>
#include <test_lib.h>
#include <histogram.h>
#include "target_test.h"

/*
 *  �¹Ի���ʬ�۷�¬�ο�
 */
#ifndef TNUM_HIST
#define TNUM_HIST		10
#endif /* TNUM_HIST */

/*
 *  �������åȰ�¸���������ѹ����뤿��Υޥ���
 */
#ifndef HISTTIM						/* �¹Ի��ַ�¬�Ѥλ���Υǡ����� */
#define HISTTIM			SYSUTM
#endif /* HISTTIM */

#ifndef HIST_GET_TIM				/* �¹Ի��ַ�¬�Ѥθ��߻���μ��� */
#ifndef TOPPERS_SUPPORT_GET_UTM
#error get_utm is not supported.
#endif /* TOPPERS_SUPPORT_GET_UTM */
#define HIST_GET_TIM(p_time)	((void) get_utm(p_time))
#endif /* HIST_GET_TIM */

#ifndef HIST_CONV_TIM				/* ����κ�����¹Ի��֤ؤ��Ѵ� */
#define HIST_CONV_TIM(time)		((uint_t)(time))
#endif /* HIST_CONV_TIM */

#ifndef HIST_BM_HOOK				/* �¹Ի��ַ�¬ľ���˹Ԥ��٤����� */
#define HIST_BM_HOOK()			((void) 0)
#endif

/*
 *  �¹Ի���ʬ�۷�¬�����֥��å�
 */
typedef struct histogram_control_block {
	HISTTIM		begin_time;			/* ��¬���ϻ��� */
	uint_t		maxval;				/* ʬ�ۤ�Ͽ���������� */
	uint_t		*histarea;			/* ʬ�ۤ�Ͽ��������ΰ� */
	uint_t		over;				/* ������֤�Ķ�����ٿ� */
	uint_t		under;				/* ���֤ε�ž���������ٿ� */
} HISTCB;

/*
 *  �¹Ի���ʬ�۷�¬�����֥��å��Υ��ꥢ
 */
static HISTCB	histcb_table[TNUM_HIST];

/*
 *  �¹Ի���ʬ�۷�¬ID�κǾ��ͤȺ�����
 */
#define TMIN_HISTID		1
#define TMAX_HISTID		(TMIN_HISTID + TNUM_HIST - 1)

/*
 *  �¹Ի���ʬ�۷�¬�ν����
 */
void
init_hist(ID histid, uint_t maxval, uint_t histarea[])
{
	HISTCB	*p_histcb;
	uint_t	i;

	assert(TMIN_HISTID <= histid && histid <= TMAX_HISTID);
	p_histcb = &(histcb_table[histid - TMIN_HISTID]);

	for (i = 0; i <= maxval; i++) {
		histarea[i] = 0U;
	}
	p_histcb->maxval = maxval;
	p_histcb->histarea = histarea;
	p_histcb->over = 0U;
	p_histcb->under = 0U;
}

/*
 *  �¹Ի��ַ�¬�γ���
 */
void
begin_measure(ID histid)
{
	HISTCB	*p_histcb;

	assert(TMIN_HISTID <= histid && histid <= TMAX_HISTID);
	p_histcb = &(histcb_table[histid - TMIN_HISTID]);

	HIST_BM_HOOK();
	HIST_GET_TIM(&(p_histcb->begin_time));
}

/*
 *  �¹Ի��ַ�¬�ν�λ
 */
void
end_measure(ID histid)
{
	HISTCB	*p_histcb;
	HISTTIM	end_time;
	uint_t	val;

	HIST_GET_TIM(&end_time);

	assert(TMIN_HISTID <= histid && histid <= TMAX_HISTID);
	p_histcb = &(histcb_table[histid - TMIN_HISTID]);

	val = HIST_CONV_TIM(end_time - p_histcb->begin_time);
	if (val <= p_histcb->maxval) {
		p_histcb->histarea[val]++;
	}
	else if (val <= ((uint_t) INT_MAX)) {
		p_histcb->over++;
	}
	else {
		p_histcb->under++;
	}
}

/*
 *  �¹Ի���ʬ�۷�¬��ɽ��
 */
void
print_hist(ID histid)
{
	HISTCB	*p_histcb;
	uint_t	i;

	assert(TMIN_HISTID <= histid && histid <= TMAX_HISTID);
	p_histcb = &(histcb_table[histid - TMIN_HISTID]);

	for (i = 0; i <= p_histcb->maxval; i++) {
		if (p_histcb->histarea[i] > 0) {
			syslog_2(LOG_NOTICE, "%d : %d", i, p_histcb->histarea[i]);
			syslog_flush();
		}
	}
	if (p_histcb->over > 0) {
		syslog_2(LOG_NOTICE, "> %d : %d", p_histcb->maxval, p_histcb->over);
	}
	if (p_histcb->under > 0) {
		syslog_1(LOG_NOTICE, "> INT_MAX : %d", p_histcb->under);
	}
	syslog_flush();
}