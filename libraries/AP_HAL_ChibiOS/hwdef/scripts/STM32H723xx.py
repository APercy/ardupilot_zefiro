#!/usr/bin/env python
'''
these tables are generated from the STM32 datasheets for the STM32H723VG
'''

# additional build information for ChibiOS
build = {
    "CHIBIOS_STARTUP_MK"  : "os/common/startup/ARMCMx/compilers/GCC/mk/startup_stm32h7xx.mk",
    "CHIBIOS_PLATFORM_MK" : "os/hal/ports/STM32/STM32H7xx/platform_type2.mk"
    }

# MCU parameters
mcu = {
    # DMA peripheral capabilities:
    # - can't use ITCM or DTCM for any DMA
    # - SPI1 to SPI5 can use AXI SRAM, SRAM1 to SRAM3 and SRAM4 for DMA
    # - SPI6, I2C4 and ADC3 can use SRAM4 on BDMA
    # - UARTS can use AXI SRAM, SRAM1 to SRAM3 and SRAM4 for DMA
    # - I2C1, I2C2 and I2C3 can use AXI SRAM, SRAM1 to SRAM3 and SRAM4 with DMA
    # - timers can use AXI SRAM, SRAM1 to SRAM3 and SRAM4 with DMA
    # - ADC12 can use AXI SRAM, SRAM1 to SRAM3 and SRAM4
    # - SDMMC can use AXI SRAM, SRAM1 to SRAM3 with IDMA (cannot use SRAM4)

    # ram map, as list of (address, size-kb, flags)
    # flags of 1 means DMA-capable (DMA and BDMA)
    # flags of 2 means faster memory for CPU intensive work
    # flags of 4 means memory can be used for SDMMC DMA
    'RAM_MAP' : [
        (0x20000000, 128, 2), # DTCM
        (0x24000000, 128, 4), # AXI SRAM.
        (0x00000400,  63, 2), # ITCM (first 1k removed, to keep address 0 unused)
        (0x30000000, 32, 8), # SRAM1, SRAM2
        (0x38000000, 16, 1), # SRAM4
    ],

    'EXPECTED_CLOCK' : 400000000,
    
	'EXPECTED_CLOCKS' : [
        ('STM32_SYS_CK',	400000000),
        ('STM32_OSPICLK', 	200000000),
        ('STM32_SDMMC1CLK',  66666666),
		('STM32_SPI45CLK',  100000000),
        ('STM32_FDCANCLK',   80000000),
	],

    # this MCU has M7 instructions and hardware double precision
    'CORTEX'    : 'cortex-m7',
    'CPU_FLAGS' : '-mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard',

	# this MCU has a strange OTG setup
    'STM32_OTG2_IS_OTG1' : 1,

    'DEFINES' : {
        'HAL_HAVE_HARDWARE_DOUBLE' : '1',
        'HAL_WITH_MCU_MONITORING' : '1',
        'STM32H7' : '1',
    }
}

pincount = {
    'A': 16,
    'B': 16,
    'C': 16,
    'D': 16,
    'E': 16,
    'F': 16,
    'G': 16,
    'H': 16,
    'I': 16,
    'J': 16,
    'K': 16
}
    
# no DMA map as we will dynamically allocate DMA channels using the DMAMUX
DMA_Map = None

ADC1_map = {
    # format is PIN : ADC1_CHAN
    "PF11"  :   2,
    "PA6"	:	3,
    "PC4"	:	4,
    "PB1"	:	5,
    "PF12"  :   6,
    "PA7"	:	7,
    "PC5"	:	8,
    "PB0"	:	9,
    "PC0"	:	10,
	"PC1"	:	11,
	"PC2"	:	12,
    "PC3"	:	13,
    "PA2"	:	14,
    "PA3"	:	15,
    "PA0"	:	16,
    "PA1"	:	17,
    "PA4"	:	18,
    "PA5"	:	19,
}

ADC2_map = {
    "PF13"	:	2,
    "PA6"	:	3,
    "PC4"	:	4,
    "PB1"	:	5,
    "PF14"	:	6,
    "PA7"	:	7,
    "PC5"	:	8,
    "PB0"	:	9,
    "PC0"	:	10,
    "PC1"	:	11,
    "PC2"	:	12,
    "PC3"	:	13,
    "PA2"	:	14,
    "PA3"	:	15,
    "N/A"	:	16,
    "N/A"	:	17,
    "PA4"	:	18,
    "PA5"	:	19,
}

AltFunction_map = {
	# format is PIN:FUNCTION : AFNUM
	# extracted from h723.txt
	"PA0:ETH_RMII_CRS"       	:	11,
	"PA0:EVENTOUT"      	:	15,
	"PA0:FMC_A19"       	:	12,
	"PA0:I2S6_WS"       	:	5,
	"PA0:SAI4_SD_B"     	:	10,
	"PA0:SDMMC2_CMD"    	:	9,
	"PA0:SPI6_NSS"      	:	5,
	"PA0:TIM15_BKIN"    	:	4,
	"PA0:TIM2_CH1"      	:	1,
	"PA0:TIM2_ETR"      	:	1,
	"PA0:TIM5_CH1"      	:	2,
	"PA0:TIM8_ETR"      	:	3,
	"PA0:UART4_TX"      	:	8,
	"PA0:USART2_CTS"    	:	7,
	"PA0:USART2_NSS"    	:	7,
	"PA1:ETH_RMII_REF_CLK"   	:	11,
	"PA1:ETH_RMII_RX_CLK"    	:	11,
	"PA1:EVENTOUT"      	:	15,
	"PA1:LPTIM3_OUT"    	:	3,
	"PA1:LTDC_R2"       	:	14,
	"PA1:OCTOSPIM_P1_DQS"	:	12,
	"PA1:OCTOSPIM_P1_IO3"	:	9,
	"PA1:SAI4_MCLK_B"   	:	10,
	"PA1:TIM15_CH1N"    	:	4,
	"PA1:TIM2_CH2"      	:	1,
	"PA1:TIM5_CH2"      	:	2,
	"PA1:UART4_RX"      	:	8,
	"PA1:USART2_DE"     	:	7,
	"PA1:USART2_RTS"    	:	7,
    "PA2:ETH_MDIO"      	:	11,
	"PA2:EVENTOUT"      	:	15,
	"PA2:LPTIM4_OUT"    	:	3,
	"PA2:LTDC_R1"       	:	14,
	"PA2:MDIOS_MDIO"    	:	12,
	"PA2:OCTOSPIM_P1_IO0"	:	6,
	"PA2:SAI4_SCK_B"    	:	8,
	"PA2:TIM15_CH1"     	:	4,
	"PA2:TIM2_CH3"      	:	1,
	"PA2:TIM5_CH3"      	:	2,
	"PA2:USART2_TX"     	:	7,
	"PA3:ETH_RMII_COL"       	:	11,
	"PA3:EVENTOUT"      	:	15,
	"PA3:I2S6_MCK"      	:	5,
	"PA3:LPTIM5_OUT"    	:	3,
	"PA3:LTDC_B2"       	:	9,
	"PA3:LTDC_B5"       	:	14,
	"PA3:OCTOSPIM_P1_CLK"	:	12,
	"PA3:OCTOSPIM_P1_IO2"	:	6,
	"PA3:TIM15_CH2"     	:	4,
	"PA3:TIM2_CH4"      	:	1,
	"PA3:TIM5_CH4"      	:	2,
	"PA3:USART2_RX"     	:	7,
	"PA3:USB_OTG_HS_ULPI_D0"	:	10,
	"PA4:DCMI_HSYNC"    	:	13,
	"PA4:EVENTOUT"      	:	15,
	"PA4:FMC_D8"        	:	12,
	"PA4:FMC_DA8"       	:	12,
	"PA4:I2S1_WS"       	:	5,
	"PA4:I2S3_WS"       	:	6,
	"PA4:I2S6_WS"       	:	8,
	"PA4:LTDC_VSYNC"    	:	14,
	"PA4:PSSI_DE"       	:	13,
	"PA4:SPI1_NSS"      	:	5,
	"PA4:SPI3_NSS"      	:	6,
	"PA4:SPI6_NSS"      	:	8,
	"PA4:TIM5_ETR"      	:	2,
	"PA4:USART2_CK"     	:	7,
	"PA5:EVENTOUT"      	:	15,
	"PA5:FMC_D9"        	:	12,
	"PA5:FMC_DA9"       	:	12,
	"PA5:I2S1_CK"       	:	5,
	"PA5:I2S6_CK"       	:	8,
	"PA5:LTDC_R4"       	:	14,
	"PA5:PSSI_D14"      	:	13,
	"PA5:SPI1_SCK"      	:	5,
	"PA5:SPI6_SCK"      	:	8,
	"PA5:TIM2_CH1"      	:	1,
	"PA5:TIM2_ETR"      	:	1,
	"PA5:TIM8_CH1N"     	:	3,
	"PA5:USB_OTG_HS_ULPI_CK"	:	10,
	"PA6:DCMI_PIXCLK"   	:	13,
	"PA6:EVENTOUT"      	:	15,
	"PA6:I2S1_SDI"      	:	5,
	"PA6:I2S6_SDI"      	:	8,
	"PA6:LTDC_G2"       	:	14,
	"PA6:MDIOS_MDC"     	:	11,
	"PA6:OCTOSPIM_P1_IO3"	:	6,
	"PA6:PSSI_PDCK"     	:	13,
	"PA6:SPI1_MISO"     	:	5,
	"PA6:SPI6_MISO"     	:	8,
	"PA6:TIM13_CH1"     	:	9,
	"PA6:TIM1_BKIN"     	:	1,
	"PA6:TIM1_BKIN_COMP1"	:	12,
	"PA6:TIM1_BKIN_COMP2"	:	12,
	"PA6:TIM3_CH1"      	:	2,
	"PA6:TIM8_BKIN"     	:	3,
	"PA6:TIM8_BKIN_COMP1"	:	10,
	"PA6:TIM8_BKIN_COMP2"	:	10,
	"PA7:ETH_RMII_CRS_DV"    	:	11,
	"PA7:ETH_RMII_RX_DV"     	:	11,
	"PA7:EVENTOUT"      	:	15,
	"PA7:FMC_SDNWE"     	:	12,
	"PA7:I2S1_SDO"      	:	5,
	"PA7:I2S6_SDO"      	:	8,
	"PA7:LTDC_VSYNC"    	:	14,
	"PA7:OCTOSPIM_P1_IO2"	:	10,
	"PA7:SPI1_MOSI"     	:	5,
	"PA7:SPI6_MOSI"     	:	8,
	"PA7:TIM14_CH1"     	:	9,
	"PA7:TIM1_CH1N"     	:	1,
	"PA7:TIM3_CH2"      	:	2,
	"PA7:TIM8_CH1N"     	:	3,
	"PA8:EVENTOUT"      	:	15,
	"PA8:I2C3_SCL"      	:	4,
	"PA8:I2C5_SCL"      	:	6,
	"PA8:LTDC_B3"       	:	13,
	"PA8:LTDC_R6"       	:	14,
	"PA8:RCC_MCO_1"     	:	0,
	"PA8:TIM1_CH1"      	:	1,
	"PA8:TIM8_BKIN2"    	:	3,
	"PA8:TIM8_BKIN2_COMP1"	:	12,
	"PA8:TIM8_BKIN2_COMP2"	:	12,
	"PA8:UART7_RX"      	:	11,
	"PA8:USART1_CK"     	:	7,
	"PA8:USB_OTG_HS_SOF"	:	10,
	"PA9:DCMI_D0"       	:	13,
	"PA9:ETH_RMII_TX_ER"     	:	11,
	"PA9:EVENTOUT"      	:	15,
	"PA9:I2C3_SMBA"     	:	4,
	"PA9:I2C5_SMBA"     	:	6,
	"PA9:I2S2_CK"       	:	5,
	"PA9:LPUART1_TX"    	:	3,
	"PA9:LTDC_R5"       	:	14,
	"PA9:PSSI_D0"       	:	13,
	"PA9:SPI2_SCK"      	:	5,
	"PA9:TIM1_CH2"      	:	1,
	"PA9:USART1_TX"     	:	7,
	"PA10:DCMI_D1"      	:	13,
	"PA10:EVENTOUT"     	:	15,
	"PA10:LPUART1_RX"   	:	3,
	"PA10:LTDC_B1"      	:	14,
	"PA10:LTDC_B4"      	:	12,
	"PA10:MDIOS_MDIO"   	:	11,
	"PA10:PSSI_D1"      	:	13,
	"PA10:TIM1_CH3"     	:	1,
	"PA10:USART1_RX"    	:	7,
	"PA10:USB_OTG_HS_ID"	:	10,
    "PA11:OTG_HS_DM"		:   0,
    "PA11:EVENTOUT"     	:	15,
	"PA11:CAN1_RX"    	:	9,
	"PA11:I2S2_WS"      	:	5,
	"PA11:LPUART1_CTS"  	:	3,
	"PA11:LTDC_R4"      	:	14,
	"PA11:SPI2_NSS"     	:	5,
	"PA11:TIM1_CH4"     	:	1,
	"PA11:UART4_RX"     	:	6,
	"PA11:USART1_CTS"   	:	7,
	"PA11:USART1_NSS"   	:	7,
    "PA12:OTG_HS_DP"		:   0,
    "PA12:EVENTOUT"     	:	15,
	"PA12:CAN1_TX"    	:	9,
	"PA12:I2S2_CK"      	:	5,
	"PA12:LPUART1_DE"   	:	3,
	"PA12:LPUART1_RTS"  	:	3,
	"PA12:LTDC_R5"      	:	14,
	"PA12:SAI4_FS_B"    	:	8,
	"PA12:SPI2_SCK"     	:	5,
	"PA12:TIM1_BKIN2"   	:	12,
	"PA12:TIM1_ETR"     	:	1,
	"PA12:UART4_TX"     	:	6,
	"PA12:USART1_DE"    	:	7,
	"PA12:USART1_RTS"   	:	7,
    "PA13:JTMS-SWDIO"	:	0,
	"PA13:EVENTOUT"     	:	15,
    "PA14:JTCK-SWCLK"	:	0,
	"PA14:EVENTOUT"     	:	15,
	"PA15:CEC"          	:	4,
	"PA15:DEBUG_JTDI"   	:	0,
	"PA15:EVENTOUT"     	:	15,
	"PA15:I2S1_WS"      	:	5,
	"PA15:I2S3_WS"      	:	6,
	"PA15:I2S6_WS"      	:	7,
	"PA15:LTDC_B6"      	:	14,
	"PA15:LTDC_R3"      	:	9,
	"PA15:SPI1_NSS"     	:	5,
	"PA15:SPI3_NSS"     	:	6,
	"PA15:SPI6_NSS"     	:	7,
	"PA15:TIM2_CH1"     	:	1,
	"PA15:TIM2_ETR"     	:	1,
	"PA15:UART4_DE"     	:	8,
	"PA15:UART4_RTS"    	:	8,
	"PA15:UART7_TX"     	:	11,
	"PB0:DFSDM1_CKOUT"  	:	6,
	"PB0:ETH_RMII_RXD2"      	:	11,
	"PB0:EVENTOUT"      	:	15,
	"PB0:LTDC_G1"       	:	14,
	"PB0:LTDC_R3"       	:	9,
	"PB0:OCTOSPIM_P1_IO1"	:	4,
	"PB0:TIM1_CH2N"     	:	1,
	"PB0:TIM3_CH3"      	:	2,
	"PB0:TIM8_CH2N"     	:	3,
	"PB0:UART4_CTS"     	:	8,
	"PB0:USB_OTG_HS_ULPI_D1"	:	10,
	"PB1:DFSDM1_DATIN1" 	:	6,
	"PB1:ETH_RMII_RXD3"      	:	11,
	"PB1:EVENTOUT"      	:	15,
	"PB1:LTDC_G0"       	:	14,
	"PB1:LTDC_R6"       	:	9,
	"PB1:OCTOSPIM_P1_IO0"	:	4,
	"PB1:TIM1_CH3N"     	:	1,
	"PB1:TIM3_CH4"      	:	2,
	"PB1:TIM8_CH3N"     	:	3,
	"PB1:USB_OTG_HS_ULPI_D2"	:	10,
	"PB2:DFSDM1_CKIN1"  	:	4,
	"PB2:ETH_RMII_TX_ER"     	:	11,
	"PB2:EVENTOUT"      	:	15,
	"PB2:I2S3_SDO"      	:	7,
	"PB2:OCTOSPIM_P1_CLK"	:	9,
	"PB2:OCTOSPIM_P1_DQS"	:	10,
	"PB2:RTC_OUT_ALARM" 	:	0,
	"PB2:RTC_OUT_CALIB" 	:	0,
	"PB2:SAI1_D1"       	:	2,
	"PB2:SAI1_SD_A"     	:	6,
	"PB2:SAI4_D1"       	:	1,
	"PB2:SAI4_SD_A"     	:	8,
	"PB2:SPI3_MOSI"     	:	7,
	"PB2:TIM23_ETR"     	:	13,
	"PB3:CRS_SYNC"      	:	10,
	"PB3:DEBUG_JTDO-SWO"	:	0,
	"PB3:EVENTOUT"      	:	15,
	"PB3:I2S1_CK"       	:	5,
	"PB3:I2S3_CK"       	:	6,
	"PB3:I2S6_CK"       	:	8,
	"PB3:SDMMC2_D2"     	:	9,
	"PB3:SPI1_SCK"      	:	5,
	"PB3:SPI3_SCK"      	:	6,
	"PB3:SPI6_SCK"      	:	8,
	"PB3:TIM24_ETR"     	:	14,
	"PB3:TIM2_CH2"      	:	1,
	"PB3:UART7_RX"      	:	11,
	"PB4:DEBUG_JTRST"   	:	0,
	"PB4:EVENTOUT"      	:	15,
	"PB4:I2S1_SDI"      	:	5,
	"PB4:I2S2_WS"       	:	7,
	"PB4:I2S3_SDI"      	:	6,
	"PB4:I2S6_SDI"      	:	8,
	"PB4:SDMMC2_D3"     	:	9,
	"PB4:SPI1_MISO"     	:	5,
	"PB4:SPI2_NSS"      	:	7,
	"PB4:SPI3_MISO"     	:	6,
	"PB4:SPI6_MISO"     	:	8,
	"PB4:TIM16_BKIN"    	:	1,
	"PB4:TIM3_CH1"      	:	2,
	"PB4:UART7_TX"      	:	11,
	"PB5:DCMI_D10"      	:	13,
	"PB5:ETH_RMII_PPS_OUT"   	:	11,
	"PB5:EVENTOUT"      	:	15,
    "PB5:CAN2_RX"     	:	9,
	"PB5:FMC_SDCKE1"    	:	12,
	"PB5:I2C1_SMBA"     	:	4,
	"PB5:I2C4_SMBA"     	:	6,
	"PB5:I2S1_SDO"      	:	5,
	"PB5:I2S3_SDO"      	:	7,
	"PB5:I2S6_SDO"      	:	8,
	"PB5:LTDC_B5"       	:	3,
	"PB5:PSSI_D10"      	:	13,
	"PB5:SPI1_MOSI"     	:	5,
	"PB5:SPI3_MOSI"     	:	7,
	"PB5:SPI6_MOSI"     	:	8,
	"PB5:TIM17_BKIN"    	:	1,
	"PB5:TIM3_CH2"      	:	2,
	"PB5:UART5_RX"      	:	14,
	"PB5:USB_OTG_HS_ULPI_D7"	:	10,
	"PB6:CEC"           	:	5,
	"PB6:DCMI_D5"       	:	13,
	"PB6:DFSDM1_DATIN5" 	:	11,
	"PB6:EVENTOUT"      	:	15,
    "PB6:CAN2_TX"     	:	9,
	"PB6:FMC_SDNE1"     	:	12,
	"PB6:I2C1_SCL"      	:	4,
	"PB6:I2C4_SCL"      	:	6,
	"PB6:LPUART1_TX"    	:	8,
	"PB6:OCTOSPIM_P1_NCS"	:	10,
	"PB6:PSSI_D5"       	:	13,
	"PB6:TIM16_CH1N"    	:	1,
	"PB6:TIM4_CH1"      	:	2,
	"PB6:UART5_TX"      	:	14,
	"PB6:USART1_TX"     	:	7,
	"PB7:DCMI_VSYNC"    	:	13,
	"PB7:DFSDM1_CKIN5"  	:	11,
	"PB7:EVENTOUT"      	:	15,
	"PB7:FMC_NL"        	:	12,
	"PB7:I2C1_SDA"      	:	4,
	"PB7:I2C4_SDA"      	:	6,
	"PB7:LPUART1_RX"    	:	8,
	"PB7:PSSI_RDY"      	:	13,
	"PB7:TIM17_CH1N"    	:	1,
	"PB7:TIM4_CH2"      	:	2,
	"PB7:USART1_RX"     	:	7,
	"PB8:DCMI_D6"       	:	13,
	"PB8:DFSDM1_CKIN7"  	:	3,
	"PB8:ETH_RMII_TXD3"      	:	11,
	"PB8:EVENTOUT"      	:	15,
	"PB8:CAN1_RX"     	:	9,
	"PB8:I2C1_SCL"      	:	4,
	"PB8:I2C4_SCL"      	:	6,
	"PB8:LTDC_B6"       	:	14,
	"PB8:PSSI_D6"       	:	13,
	"PB8:SDMMC1_CKIN"   	:	7,
	"PB8:SDMMC1_D4"     	:	12,
	"PB8:SDMMC2_D4"     	:	10,
	"PB8:TIM16_CH1"     	:	1,
	"PB8:TIM4_CH3"      	:	2,
	"PB8:UART4_RX"      	:	8,
	"PB9:DCMI_D7"       	:	13,
	"PB9:DFSDM1_DATIN7" 	:	3,
	"PB9:EVENTOUT"      	:	15,
	"PB9:CAN1_TX"     	:	9,
	"PB9:I2C1_SDA"      	:	4,
	"PB9:I2C4_SDA"      	:	6,
	"PB9:I2C4_SMBA"     	:	11,
	"PB9:I2S2_WS"       	:	5,
	"PB9:LTDC_B7"       	:	14,
	"PB9:PSSI_D7"       	:	13,
	"PB9:SDMMC1_CDIR"   	:	7,
	"PB9:SDMMC1_D5"     	:	12,
	"PB9:SDMMC2_D5"     	:	10,
	"PB9:SPI2_NSS"      	:	5,
	"PB9:TIM17_CH1"     	:	1,
	"PB9:TIM4_CH4"      	:	2,
	"PB9:UART4_TX"      	:	8,
	"PB10:DFSDM1_DATIN7"	:	6,
	"PB10:ETH_RMII_RX_ER"    	:	11,
	"PB10:EVENTOUT"     	:	15,
	"PB10:I2C2_SCL"     	:	4,
	"PB10:I2S2_CK"      	:	5,
	"PB10:LPTIM2_IN1"   	:	3,
	"PB10:LTDC_G4"      	:	14,
	"PB10:OCTOSPIM_P1_NCS"	:	9,
	"PB10:SPI2_SCK"     	:	5,
	"PB10:TIM2_CH3"     	:	1,
	"PB10:USART3_TX"    	:	7,
	"PB10:USB_OTG_HS_ULPI_D3"	:	10,
	"PB11:DFSDM1_CKIN7" 	:	6,
	"PB11:ETH_RMII_TX_EN"    	:	11,
	"PB11:EVENTOUT"     	:	15,
	"PB11:I2C2_SDA"     	:	4,
	"PB11:LPTIM2_ETR"   	:	3,
	"PB11:LTDC_G5"      	:	14,
	"PB11:TIM2_CH4"     	:	1,
	"PB11:USART3_RX"    	:	7,
	"PB11:USB_OTG_HS_ULPI_D4"	:	10,
	"PB12:DFSDM1_DATIN1"	:	6,
	"PB12:ETH_RMII_TXD0"     	:	11,
	"PB12:EVENTOUT"     	:	15,
	"PB12:CAN2_RX"    	:	9,
	"PB12:I2C2_SMBA"    	:	4,
	"PB12:I2S2_WS"      	:	5,
	"PB12:OCTOSPIM_P1_IO0"	:	12,
	"PB12:OCTOSPIM_P1_NCLK"	:	3,
	"PB12:SPI2_NSS"     	:	5,
	"PB12:TIM1_BKIN"    	:	1,
	"PB12:TIM1_BKIN_COMP1"	:	13,
	"PB12:TIM1_BKIN_COMP2"	:	13,
	"PB12:UART5_RX"     	:	14,
	"PB12:USART3_CK"    	:	7,
	"PB12:USB_OTG_HS_ULPI_D5"	:	10,
	"PB13:DCMI_D2"      	:	13,
	"PB13:DFSDM1_CKIN1" 	:	6,
	"PB13:ETH_RMII_TXD1"     	:	11,
	"PB13:EVENTOUT"     	:	15,
	"PB13:CAN2_TX"    	:	9,
	"PB13:I2S2_CK"      	:	5,
	"PB13:LPTIM2_OUT"   	:	3,
	"PB13:OCTOSPIM_P1_IO2"	:	4,
	"PB13:PSSI_D2"      	:	13,
	"PB13:SDMMC1_D0"    	:	12,
	"PB13:SPI2_SCK"     	:	5,
	"PB13:TIM1_CH1N"    	:	1,
	"PB13:UART5_TX"     	:	14,
	"PB13:USART3_CTS"   	:	7,
	"PB13:USART3_NSS"   	:	7,
	"PB13:USB_OTG_HS_ULPI_D6"	:	10,
	"PB14:DFSDM1_DATIN2"	:	6,
	"PB14:EVENTOUT"     	:	15,
	"PB14:FMC_D10"      	:	12,
	"PB14:FMC_DA10"     	:	12,
	"PB14:I2S2_SDI"     	:	5,
	"PB14:LTDC_CLK"     	:	14,
	"PB14:SDMMC2_D0"    	:	9,
	"PB14:SPI2_MISO"    	:	5,
	"PB14:TIM12_CH1"    	:	2,
	"PB14:TIM1_CH2N"    	:	1,
	"PB14:TIM8_CH2N"    	:	3,
	"PB14:UART4_DE"     	:	8,
	"PB14:UART4_RTS"    	:	8,
	"PB14:USART1_TX"    	:	4,
	"PB14:USART3_DE"    	:	7,
	"PB14:USART3_RTS"   	:	7,
	"PB15:DFSDM1_CKIN2" 	:	6,
	"PB15:EVENTOUT"     	:	15,
	"PB15:FMC_D11"      	:	12,
	"PB15:FMC_DA11"     	:	12,
	"PB15:I2S2_SDO"     	:	5,
	"PB15:LTDC_G7"      	:	14,
	"PB15:RTC_REFIN"    	:	0,
	"PB15:SDMMC2_D1"    	:	9,
	"PB15:SPI2_MOSI"    	:	5,
	"PB15:TIM12_CH2"    	:	2,
	"PB15:TIM1_CH3N"    	:	1,
	"PB15:TIM8_CH3N"    	:	3,
	"PB15:UART4_CTS"    	:	8,
	"PB15:USART1_RX"    	:	4,
	"PC0:DFSDM1_CKIN0"  	:	3,
	"PC0:DFSDM1_DATIN4" 	:	6,
	"PC0:EVENTOUT"      	:	15,
	"PC0:FMC_A25"       	:	9,
	"PC0:FMC_D12"       	:	1,
	"PC0:FMC_DA12"      	:	1,
	"PC0:FMC_SDNWE"     	:	12,
	"PC0:LTDC_G2"       	:	11,
	"PC0:LTDC_R5"       	:	14,
	"PC0:SAI4_FS_B"     	:	8,
	"PC0:USB_OTG_HS_ULPI_STP"	:	10,
	"PC1:DEBUG_TRACED0" 	:	0,
	"PC1:DFSDM1_CKIN4"  	:	4,
	"PC1:DFSDM1_DATIN0" 	:	3,
    "PC1:ETH_MDC"       	:	11,
	"PC1:EVENTOUT"      	:	15,
	"PC1:I2S2_SDO"      	:	5,
	"PC1:LTDC_G5"       	:	14,
	"PC1:MDIOS_MDC"     	:	12,
	"PC1:OCTOSPIM_P1_IO4"	:	10,
	"PC1:SAI1_D1"       	:	2,
	"PC1:SAI1_SD_A"     	:	6,
	"PC1:SAI4_D1"       	:	1,
	"PC1:SAI4_SD_A"     	:	8,
	"PC1:SDMMC2_CK"     	:	9,
	"PC1:SPI2_MOSI"     	:	5,
	"PC2:DFSDM1_CKIN1"  	:	3,
	"PC2:DFSDM1_CKOUT"  	:	6,
	"PC2:ETH_RMII_TXD2"      	:	11,
	"PC2:FMC_SDNE0"     	:	12,
	"PC2:I2S2_SDI"      	:	5,
	"PC2:OCTOSPIM_P1_IO2"	:	9,
	"PC2:OCTOSPIM_P1_IO5"	:	4,
	"PC2:SPI2_MISO"     	:	5,
	"PC2:USB_OTG_HS_ULPI_DIR"	:	10,
	"PC3:DFSDM1_DATIN1" 	:	3,
	"PC3:ETH_RMII_TX_CLK"    	:	11,
	"PC3:FMC_SDCKE0"    	:	12,
	"PC3:I2S2_SDO"      	:	5,
	"PC3:OCTOSPIM_P1_IO0"	:	9,
	"PC3:OCTOSPIM_P1_IO6"	:	4,
	"PC3:SPI2_MOSI"     	:	5,
	"PC3:USB_OTG_HS_ULPI_NXT"	:	10,
	"PC4:DFSDM1_CKIN2"  	:	3,
    "PC4:ETH_RMII_RXD0"      	:	11,
	"PC4:EVENTOUT"      	:	15,
	"PC4:FMC_A22"       	:	1,
	"PC4:FMC_SDNE0"     	:	12,
	"PC4:I2S1_MCK"      	:	5,
	"PC4:LTDC_R7"       	:	14,
	"PC4:SDMMC2_CKIN"   	:	10,
	"PC4:SPDIFRX1_IN2"  	:	9,
	"PC5:COMP1_OUT"     	:	13,
	"PC5:DFSDM1_DATIN2" 	:	3,
    "PC5:ETH_RMII_RXD1"      	:	11,
	"PC5:EVENTOUT"      	:	15,
	"PC5:FMC_SDCKE0"    	:	12,
	"PC5:LTDC_DE"       	:	14,
	"PC5:OCTOSPIM_P1_DQS"	:	10,
	"PC5:PSSI_D15"      	:	4,
	"PC5:SAI1_D3"       	:	2,
	"PC5:SAI4_D3"       	:	1,
	"PC5:SPDIFRX1_IN3"  	:	9,
	"PC6:DCMI_D0"       	:	13,
	"PC6:DFSDM1_CKIN3"  	:	4,
	"PC6:EVENTOUT"      	:	15,
	"PC6:FMC_NWAIT"     	:	9,
	"PC6:I2S2_MCK"      	:	5,
	"PC6:LTDC_HSYNC"    	:	14,
	"PC6:PSSI_D0"       	:	13,
	"PC6:SDMMC1_D0DIR"  	:	8,
	"PC6:SDMMC1_D6"     	:	12,
	"PC6:SDMMC2_D6"     	:	10,
	"PC6:TIM3_CH1"      	:	2,
	"PC6:TIM8_CH1"      	:	3,
	"PC6:USART6_TX"     	:	7,
	"PC7:DCMI_D1"       	:	13,
	"PC7:DEBUG_TRGIO"   	:	0,
	"PC7:DFSDM1_DATIN3" 	:	4,
	"PC7:EVENTOUT"      	:	15,
	"PC7:FMC_NE1"       	:	9,
	"PC7:I2S3_MCK"      	:	6,
	"PC7:LTDC_G6"       	:	14,
	"PC7:PSSI_D1"       	:	13,
	"PC7:SDMMC1_D123DIR"	:	8,
	"PC7:SDMMC1_D7"     	:	12,
	"PC7:SDMMC2_D7"     	:	10,
	"PC7:SWPMI1_TX"     	:	11,
	"PC7:TIM3_CH2"      	:	2,
	"PC7:TIM8_CH2"      	:	3,
	"PC7:USART6_RX"     	:	7,
	"PC8:DCMI_D2"       	:	13,
	"PC8:DEBUG_TRACED1" 	:	0,
	"PC8:EVENTOUT"      	:	15,
	"PC8:FMC_INT"       	:	10,
	"PC8:FMC_NCE"       	:	9,
	"PC8:FMC_NE2"       	:	9,
	"PC8:PSSI_D2"       	:	13,
	"PC8:SDMMC1_D0"     	:	12,
	"PC8:SWPMI1_RX"     	:	11,
	"PC8:TIM3_CH3"      	:	2,
	"PC8:TIM8_CH3"      	:	3,
	"PC8:UART5_DE"      	:	8,
	"PC8:UART5_RTS"     	:	8,
	"PC8:USART6_CK"     	:	7,
	"PC9:DCMI_D3"       	:	13,
	"PC9:EVENTOUT"      	:	15,
	"PC9:I2C3_SDA"      	:	4,
	"PC9:I2C5_SDA"      	:	6,
	"PC9:I2S_CKIN"      	:	5,
	"PC9:LTDC_B2"       	:	14,
	"PC9:LTDC_G3"       	:	10,
	"PC9:OCTOSPIM_P1_IO0"	:	9,
	"PC9:PSSI_D3"       	:	13,
	"PC9:RCC_MCO_2"     	:	0,
	"PC9:SDMMC1_D1"     	:	12,
	"PC9:SWPMI1_SUSPEND"	:	11,
	"PC9:TIM3_CH4"      	:	2,
	"PC9:TIM8_CH4"      	:	3,
	"PC9:UART5_CTS"     	:	8,
	"PC10:DCMI_D8"      	:	13,
	"PC10:DFSDM1_CKIN5" 	:	3,
	"PC10:EVENTOUT"     	:	15,
	"PC10:I2C5_SDA"     	:	4,
	"PC10:I2S3_CK"      	:	6,
	"PC10:LTDC_B1"      	:	10,
	"PC10:LTDC_R2"      	:	14,
	"PC10:OCTOSPIM_P1_IO1"	:	9,
	"PC10:PSSI_D8"      	:	13,
	"PC10:SDMMC1_D2"    	:	12,
	"PC10:SPI3_SCK"     	:	6,
	"PC10:SWPMI1_RX"    	:	11,
	"PC10:UART4_TX"     	:	8,
	"PC10:USART3_TX"    	:	7,
	"PC11:DCMI_D4"      	:	13,
	"PC11:DFSDM1_DATIN5"	:	3,
	"PC11:EVENTOUT"     	:	15,
	"PC11:I2C5_SCL"     	:	4,
	"PC11:I2S3_SDI"     	:	6,
	"PC11:LTDC_B4"      	:	14,
	"PC11:OCTOSPIM_P1_NCS"	:	9,
	"PC11:PSSI_D4"      	:	13,
	"PC11:SDMMC1_D3"    	:	12,
	"PC11:SPI3_MISO"    	:	6,
	"PC11:UART4_RX"     	:	8,
	"PC11:USART3_RX"    	:	7,
	"PC12:DCMI_D9"      	:	13,
	"PC12:DEBUG_TRACED3"	:	0,
	"PC12:EVENTOUT"     	:	15,
	"PC12:FMC_D6"       	:	1,
	"PC12:FMC_DA6"      	:	1,
	"PC12:I2C5_SMBA"    	:	4,
	"PC12:I2S3_SDO"     	:	6,
	"PC12:I2S6_CK"      	:	5,
	"PC12:LTDC_R6"      	:	14,
	"PC12:PSSI_D9"      	:	13,
	"PC12:SDMMC1_CK"    	:	12,
	"PC12:SPI3_MOSI"    	:	6,
	"PC12:SPI6_SCK"     	:	5,
	"PC12:TIM15_CH1"    	:	2,
	"PC12:UART5_TX"     	:	8,
	"PC12:USART3_CK"    	:	7,
	"PC13:EVENTOUT"     	:	15,
	"PC14:EVENTOUT"     	:	15,
	"PC15:EVENTOUT"     	:	15,
	"PD0:DFSDM1_CKIN6"  	:	3,
	"PD0:EVENTOUT"      	:	15,
    "PD0:CAN1_RX"     	:	9,
	"PD0:FMC_D2"        	:	12,
	"PD0:FMC_DA2"       	:	12,
	"PD0:LTDC_B1"       	:	14,
	"PD0:UART4_RX"      	:	8,
	"PD0:UART9_CTS"     	:	11,
	"PD1:DFSDM1_DATIN6" 	:	3,
	"PD1:EVENTOUT"      	:	15,
    "PD1:CAN1_TX"     	:	9,
	"PD1:FMC_D3"        	:	12,
	"PD1:FMC_DA3"       	:	12,
	"PD1:UART4_TX"      	:	8,
	"PD2:DCMI_D11"      	:	13,
	"PD2:DEBUG_TRACED2" 	:	0,
	"PD2:EVENTOUT"      	:	15,
	"PD2:FMC_D7"        	:	1,
	"PD2:FMC_DA7"       	:	1,
	"PD2:LTDC_B2"       	:	14,
	"PD2:LTDC_B7"       	:	9,
	"PD2:PSSI_D11"      	:	13,
	"PD2:SDMMC1_CMD"    	:	12,
	"PD2:TIM15_BKIN"    	:	4,
	"PD2:TIM3_ETR"      	:	2,
	"PD2:UART5_RX"      	:	8,
	"PD3:DCMI_D5"       	:	13,
	"PD3:DFSDM1_CKOUT"  	:	3,
	"PD3:EVENTOUT"      	:	15,
	"PD3:FMC_CLK"       	:	12,
	"PD3:I2S2_CK"       	:	5,
	"PD3:LTDC_G7"       	:	14,
	"PD3:PSSI_D5"       	:	13,
	"PD3:SPI2_SCK"      	:	5,
	"PD3:USART2_CTS"    	:	7,
	"PD3:USART2_NSS"    	:	7,
	"PD4:EVENTOUT"      	:	15,
	"PD4:FMC_NOE"       	:	12,
	"PD4:OCTOSPIM_P1_IO4"	:	10,
	"PD4:USART2_DE"     	:	7,
	"PD4:USART2_RTS"    	:	7,
	"PD5:EVENTOUT"      	:	15,
	"PD5:FMC_NWE"       	:	12,
	"PD5:OCTOSPIM_P1_IO5"	:	10,
	"PD5:USART2_TX"     	:	7,
	"PD6:DCMI_D10"      	:	13,
	"PD6:DFSDM1_CKIN4"  	:	3,
	"PD6:DFSDM1_DATIN1" 	:	4,
	"PD6:EVENTOUT"      	:	15,
	"PD6:FMC_NWAIT"     	:	12,
	"PD6:I2S3_SDO"      	:	5,
	"PD6:LTDC_B2"       	:	14,
	"PD6:OCTOSPIM_P1_IO6"	:	10,
	"PD6:PSSI_D10"      	:	13,
	"PD6:SAI1_D1"       	:	2,
	"PD6:SAI1_SD_A"     	:	6,
	"PD6:SAI4_D1"       	:	1,
	"PD6:SAI4_SD_A"     	:	8,
	"PD6:SDMMC2_CK"     	:	11,
	"PD6:SPI3_MOSI"     	:	5,
	"PD6:USART2_RX"     	:	7,
	"PD7:DFSDM1_CKIN1"  	:	6,
	"PD7:DFSDM1_DATIN4" 	:	3,
	"PD7:EVENTOUT"      	:	15,
	"PD7:FMC_NE1"       	:	12,
	"PD7:I2S1_SDO"      	:	5,
	"PD7:OCTOSPIM_P1_IO7"	:	10,
	"PD7:SDMMC2_CMD"    	:	11,
	"PD7:SPDIFRX1_IN0"  	:	9,
	"PD7:SPI1_MOSI"     	:	5,
	"PD7:USART2_CK"     	:	7,
	"PD8:DFSDM1_CKIN3"  	:	3,
	"PD8:EVENTOUT"      	:	15,
	"PD8:FMC_D13"       	:	12,
	"PD8:FMC_DA13"      	:	12,
	"PD8:SPDIFRX1_IN1"  	:	9,
	"PD8:USART3_TX"     	:	7,
	"PD9:DFSDM1_DATIN3" 	:	3,
	"PD9:EVENTOUT"      	:	15,
	"PD9:FMC_D14"       	:	12,
	"PD9:FMC_DA14"      	:	12,
	"PD9:USART3_RX"     	:	7,
	"PD10:DFSDM1_CKOUT" 	:	3,
	"PD10:EVENTOUT"     	:	15,
	"PD10:FMC_D15"      	:	12,
	"PD10:FMC_DA15"     	:	12,
	"PD10:LTDC_B3"      	:	14,
	"PD10:USART3_CK"    	:	7,
	"PD11:EVENTOUT"     	:	15,
	"PD11:FMC_A16"      	:	12,
	"PD11:FMC_CLE"      	:	12,
	"PD11:I2C4_SMBA"    	:	4,
	"PD11:LPTIM2_IN2"   	:	3,
	"PD11:OCTOSPIM_P1_IO0"	:	9,
	"PD11:SAI4_SD_A"    	:	10,
	"PD11:USART3_CTS"   	:	7,
	"PD11:USART3_NSS"   	:	7,
	"PD12:DCMI_D12"     	:	13,
	"PD12:EVENTOUT"     	:	15,
	"PD12:CAN3_RX"    	:	5,
	"PD12:FMC_A17"      	:	12,
	"PD12:FMC_ALE"      	:	12,
	"PD12:I2C4_SCL"     	:	4,
	"PD12:LPTIM1_IN1"   	:	1,
	"PD12:LPTIM2_IN1"   	:	3,
	"PD12:OCTOSPIM_P1_IO1"	:	9,
	"PD12:PSSI_D12"     	:	13,
	"PD12:SAI4_FS_A"    	:	10,
	"PD12:TIM4_CH1"     	:	2,
	"PD12:USART3_DE"    	:	7,
	"PD12:USART3_RTS"   	:	7,
	"PD13:DCMI_D13"     	:	13,
	"PD13:EVENTOUT"     	:	15,
	"PD13:CAN3_TX"    	:	5,
	"PD13:FMC_A18"      	:	12,
	"PD13:I2C4_SDA"     	:	4,
	"PD13:LPTIM1_OUT"   	:	1,
	"PD13:OCTOSPIM_P1_IO3"	:	9,
	"PD13:PSSI_D13"     	:	13,
	"PD13:SAI4_SCK_A"   	:	10,
	"PD13:TIM4_CH2"     	:	2,
	"PD13:UART9_DE"     	:	11,
	"PD13:UART9_RTS"    	:	11,
	"PD14:EVENTOUT"     	:	15,
	"PD14:FMC_D0"       	:	12,
	"PD14:FMC_DA0"      	:	12,
	"PD14:TIM4_CH3"     	:	2,
	"PD14:UART8_CTS"    	:	8,
	"PD14:UART9_RX"     	:	11,
	"PD15:EVENTOUT"     	:	15,
	"PD15:FMC_D1"       	:	12,
	"PD15:FMC_DA1"      	:	12,
	"PD15:TIM4_CH4"     	:	2,
	"PD15:UART8_DE"     	:	8,
	"PD15:UART8_RTS"    	:	8,
	"PD15:UART9_TX"     	:	11,
	"PE0:DCMI_D2"       	:	13,
	"PE0:EVENTOUT"      	:	15,
	"PE0:FMC_NBL0"      	:	12,
	"PE0:LPTIM1_ETR"    	:	1,
	"PE0:LPTIM2_ETR"    	:	4,
	"PE0:LTDC_R0"       	:	14,
	"PE0:PSSI_D2"       	:	13,
	"PE0:SAI4_MCLK_A"   	:	10,
	"PE0:TIM4_ETR"      	:	2,
	"PE0:UART8_RX"      	:	8,
	"PE1:DCMI_D3"       	:	13,
	"PE1:EVENTOUT"      	:	15,
	"PE1:FMC_NBL1"      	:	12,
	"PE1:LPTIM1_IN2"    	:	1,
	"PE1:LTDC_R6"       	:	14,
	"PE1:PSSI_D3"       	:	13,
	"PE1:UART8_TX"      	:	8,
	"PE2:DEBUG_TRACECLK"	:	0,
    "PE2:ETH_RMII_TXD3"      	:	11,
	"PE2:EVENTOUT"      	:	15,
	"PE2:FMC_A23"       	:	12,
	"PE2:OCTOSPIM_P1_IO2"	:	9,
	"PE2:SAI1_CK1"      	:	2,
	"PE2:SAI1_MCLK_A"   	:	6,
	"PE2:SAI4_CK1"      	:	10,
	"PE2:SAI4_MCLK_A"   	:	8,
	"PE2:SPI4_SCK"      	:	5,
	"PE2:USART10_RX"    	:	4,
	"PE3:DEBUG_TRACED0" 	:	0,
	"PE3:EVENTOUT"      	:	15,
	"PE3:FMC_A19"       	:	12,
	"PE3:SAI1_SD_B"     	:	6,
	"PE3:SAI4_SD_B"     	:	8,
	"PE3:TIM15_BKIN"    	:	4,
	"PE3:USART10_TX"    	:	11,
	"PE4:DCMI_D4"       	:	13,
	"PE4:DEBUG_TRACED1" 	:	0,
	"PE4:DFSDM1_DATIN3" 	:	3,
	"PE4:EVENTOUT"      	:	15,
	"PE4:FMC_A20"       	:	12,
	"PE4:LTDC_B0"       	:	14,
	"PE4:PSSI_D4"       	:	13,
	"PE4:SAI1_D2"       	:	2,
	"PE4:SAI1_FS_A"     	:	6,
	"PE4:SAI4_D2"       	:	10,
	"PE4:SAI4_FS_A"     	:	8,
	"PE4:SPI4_NSS"      	:	5,
	"PE4:TIM15_CH1N"    	:	4,
	"PE5:DCMI_D6"       	:	13,
	"PE5:DEBUG_TRACED2" 	:	0,
	"PE5:DFSDM1_CKIN3"  	:	3,
	"PE5:EVENTOUT"      	:	15,
	"PE5:FMC_A21"       	:	12,
	"PE5:LTDC_G0"       	:	14,
	"PE5:PSSI_D6"       	:	13,
	"PE5:SAI1_CK2"      	:	2,
	"PE5:SAI1_SCK_A"    	:	6,
	"PE5:SAI4_CK2"      	:	10,
	"PE5:SAI4_SCK_A"    	:	8,
	"PE5:SPI4_MISO"     	:	5,
	"PE5:TIM15_CH1"     	:	4,
	"PE6:DCMI_D7"       	:	13,
	"PE6:DEBUG_TRACED3" 	:	0,
	"PE6:EVENTOUT"      	:	15,
	"PE6:FMC_A22"       	:	12,
	"PE6:LTDC_G1"       	:	14,
	"PE6:PSSI_D7"       	:	13,
	"PE6:SAI1_D1"       	:	2,
	"PE6:SAI1_SD_A"     	:	6,
	"PE6:SAI4_D1"       	:	9,
	"PE6:SAI4_MCLK_B"   	:	10,
	"PE6:SAI4_SD_A"     	:	8,
	"PE6:SPI4_MOSI"     	:	5,
	"PE6:TIM15_CH2"     	:	4,
	"PE6:TIM1_BKIN2"    	:	1,
	"PE6:TIM1_BKIN2_COMP1"	:	11,
	"PE6:TIM1_BKIN2_COMP2"	:	11,
	"PE7:DFSDM1_DATIN2" 	:	3,
	"PE7:EVENTOUT"      	:	15,
	"PE7:FMC_D4"        	:	12,
	"PE7:FMC_DA4"       	:	12,
	"PE7:OCTOSPIM_P1_IO4"	:	10,
	"PE7:TIM1_ETR"      	:	1,
	"PE7:UART7_RX"      	:	7,
	"PE8:COMP2_OUT"     	:	13,
	"PE8:DFSDM1_CKIN2"  	:	3,
	"PE8:EVENTOUT"      	:	15,
	"PE8:FMC_D5"        	:	12,
	"PE8:FMC_DA5"       	:	12,
	"PE8:OCTOSPIM_P1_IO5"	:	10,
	"PE8:TIM1_CH1N"     	:	1,
	"PE8:UART7_TX"      	:	7,
	"PE9:DFSDM1_CKOUT"  	:	3,
	"PE9:EVENTOUT"      	:	15,
	"PE9:FMC_D6"        	:	12,
	"PE9:FMC_DA6"       	:	12,
	"PE9:OCTOSPIM_P1_IO6"	:	10,
	"PE9:TIM1_CH1"      	:	1,
	"PE9:UART7_DE"      	:	7,
	"PE9:UART7_RTS"     	:	7,
	"PE10:DFSDM1_DATIN4"	:	3,
	"PE10:EVENTOUT"     	:	15,
	"PE10:FMC_D7"       	:	12,
	"PE10:FMC_DA7"      	:	12,
	"PE10:OCTOSPIM_P1_IO7"	:	10,
	"PE10:TIM1_CH2N"    	:	1,
	"PE10:UART7_CTS"    	:	7,
	"PE11:DFSDM1_CKIN4" 	:	3,
	"PE11:EVENTOUT"     	:	15,
	"PE11:FMC_D8"       	:	12,
	"PE11:FMC_DA8"      	:	12,
	"PE11:LTDC_G3"      	:	14,
	"PE11:OCTOSPIM_P1_NCS"	:	11,
	"PE11:SAI4_SD_B"    	:	10,
	"PE11:SPI4_NSS"     	:	5,
	"PE11:TIM1_CH2"     	:	1,
	"PE12:COMP1_OUT"    	:	13,
	"PE12:DFSDM1_DATIN5"	:	3,
	"PE12:EVENTOUT"     	:	15,
	"PE12:FMC_D9"       	:	12,
	"PE12:FMC_DA9"      	:	12,
	"PE12:LTDC_B4"      	:	14,
	"PE12:SAI4_SCK_B"   	:	10,
	"PE12:SPI4_SCK"     	:	5,
	"PE12:TIM1_CH3N"    	:	1,
	"PE13:COMP2_OUT"    	:	13,
	"PE13:DFSDM1_CKIN5" 	:	3,
	"PE13:EVENTOUT"     	:	15,
	"PE13:FMC_D10"      	:	12,
	"PE13:FMC_DA10"     	:	12,
	"PE13:LTDC_DE"      	:	14,
	"PE13:SAI4_FS_B"    	:	10,
	"PE13:SPI4_MISO"    	:	5,
	"PE13:TIM1_CH3"     	:	1,
	"PE14:EVENTOUT"     	:	15,
	"PE14:FMC_D11"      	:	12,
	"PE14:FMC_DA11"     	:	12,
	"PE14:LTDC_CLK"     	:	14,
	"PE14:SAI4_MCLK_B"  	:	10,
	"PE14:SPI4_MOSI"    	:	5,
	"PE14:TIM1_CH4"     	:	1,
	"PE15:EVENTOUT"     	:	15,
	"PE15:FMC_D12"      	:	12,
	"PE15:FMC_DA12"     	:	12,
	"PE15:LTDC_R7"      	:	14,
	"PE15:TIM1_BKIN"    	:	1,
	"PE15:TIM1_BKIN_COMP1"	:	13,
	"PE15:TIM1_BKIN_COMP2"	:	13,
	"PE15:USART10_CK"   	:	11,
	"PH0:EVENTOUT"      	:	15,
	"PH1:EVENTOUT"      	:	15,

    # for Nucleo
	"PG11:ETH_MII_TX_EN"	:	11,
	"PG11:ETH_RMII_TX_EN"	:	11,
	"PG13:ETH_MII_TXD0" 	:	11,
	"PG13:ETH_RMII_TXD0"	:	11,
}
