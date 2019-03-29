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
 * \brief MiniPort-LED �û������ļ�
 * \sa am_hwconf_miniport_led.c
 *
 * �����Ե���ʹ�ã�Ҳ���Ժ� MiniPort-595 ����ʹ�ã��Խ�ʡ�������š�
 *
 * ��ǰ֧�ֵ��÷��У�
 * 1. MiniPort-LED                : am_miniport_led_inst_init();
 * 2. MiniPort-LED + MiniPort-595 : am_miniport_led_595_inst_init();
 *
 * \internal
 * \par Modification history
 * - 1.00 17-07-25  tee, first implementation
 * \endinternal
 */

#include "ametal.h"
#include "am_led_hc595.h"
#include "am_led_gpio.h"
#include "am_hc595_gpio.h"
#include "am_hc595_spi.h"
#include "am_zmf159_inst_init.h"
#include "zmf159_pin.h"
#include "am_hwconf_microport.h"

/**
 * \addtogroup am_if_src_hwconf_miniport_led
 * \copydoc am_hwconf_miniport_led.c
 * @{
 */

/*******************************************************************************
   MiniPort-LED ����ʹ��
*******************************************************************************/

/* ����GPIO LED ʵ�� */
static am_led_gpio_dev_t  __g_miniport_led;

static const int __g_miniport_led_pins[] = {
    PIOB_7, PIOB_6, PIOB_15, PIOB_13, PIOC_10, PIOB_14, PIOB_12, PIOC_14
};

/* ����GPIO����ʵ����Ϣ */
static const am_led_gpio_info_t __g_miniport_led_info = {
    {
        0,                            /* ��ʼ���0 */
        7                             /* �������7������8��LED */
    },
    __g_miniport_led_pins,
    AM_TRUE
};

int am_miniport_led_inst_init (void)
{
    return am_led_gpio_init(&__g_miniport_led, &__g_miniport_led_info);
}

/*******************************************************************************
   MiniPort-LED �� MiniPort-595����ʹ��
*******************************************************************************/

static am_led_hc595_dev_t  __g_miniport_led_595;

static uint8_t __g_miniport_led_595_buf[1];

/* ����GPIO����ʵ����Ϣ */
static const am_led_hc595_info_t __g_miniport_led_595_info = {
    {
        2,                            /* ��ʼ���0 */
        9                             /* �������1������2��LED */
    },
    1,
    __g_miniport_led_595_buf,
    AM_TRUE
};

int am_miniport_led_595_inst_init (void)
{

    return am_led_hc595_init(&__g_miniport_led_595,
                             &__g_miniport_led_595_info,
                              am_miniport_595_inst_init());
}

/**
 * @}
 */

/* end of file */