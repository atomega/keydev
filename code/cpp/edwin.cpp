

void steupUart()
{
	//GPS 36 bytesi
	static volatile uint8_t rxBuffer[36]; 
	uDMAEnable(); // enables dma generag DNA activation does not depent on periferals. 
	uDMAControlBaseSet(void *psControlTable); // DMA control table for ocnfiguration & application. Table schould be dclared from user. 
	uDMAChannelAttributeEnable(UDMA_CHANNEL_UART1RX, UDMA_ATTR_HIGH_PRIORITY); // Channel selection  
	uDMAChannelControlSet(UDMA_CHANNEL_UART1RX | UDMA_PRI_SELECT, UDMA_SIZE_8 | UDMA_SRC_INC_NONE | UDMA_DST_INC_8 | UDMA_ARB_36); //Channel enabling ? 
	uDMAChannelTransferSet(UDMA_CHANNEL_UART1RX | UDMA_PRI_SELECT, UDMA_MODE_BASIC, (void *)(UART0_BASE + UART_O_DR), rxBuffer, sizeof(rxbuffer)); // unknown

	// Don't know which one comes first. 
	uDMAChannelEnable(); // Let all of it
	uDMAIntRegister(UDMA_CHANNEL_UART1RX, HANDLER );
}
