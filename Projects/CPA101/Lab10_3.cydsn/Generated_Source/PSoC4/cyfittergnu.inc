.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu_trm.inc"

/* led */
.set led__0__DM__MASK, 0x07
.set led__0__DM__SHIFT, 0
.set led__0__DR, CYREG_PRT0_DR
.set led__0__HSIOM, CYREG_HSIOM_PORT_SEL0
.set led__0__HSIOM_MASK, 0x0000000F
.set led__0__HSIOM_SHIFT, 0
.set led__0__INTCFG, CYREG_PRT0_INTCFG
.set led__0__INTSTAT, CYREG_PRT0_INTSTAT
.set led__0__MASK, 0x01
.set led__0__PA__CFG0, CYREG_UDB_PA0_CFG0
.set led__0__PA__CFG1, CYREG_UDB_PA0_CFG1
.set led__0__PA__CFG10, CYREG_UDB_PA0_CFG10
.set led__0__PA__CFG11, CYREG_UDB_PA0_CFG11
.set led__0__PA__CFG12, CYREG_UDB_PA0_CFG12
.set led__0__PA__CFG13, CYREG_UDB_PA0_CFG13
.set led__0__PA__CFG14, CYREG_UDB_PA0_CFG14
.set led__0__PA__CFG2, CYREG_UDB_PA0_CFG2
.set led__0__PA__CFG3, CYREG_UDB_PA0_CFG3
.set led__0__PA__CFG4, CYREG_UDB_PA0_CFG4
.set led__0__PA__CFG5, CYREG_UDB_PA0_CFG5
.set led__0__PA__CFG6, CYREG_UDB_PA0_CFG6
.set led__0__PA__CFG7, CYREG_UDB_PA0_CFG7
.set led__0__PA__CFG8, CYREG_UDB_PA0_CFG8
.set led__0__PA__CFG9, CYREG_UDB_PA0_CFG9
.set led__0__PC, CYREG_PRT0_PC
.set led__0__PC2, CYREG_PRT0_PC2
.set led__0__PORT, 0
.set led__0__PS, CYREG_PRT0_PS
.set led__0__SHIFT, 0
.set led__DR, CYREG_PRT0_DR
.set led__INTCFG, CYREG_PRT0_INTCFG
.set led__INTSTAT, CYREG_PRT0_INTSTAT
.set led__MASK, 0x01
.set led__PA__CFG0, CYREG_UDB_PA0_CFG0
.set led__PA__CFG1, CYREG_UDB_PA0_CFG1
.set led__PA__CFG10, CYREG_UDB_PA0_CFG10
.set led__PA__CFG11, CYREG_UDB_PA0_CFG11
.set led__PA__CFG12, CYREG_UDB_PA0_CFG12
.set led__PA__CFG13, CYREG_UDB_PA0_CFG13
.set led__PA__CFG14, CYREG_UDB_PA0_CFG14
.set led__PA__CFG2, CYREG_UDB_PA0_CFG2
.set led__PA__CFG3, CYREG_UDB_PA0_CFG3
.set led__PA__CFG4, CYREG_UDB_PA0_CFG4
.set led__PA__CFG5, CYREG_UDB_PA0_CFG5
.set led__PA__CFG6, CYREG_UDB_PA0_CFG6
.set led__PA__CFG7, CYREG_UDB_PA0_CFG7
.set led__PA__CFG8, CYREG_UDB_PA0_CFG8
.set led__PA__CFG9, CYREG_UDB_PA0_CFG9
.set led__PC, CYREG_PRT0_PC
.set led__PC2, CYREG_PRT0_PC2
.set led__PORT, 0
.set led__PS, CYREG_PRT0_PS
.set led__SHIFT, 0

/* EZI2C_SCB */
.set EZI2C_SCB__BIST_CONTROL, CYREG_SCB1_BIST_CONTROL
.set EZI2C_SCB__BIST_DATA, CYREG_SCB1_BIST_DATA
.set EZI2C_SCB__CTRL, CYREG_SCB1_CTRL
.set EZI2C_SCB__EZ_DATA00, CYREG_SCB1_EZ_DATA00
.set EZI2C_SCB__EZ_DATA01, CYREG_SCB1_EZ_DATA01
.set EZI2C_SCB__EZ_DATA02, CYREG_SCB1_EZ_DATA02
.set EZI2C_SCB__EZ_DATA03, CYREG_SCB1_EZ_DATA03
.set EZI2C_SCB__EZ_DATA04, CYREG_SCB1_EZ_DATA04
.set EZI2C_SCB__EZ_DATA05, CYREG_SCB1_EZ_DATA05
.set EZI2C_SCB__EZ_DATA06, CYREG_SCB1_EZ_DATA06
.set EZI2C_SCB__EZ_DATA07, CYREG_SCB1_EZ_DATA07
.set EZI2C_SCB__EZ_DATA08, CYREG_SCB1_EZ_DATA08
.set EZI2C_SCB__EZ_DATA09, CYREG_SCB1_EZ_DATA09
.set EZI2C_SCB__EZ_DATA10, CYREG_SCB1_EZ_DATA10
.set EZI2C_SCB__EZ_DATA11, CYREG_SCB1_EZ_DATA11
.set EZI2C_SCB__EZ_DATA12, CYREG_SCB1_EZ_DATA12
.set EZI2C_SCB__EZ_DATA13, CYREG_SCB1_EZ_DATA13
.set EZI2C_SCB__EZ_DATA14, CYREG_SCB1_EZ_DATA14
.set EZI2C_SCB__EZ_DATA15, CYREG_SCB1_EZ_DATA15
.set EZI2C_SCB__EZ_DATA16, CYREG_SCB1_EZ_DATA16
.set EZI2C_SCB__EZ_DATA17, CYREG_SCB1_EZ_DATA17
.set EZI2C_SCB__EZ_DATA18, CYREG_SCB1_EZ_DATA18
.set EZI2C_SCB__EZ_DATA19, CYREG_SCB1_EZ_DATA19
.set EZI2C_SCB__EZ_DATA20, CYREG_SCB1_EZ_DATA20
.set EZI2C_SCB__EZ_DATA21, CYREG_SCB1_EZ_DATA21
.set EZI2C_SCB__EZ_DATA22, CYREG_SCB1_EZ_DATA22
.set EZI2C_SCB__EZ_DATA23, CYREG_SCB1_EZ_DATA23
.set EZI2C_SCB__EZ_DATA24, CYREG_SCB1_EZ_DATA24
.set EZI2C_SCB__EZ_DATA25, CYREG_SCB1_EZ_DATA25
.set EZI2C_SCB__EZ_DATA26, CYREG_SCB1_EZ_DATA26
.set EZI2C_SCB__EZ_DATA27, CYREG_SCB1_EZ_DATA27
.set EZI2C_SCB__EZ_DATA28, CYREG_SCB1_EZ_DATA28
.set EZI2C_SCB__EZ_DATA29, CYREG_SCB1_EZ_DATA29
.set EZI2C_SCB__EZ_DATA30, CYREG_SCB1_EZ_DATA30
.set EZI2C_SCB__EZ_DATA31, CYREG_SCB1_EZ_DATA31
.set EZI2C_SCB__I2C_CFG, CYREG_SCB1_I2C_CFG
.set EZI2C_SCB__I2C_CTRL, CYREG_SCB1_I2C_CTRL
.set EZI2C_SCB__I2C_M_CMD, CYREG_SCB1_I2C_M_CMD
.set EZI2C_SCB__I2C_S_CMD, CYREG_SCB1_I2C_S_CMD
.set EZI2C_SCB__I2C_STATUS, CYREG_SCB1_I2C_STATUS
.set EZI2C_SCB__INTR_CAUSE, CYREG_SCB1_INTR_CAUSE
.set EZI2C_SCB__INTR_I2C_EC, CYREG_SCB1_INTR_I2C_EC
.set EZI2C_SCB__INTR_I2C_EC_MASK, CYREG_SCB1_INTR_I2C_EC_MASK
.set EZI2C_SCB__INTR_I2C_EC_MASKED, CYREG_SCB1_INTR_I2C_EC_MASKED
.set EZI2C_SCB__INTR_M, CYREG_SCB1_INTR_M
.set EZI2C_SCB__INTR_M_MASK, CYREG_SCB1_INTR_M_MASK
.set EZI2C_SCB__INTR_M_MASKED, CYREG_SCB1_INTR_M_MASKED
.set EZI2C_SCB__INTR_M_SET, CYREG_SCB1_INTR_M_SET
.set EZI2C_SCB__INTR_RX, CYREG_SCB1_INTR_RX
.set EZI2C_SCB__INTR_RX_MASK, CYREG_SCB1_INTR_RX_MASK
.set EZI2C_SCB__INTR_RX_MASKED, CYREG_SCB1_INTR_RX_MASKED
.set EZI2C_SCB__INTR_RX_SET, CYREG_SCB1_INTR_RX_SET
.set EZI2C_SCB__INTR_S, CYREG_SCB1_INTR_S
.set EZI2C_SCB__INTR_S_MASK, CYREG_SCB1_INTR_S_MASK
.set EZI2C_SCB__INTR_S_MASKED, CYREG_SCB1_INTR_S_MASKED
.set EZI2C_SCB__INTR_S_SET, CYREG_SCB1_INTR_S_SET
.set EZI2C_SCB__INTR_SPI_EC, CYREG_SCB1_INTR_SPI_EC
.set EZI2C_SCB__INTR_SPI_EC_MASK, CYREG_SCB1_INTR_SPI_EC_MASK
.set EZI2C_SCB__INTR_SPI_EC_MASKED, CYREG_SCB1_INTR_SPI_EC_MASKED
.set EZI2C_SCB__INTR_TX, CYREG_SCB1_INTR_TX
.set EZI2C_SCB__INTR_TX_MASK, CYREG_SCB1_INTR_TX_MASK
.set EZI2C_SCB__INTR_TX_MASKED, CYREG_SCB1_INTR_TX_MASKED
.set EZI2C_SCB__INTR_TX_SET, CYREG_SCB1_INTR_TX_SET
.set EZI2C_SCB__RX_CTRL, CYREG_SCB1_RX_CTRL
.set EZI2C_SCB__RX_FIFO_CTRL, CYREG_SCB1_RX_FIFO_CTRL
.set EZI2C_SCB__RX_FIFO_RD, CYREG_SCB1_RX_FIFO_RD
.set EZI2C_SCB__RX_FIFO_RD_SILENT, CYREG_SCB1_RX_FIFO_RD_SILENT
.set EZI2C_SCB__RX_FIFO_STATUS, CYREG_SCB1_RX_FIFO_STATUS
.set EZI2C_SCB__RX_MATCH, CYREG_SCB1_RX_MATCH
.set EZI2C_SCB__SPI_CTRL, CYREG_SCB1_SPI_CTRL
.set EZI2C_SCB__SPI_STATUS, CYREG_SCB1_SPI_STATUS
.set EZI2C_SCB__SS0_POSISTION, 0
.set EZI2C_SCB__SS1_POSISTION, 1
.set EZI2C_SCB__SS2_POSISTION, 2
.set EZI2C_SCB__SS3_POSISTION, 3
.set EZI2C_SCB__STATUS, CYREG_SCB1_STATUS
.set EZI2C_SCB__TX_CTRL, CYREG_SCB1_TX_CTRL
.set EZI2C_SCB__TX_FIFO_CTRL, CYREG_SCB1_TX_FIFO_CTRL
.set EZI2C_SCB__TX_FIFO_STATUS, CYREG_SCB1_TX_FIFO_STATUS
.set EZI2C_SCB__TX_FIFO_WR, CYREG_SCB1_TX_FIFO_WR
.set EZI2C_SCB__UART_CTRL, CYREG_SCB1_UART_CTRL
.set EZI2C_SCB__UART_RX_CTRL, CYREG_SCB1_UART_RX_CTRL
.set EZI2C_SCB__UART_RX_STATUS, CYREG_SCB1_UART_RX_STATUS
.set EZI2C_SCB__UART_TX_CTRL, CYREG_SCB1_UART_TX_CTRL

/* EZI2C_SCB_IRQ */
.set EZI2C_SCB_IRQ__INTC_CLR_EN_REG, CYREG_CM0_ICER
.set EZI2C_SCB_IRQ__INTC_CLR_PD_REG, CYREG_CM0_ICPR
.set EZI2C_SCB_IRQ__INTC_MASK, 0x800
.set EZI2C_SCB_IRQ__INTC_NUMBER, 11
.set EZI2C_SCB_IRQ__INTC_PRIOR_MASK, 0xC0000000
.set EZI2C_SCB_IRQ__INTC_PRIOR_NUM, 3
.set EZI2C_SCB_IRQ__INTC_PRIOR_REG, CYREG_CM0_IPR2
.set EZI2C_SCB_IRQ__INTC_SET_EN_REG, CYREG_CM0_ISER
.set EZI2C_SCB_IRQ__INTC_SET_PD_REG, CYREG_CM0_ISPR

/* EZI2C_SCBCLK */
.set EZI2C_SCBCLK__DIVIDER_MASK, 0x0000FFFF
.set EZI2C_SCBCLK__ENABLE, CYREG_CLK_DIVIDER_C00
.set EZI2C_SCBCLK__ENABLE_MASK, 0x80000000
.set EZI2C_SCBCLK__MASK, 0x80000000
.set EZI2C_SCBCLK__REGISTER, CYREG_CLK_DIVIDER_C00

/* EZI2C_scl */
.set EZI2C_scl__0__DM__MASK, 0x07
.set EZI2C_scl__0__DM__SHIFT, 0
.set EZI2C_scl__0__DR, CYREG_PRT3_DR
.set EZI2C_scl__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set EZI2C_scl__0__HSIOM_GPIO, 0
.set EZI2C_scl__0__HSIOM_I2C, 14
.set EZI2C_scl__0__HSIOM_I2C_SCL, 14
.set EZI2C_scl__0__HSIOM_MASK, 0x0000000F
.set EZI2C_scl__0__HSIOM_SHIFT, 0
.set EZI2C_scl__0__HSIOM_SPI, 15
.set EZI2C_scl__0__HSIOM_SPI_MOSI, 15
.set EZI2C_scl__0__HSIOM_UART, 9
.set EZI2C_scl__0__HSIOM_UART_RX, 9
.set EZI2C_scl__0__INTCFG, CYREG_PRT3_INTCFG
.set EZI2C_scl__0__INTSTAT, CYREG_PRT3_INTSTAT
.set EZI2C_scl__0__MASK, 0x01
.set EZI2C_scl__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set EZI2C_scl__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set EZI2C_scl__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set EZI2C_scl__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set EZI2C_scl__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set EZI2C_scl__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set EZI2C_scl__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set EZI2C_scl__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set EZI2C_scl__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set EZI2C_scl__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set EZI2C_scl__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set EZI2C_scl__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set EZI2C_scl__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set EZI2C_scl__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set EZI2C_scl__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set EZI2C_scl__0__PC, CYREG_PRT3_PC
.set EZI2C_scl__0__PC2, CYREG_PRT3_PC2
.set EZI2C_scl__0__PORT, 3
.set EZI2C_scl__0__PS, CYREG_PRT3_PS
.set EZI2C_scl__0__SHIFT, 0
.set EZI2C_scl__DR, CYREG_PRT3_DR
.set EZI2C_scl__INTCFG, CYREG_PRT3_INTCFG
.set EZI2C_scl__INTSTAT, CYREG_PRT3_INTSTAT
.set EZI2C_scl__MASK, 0x01
.set EZI2C_scl__PA__CFG0, CYREG_UDB_PA3_CFG0
.set EZI2C_scl__PA__CFG1, CYREG_UDB_PA3_CFG1
.set EZI2C_scl__PA__CFG10, CYREG_UDB_PA3_CFG10
.set EZI2C_scl__PA__CFG11, CYREG_UDB_PA3_CFG11
.set EZI2C_scl__PA__CFG12, CYREG_UDB_PA3_CFG12
.set EZI2C_scl__PA__CFG13, CYREG_UDB_PA3_CFG13
.set EZI2C_scl__PA__CFG14, CYREG_UDB_PA3_CFG14
.set EZI2C_scl__PA__CFG2, CYREG_UDB_PA3_CFG2
.set EZI2C_scl__PA__CFG3, CYREG_UDB_PA3_CFG3
.set EZI2C_scl__PA__CFG4, CYREG_UDB_PA3_CFG4
.set EZI2C_scl__PA__CFG5, CYREG_UDB_PA3_CFG5
.set EZI2C_scl__PA__CFG6, CYREG_UDB_PA3_CFG6
.set EZI2C_scl__PA__CFG7, CYREG_UDB_PA3_CFG7
.set EZI2C_scl__PA__CFG8, CYREG_UDB_PA3_CFG8
.set EZI2C_scl__PA__CFG9, CYREG_UDB_PA3_CFG9
.set EZI2C_scl__PC, CYREG_PRT3_PC
.set EZI2C_scl__PC2, CYREG_PRT3_PC2
.set EZI2C_scl__PORT, 3
.set EZI2C_scl__PS, CYREG_PRT3_PS
.set EZI2C_scl__SHIFT, 0

/* EZI2C_sda */
.set EZI2C_sda__0__DM__MASK, 0x38
.set EZI2C_sda__0__DM__SHIFT, 3
.set EZI2C_sda__0__DR, CYREG_PRT3_DR
.set EZI2C_sda__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set EZI2C_sda__0__HSIOM_GPIO, 0
.set EZI2C_sda__0__HSIOM_I2C, 14
.set EZI2C_sda__0__HSIOM_I2C_SDA, 14
.set EZI2C_sda__0__HSIOM_MASK, 0x000000F0
.set EZI2C_sda__0__HSIOM_SHIFT, 4
.set EZI2C_sda__0__HSIOM_SPI, 15
.set EZI2C_sda__0__HSIOM_SPI_MISO, 15
.set EZI2C_sda__0__HSIOM_UART, 9
.set EZI2C_sda__0__HSIOM_UART_TX, 9
.set EZI2C_sda__0__INTCFG, CYREG_PRT3_INTCFG
.set EZI2C_sda__0__INTSTAT, CYREG_PRT3_INTSTAT
.set EZI2C_sda__0__MASK, 0x02
.set EZI2C_sda__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set EZI2C_sda__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set EZI2C_sda__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set EZI2C_sda__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set EZI2C_sda__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set EZI2C_sda__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set EZI2C_sda__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set EZI2C_sda__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set EZI2C_sda__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set EZI2C_sda__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set EZI2C_sda__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set EZI2C_sda__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set EZI2C_sda__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set EZI2C_sda__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set EZI2C_sda__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set EZI2C_sda__0__PC, CYREG_PRT3_PC
.set EZI2C_sda__0__PC2, CYREG_PRT3_PC2
.set EZI2C_sda__0__PORT, 3
.set EZI2C_sda__0__PS, CYREG_PRT3_PS
.set EZI2C_sda__0__SHIFT, 1
.set EZI2C_sda__DR, CYREG_PRT3_DR
.set EZI2C_sda__INTCFG, CYREG_PRT3_INTCFG
.set EZI2C_sda__INTSTAT, CYREG_PRT3_INTSTAT
.set EZI2C_sda__MASK, 0x02
.set EZI2C_sda__PA__CFG0, CYREG_UDB_PA3_CFG0
.set EZI2C_sda__PA__CFG1, CYREG_UDB_PA3_CFG1
.set EZI2C_sda__PA__CFG10, CYREG_UDB_PA3_CFG10
.set EZI2C_sda__PA__CFG11, CYREG_UDB_PA3_CFG11
.set EZI2C_sda__PA__CFG12, CYREG_UDB_PA3_CFG12
.set EZI2C_sda__PA__CFG13, CYREG_UDB_PA3_CFG13
.set EZI2C_sda__PA__CFG14, CYREG_UDB_PA3_CFG14
.set EZI2C_sda__PA__CFG2, CYREG_UDB_PA3_CFG2
.set EZI2C_sda__PA__CFG3, CYREG_UDB_PA3_CFG3
.set EZI2C_sda__PA__CFG4, CYREG_UDB_PA3_CFG4
.set EZI2C_sda__PA__CFG5, CYREG_UDB_PA3_CFG5
.set EZI2C_sda__PA__CFG6, CYREG_UDB_PA3_CFG6
.set EZI2C_sda__PA__CFG7, CYREG_UDB_PA3_CFG7
.set EZI2C_sda__PA__CFG8, CYREG_UDB_PA3_CFG8
.set EZI2C_sda__PA__CFG9, CYREG_UDB_PA3_CFG9
.set EZI2C_sda__PC, CYREG_PRT3_PC
.set EZI2C_sda__PC2, CYREG_PRT3_PC2
.set EZI2C_sda__PORT, 3
.set EZI2C_sda__PS, CYREG_PRT3_PS
.set EZI2C_sda__SHIFT, 1

/* CapSense_Cmod */
.set CapSense_Cmod__0__DM__MASK, 0x1C0
.set CapSense_Cmod__0__DM__SHIFT, 6
.set CapSense_Cmod__0__DR, CYREG_PRT4_DR
.set CapSense_Cmod__0__HSIOM, CYREG_HSIOM_PORT_SEL4
.set CapSense_Cmod__0__HSIOM_MASK, 0x00000F00
.set CapSense_Cmod__0__HSIOM_SHIFT, 8
.set CapSense_Cmod__0__INTCFG, CYREG_PRT4_INTCFG
.set CapSense_Cmod__0__INTSTAT, CYREG_PRT4_INTSTAT
.set CapSense_Cmod__0__MASK, 0x04
.set CapSense_Cmod__0__PC, CYREG_PRT4_PC
.set CapSense_Cmod__0__PC2, CYREG_PRT4_PC2
.set CapSense_Cmod__0__PORT, 4
.set CapSense_Cmod__0__PS, CYREG_PRT4_PS
.set CapSense_Cmod__0__SHIFT, 2
.set CapSense_Cmod__DR, CYREG_PRT4_DR
.set CapSense_Cmod__INTCFG, CYREG_PRT4_INTCFG
.set CapSense_Cmod__INTSTAT, CYREG_PRT4_INTSTAT
.set CapSense_Cmod__MASK, 0x04
.set CapSense_Cmod__PC, CYREG_PRT4_PC
.set CapSense_Cmod__PC2, CYREG_PRT4_PC2
.set CapSense_Cmod__PORT, 4
.set CapSense_Cmod__PS, CYREG_PRT4_PS
.set CapSense_Cmod__SHIFT, 2

/* CapSense_CSD */
.set CapSense_CSD__CSD_CONFIG, CYREG_CSD_CONFIG
.set CapSense_CSD__CSD_COUNTER, CYREG_CSD_COUNTER
.set CapSense_CSD__CSD_ID, CYREG_CSD_ID
.set CapSense_CSD__CSD_INTR, CYREG_CSD_INTR
.set CapSense_CSD__CSD_INTR_SET, CYREG_CSD_INTR_SET
.set CapSense_CSD__CSD_NUMBER, 0
.set CapSense_CSD__CSD_STATUS, CYREG_CSD_STATUS

/* CapSense_IDACComp_cy_psoc4_idac */
.set CapSense_IDACComp_cy_psoc4_idac__CONTROL, CYREG_CSD_CONFIG
.set CapSense_IDACComp_cy_psoc4_idac__CSD_IDAC, CYREG_CSD_IDAC
.set CapSense_IDACComp_cy_psoc4_idac__CSD_IDAC_SHIFT, 16
.set CapSense_IDACComp_cy_psoc4_idac__CSD_TRIM1, CYREG_CSD_TRIM1
.set CapSense_IDACComp_cy_psoc4_idac__CSD_TRIM1_SHIFT, 4
.set CapSense_IDACComp_cy_psoc4_idac__CSD_TRIM2, CYREG_CSD_TRIM2
.set CapSense_IDACComp_cy_psoc4_idac__CSD_TRIM2_SHIFT, 4
.set CapSense_IDACComp_cy_psoc4_idac__IDAC_NUMBER, 2
.set CapSense_IDACComp_cy_psoc4_idac__POLARITY, CYREG_CSD_CONFIG
.set CapSense_IDACComp_cy_psoc4_idac__POLARITY_SHIFT, 17

/* CapSense_IDACMod_cy_psoc4_idac */
.set CapSense_IDACMod_cy_psoc4_idac__CONTROL, CYREG_CSD_CONFIG
.set CapSense_IDACMod_cy_psoc4_idac__CSD_IDAC, CYREG_CSD_IDAC
.set CapSense_IDACMod_cy_psoc4_idac__CSD_IDAC_SHIFT, 0
.set CapSense_IDACMod_cy_psoc4_idac__CSD_TRIM1, CYREG_CSD_TRIM1
.set CapSense_IDACMod_cy_psoc4_idac__CSD_TRIM1_SHIFT, 0
.set CapSense_IDACMod_cy_psoc4_idac__CSD_TRIM2, CYREG_CSD_TRIM2
.set CapSense_IDACMod_cy_psoc4_idac__CSD_TRIM2_SHIFT, 0
.set CapSense_IDACMod_cy_psoc4_idac__IDAC_NUMBER, 1
.set CapSense_IDACMod_cy_psoc4_idac__POLARITY, CYREG_CSD_CONFIG
.set CapSense_IDACMod_cy_psoc4_idac__POLARITY_SHIFT, 16

/* CapSense_ISR */
.set CapSense_ISR__INTC_CLR_EN_REG, CYREG_CM0_ICER
.set CapSense_ISR__INTC_CLR_PD_REG, CYREG_CM0_ICPR
.set CapSense_ISR__INTC_MASK, 0x8000
.set CapSense_ISR__INTC_NUMBER, 15
.set CapSense_ISR__INTC_PRIOR_MASK, 0xC0000000
.set CapSense_ISR__INTC_PRIOR_NUM, 3
.set CapSense_ISR__INTC_PRIOR_REG, CYREG_CM0_IPR3
.set CapSense_ISR__INTC_SET_EN_REG, CYREG_CM0_ISER
.set CapSense_ISR__INTC_SET_PD_REG, CYREG_CM0_ISPR

/* CapSense_ModClk */
.set CapSense_ModClk__DIVIDER_MASK, 0x0000FFFF
.set CapSense_ModClk__ENABLE, CYREG_CLK_DIVIDER_A00
.set CapSense_ModClk__ENABLE_MASK, 0x80000000
.set CapSense_ModClk__MASK, 0x80000000
.set CapSense_ModClk__REGISTER, CYREG_CLK_DIVIDER_A00

/* CapSense_Sns */
.set CapSense_Sns__0__DM__MASK, 0x7000
.set CapSense_Sns__0__DM__SHIFT, 12
.set CapSense_Sns__0__DR, CYREG_PRT3_DR
.set CapSense_Sns__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set CapSense_Sns__0__HSIOM_MASK, 0x000F0000
.set CapSense_Sns__0__HSIOM_SHIFT, 16
.set CapSense_Sns__0__INTCFG, CYREG_PRT3_INTCFG
.set CapSense_Sns__0__INTSTAT, CYREG_PRT3_INTSTAT
.set CapSense_Sns__0__MASK, 0x10
.set CapSense_Sns__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set CapSense_Sns__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set CapSense_Sns__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set CapSense_Sns__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set CapSense_Sns__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set CapSense_Sns__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set CapSense_Sns__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set CapSense_Sns__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set CapSense_Sns__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set CapSense_Sns__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set CapSense_Sns__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set CapSense_Sns__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set CapSense_Sns__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set CapSense_Sns__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set CapSense_Sns__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set CapSense_Sns__0__PC, CYREG_PRT3_PC
.set CapSense_Sns__0__PC2, CYREG_PRT3_PC2
.set CapSense_Sns__0__PORT, 3
.set CapSense_Sns__0__PS, CYREG_PRT3_PS
.set CapSense_Sns__0__SHIFT, 4
.set CapSense_Sns__Button0_Sns0__DM__MASK, 0x7000
.set CapSense_Sns__Button0_Sns0__DM__SHIFT, 12
.set CapSense_Sns__Button0_Sns0__DR, CYREG_PRT3_DR
.set CapSense_Sns__Button0_Sns0__INTCFG, CYREG_PRT3_INTCFG
.set CapSense_Sns__Button0_Sns0__INTSTAT, CYREG_PRT3_INTSTAT
.set CapSense_Sns__Button0_Sns0__MASK, 0x10
.set CapSense_Sns__Button0_Sns0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set CapSense_Sns__Button0_Sns0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set CapSense_Sns__Button0_Sns0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set CapSense_Sns__Button0_Sns0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set CapSense_Sns__Button0_Sns0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set CapSense_Sns__Button0_Sns0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set CapSense_Sns__Button0_Sns0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set CapSense_Sns__Button0_Sns0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set CapSense_Sns__Button0_Sns0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set CapSense_Sns__Button0_Sns0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set CapSense_Sns__Button0_Sns0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set CapSense_Sns__Button0_Sns0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set CapSense_Sns__Button0_Sns0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set CapSense_Sns__Button0_Sns0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set CapSense_Sns__Button0_Sns0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set CapSense_Sns__Button0_Sns0__PC, CYREG_PRT3_PC
.set CapSense_Sns__Button0_Sns0__PC2, CYREG_PRT3_PC2
.set CapSense_Sns__Button0_Sns0__PORT, 3
.set CapSense_Sns__Button0_Sns0__PS, CYREG_PRT3_PS
.set CapSense_Sns__Button0_Sns0__SHIFT, 4
.set CapSense_Sns__DR, CYREG_PRT3_DR
.set CapSense_Sns__INTCFG, CYREG_PRT3_INTCFG
.set CapSense_Sns__INTSTAT, CYREG_PRT3_INTSTAT
.set CapSense_Sns__MASK, 0x10
.set CapSense_Sns__PA__CFG0, CYREG_UDB_PA3_CFG0
.set CapSense_Sns__PA__CFG1, CYREG_UDB_PA3_CFG1
.set CapSense_Sns__PA__CFG10, CYREG_UDB_PA3_CFG10
.set CapSense_Sns__PA__CFG11, CYREG_UDB_PA3_CFG11
.set CapSense_Sns__PA__CFG12, CYREG_UDB_PA3_CFG12
.set CapSense_Sns__PA__CFG13, CYREG_UDB_PA3_CFG13
.set CapSense_Sns__PA__CFG14, CYREG_UDB_PA3_CFG14
.set CapSense_Sns__PA__CFG2, CYREG_UDB_PA3_CFG2
.set CapSense_Sns__PA__CFG3, CYREG_UDB_PA3_CFG3
.set CapSense_Sns__PA__CFG4, CYREG_UDB_PA3_CFG4
.set CapSense_Sns__PA__CFG5, CYREG_UDB_PA3_CFG5
.set CapSense_Sns__PA__CFG6, CYREG_UDB_PA3_CFG6
.set CapSense_Sns__PA__CFG7, CYREG_UDB_PA3_CFG7
.set CapSense_Sns__PA__CFG8, CYREG_UDB_PA3_CFG8
.set CapSense_Sns__PA__CFG9, CYREG_UDB_PA3_CFG9
.set CapSense_Sns__PC, CYREG_PRT3_PC
.set CapSense_Sns__PC2, CYREG_PRT3_PC2
.set CapSense_Sns__PORT, 3
.set CapSense_Sns__PS, CYREG_PRT3_PS
.set CapSense_Sns__SHIFT, 4

/* CapSense_SnsClk */
.set CapSense_SnsClk__DIVIDER_MASK, 0x0000FFFF
.set CapSense_SnsClk__ENABLE, CYREG_CLK_DIVIDER_B00
.set CapSense_SnsClk__ENABLE_MASK, 0x80000000
.set CapSense_SnsClk__MASK, 0x80000000
.set CapSense_SnsClk__REGISTER, CYREG_CLK_DIVIDER_B00

/* Miscellaneous */
.set CYDEV_BCLK__HFCLK__HZ, 48000000
.set CYDEV_BCLK__HFCLK__KHZ, 48000
.set CYDEV_BCLK__HFCLK__MHZ, 48
.set CYDEV_BCLK__SYSCLK__HZ, 48000000
.set CYDEV_BCLK__SYSCLK__KHZ, 48000
.set CYDEV_BCLK__SYSCLK__MHZ, 48
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PANTHER, 19
.set CYDEV_CHIP_DIE_PSOC4A, 11
.set CYDEV_CHIP_DIE_PSOC5LP, 18
.set CYDEV_CHIP_DIE_TMA4, 2
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC4
.set CYDEV_CHIP_JTAG_ID, 0x04C81193
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 11
.set CYDEV_CHIP_MEMBER_4C, 16
.set CYDEV_CHIP_MEMBER_4D, 7
.set CYDEV_CHIP_MEMBER_4E, 4
.set CYDEV_CHIP_MEMBER_4F, 12
.set CYDEV_CHIP_MEMBER_4G, 2
.set CYDEV_CHIP_MEMBER_4H, 10
.set CYDEV_CHIP_MEMBER_4I, 15
.set CYDEV_CHIP_MEMBER_4J, 8
.set CYDEV_CHIP_MEMBER_4K, 9
.set CYDEV_CHIP_MEMBER_4L, 14
.set CYDEV_CHIP_MEMBER_4M, 13
.set CYDEV_CHIP_MEMBER_4N, 6
.set CYDEV_CHIP_MEMBER_4O, 5
.set CYDEV_CHIP_MEMBER_4U, 3
.set CYDEV_CHIP_MEMBER_5A, 18
.set CYDEV_CHIP_MEMBER_5B, 17
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_4A
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PANTHER_ES0, 0
.set CYDEV_CHIP_REV_PANTHER_ES1, 1
.set CYDEV_CHIP_REV_PANTHER_PRODUCTION, 1
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4C_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_4A_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_READ_ACCELERATOR, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_PROTECT_KILL, 4
.set CYDEV_DEBUG_PROTECT_OPEN, 1
.set CYDEV_DEBUG_PROTECT, CYDEV_DEBUG_PROTECT_OPEN
.set CYDEV_DEBUG_PROTECT_PROTECTED, 2
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DFT_SELECT_CLK0, 1
.set CYDEV_DFT_SELECT_CLK1, 2
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_IMO_TRIMMED_BY_USB, 0
.set CYDEV_IMO_TRIMMED_BY_WCO, 0
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 1
.set CYDEV_VDDA_MV, 3300
.set CYDEV_VDDD_MV, 3300
.set CYDEV_WDT_GENERATE_ISR, 0
.set CYIPBLOCK_M0S8_CTBM_VERSION, 0
.set CYIPBLOCK_m0s8cpuss_VERSION, 0
.set CYIPBLOCK_m0s8csd_VERSION, 0
.set CYIPBLOCK_m0s8gpio2_VERSION, 0
.set CYIPBLOCK_m0s8hsiom4a_VERSION, 0
.set CYIPBLOCK_m0s8lcd_VERSION, 0
.set CYIPBLOCK_m0s8lpcomp_VERSION, 0
.set CYIPBLOCK_m0s8pclk_VERSION, 0
.set CYIPBLOCK_m0s8sar_VERSION, 0
.set CYIPBLOCK_m0s8scb_VERSION, 0
.set CYIPBLOCK_m0s8srssv2_VERSION, 1
.set CYIPBLOCK_m0s8tcpwm_VERSION, 0
.set CYIPBLOCK_m0s8udbif_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 2
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif