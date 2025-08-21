# Systeminfo

Diese Bibliothek soll einem die Systeminformationen zur Verfügung stellen. Dazu zählen sowohl
Hardwarekomponenten als auch Softwareinformationen. Der grundlegendste Teil basiert aber auf Informationen
der Software. Dazu gibt die Bibliothek auch noch Aufschluss darüber, auf welchem Softwarestand die
compilierte Firmware des STM32 arbeitet. Zusätzlich wird noch das Git-Repository mit angezeigt.

## Hardware

Bei der Hardware sind Informationen über den STM32 von Bedeutung. Hier wird dann neben dem Systemtakt
noch die Revision, die Device ID und die UUID ausgegeben.

## Software

Zur Software stehen einem deutlich mehr Informationen zur Verfügung. Zum einen werden hier dann
einige Informationen zur Software des Systemes aufgeführt. Aktuell sind dann hier die Daten der
kompilierten Software in Datum und Zeit gezeigt. Zusätzlich werden Angaben über Git mit ausgegeben.

## Git

Die Angaben über Git sind neben dem aktuellen Git-Hash auch noch das Datum, die Zeit, der aktuelle
Branch sowie der letzte Tag bzw. die Tags aus dem Branch.

Zusätzlich werden Informationen über die Anzahl der Branches und Commits mit angezeigt.

## FreeRTOS

Sollte im Programm ein FreeRTOS System mit implementiert werden, so kann hier dann auch eine Ausgabe
der Revision und Version erfolgen.