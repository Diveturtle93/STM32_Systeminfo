//----------------------------------------------------------------------
// Titel	:	systeminfo.h
//----------------------------------------------------------------------
// Sprache	:	C
// Datum	:	16.01.2021
// Autor	:	Diveturtle93
// Projekt	:	Systeminfo
// Quelle	:
//----------------------------------------------------------------------

// Sicherheitssymbol
//----------------------------------------------------------------------
#pragma once
//----------------------------------------------------------------------

// Dateiheader definieren
//----------------------------------------------------------------------
#ifndef INC_SYSTEMINFO_H_
#define INC_SYSTEMINFO_H_
//----------------------------------------------------------------------

// Einfuegen der standard Include-Dateien
//----------------------------------------------------------------------

//----------------------------------------------------------------------

// Einfuegen der STM Include-Dateien
//----------------------------------------------------------------------

//----------------------------------------------------------------------

// Einfuegen der eigenen Include-Dateien
//----------------------------------------------------------------------

//----------------------------------------------------------------------

// Definiere Debug-Symbole
//----------------------------------------------------------------------
#ifdef DEBUG
	#define DEBUG_SYSTEMINFO
#endif
//----------------------------------------------------------------------

// Build Daten definieren
//----------------------------------------------------------------------
#ifndef BUILD_DATE
#define BUILD_DATE								__DATE__					// Build Datum speichern wenn noch nicht definiert
#endif

#ifndef BUILD_TIME
#define BUILD_TIME								__TIME__					// Build Zeit speichern wenn noch nicht definiert
#endif
//----------------------------------------------------------------------

// Version definieren
//----------------------------------------------------------------------
#define SYSTEMINFO_MAJOR						0
#define SYSTEMINFO_MINOR						0
#define SYSTEMINFO_PATCH						0
#define SYSTEMINFO_DEV							1
//----------------------------------------------------------------------

// Funktionen definieren
//----------------------------------------------------------------------
void collectSystemInfo (void);												// Sammelt Systeminformationen, Schreibt diese auf Uart
void collectHardwareInfo (void);											// Sammle Hardware Informationen
void collectSoftwareInfo (void);											// Sammle Software Informationen
void collectMiddlewareInfo (void);											// Sammle Middleware Informationen
void collectGitcounts (void);												// Sammle Git Count Informationen
//----------------------------------------------------------------------

#endif /* INC_SYSTEMINFO_H_ */
//----------------------------------------------------------------------