# STM32 Systeminfo
 
Eine in C implementierte Bibliothek für STM32-Mikrocontroller, die beim Systemstart
umfassende Hardware- und Softwareinformationen zusammenstellt und über UART ausgibt.
Sie dient als praktisches Diagnosewerkzeug, um den aktuellen Zustand einer Firmware
schnell und vollständig nachvollziehen zu können.
 
## Beschreibung
 
Die Bibliothek sammelt Systeminformationen aus verschiedenen Quellen – von der
STM32-Hardware über den verwendeten Middleware-Stack bis hin zu detaillierten
Informationen aus dem Git-Repository. Auf Wunsch können auch RTOS-Informationen von
FreeRTOS mit ausgegeben werden. Alle Informationen werden strukturiert über die
UART-Schnittstelle ausgegeben, was besonders beim Debugging und bei der
Qualitätssicherung im Embedded-Bereich hilfreich ist.
 
## Funktionsumfang
 
### Hardware
 
Folgende Informationen werden direkt vom STM32-Mikrocontroller ausgelesen und ausgegeben:
 
| Information        | Beschreibung                                      |
|--------------------|---------------------------------------------------|
| Device ID          | Mikrocontrollertyp                                |
| Revision ID        | Hardware-Revision (z. B. Y, Z, X)                 |
| CPU-Frequenz       | Aktueller Systemtakt in MHz                       |
| UUID               | Eindeutige 96-Bit-ID des Mikrocontrollers         |
| CPUID (Cortex-M)   | Implementer, Variant, Architektur, Partnummer     |
 
### Software
 
Zur kompilierten Firmware werden folgende Informationen ausgegeben:
 
| Information        | Beschreibung                                      |
|--------------------|---------------------------------------------------|
| Build Date / Time  | Datum und Uhrzeit des Kompiliervorgangs           |
| Git Build Date/Time| Erstellungszeitpunkt der `git.h`-Datei            |
| Git Commit         | Aktueller Commit-Name                             |
| Git Branch         | Aktueller Branch                                  |
| Git Hash           | Aktueller Commit-Hash                             |
| Git Tags           | Alle Tags im Branch sowie der letzte Tag          |
| Git Tag Commit     | Commit des letzten Tags (auch im Dirty-Format)    |
 
### Git-Statistiken
 
Zusätzlich werden Zählinformationen aus dem Git-Repository ausgegeben:
 
| Information              | Beschreibung                                         |
|--------------------------|------------------------------------------------------|
| Dirty Count              | Anzahl der Commits seit dem letzten Tag              |
| Overall Commit Count     | Gesamtanzahl der Commits im Repository               |
| Branch Commit Count      | Anzahl der Commits im aktuellen Branch               |
| Active Branches          | Anzahl der aktiven Branches                          |
| Tag Count                | Gesamtanzahl der Tags                                |
 
### Middleware
 
Die Bibliothek gibt außerdem die Versionsinformationen des verwendeten Software-Stacks aus:
 
| Information          | Beschreibung                                       |
|----------------------|----------------------------------------------------|
| Cortex CMSIS Version | Version der ARM Cortex-M CMSIS-Bibliothek          |
| STM32 CMSIS Version  | Versionsnummer der STM32-spezifischen CMSIS-Schicht (F1 / F7 / G0) |
| HAL Version          | Version der STM32 HAL-Bibliothek                   |
| FreeRTOS Version     | CMSIS-RTOS- und Kernel-Version (optional)          |
 
## API
 
```c
void collectSystemInfo(void);       // Gibt alle Systeminformationen über UART aus
void collectHardwareInfo(void);     // Gibt Hardware-Informationen aus
void collectSoftwareInfo(void);     // Gibt Software- und Git-Informationen aus
void collectMiddlewareInfo(void);   // Gibt Middleware-Versionsinformationen aus
void collectGitcounts(void);        // Gibt Git-Zählinformationen aus
```
 
## Verwendung
 
1. `systeminfo.h` und `systeminfo.c` in das STM32-Projekt einbinden.
2. Eine `git.h`-Datei mit den Git-Metadaten als Teil des Build-Prozesses generieren
(z. B. über ein Pre-Build-Skript).
3. `BUILD_DATE` und `BUILD_TIME` werden automatisch aus den Compiler-Makros `__DATE__`
und `__TIME__` befüllt, können aber auch manuell gesetzt werden.
4. `collectSystemInfo()` beim Systemstart aufrufen, um alle Informationen einmalig
über UART auszugeben.

### Optionale FreeRTOS-Unterstützung
 
Wenn FreeRTOS im Projekt eingebunden ist, werden CMSIS-RTOS- und Kernel-
Versionsinformationen automatisch mit ausgegeben. Dazu müssen lediglich die
entsprechenden Includes in `systeminfo.c` aktiviert werden:
 
```c
#include "cmsis_os.h"
#include "task.h"
```
 
### Unterstützte STM32-Familien
 
Die Bibliothek unterstützt über Präprozessor-Direktiven verschiedene STM32-Serien:
 
- STM32F1
- STM32F7
- STM32G0

## Abhängigkeiten
 
- `main.h` – STM32 HAL
- [`basicuart.h`](https://github.com/Diveturtle93/STM32_Basicuart) – UART-Sende- und Empfangsfunktionen
- `git.h` – Automatisch generierte Git-Metadaten

## Lizenz
 
Dieses Projekt steht unter der [GPL-3.0 Lizenz](LICENSE).
