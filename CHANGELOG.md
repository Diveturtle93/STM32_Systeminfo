# Changelog

Alle nennenswerten Änderungen an diesem Projekt werden hier dokumentiert.
Format nach [Keep a Changelog](https://keepachangelog.com/de/1.1.0/),
Versionierung nach [Semantic Versioning](https://semver.org/lang/de/).

## [Unveröffentlicht]

### Hinzugefügt

- `collectSystemInfo()` gibt alle Systeminformationen gegliedert in die Blöcke Hardware,
  Software, Middleware und Git counts über UART aus.
- `collectHardwareInfo()` gibt Device ID, Revision ID, CPU-Frequenz in MHz, die 96-Bit-UUID
  und die Cortex-M-CPUID mit Implementer, Variant, Architektur, Partnummer und Revision aus.
  Implementer, Architektur und Partnummer werden hexadezimal ausgegeben, z. B. `C27` für
  den Cortex-M7.
- `collectSoftwareInfo()` gibt Build-Datum und -Zeit, den Erstellungszeitpunkt der
  `git.h`, Commit, Branch, Hash, alle Tags des Branches, den letzten Tag und dessen Commit
  auch im Dirty-Format aus.
- `collectMiddlewareInfo()` gibt die Versionen von Cortex CMSIS, STM32 CMSIS und HAL aus.
- CMSIS-RTOS- und FreeRTOS-Kernel-Version werden zusätzlich ausgegeben, wenn `cmsis_os.h`
  und `task.h` eingebunden sind.
- `collectGitcounts()` gibt die Anzahl der Commits seit dem letzten Tag, aller Commits, der
  Commits im Branch, der aktiven Branches und der Tags aus.
- Unterstützung der STM32-Familien F1, F7 und G0.
- `BUILD_DATE` und `BUILD_TIME` werden aus `__DATE__` und `__TIME__` befüllt, wenn sie
  nicht vorher definiert sind.
- Debug-Symbol `DEBUG_SYSTEMINFO`, das mit `DEBUG` gesetzt wird. Ohne das Symbol sind alle
  Funktionen leer und es findet keine UART-Ausgabe statt.
- Versions-Defines `SYSTEMINFO_MAJOR`, `_MINOR`, `_PATCH` und `_DEV` in `systeminfo.h`.
- README mit Beschreibung, Funktionsumfang, Dateien, Konfigurationsparametern, API,
  Verwendung, Hinweisen und unterstützten STM32-Familien.
- Dieses Changelog.
