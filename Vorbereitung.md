# Vorbereitung

#### Wie können in einem C++-Programm die Funktionsdefinitionen auf mehrere Sourcedateien verteilt werden? Welche Schritte werden bis zur Erstellung des Executables durchlaufen (Wiederholung PE1)?

-   Header files die auf die einzelnen Source files referenzieren

#### Wie kann die Projektverwaltung mit make und einem Makefile automatisiert werden?

-   make automatisiert den prozess vom kompilieren indem es einen skript ausführt der alle dateien kompiliert und man nicht alles händisch machen muss.

#### Schauen Sie Sich das bereitgestellte Makefile an. Welche C++-Sourcedateien müssen Sie selber erstellen

-   db.cpp und main.cpp

#### Schauen Sie Sich die bereitgestellte Datei db.h an. Welche Funktionen müssen Sie in db.cpp implementieren?

-   alle in db.h

#### Wie kann man in einem C++-Programm die Kommandozeilenargumente auslesen

-   argc: anzahl der argumente; argv: ist ein Vektor/Array mit den Argumenten als Inhalt. argv[0] ist immer der Programmaufruf.

#### Wie kann man einen std::string an eine Funktion wie z.B. PQconnectdb() übergeben, die als Parameter einen const char\* erwartet?

-   mit der nativen Funktion `c_str()`

#### Wie kann man eine Datei in der Programmiersprache C++ zeilenweise einlesen und jede Zeile in die durch ein Trennzeichen getrennten Felder zerlegen? (Hinweis: fgets() und strtok() bzw. strsep())

-   Stream erstellen, über den Stream loopen und mit fgets/getline/strtok zeilenweise einlesen.
