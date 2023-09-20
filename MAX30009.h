/*******************************************************************************
* Copyright (C) 2023 Maxim Integrated Products, Inc., All rights Reserved.
*
* This software is protected by copyright laws of the United States and
* of foreign countries. This material may also be protected by patent laws
* and technology transfer regulations of the United States and of foreign
* countries. This software is furnished under a license agreement and/or a
* nondisclosure agreement and may only be used or reproduced in accordance
* with the terms of those agreements. Dissemination of this information to
* any party or parties not specified in the license agreement and/or
* nondisclosure agreement is expressly prohibited.
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated
* Products, Inc. shall not be used except as stated in the Maxim Integrated
* Products, Inc. Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products, Inc. retains all
* ownership rights.
*******************************************************************************
*/
/*
 * Analog Devices
 * File contents using max30009_reg.csv
 * Friday, March 17, 2023 11:09:25 AM
 */


/*
Added by me:
**************************************************************/
void init();
#define NUM_SAMPLES_PER_INT		2	/* number of samples in FIFO that generates a FIFO_A_FULL interrupt */
#define NUM_BYTES_PER_SAMPLE 3



















//*********************************
#ifndef MAX30009_H
#define MAX30009_H
// Section - Status
#define STATUS_1_REGISTER	0x00
#define A_FULL_MASK	0x80
#define A_FULL_SHIFT	7
#define FIFO_DATA_RDY_MASK	0x20
#define FIFO_DATA_RDY_SHIFT	5
#define FREQ_UNLOCK_MASK	0x10
#define FREQ_UNLOCK_SHIFT	4
#define FREQ_LOCK_MASK	0x08
#define FREQ_LOCK_SHIFT	3
#define PHASE_UNLOCK_MASK	0x04
#define PHASE_UNLOCK_SHIFT	2
#define PHASE_LOCK_MASK	0x02
#define PHASE_LOCK_SHIFT	1
#define PWR_RDY_MASK	0x01
#define PWR_RDY_SHIFT	0

#define STATUS_2_REGISTER	0x01
#define LON_MASK	0x80
#define LON_SHIFT	7
#define BIOZ_OVER_MASK	0x40
#define BIOZ_OVER_SHIFT	6
#define BIOZ_UNDR_MASK	0x20
#define BIOZ_UNDR_SHIFT	5
#define DRV_OOR_MASK	0x10
#define DRV_OOR_SHIFT	4
#define DC_LOFF_PH_MASK	0x08
#define DC_LOFF_PH_SHIFT	3
#define DC_LOFF_PL_MASK	0x04
#define DC_LOFF_PL_SHIFT	2
#define DC_LOFF_NH_MASK	0x02
#define DC_LOFF_NH_SHIFT	1
#define DC_LOFF_NL_MASK	0x01
#define DC_LOFF_NL_SHIFT	0

// Section - FIFO
#define FIFO_WRITE_POINTER_REGISTER	0x08
#define FIFO_WR_PTR_MASK	0xFF
#define FIFO_WR_PTR_SHIFT	0

#define FIFO_READ_POINTER_REGISTER	0x09
#define FIFO_RD_PTR_MASK	0xFF
#define FIFO_RD_PTR_SHIFT	0

#define FIFO_COUNTER_1_REGISTER	0x0A
#define FIFO_DATA_COUNT_MSB_MASK	0x80
#define FIFO_DATA_COUNT_MSB_SHIFT	7
#define OVF_COUNTER_MASK	0x7F
#define OVF_COUNTER_SHIFT	0

#define FIFO_COUNTER_2_REGISTER	0x0B
#define FIFO_DATA_COUNT_LSB_MASK	0xFF
#define FIFO_DATA_COUNT_LSB_SHIFT	0

#define FIFO_DATA_REGISTER_REGISTER	0x0C
#define FIFO_DATA_MASK	0xFF
#define FIFO_DATA_SHIFT	0

#define FIFO_CONFIGURATION_1_REGISTER	0x0D
#define FIFO_A_FULL_MASK	0xFF
#define FIFO_A_FULL_SHIFT	0

#define FIFO_CONFIGURATION_2_REGISTER	0x0E
#define FIFO_MARK_MASK	0x20
#define FIFO_MARK_SHIFT	5
#define FLUSH_FIFO_MASK	0x10
#define FLUSH_FIFO_SHIFT	4
#define FIFO_STAT_CLR_MASK	0x08
#define FIFO_STAT_CLR_SHIFT	3
#define A_FULL_TYPE_MASK	0x04
#define A_FULL_TYPE_SHIFT	2
#define FIFO_RO_MASK	0x02
#define FIFO_RO_SHIFT	1

// Section - System Control
#define SYSTEM_SYNC_REGISTER	0x10
#define TIMING_SYS_RESET_MASK	0x80
#define TIMING_SYS_RESET_SHIFT	7

#define SYSTEM_CONFIGURATION_1_REGISTER	0x11
#define MASTER_MASK	0x80
#define MASTER_SHIFT	7
#define DISABLE_I2C_MASK	0x40
#define DISABLE_I2C_SHIFT	6
#define SHDN_MASK	0x02
#define SHDN_SHIFT	1
#define RESET_MASK	0x01
#define RESET_SHIFT	0

#define PIN_FUNCTIONAL_CONFIGURATION_REGISTER	0x12
#define INT_FCFG_MASK	0x0C
#define INT_FCFG_SHIFT	2
#define TRIG_ICFG_MASK	0x01
#define TRIG_ICFG_SHIFT	0

#define OUTPUT_PIN_CONFIGURATION_REGISTER	0x13
#define INT_OCFG_MASK	0x0C
#define INT_OCFG_SHIFT	2
#define TRIG_OCFG_MASK	0x03
#define TRIG_OCFG_SHIFT	0

#define I2C_BROADCAST_ADDRESS_REGISTER	0x14
#define I2C_BCAST_ADDR_MASK	0xFE
#define I2C_BCAST_ADDR_SHIFT	1
#define I2C_BCAST_EN_MASK	0x01
#define I2C_BCAST_EN_SHIFT	0

// Section - PLL
#define PLL_CONFIGURATION_1_REGISTER	0x17
#define MDIV_MSB_MASK	0xC0
#define MDIV_MSB_SHIFT	6
#define NDIV_MASK	0x20
#define NDIV_SHIFT	5
#define KDIV_MASK	0x1E
#define KDIV_SHIFT	1
#define PLL_EN_MASK	0x01
#define PLL_EN_SHIFT	0

#define PLL_CONFIGURATION_2_REGISTER	0x18
#define MDIV_LSB_MASK	0xFF
#define MDIV_LSB_SHIFT	0

#define PLL_CONFIGURATION_3_REGISTER	0x19
#define PLL_LOCK_WNDW_MASK	0x01
#define PLL_LOCK_WNDW_SHIFT	0

#define PLL_CONFIGURATION_4_REGISTER	0x1A
#define REF_CLK_SEL_MASK	0x40
#define REF_CLK_SEL_SHIFT	6
#define CLK_FREQ_SEL_MASK	0x20
#define CLK_FREQ_SEL_SHIFT	5
#define CLK_FINE_TUNE_MASK	0x1F
#define CLK_FINE_TUNE_SHIFT	0

// Section - BioZ Setup
#define BIOZ_CONFIGURATION_1_REGISTER	0x20
#define BIOZ_DAC_OSR_MASK	0xC0
#define BIOZ_DAC_OSR_SHIFT	6
#define BIOZ_ADC_OSR_MASK	0x38
#define BIOZ_ADC_OSR_SHIFT	3
#define BIOZ_BG_EN_MASK	0x04
#define BIOZ_BG_EN_SHIFT	2
#define BIOZ_Q_EN_MASK	0x02
#define BIOZ_Q_EN_SHIFT	1
#define BIOZ_I_EN_MASK	0x01
#define BIOZ_I_EN_SHIFT	0

#define BIOZ_CONFIGURATION_2_REGISTER	0x21
#define BIOZ_DHPF_MASK	0xC0
#define BIOZ_DHPF_SHIFT	6
#define BIOZ_DLPF_MASK	0x38
#define BIOZ_DLPF_SHIFT	3
#define BIOZ_CMP_MASK	0x06
#define BIOZ_CMP_SHIFT	1
#define EN_BIOZ_THRESH_MASK	0x01
#define EN_BIOZ_THRESH_SHIFT	0

#define BIOZ_CONFIGURATION_3_REGISTER	0x22
#define BIOZ_EXT_RES_MASK	0x80
#define BIOZ_EXT_RES_SHIFT	7
#define LOFF_RAPID_MASK	0x40
#define LOFF_RAPID_SHIFT	6
#define BIOZ_VDRV_MAG_MASK	0x30
#define BIOZ_VDRV_MAG_SHIFT	4
#define BIOZ_IDRV_RGE_MASK	0x0C
#define BIOZ_IDRV_RGE_SHIFT	2
#define BIOZ_DRV_MODE_MASK	0x03
#define BIOZ_DRV_MODE_SHIFT	0

#define BIOZ_CONFIGURATION_4_REGISTER	0x23
#define BIOZ_FAST_MANUAL_MASK	0x02
#define BIOZ_FAST_MANUAL_SHIFT	1
#define BIOZ_FAST_START_EN_MASK	0x01
#define BIOZ_FAST_START_EN_SHIFT	0

#define BIOZ_CONFIGURATION_5_REGISTER	0x24
#define BIOZ_AHPF_MASK	0xF0
#define BIOZ_AHPF_SHIFT	4
#define BIOZ_INA_MODE_MASK	0x08
#define BIOZ_INA_MODE_SHIFT	3
#define BIOZ_DM_DIS_MASK	0x04
#define BIOZ_DM_DIS_SHIFT	2
#define BIOZ_GAIN_MASK	0x03
#define BIOZ_GAIN_SHIFT	0

#define BIOZ_CONFIGURATION_6_REGISTER	0x25
#define BIOZ_EXT_CAP_MASK	0x80
#define BIOZ_EXT_CAP_SHIFT	7
#define BIOZ_DC_RESTORE_MASK	0x40
#define BIOZ_DC_RESTORE_SHIFT	6
#define BIOZ_DRV_RESET_MASK	0x20
#define BIOZ_DRV_RESET_SHIFT	5
#define BIOZ_DAC_RESET_MASK	0x10
#define BIOZ_DAC_RESET_SHIFT	4
#define BIOZ_AMP_RGE_MASK	0x0C
#define BIOZ_AMP_RGE_SHIFT	2
#define BIOZ_AMP_BW_MASK	0x03
#define BIOZ_AMP_BW_SHIFT	0

#define BIOZ_LOW_THRESHOLD_REGISTER	0x26
#define BIOZ_LO_THRESH_MASK	0xFF
#define BIOZ_LO_THRESH_SHIFT	0

#define BIOZ_HIGH_THRESHOLD_REGISTER	0x27
#define BIOZ_HI_THRESH_MASK	0xFF
#define BIOZ_HI_THRESH_SHIFT	0

#define BIOZ_CONFIGURATION_7_REGISTER	0x28
#define BIOZ_STBYON_MASK	0x10
#define BIOZ_STBYON_SHIFT	4
#define BIOZ_Q_CLK_PHASE_MASK	0x08
#define BIOZ_Q_CLK_PHASE_SHIFT	3
#define BIOZ_I_CLK_PHASE_MASK	0x04
#define BIOZ_I_CLK_PHASE_SHIFT	2
#define BIOZ_INA_CHOP_EN_MASK	0x02
#define BIOZ_INA_CHOP_EN_SHIFT	1
#define BIOZ_CH_FSEL_MASK	0x01
#define BIOZ_CH_FSEL_SHIFT	0

// Section - BioZ Calibration
#define BIOZ_MUX_CONFIGURATION_1_REGISTER	0x41
#define BMUX_RSEL_MASK	0xC0
#define BMUX_RSEL_SHIFT	6
#define BMUX_BIST_EN_MASK	0x20
#define BMUX_BIST_EN_SHIFT	5
#define CONNECT_CAL_ONLY_MASK	0x04
#define CONNECT_CAL_ONLY_SHIFT	2
#define MUX_EN_MASK	0x02
#define MUX_EN_SHIFT	1
#define CAL_EN_MASK	0x01
#define CAL_EN_SHIFT	0

#define BIOZ_MUX_CONFIGURATION_2_REGISTER	0x42
#define BMUX_GSR_RSEL_MASK	0xC0
#define BMUX_GSR_RSEL_SHIFT	6
#define GSR_LOAD_EN_MASK	0x20
#define GSR_LOAD_EN_SHIFT	5
#define EN_EXT_INLOAD_MASK	0x02
#define EN_EXT_INLOAD_SHIFT	1
#define EN_INT_INLOAD_MASK	0x01
#define EN_INT_INLOAD_SHIFT	0

#define BIOZ_MUX_CONFIGURATION_3_REGISTER	0x43
#define BIP_ASSIGN_MASK	0xC0
#define BIP_ASSIGN_SHIFT	6
#define BIN_ASSIGN_MASK	0x30
#define BIN_ASSIGN_SHIFT	4
#define DRVP_ASSIGN_MASK	0x0C
#define DRVP_ASSIGN_SHIFT	2
#define DRVN_ASSIGN_MASK	0x03
#define DRVN_ASSIGN_SHIFT	0

#define BIOZ_MUX_CONFIGURATION_4_REGISTER	0x44
#define BIST_R_ERR_MASK	0xFF
#define BIST_R_ERR_SHIFT	0

// Section - DC Leads Setup
#define DC_LEADS_CONFIGURATION_REGISTER	0x50
#define EN_LON_DET_MASK	0x80
#define EN_LON_DET_SHIFT	7
#define EN_LOFF_DET_MASK	0x40
#define EN_LOFF_DET_SHIFT	6
#define EN_EXT_LOFF_MASK	0x20
#define EN_EXT_LOFF_SHIFT	5
#define EN_DRV_OOR_MASK	0x10
#define EN_DRV_OOR_SHIFT	4
#define LOFF_IPOL_MASK	0x08
#define LOFF_IPOL_SHIFT	3
#define LOFF_IMAG_MASK	0x07
#define LOFF_IMAG_SHIFT	0

#define DC_LEAD_DETECT_THRESHOLD_REGISTER	0x51
#define LOFF_THRESH_MASK	0x0F
#define LOFF_THRESH_SHIFT	0

// Section - Lead Bias
#define LEAD_BIAS_CONFIGURATION_1_REGISTER	0x58
#define RBIAS_VALUE_MASK	0x0C
#define RBIAS_VALUE_SHIFT	2
#define EN_RBIAS_BIP_MASK	0x02
#define EN_RBIAS_BIP_SHIFT	1
#define EN_RBIAS_BIN_MASK	0x01
#define EN_RBIAS_BIN_SHIFT	0

// Section - Interrupt Enables
#define INTERRUPT_ENABLE_1_REGISTER	0x80
#define A_FULL_EN_MASK	0x80
#define A_FULL_EN_SHIFT	7
#define FIFO_DATA_RDY_EN_MASK	0x20
#define FIFO_DATA_RDY_EN_SHIFT	5
#define FREQ_UNLOCK_EN_MASK	0x10
#define FREQ_UNLOCK_EN_SHIFT	4
#define FREQ_LOCK_EN_MASK	0x08
#define FREQ_LOCK_EN_SHIFT	3
#define PHASE_UNLOCK_EN_MASK	0x04
#define PHASE_UNLOCK_EN_SHIFT	2
#define PHASE_LOCK_EN_MASK	0x02
#define PHASE_LOCK_EN_SHIFT	1

#define INTERRUPT_ENABLE_2_REGISTER	0x81
#define LON_EN_MASK	0x80
#define LON_EN_SHIFT	7
#define BIOZ_OVER_EN_MASK	0x40
#define BIOZ_OVER_EN_SHIFT	6
#define BIOZ_UNDR_EN_MASK	0x20
#define BIOZ_UNDR_EN_SHIFT	5
#define DRVP_OFF_EN_MASK	0x10
#define DRVP_OFF_EN_SHIFT	4
#define DC_LOFF_PH_EN_MASK	0x08
#define DC_LOFF_PH_EN_SHIFT	3
#define DC_LOFF_PL_EN_MASK	0x04
#define DC_LOFF_PL_EN_SHIFT	2
#define DC_LOFF_NH_EN_MASK	0x02
#define DC_LOFF_NH_EN_SHIFT	1
#define DC_LOFF_NL_EN_MASK	0x01
#define DC_LOFF_NL_EN_SHIFT	0

// Section - Part ID
#define PART_ID_REGISTER	0xFF
#define PART_ID_MASK	0xFF
#define PART_ID_SHIFT	0

#endif
