/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ����������ʾ���̣�ͨ����׼�ӿ�ʵ��
 *
 * - �������裺
 *   1. �� J14 �� KEY �� PIOA_7 �̽���һ��
 *
 * - ʵ������:
 *   1. ���Դ��ڴ�ӡ�����¼���
 *
 * \note
 *    1. ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOB_11 �������� PC ���ڵ� TXD��
 *       PIOB_12 �������� PC ���ڵ� RXD��
 *    2. ���Ա� Demo ������ am_prj_config.h �ڽ� AM_CFG_KEY_GPIO_ENABLE��
 *       AM_CFG_KEY_ENABLE �� AM_CFG_SOFTIMER_ENABLE ����Ϊ 1������Щ��
 *       �Ѿ�Ĭ������Ϊ 1�� �û������ٴ����ã�
 *
 * \par Դ����
 * \snippet demo_zsl42x_std_key_input_event.c src_zsl42x_std_key_input_event
 *
 * \internal
 * \par Modification history
 * - 1.00 19-09-27  zp, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_zsl42x_std_key_input_event
 * \copydoc demo_zsl42x_std_key_input_event.c
 */

/** [src_zsl42x_std_key_input_event] */
#include "ametal.h"
#include "am_vdebug.h"
#include "demo_std_entries.h"
#include "demo_am42x_core_entries.h"

/**
 * \brief �������
 */
void demo_zsl42x_core_std_key_input_event_entry (void)
{
    AM_DBG_INFO("demo am42x_core std input event!\r\n");

    demo_std_key_entry();
}
/** [src_zsl42x_std_key_input_event] */

/* end of file */