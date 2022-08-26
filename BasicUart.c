//----------------------------------------------------------------------
// Titel	:	Error.c
//----------------------------------------------------------------------
// Sprache	:	C
// Datum	:	26.08.2022
// Version	:	1.0
// Autor	:	Diveturtle93
// Projekt	:	STM32_Systeminfo
//----------------------------------------------------------------------

// Einfuegen der standard Include-Dateien
//----------------------------------------------------------------------
#include "string.h"
#include "stdlib.h"
#include "inttypes.h"
//----------------------------------------------------------------------

// Einfuegen der STM Include-Dateien
//----------------------------------------------------------------------
#include "main.h"
#include "usart.h"
//----------------------------------------------------------------------

// Einfuegen der eigenen Include Dateien
//----------------------------------------------------------------------
#include "BasicUart.h"
//----------------------------------------------------------------------

// Uart Transmit Funktion
//----------------------------------------------------------------------
void uartTransmit(const char *str, const size_t size)
{
	// Sende String mit Laenge "Size", "Size" muss bekannt sein
	HAL_UART_Transmit(&huart3, (uint8_t *)str, size, 1000);
}
//----------------------------------------------------------------------

// Uart Transmit String Funktion
//----------------------------------------------------------------------
void uartTransmitString(const char *str)
{
	// So lange *text != '\0', also ungleich dem "String-Endezeichen(Terminator)"
	while(*str)																// Starte Pointerschleife
	{
		HAL_UART_Transmit(&huart3, (uint8_t*) str, 1, 1000);				// Sende Zeichen
		str++;																// Pointer hochzaehlen
	}
}
//----------------------------------------------------------------------

// Uart Transmit Nummer Funktion
//----------------------------------------------------------------------
void uartTransmitNumber(const uint32_t number, const uint32_t base)
{
	char str[11];

	// Zahl umrechnen
	itoa(number, str, base);
	HAL_UART_Transmit(&huart3, (uint8_t *)str, strlen(str), 1000);
}
//----------------------------------------------------------------------

// Deinitialisieren des Uart
//----------------------------------------------------------------------
void uartReInitBasicPolling(void)
{
	HAL_UART_DMAStop(&huart3);
	HAL_UART_DeInit(&huart3);
	HAL_UART_MspDeInit(&huart3);

	HAL_UART_Init(&huart3);
	HAL_UART_MspInit(&huart3);

	HAL_UART_DMAStop(&huart3);
	HAL_DMA_DeInit(huart3.hdmatx);
	HAL_DMA_DeInit(huart3.hdmarx);
}
//----------------------------------------------------------------------
