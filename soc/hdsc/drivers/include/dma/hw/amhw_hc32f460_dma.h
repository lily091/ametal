/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg118.cn/
*******************************************************************************/

/**
 * \file
 * \brief DMA hardware operation interface.
 *
 * 1. 2 independent programmable DMA channel.
 * 2. 8,16,32 bits data to transfer.
 * 3. support programmable source address,destination address and data size��
 *
 * ����һ�� Ӳ������� AMHW_HC32F460_DMA_CHAN_CNT���������� DMAͨ����Ŀ��ʹ�ñ��ļ�ʱ��
 * Ӧ�� soc_cfg.h �ļ��ж���úꡣ
 *
 * \internal
 * \par Modification history
 * - 1.00 20-03-04  cds, first implementation
 * \endinternal
 */

#ifndef __AMHW_HC32F460_DMA_H
#define __AMHW_HC32F460_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "am_types.h"
#include "am_common.h"
#include "am_vdebug.h"
#include "hc32f460_dma_chan.h"
#include "hc32f460_regbase.h"
/**
 * \addtogroup amhw_hc32f460_if_dma
 * \copydoc amhw_hc32f460_dma.h
 * @{
 */

/** \brief DMA ͨ����Ŀ  */
#define AMHW_HC32F460_DMA_CHAN_CNT  4

#define AMHW_HC32F460_DMA_DTCTL_CNT_MAX         (0XFFFFUL)
#define AMHW_HC32F460_DMA_DTCTL_BLKSIZE_MAX     (1024UL)
#define AMHW_HC32F460_DMA_RPT_DRPT_MAX          (0X3FFUL)
#define AMHW_HC32F460_DMA_RPT_SRPT_MAX          (0X3FFUL)
#define AMHW_HC32F460_DMA_SNSEQCTL_SNSCNT_MAX   (0XFFFUL)
#define AMHW_HC32F460_DMA_SNSEQCTL_SOFFSET_MAX  (0XFFFFFUL)
#define AMHW_HC32F460_DMA_DNSEQCTL_DNSCNT_MAX   (0XFFFUL)
#define AMHW_HC32F460_DMA_DNSEQCTL_DSOFFSET_MAX (0XFFFFFUL)

#define AMHW_HC32F460_DMA_DTCTL_CNT_SHIFT        (16UL)
#define AMHW_HC32F460_DMA_RPT_DRPT_SHIFT         (16UL)
#define AMHW_HC32F460_DMA_SNSEQCTL_SNSCNT_SHIFT  (20UL)
#define AMHW_HC32F460_DMA_DNSEQCTL_DNSCNT_SHIFT  (20UL)

#define AMHW_HC32F460_DMA_RCFGCTL_CNTMD_SHIFT    (20UL)
#define AMHW_HC32F460_DMA_RCFGCTL_DARMD_SHIFT    (18UL)
#define AMHW_HC32F460_DMA_RCFGCTL_SARMD_SHIFT    (16UL)
#define AMHW_HC32F460_DMA_RCFGCTL_RCFGCHS_SHIFT  (8UL)
#define AMHW_HC32F460_DMA_RCFGCTL_RCFGLLP_SHIFT  (1UL)
#define AMHW_HC32F460_DMA_RCFGCTL_RCFGEN_SHIFT   (0UL)

typedef struct
{
    __IO uint32_t EN                        : 1;
    uint32_t RESERVED1                      :31;
} stc_dma_en_field_t;

typedef struct
{
    __IO uint32_t TRNERR                    : 4;
    uint32_t RESERVED4                      :12;
    __IO uint32_t REQERR                    : 4;
    uint32_t RESERVED20                     :12;
} stc_dma_intstat0_field_t;

typedef struct
{
    __IO uint32_t TC                        : 4;
    uint32_t RESERVED4                      :12;
    __IO uint32_t BTC                       : 4;
    uint32_t RESERVED20                     :12;
} stc_dma_intstat1_field_t;

typedef struct
{
    __IO uint32_t MSKTRNERR                 : 4;
    uint32_t RESERVED4                      :12;
    __IO uint32_t MSKREQERR                 : 4;
    uint32_t RESERVED20                     :12;
} stc_dma_intmask0_field_t;

typedef struct
{
    __IO uint32_t MSKTC                     : 4;
    uint32_t RESERVED4                      :12;
    __IO uint32_t MSKBTC                    : 4;
    uint32_t RESERVED20                     :12;
} stc_dma_intmask1_field_t;

typedef struct
{
    __IO uint32_t CLRTRNERR                 : 4;
    uint32_t RESERVED4                      :12;
    __IO uint32_t CLRREQERR                 : 4;
    uint32_t RESERVED20                     :12;
} stc_dma_intclr0_field_t;

typedef struct
{
    __IO uint32_t CLRTC                     : 4;
    uint32_t RESERVED4                      :12;
    __IO uint32_t CLRBTC                    : 4;
    uint32_t RESERVED20                     :12;
} stc_dma_intclr1_field_t;

typedef struct
{
    __IO uint32_t CHEN                      : 4;
    uint32_t RESERVED4                      :28;
} stc_dma_chen_field_t;

typedef struct
{
    __IO uint32_t DMAACT                    : 1;
    __IO uint32_t RCFGACT                   : 1;
    uint32_t RESERVED2                      :14;
    __IO uint32_t CHACT                     : 4;
    uint32_t RESERVED20                     :12;
} stc_dma_chstat_field_t;

typedef struct
{
    __IO uint32_t RCFGEN                    : 1;
    __IO uint32_t RCFGLLP                   : 1;
    uint32_t RESERVED2                      : 6;
    __IO uint32_t RCFGCHS                   : 4;
    uint32_t RESERVED12                     : 4;
    __IO uint32_t SARMD                     : 2;
    __IO uint32_t DARMD                     : 2;
    __IO uint32_t CNTMD                     : 2;
    uint32_t RESERVED22                     :10;
} stc_dma_rcfgctl_field_t;

typedef struct
{
    __IO uint32_t BLKSIZE                   :10;
    uint32_t RESERVED10                     : 6;
    __IO uint32_t CNT                       :16;
} stc_dma_dtctl_field_t;

typedef struct
{
    __IO uint32_t SRPT                      :10;
    uint32_t RESERVED10                     : 6;
    __IO uint32_t DRPT                      :10;
    uint32_t RESERVED26                     : 6;
} stc_dma_rpt_field_t;

typedef struct
{
    __IO uint32_t SRPTB                     :10;
    uint32_t RESERVED10                     : 6;
    __IO uint32_t DRPTB                     :10;
    uint32_t RESERVED26                     : 6;
} stc_dma_rptb_field_t;

typedef struct
{
    __IO uint32_t SOFFSET                   :20;
    __IO uint32_t SNSCNT                    :12;
} stc_dma_snseqctl_field_t;

typedef struct
{
    __IO uint32_t SNSDIST                   :20;
    __IO uint32_t SNSCNTB                   :12;
} stc_dma_snseqctlb_field_t;

typedef struct
{
    __IO uint32_t DOFFSET                   :20;
    __IO uint32_t DNSCNT                    :12;
} stc_dma_dnseqctl_field_t;

typedef struct
{
    __IO uint32_t DNSDIST                   :20;
    __IO uint32_t DNSCNTB                   :12;
} stc_dma_dnseqctlb_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 2;
    __IO uint32_t LLP                       :30;
} stc_dma_llp_field_t;

typedef struct
{
    __IO uint32_t SINC                      : 2;
    __IO uint32_t DINC                      : 2;
    __IO uint32_t SRTPEN                    : 1;
    __IO uint32_t DRPTEN                    : 1;
    __IO uint32_t SNSEQEN                   : 1;
    __IO uint32_t DNSEQEN                   : 1;
    __IO uint32_t HSIZE                     : 2;
    __IO uint32_t LLPEN                     : 1;
    __IO uint32_t LLPRUN                    : 1;
    __IO uint32_t IE                        : 1;
    uint32_t RESERVED13                     :19;
} stc_dma_ch0ctl_field_t;

typedef struct
{
    __IO uint32_t BLKSIZE                   :10;
    uint32_t RESERVED10                     : 6;
    __IO uint32_t CNT                       :16;
} stc_dma_mondtctl_field_t;

typedef struct
{
    __IO uint32_t SRPT                      :10;
    uint32_t RESERVED10                     : 6;
    __IO uint32_t DRPT                      :10;
    uint32_t RESERVED26                     : 6;
} stc_dma_monrpt_field_t;

typedef struct
{
    __IO uint32_t SOFFSET                   :20;
    __IO uint32_t SNSCNT                    :12;
} stc_dma_monsnseqctl_field_t;

typedef struct
{
    __IO uint32_t DOFFSET                   :20;
    __IO uint32_t DNSCNT                    :12;
} stc_dma_mondnseqctl_field_t;

typedef struct
{
    __IO uint32_t SINC                      : 2;
    __IO uint32_t DINC                      : 2;
    __IO uint32_t SRTPEN                    : 1;
    __IO uint32_t DRPTEN                    : 1;
    __IO uint32_t SNSEQEN                   : 1;
    __IO uint32_t DNSEQEN                   : 1;
    __IO uint32_t HSIZE                     : 2;
    __IO uint32_t LLPEN                     : 1;
    __IO uint32_t LLPRUN                    : 1;
    __IO uint32_t IE                        : 1;
    uint32_t RESERVED13                     :19;
} stc_dma_ch1ctl_field_t;

typedef struct
{
    __IO uint32_t SINC                      : 2;
    __IO uint32_t DINC                      : 2;
    __IO uint32_t SRTPEN                    : 1;
    __IO uint32_t DRPTEN                    : 1;
    __IO uint32_t SNSEQEN                   : 1;
    __IO uint32_t DNSEQEN                   : 1;
    __IO uint32_t HSIZE                     : 2;
    __IO uint32_t LLPEN                     : 1;
    __IO uint32_t LLPRUN                    : 1;
    __IO uint32_t IE                        : 1;
    uint32_t RESERVED13                     :19;
} stc_dma_ch2ctl_field_t;

typedef struct
{
    __IO uint32_t SINC                      : 2;
    __IO uint32_t DINC                      : 2;
    __IO uint32_t SRTPEN                    : 1;
    __IO uint32_t DRPTEN                    : 1;
    __IO uint32_t SNSEQEN                   : 1;
    __IO uint32_t DNSEQEN                   : 1;
    __IO uint32_t HSIZE                     : 2;
    __IO uint32_t LLPEN                     : 1;
    __IO uint32_t LLPRUN                    : 1;
    __IO uint32_t IE                        : 1;
    uint32_t RESERVED13                     :19;
} stc_dma_ch3ctl_field_t;

/**
 * \brief structure of DMA controller register
 */
typedef struct amhw_hc32f460_dma_chan {
    union
    {   /* DMAʹ�ܼĴ��� */
        __IO uint32_t EN;
        stc_dma_en_field_t EN_f;
    };
    union
    {   /* �ж�״̬�Ĵ���0 */
        __IO uint32_t INTSTAT0;
        stc_dma_intstat0_field_t INTSTAT0_f;
    };
    union
    {   /* �ж�״̬�Ĵ���1 */
        __IO uint32_t INTSTAT1;
        stc_dma_intstat1_field_t INTSTAT1_f;
    };
    union
    {   /* �ж����μĴ���0 */
        __IO uint32_t INTMASK0;
        stc_dma_intmask0_field_t INTMASK0_f;
    };
    union
    {   /* �ж����μĴ���1 */
        __IO uint32_t INTMASK1;
        stc_dma_intmask1_field_t INTMASK1_f;
    };
    union
    {   /* �жϸ�λ�Ĵ���0 */
        __IO uint32_t INTCLR0;
        stc_dma_intclr0_field_t INTCLR0_f;
    };
    union
    {   /* �жϸ�λ�Ĵ���1 */
        __IO uint32_t INTCLR1;
        stc_dma_intclr1_field_t INTCLR1_f;
    };
    union
    {   /* ͨ��ʹ�ܼĴ��� */
        __IO uint32_t CHEN;
        stc_dma_chen_field_t CHEN_f;
    };
    uint8_t RESERVED8[4];
    union
    {   /* ������ͨ�����ӼĴ��� */
        __IO uint32_t CHSTAT;
        stc_dma_chstat_field_t CHSTAT_f;
    };
    uint8_t RESERVED9[4];
    union
    {   /* ͨ�����ÿ��ƼĴ��� */
        __IO uint32_t RCFGCTL;
        stc_dma_rcfgctl_field_t RCFGCTL_f;
    };
    uint8_t RESERVED10[16];
    /* ����Դ��ַ�Ĵ��� */
    __IO uint32_t SAR0;
    /* ����Ŀ���ַ�Ĵ��� */
    __IO uint32_t DAR0;
    union
    {   /* ���ݿ��ƼĴ��� */
        __IO uint32_t DTCTL0;
        stc_dma_dtctl_field_t DTCTL0_f;
    };
    union
    {   /* �ظ������С�Ĵ��� */
        __IO uint32_t RPT0;
        stc_dma_rpt_field_t RPT0_f;
        /* �ظ������С�Ĵ���B */
        __IO uint32_t RPTB0;
        stc_dma_rptb_field_t RPTB0_f;
    };
    union
    {
        /* Դ�豸��������ַ������ƼĴ��� */
        __IO uint32_t SNSEQCTL0;
        stc_dma_snseqctl_field_t SNSEQCTL0_f;
        /* Դ�豸��������ַ������ƼĴ���B */
        __IO uint32_t SNSEQCTLB0;
        stc_dma_snseqctlb_field_t SNSEQCTLB0_f;
    };
    union
    {
        /* Ŀ���豸��������ַ������ƼĴ��� */
        __IO uint32_t DNSEQCTL0;
        stc_dma_dnseqctl_field_t DNSEQCTL0_f;
        /* Ŀ���豸��������ַ������ƼĴ���B */
        __IO uint32_t DNSEQCTLB0;
        stc_dma_dnseqctlb_field_t DNSEQCTLB0_f;
    };
    union
    {   /* ��ָ��Ĵ��� */
        __IO uint32_t LLP0;
        stc_dma_llp_field_t LLP0_f;
    };
    union
    {   /* ͨ�����ƼĴ��� */
        __IO uint32_t CH0CTL;
        stc_dma_ch0ctl_field_t CH0CTL_f;
    };
    __IO uint32_t MONSAR0;
    __IO uint32_t MONDAR0;
    union
    {
        __IO uint32_t MONDTCTL0;
        stc_dma_mondtctl_field_t MONDTCTL0_f;
    };
    union
    {
        __IO uint32_t MONRPT0;
        stc_dma_monrpt_field_t MONRPT0_f;
    };
    union
    {
        __IO uint32_t MONSNSEQCTL0;
        stc_dma_monsnseqctl_field_t MONSNSEQCTL0_f;
    };
    union
    {
        __IO uint32_t MONDNSEQCTL0;
        stc_dma_mondnseqctl_field_t MONDNSEQCTL0_f;
    };
    uint8_t RESERVED27[8];
    __IO uint32_t SAR1;
    __IO uint32_t DAR1;
    union
    {
        __IO uint32_t DTCTL1;
        stc_dma_dtctl_field_t DTCTL1_f;
    };
    union
    {
        __IO uint32_t RPT1;
        stc_dma_rpt_field_t RPT1_f;
        __IO uint32_t RPTB1;
        stc_dma_rptb_field_t RPTB1_f;
    };
    union
    {
        __IO uint32_t SNSEQCTL1;
        stc_dma_snseqctl_field_t SNSEQCTL1_f;
        __IO uint32_t SNSEQCTLB1;
        stc_dma_snseqctlb_field_t SNSEQCTLB1_f;
    };
    union
    {
        __IO uint32_t DNSEQCTL1;
        stc_dma_dnseqctl_field_t DNSEQCTL1_f;
        __IO uint32_t DNSEQCTLB1;
        stc_dma_dnseqctlb_field_t DNSEQCTLB1_f;
    };
    union
    {
        __IO uint32_t LLP1;
        stc_dma_llp_field_t LLP1_f;
    };
    union
    {
        __IO uint32_t CH1CTL;
        stc_dma_ch1ctl_field_t CH1CTL_f;
    };
    __IO uint32_t MONSAR1;
    __IO uint32_t MONDAR1;
    union
    {
        __IO uint32_t MONDTCTL1;
        stc_dma_mondtctl_field_t MONDTCTL1_f;
    };
    union
    {
        __IO uint32_t MONRPT1;
        stc_dma_monrpt_field_t MONRPT1_f;
    };
    union
    {
        __IO uint32_t MONSNSEQCTL1;
        stc_dma_monsnseqctl_field_t MONSNSEQCTL1_f;
    };
    union
    {
        __IO uint32_t MONDNSEQCTL1;
        stc_dma_mondnseqctl_field_t MONDNSEQCTL1_f;
    };
    uint8_t RESERVED44[8];
    __IO uint32_t SAR2;
    __IO uint32_t DAR2;
    union
    {
        __IO uint32_t DTCTL2;
        stc_dma_dtctl_field_t DTCTL2_f;
    };
    union
    {
        __IO uint32_t RPT2;
        stc_dma_rpt_field_t RPT2_f;
        __IO uint32_t RPTB2;
        stc_dma_rptb_field_t RPTB2_f;
    };
    union
    {
        __IO uint32_t SNSEQCTL2;
        stc_dma_snseqctl_field_t SNSEQCTL2_f;
        __IO uint32_t SNSEQCTLB2;
        stc_dma_snseqctlb_field_t SNSEQCTLB2_f;
    };
    union
    {
        __IO uint32_t DNSEQCTL2;
        stc_dma_dnseqctl_field_t DNSEQCTL2_f;
        __IO uint32_t DNSEQCTLB2;
        stc_dma_dnseqctlb_field_t DNSEQCTLB2_f;
    };
    union
    {
        __IO uint32_t LLP2;
        stc_dma_llp_field_t LLP2_f;
    };
    union
    {
        __IO uint32_t CH2CTL;
        stc_dma_ch2ctl_field_t CH2CTL_f;
    };
    __IO uint32_t MONSAR2;
    __IO uint32_t MONDAR2;
    union
    {
        __IO uint32_t MONDTCTL2;
        stc_dma_mondtctl_field_t MONDTCTL2_f;
    };
    union
    {
        __IO uint32_t MONRPT2;
        stc_dma_monrpt_field_t MONRPT2_f;
    };
    union
    {
        __IO uint32_t MONSNSEQCTL2;
        stc_dma_monsnseqctl_field_t MONSNSEQCTL2_f;
    };
    union
    {
        __IO uint32_t MONDNSEQCTL2;
        stc_dma_mondnseqctl_field_t MONDNSEQCTL2_f;
    };
    uint8_t RESERVED61[8];
    __IO uint32_t SAR3;
    __IO uint32_t DAR3;
    union
    {
        __IO uint32_t DTCTL3;
        stc_dma_dtctl_field_t DTCTL3_f;
    };
    union
    {
        __IO uint32_t RPT3;
        stc_dma_rpt_field_t RPT3_f;
        __IO uint32_t RPTB3;
        stc_dma_rptb_field_t RPTB3_f;
    };
    union
    {
        __IO uint32_t SNSEQCTL3;
        stc_dma_snseqctl_field_t SNSEQCTL3_f;
        __IO uint32_t SNSEQCTLB3;
        stc_dma_snseqctlb_field_t SNSEQCTLB3_f;
    };
    union
    {
        __IO uint32_t DNSEQCTL3;
        stc_dma_dnseqctl_field_t DNSEQCTL3_f;
        __IO uint32_t DNSEQCTLB3;
        stc_dma_dnseqctlb_field_t DNSEQCTLB3_f;
    };
    union
    {
        __IO uint32_t LLP3;
        stc_dma_llp_field_t LLP3_f;
    };
    union
    {
        __IO uint32_t CH3CTL;
        stc_dma_ch3ctl_field_t CH3CTL_f;
    };
    __IO uint32_t MONSAR3;
    __IO uint32_t MONDAR3;
    union
    {
        __IO uint32_t MONDTCTL3;
        stc_dma_mondtctl_field_t MONDTCTL3_f;
    };
    union
    {
        __IO uint32_t MONRPT3;
        stc_dma_monrpt_field_t MONRPT3_f;
    };
    union
    {
        __IO uint32_t MONSNSEQCTL3;
        stc_dma_monsnseqctl_field_t MONSNSEQCTL3_f;
    };
    union
    {
        __IO uint32_t MONDNSEQCTL3;
        stc_dma_mondnseqctl_field_t MONDNSEQCTL3_f;
    };
} amhw_hc32f460_dma_t;


/**
 * \brief DMA transfer mode select
 */
typedef enum {
    AMHW_HC32F460_DMA_PER_TO_MER,     /**< \brief DMA peripheral to memory mode */
    AMHW_HC32F460_DMA_MER_TO_PER,     /**< \brief DMA memory to peripheral mode */
    AMHW_HC32F460_DMA_MER_TO_MER,     /**< \brief DMA memory to memory mode */
    AMHW_HC32F460_DMA_PER_TO_PER      /**< \brief DMA peripheral to peripheral mode */
} amhw_hc32f460_dma_transfer_type_t;


/**
 * \brief DMA descriptor
 */
typedef struct amhw_hc32f460_dma_xfer_desc {
    volatile uint32_t          xfercfg;        /**< \brief transfer configuration */
    volatile uint32_t          src_addr;       /**< \brief source address */
    volatile uint32_t          dst_addr;       /**< \brief destination address */
    volatile uint32_t          nbytes;         /**< \brief the bytes of data to transfer */
} amhw_hc32f460_dma_xfer_desc_t;

/**
 * \brief DMA chain transmission descriptor
 */
typedef struct amhw_hc32f460_dma_chain_xfer_desc {
    volatile uint32_t src_addr;       /**< \brief Դ��ַ  */
    volatile uint32_t dst_addr;       /**< \brief Ŀ���ַ  */
    volatile uint32_t data_ctrl;      /**< \brief ���ݿ��ƼĴ���  */
    volatile uint32_t rpt;            /**< \brief �ظ������С�Ĵ���  */
    volatile uint32_t snseqctl;       /**< \brief Դ�豸��������ַ������ƼĴ���  */
    volatile uint32_t dnseqctl;       /**< \brief Ŀ���豸��������ַ������ƼĴ���  */
    volatile uint32_t llp;            /**< \brief ��ָ��Ĵ���  */
    volatile uint32_t ch_ctl;         /**< \brief ͨ�����ƼĴ���  */
} amhw_hc32f460_dma_chain_xfer_desc_t;

/**
 * \brief DMA ͨ����ʹ�ܿ���λ     ʹ��
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_enable(amhw_hc32f460_dma_t *p_hw_dma)
{
    p_hw_dma->EN_f.EN = 0x01;
}

/**
 * \brief DMA ͨ����ʹ�ܿ���λ     ����
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_disable(amhw_hc32f460_dma_t *p_hw_dma)
{
    p_hw_dma->EN_f.EN = 0x0;
}


/**
 * \brief DMA ͨ��״̬��־λ
 *@{
 */
typedef enum {
    AMHW_HC32F460_DMA_CHSTAT_DMAACT     = 0,               /* DMA��������λ */
    AMHW_HC32F460_DMA_CHSTAT_RCFGACT    = 1 ,              /* DMAͨ�����ö����м���λ */
    AMHW_HC32F460_DMA_CHSTAT_CHACT      = 16,              /* ���䶯����ͨ������λ */
}amhw_hc32f460_dma_trans_status_t;

/**
 * \brief DMA ����ͨ���Ĵ���״̬   ��ȡ
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 *
 * \note
 *
 * \return none
 */
am_static_inline
am_bool_t amhw_hc32f460_dma_transfer_check (amhw_hc32f460_dma_t             *p_hw_dma,
                                            uint8_t                          channel,
                                            amhw_hc32f460_dma_trans_status_t flag)
{
    if (flag == AMHW_HC32F460_DMA_CHSTAT_DMAACT) {
        /* DMA�Ƿ��ڴ��䶯���� */
        return ((p_hw_dma->CHSTAT) & 0x1ul) ? AM_TRUE : AM_FALSE;
    } else if (flag == AMHW_HC32F460_DMA_CHSTAT_RCFGACT) {
        /* DMA�Ƿ�ͨ�����ö����� */
        return ((p_hw_dma->CHSTAT) & 0x2ul) ? AM_TRUE : AM_FALSE;
    } else if (flag == AMHW_HC32F460_DMA_CHSTAT_CHACT) {
        /* DMA��Ӧͨ���Ƿ��ڶ����� */
        return (((p_hw_dma->CHSTAT) >> 16) & (1 << channel)) ? AM_TRUE : AM_FALSE;
    } else {
        return -AM_EINVAL;
    }
}


/**
 * \brief DMA ĳһͨ����ʹ�ܿ���λ    ʹ��
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 *
 * \note CHEN[3:0]ÿ��λ��Ӧһ��ͨ����ʹ�ø�ͨ���轫��λ��1.���������ʹ��λ����Ϊ1��
 *       ��������ɴ����Ĵ���DMA_DTCTLx.CNT���õĴ�������󽫻��Զ����㡣���DMA_CTLx.CNT
 *       ����Ϊ0��������ɺ󲻻��Զ����㣬�����޴δ��䡣
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_enable(amhw_hc32f460_dma_t *p_hw_dma,
                                   uint8_t              channel)
{
    p_hw_dma->CHEN_f.CHEN |= (1 << channel);
}

/**
 * \brief DMA ĳһͨ����ʹ�ܿ���λ    ����
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 *
 * \note CHEN[3:0]ÿ��λ��Ӧһ��ͨ����ʹ�ø�ͨ���轫��λ��1.���������ʹ��λ����Ϊ1��
 *       ��������ɴ����Ĵ���DMA_DTCTLx.CNT���õĴ�������󽫻��Զ����㡣���DMA_CTLx.CNT
 *       ����Ϊ0��������ɺ󲻻��Զ����㣬�����޴δ��䡣
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_disable(amhw_hc32f460_dma_t *p_hw_dma,
                                    uint8_t              channel)
{
    p_hw_dma->CHEN_f.CHEN &= (~(1 << channel));
}


#define HC32F460_AOS_DMA1_TRIGSEL0_BASE    (HC32F460_AOS_BASE + 20UL)
#define HC32F460_AOS_DMA2_TRIGSEL0_BASE    (HC32F460_AOS_BASE + 36UL)

/**
 * \brief DMA TRGSEL[8:0]λѡ��������Ĵ���Դ
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] src        : ���������趨��hc32f460_dma_chan.h�궨�壩
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_trigger_src_set(amhw_hc32f460_dma_t *p_hw_dma,
                                            uint8_t             id,
                                            uint8_t             channel,
                                            en_event_src_t      src)
{
    if (id == 1) {
        *(volatile uint32_t *)((uint32_t)(HC32F460_AOS_DMA1_TRIGSEL0_BASE) + (channel) * 4ul) = src;
    } else if (id == 2){
        *(volatile uint32_t *)((uint32_t)(HC32F460_AOS_DMA2_TRIGSEL0_BASE) + (channel) * 4ul) = src;
    }
}

/**
 * \brief DMA TRGSELRC[8:0]λѡ����������Ĵ���Դ
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] src        : ���������趨��hc32f460_dma_chan.h�궨�壩
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_rcfg_trigger_src_set(en_event_src_t      src)
{
    *(uint32_t *)(0x40010834) = src;
}

/**
 * \brief DMA BLKSIZE[9:0]λָ����Ĵ�С
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] num        : ����ֵ
 *
 * \note �������ݿ�Ĵ�С������������1024�����ݡ�ÿ�����ݵĿ�����DMA_CHxCTL�Ĵ�����HSIZEλ������
 *       �Ĵ���ֵ�趨λ1��ÿ�δ���1�����ݣ���Ϊ0��ÿ�δ���1024�����ݡ�
 *
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_blksize_set(amhw_hc32f460_dma_t *p_hw_dma,
                                        uint8_t              channel,
                                        uint16_t              size)
{
    *(uint32_t *)(((uint32_t)&(p_hw_dma->DTCTL0)) + (channel * 0x40)) &= (~0x3FF);
    *(uint32_t *)(((uint32_t)&(p_hw_dma->DTCTL0)) + (channel * 0x40)) |= size;
}

/**
 * \brief DMA BLKSIZE[9:0] ��ȡ��Ĵ�С
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 *
 * \note �������ݿ�Ĵ�С������������1024�����ݡ�ÿ�����ݵĿ�����DMA_CHxCTL�Ĵ�����HSIZEλ������
 *       �Ĵ���ֵ�趨λ1��ÿ�δ���1�����ݣ���Ϊ0��ÿ�δ���1024�����ݡ�
 *
 *
 * \return ���ݿ�Ĵ�С��
 */
am_static_inline
uint16_t amhw_hc32f460_dma_chan_blksize_get(amhw_hc32f460_dma_t *p_hw_dma,
                                            uint8_t              channel)
{
    return *(uint32_t *)((uint32_t)(&(p_hw_dma->DTCTL0)) + (channel * 0x40)) & (0x3FF);
}

/**
 * \brief DMA CNT[15:0] λ����ָ���ܵĴ��������
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] num        : ����ֵ(���65535)
 *
 * \note ÿ����������һ�����ݿ�Ĵ��䣬���ʱ���������1��������0ʱ������������жϡ��������Ϊ0��
 *       ��ʾ���ߴδ��䣬ÿ������������һ�����ݿ飬���ʱ�����������0���䣬���������������жϡ�
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_tran_data_num_set (amhw_hc32f460_dma_t *p_hw_dma,
                                               uint8_t              channel,
                                               uint16_t             num)
{
    *(uint32_t *)((uint32_t)(&(p_hw_dma->DTCTL0)) + (channel * 0x40)) &= (~0xFFFF0000);
    *(uint32_t *)((uint32_t)(&(p_hw_dma->DTCTL0)) + (channel * 0x40)) |= (num << 16);

}

/**
 * \brief DMA CNT[15:0] λ����ָ����Ĵ��������     ��ȡ
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 *
 * \note
 *
 * \return ��ǰ����ʣ��Ĵ�����
 */
am_static_inline
uint16_t amhw_hc32f460_dma_chan_tran_data_num_get (amhw_hc32f460_dma_t *p_hw_dma,
                                                   uint8_t              channel)
{
    return (*(uint32_t *)((uint32_t)(&(p_hw_dma->DTCTL0)) + (channel * 0x40)) >> 16);
}


/**
 * \brief DMA CHxCTL[9:8] λ�������ô������ݵĿ���
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] hsize      : ���ݿ���(ö��amhw_hc32f460_dma_chan_data_hsize)
 *                         00: 8bit
 *                         01: 16bit
 *                         10,11: 32bit
 *
 * \note
 */
am_static_inline
void amhw_hc32f460_dma_chan_data_hsize_set (amhw_hc32f460_dma_t *p_hw_dma,
                                            uint8_t              channel,
                                            uint8_t              hsize)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->CH0CTL) + (channel * 0x40)) &= (~(0x3 << 8));
    *(uint32_t *)((uint32_t)&(p_hw_dma->CH0CTL) + (channel * 0x40)) |= (hsize << 8);
}

/**
 * \brief DMA CHxCTL[9:8] ��ȡ���ô������ݵĿ���
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] hsize      : ���ݿ���(ö��amhw_hc32f460_dma_chan_data_hsize)
 *                         00: 8bit
 *                         01: 16bit
 *                         10,11: 32bit
 *
 * \note
 */
am_static_inline
uint8_t amhw_hc32f460_dma_chan_data_hsize_get (amhw_hc32f460_dma_t *p_hw_dma,
                                               uint8_t              channel)
{
    return (*(uint32_t *)((uint32_t)&(p_hw_dma->CH0CTL) + (channel * 0x40)) & (0x3 << 8)) >> 8;
}

/**
 * \brief DMA CHxCTL[3:2] λ�������ö�Ӧͨ��Ŀ���ַ�ĸ��·�ʽ
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] method     : ���·�ʽ
 *
 * \note
 */
am_static_inline
void amhw_hc32f460_dma_chan_srcaddr_update_set (amhw_hc32f460_dma_t *p_hw_dma,
                                                uint8_t              channel,
                                                uint8_t              method)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->CH0CTL) + (channel * 0x40)) &= (~(0x3 << 2));
    *(uint32_t *)((uint32_t)&(p_hw_dma->CH0CTL) + (channel * 0x40)) |= (method << 2);
}

/**
 * \brief DMA CHxCTL[3:2] λ�������ö�Ӧͨ��Դ��ַ�ĸ��·�ʽ
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] method     : ���·�ʽ
 *
 * \note
 */
am_static_inline
void amhw_hc32f460_dma_chan_dstaddr_update_set (amhw_hc32f460_dma_t *p_hw_dma,
                                                uint8_t              channel,
                                                uint8_t              method)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->CH0CTL) + (channel * 0x40)) &= (~(0x3 << 0));
    *(uint32_t *)((uint32_t)&(p_hw_dma->CH0CTL) + (channel * 0x40)) |= (method << 0);
}


#define  AMHW_HC32F460_DMA_CHAN_CFG_INT_ENABLE      (1UL << 12) /**< \brief ʹ�ܸ�ͨ���ж� */
#define  AMHW_HC32F460_DMA_CHAN_CFG_INT_DISABLE     (1UL << 12) /**< \brief ���ܸ�ͨ���ж� */

#define  AMHW_HC32F460_DMA_CHAN_CFG_LLPRUN_ENABLE   (1 << 11)   /**< \brief ��������ģʽ�£��������������������ʼ���� */
#define  AMHW_HC32F460_DMA_CHAN_CFG_LLPRUN_DISABLE  (0 << 11)   /**< \brief ��������ģʽ�£�������������󣬵���һ���������������ʼ���� */

#define  AMHW_HC32F460_DMA_CHAN_CFG_LLP_ENABLE      (1 << 10)   /**< \brief ��������ʹ�� */
#define  AMHW_HC32F460_DMA_CHAN_CFG_LLP_DISABLE     (0 << 10)   /**< \brief ����������� */

#define  AMHW_HC32F460_DMA_CHAN_CFG_SIZE_8BIT       (0UL << 8)  /**< \brief ���ݿ��� 8bit */
#define  AMHW_HC32F460_DMA_CHAN_CFG_SIZE_16BIT      (1UL << 8)  /**< \brief ���ݿ��� 16bit */
#define  AMHW_HC32F460_DMA_CHAN_CFG_SIZE_32BIT      (2UL << 8)  /**< \brief ���ݿ��� 32bit */

#define  AMHW_HC32F460_DMA_CHAN_CFG_DSTADD_NOTSEQ_ENABLE  (1UL << 7) /**< \brief Ŀ���ַ����������ʹ�� */
#define  AMHW_HC32F460_DMA_CHAN_CFG_DSTADD_NOTSEQ_DISABLE (0UL << 7) /**< \brief Ŀ���ַ������������� */

#define  AMHW_HC32F460_DMA_CHAN_CFG_SRCADD_NOTSEQ_ENABLE  (1UL << 6) /**< \brief Դ��ַ����������ʹ�� */
#define  AMHW_HC32F460_DMA_CHAN_CFG_SRCADD_NOTSEQ_DISABLE (0UL << 6) /**< \brief Դ��ַ������������� */

#define  AMHW_HC32F460_DMA_CHAN_CFG_DST_DRPT_ENABLE  (1UL << 5) /**< \brief Ŀ���ظ����书��ʹ�� */
#define  AMHW_HC32F460_DMA_CHAN_CFG_DST_DRPT_DISABLE (0UL << 5) /**< \brief Ŀ���ظ����书�ܽ��� */

#define  AMHW_HC32F460_DMA_CHAN_CFG_SRC_DRPT_ENABLE  (1UL << 4) /**< \brief Դ�ظ����书��ʹ�� */
#define  AMHW_HC32F460_DMA_CHAN_CFG_SRC_DRPT_DISABLE (0UL << 4) /**< \brief Դ�ظ����书�ܽ��� */

#define  AMHW_HC32F460_DMA_CHAN_DST_ADD_FIXED      (0UL << 2) /**< \brief Ŀ���ַ�̶� */
#define  AMHW_HC32F460_DMA_CHAN_DST_ADD_INCREASING (1UL << 2) /**< \brief Ŀ���ַ���� */
#define  AMHW_HC32F460_DMA_CHAN_DST_ADD_DECREASING (2UL << 2) /**< \brief Ŀ���ַ�ݼ� */

#define  AMHW_HC32F460_DMA_CHAN_SRC_ADD_FIXED      (0UL << 0) /**< \brief Դ��ַ�̶� */
#define  AMHW_HC32F460_DMA_CHAN_SRC_ADD_INCREASING (1UL << 0) /**< \brief Դ��ַ���� */
#define  AMHW_HC32F460_DMA_CHAN_SRC_ADD_DECREASING (2UL << 0) /**< \brief Դ��ַ�ݼ� */
/**
 * \brief DMA ͨ�����ƼĴ�������
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] flag       : ���ñ�־
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_config_set(amhw_hc32f460_dma_t *p_hw_dma,
                                       uint8_t              channel,
                                       uint32_t             flag)

{
    *(uint32_t *)((uint32_t)&(p_hw_dma->CH0CTL) + (channel * 0x40)) = flag;
}


#define  AMHW_HC32F460_DMA_CHAN_INT_ERR      (1UL << 20) /**< \brief δ����ж�  */
#define  AMHW_HC32F460_DMA_CHAN_INT_TX_CMP   (1UL << 19) /**< \brief ����ж� */

/**
 * \brief DMA �ж�״̬
 *@{
 */
typedef enum {
    AMHW_HC32F460_DMA_INT_FLAG_DEFAULT         = 0,         /**< \brief ��ʼĬ��ֵ */
    AMHW_HC32F460_DMA_INT_FLAG_ERR_REQ_ERR     = (1 << 0),  /**< \brief ����������������ж� */
    AMHW_HC32F460_DMA_INT_FLAG_ERR_TRNERR      = (1 << 1),  /**< \brief ��������ж� */
    AMHW_HC32F460_DMA_INT_FLAG_BLK_TX_COMPLETE = (1 << 2),  /**< \brief �鴫������ж� */
    AMHW_HC32F460_DMA_INT_FLAG_TX_COMPLETE     = (1 << 3),  /**< \brief ��������ж�*/
}amhw_hc32f460_dma_int_flag_t;
/**
 * \brief DMA ĳһͨ���ж�ʹ��
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_int_enable(amhw_hc32f460_dma_t *p_hw_dma,
                                       uint8_t              channel)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->CH0CTL) + (channel * 0x40)) |= (1 << 12);
}

/**
 * \brief DMA ĳһͨ���жϽ���
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_int_disable(amhw_hc32f460_dma_t *p_hw_dma,
                                        uint8_t              channel)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->CH0CTL) + (channel * 0x40)) &= (~(1 << 12));
}

/**
 * \brief �����ж����μĴ���
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] chan       : ͨ����
 * \param[in] flag       : �жϱ��
 *
 * \note

 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_int_mask_set(amhw_hc32f460_dma_t *p_hw_dma,
                                    uint8_t              chan,
                                    uint32_t             flag)
{
    if (flag == AMHW_HC32F460_DMA_INT_FLAG_ERR_REQ_ERR) {
        p_hw_dma->INTMASK0_f.MSKREQERR |= (1 << chan);
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_ERR_TRNERR) {
        p_hw_dma->INTMASK0_f.MSKTRNERR |= (1 << chan);
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_BLK_TX_COMPLETE) {
        p_hw_dma->INTMASK1_f.MSKBTC    |= (1 << chan);
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_TX_COMPLETE) {
        p_hw_dma->INTMASK1_f.MSKTC     |= (1 << chan);
    }
}

/**
 * \brief ����ж����μĴ���
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] chan       : ͨ����
 * \param[in] flag       : �жϱ��
 *
 * \note

 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_int_mask_clr(amhw_hc32f460_dma_t *p_hw_dma,
                                    uint8_t              chan,
                                    uint32_t             flag)
{
    if (flag == AMHW_HC32F460_DMA_INT_FLAG_ERR_REQ_ERR) {
        p_hw_dma->INTMASK0_f.MSKREQERR &= (~(1 << chan));
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_ERR_TRNERR) {
        p_hw_dma->INTMASK0_f.MSKTRNERR &= (~(1 << chan));
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_BLK_TX_COMPLETE) {
        p_hw_dma->INTMASK1_f.MSKBTC    &= (~(1 << chan));
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_TX_COMPLETE) {
        p_hw_dma->INTMASK1_f.MSKTC     &= (~(1 << chan));
    }
}


/**
 * \brief �ж�״̬��־��ȡ
 *
 * \param[in] p_hw_dma : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel  : ͨ����
 * \param[in] flag     : ״̬��־
 *
 * \return AM_TRUE or AM_FALSE
 */
am_static_inline
am_bool_t amhw_hc32f460_dma_chan_stat_check (amhw_hc32f460_dma_t         *p_hw_dma,
                                             uint8_t                      channel,
                                             amhw_hc32f460_dma_int_flag_t flag)
{
    if (flag == AMHW_HC32F460_DMA_INT_FLAG_ERR_REQ_ERR) {
        return (((p_hw_dma->INTSTAT0 >> 16) & (1 << channel)) ? AM_TRUE: AM_FALSE);
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_ERR_TRNERR) {
        return (((p_hw_dma->INTSTAT0 >> 0) & (1 << channel)) ? AM_TRUE: AM_FALSE);
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_BLK_TX_COMPLETE) {
        return (((p_hw_dma->INTSTAT1 >> 16) & (1 << channel)) ? AM_TRUE: AM_FALSE);
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_TX_COMPLETE) {
        return (((p_hw_dma->INTSTAT1 >> 0) & (1 << channel)) ? AM_TRUE: AM_FALSE);
    } else {
        return -AM_EINVAL;
    }
}

/**
 * \brief �ж�״̬��־���
 *
 * \param[in] p_hw_dma    : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel     : ͨ����
 * \param[in] flag        : ״̬��־
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_flag_clear (amhw_hc32f460_dma_t         *p_hw_dma,
                                        uint8_t                      channel,
                                        amhw_hc32f460_dma_int_flag_t flag)
{
    if (flag == AMHW_HC32F460_DMA_INT_FLAG_ERR_REQ_ERR) {
        p_hw_dma->INTCLR0 |= (1 << (16 + channel));
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_ERR_TRNERR) {
        p_hw_dma->INTCLR0 |= (1 << (0 + channel));
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_BLK_TX_COMPLETE) {
        p_hw_dma->INTCLR1 |= (1 << (16 + channel));
    } else if (flag == AMHW_HC32F460_DMA_INT_FLAG_TX_COMPLETE) {
        p_hw_dma->INTCLR1 |= (1 << (0 + channel));
    }
}

/**
 * \brief Դ��ַ����
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] address    : ��ַ
 *
 * \note
 *
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_src_address_set(amhw_hc32f460_dma_t *p_hw_dma,
                                            uint8_t            channel,
                                            uint32_t           address)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->SAR0) + (channel * 0x40)) =  address;
}

/**
 * \brief Ŀ���ַ����
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] address    : ��ַ
 *
 * \note

 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_dst_address_set(amhw_hc32f460_dma_t *p_hw_dma,
                                            uint8_t              channel,
                                            uint32_t             address)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->DAR0) + (channel * 0x40)) =  address;
}

/**
 * \brief DMA���ݿ��ƼĴ�������
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] cfg        : ����ֵ
 *
 * \note

 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_dtctl_set(amhw_hc32f460_dma_t *p_hw_dma,
                                      uint8_t              channel,
                                      uint32_t             cfg)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->DTCTL0) + (channel * 0x40)) =  cfg;
}

/**
 * \brief DMA�ظ�����Ĵ�������
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] cfg        : ����ֵ
 *
 * \note

 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_rpt_set(amhw_hc32f460_dma_t *p_hw_dma,
                                    uint8_t              channel,
                                    uint32_t             cfg)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->RPT0) + (channel * 0x40)) =  cfg;
}

/**
 * \brief DMAĿ���ַ�ظ������С����
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] size       : Ŀ���ַ�ظ������С�������ݸ���Ϊ��λ��
 *
 * \note

 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_drpt_set(amhw_hc32f460_dma_t *p_hw_dma,
                                     uint8_t              channel,
                                     uint32_t             size)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->RPT0) + (channel * 0x40)) &= (~(0x3FF << 16));
    *(uint32_t *)((uint32_t)&(p_hw_dma->RPT0) + (channel * 0x40)) |= (size << 16);
}

/**
 * \brief DMAԴ��ַ�ظ������С����
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] size       : Դ��ַ�ظ������С�������ݸ���Ϊ��λ��
 *
 * \note

 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_srpt_set(amhw_hc32f460_dma_t *p_hw_dma,
                                     uint8_t              channel,
                                     uint32_t             size)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->RPT0) + (channel * 0x40)) &= (~0x3FF);
    *(uint32_t *)((uint32_t)&(p_hw_dma->RPT0) + (channel * 0x40)) |= size;
}

/**
 * \brief DMAԴ�豸��������ַ������ƼĴ�������
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] cfg        : ����ֵ
 *
 * \note
 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_snseqctl_set(amhw_hc32f460_dma_t *p_hw_dma,
                                         uint8_t              channel,
                                         uint32_t             cfg)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->SNSEQCTL0) + (channel * 0x40)) =  cfg;
}

/**
 * \brief DMAĿ���豸��������ַ������ƼĴ�������
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] cfg        : ����ֵ
 *
 * \note

 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_dnseqctl_set(amhw_hc32f460_dma_t *p_hw_dma,
                                         uint8_t              channel,
                                         uint32_t             cfg)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->DNSEQCTL0) + (channel * 0x40)) =  cfg;
}

/**
 * \brief DMA��ָ��Ĵ�������
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] cfg        : ����ֵ
 *
 * \note

 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_llp_set(amhw_hc32f460_dma_t *p_hw_dma,
                                    uint8_t              channel,
                                    uint32_t             cfg)
{
    *(uint32_t *)((uint32_t)&(p_hw_dma->LLP0) + (channel * 0x40)) =  cfg;
}

/**
 * \brief DMAͨ�����ÿ��ƼĴ�������
 *
 * \param[in] p_hw_dma   : ָ��DMA�Ĵ����ṹ���ָ��
 * \param[in] channel    : ͨ����
 * \param[in] cfg        : ����ֵ
 *
 * \note

 * \return none
 */
am_static_inline
void amhw_hc32f460_dma_chan_rcfg_set(amhw_hc32f460_dma_t *p_hw_dma, uint32_t flag)
{
    p_hw_dma->RCFGCTL = flag;
}




/**
 * @} amhw_if_hc32f460_dma
 */

#ifdef __cplusplus
}
#endif

#endif  /* __AMHW_HC32F460_DMA_H */

/* end of file */