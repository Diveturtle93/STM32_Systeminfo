//----------------------------------------------------------------------
// Titel	:	BasicUart.h
//----------------------------------------------------------------------
// Sprache	:	C
// Datum	:	26.08.2022
// Version	:	1.0
// Autor	:	Diveturtle93
// Projekt	:	STM32_Systeminfo
//----------------------------------------------------------------------

// Dateiheader definieren
//----------------------------------------------------------------------
#ifndef INC_BASICUART_H_
#define INC_BASICUART_H_
//----------------------------------------------------------------------

// Einfuegen der standard Include-Dateien
//----------------------------------------------------------------------
#include <stdio.h>
//----------------------------------------------------------------------

// Funktionen definieren
//----------------------------------------------------------------------
void uartTransmit(const char *str, const size_t size);						// Sende Daten an Uart
void uartTransmitString(const char *str);									// Sende String an Uart
void uartTransmitNumber(const uint32_t number, const uint32_t base);		// Sende Nummer an Uart
void uartReInitBasicPolling(void);											// Reinitialisiere Uart
//----------------------------------------------------------------------

#endif /* INC_BASICUART_H_ */
//----------------------------------------------------------------------
