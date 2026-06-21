![Gigathon Icon](https://i.imgur.com/1mSIKP4.png)

This README was written in two languages:
- **English** [Memory-Game](#memory-game-english)
-  **Polski** [Gra-w-Memory](#gra-w-memory-polski)

# Memory-Game (English)

## Table of Contents
1. [Project Overview](#project-overview)
2. [Setup and Compilation](#setup-and-compilation)
3. [Game Instructions](#game-instructions)
4. [Key Features](#key-features)

---

## Project Overview

This is a simple command-line memory game where players uncover pairs of cards on a grid, attempting to match symbols. The game can be played in two modes:
- **2-Player Mode**: Two human players alternate turns to match pairs of cards.
- **Vs. Computer Mode**: A single player competes against the computer.

The game includes optional features like **animations** for smooth card reveals and **extra turn rewards** for correct guesses.

---

## Setup and Compilation

### Prerequisites

To run this program, you need a C++ development environment. The game is compatible with most operating systems (Windows, Linux). The setup depends on your system, but generally, you will need:

- A **C++ compiler** (e.g., g++, clang, or Visual Studio).
- A terminal or command-line interface to compile and run the program.

### Compilation Instructions

1. **Download the code**:
   Clone or download the repository from GitHub to your local machine.
   
2. **Open terminal**:
   Navigate to the folder where the game code is stored.

3. **Compile the code**:
   Using a terminal, run the following command to compile the program (assuming `g++` is installed):

   ```
   g++ -o MeM MeM.cpp
   ```

   This will create an executable named `MeM`.

   [You can also download already compiled version to skip this step.](https://github.com/Student-FastDev/MeM/releases)

5. **Run the game**:
   After compiling, run the game by typing:

   ```
   ./MeM
   ```

   If you're on Windows, run it as:

   ```
   MeM.exe
   ```

---

## Game Instructions

### Main Menu Options

When you launch the game, you will see the following main menu:

```
 _  _  ____  _  _ 
( \/ )(  __)( \/ )
/ \/ \ ) _) / \/ \
\_)(_/(____)\_)(_/ 

Welcome to Memory Game!

(1) 2-Players Mode
(2) Vs. Computer Mode
(3) Settings
(4) Exit

Input: 
```

### How to Play

- **Goal**: The objective is to uncover pairs of matching cards on the board. The player with the most matched pairs wins.
  
- **2-Player Mode**:
  1. Select "1" to play in 2-player mode.
  2. Choose the board size by entering the number of rows and columns.
  3. Players take turns selecting two cards, trying to match the symbols.
  4. If a match is found, the player gets a point, and (optionally) an extra turn.
  5. The game ends when all pairs are matched.

- **Vs. Computer Mode**:
  1. Select "2" to play against the computer.
  2. Choose the board size by entering the number of rows and columns.
  3. You take turns against the computer. The game ends when all pairs are matched.

### Settings Menu

- Select "3" from the main menu to adjust game settings:
  - Enable or disable **card reveal animations**.
  - Enable or disable **extra turn rewards** for correct matches.

---

## Key Features

1. **Smooth Card Reveal Animation**:
   - Each card can be revealed with a smooth animation showing different transition steps.
   - You can toggle this feature in the settings menu.

2. **Extra Turn Rewards**:
   - If a player finds a matching pair, they are rewarded with an extra turn (if enabled in settings).

3. **AI Opponent**:
   - In Vs. Computer mode, the computer uses a random algorithm to select cards.

4. **Win Animations**:
   - If a player wins, a trophy animation is displayed.
   - If the computer wins, a "losing face" animation is shown.

5. **Adjustable Board Size**:
   - Players can customize the number of rows and columns for the board.

---

# Gra-w-Memory (Polski)

## Spis treści
1. [Opis projektu](#opis-projektu)
2. [Konfiguracja i kompilacja](#konfiguracja-i-kompilacja)
3. [Instrukcje do gry](#instrukcje-do-gry)
4. [Kluczowe funkcje](#kluczowe-funkcje)

---

## Opis projektu

To prosta gra w memory działająca w konsoli, w której gracze odkrywają pary kart na planszy, próbując dopasować symbole. Gra może być rozgrywana w dwóch trybach:
- **Tryb 2-graczy**: Dwóch graczy na zmianę odkrywa karty, aby dopasować pary.
- **Tryb vs. komputer**: Jeden gracz rywalizuje z komputerem.

Gra zawiera opcjonalne funkcje, takie jak **animacje** dla płynnych odkryć kart oraz **nagrody za dodatkowe tury** za poprawne zgadywanie.

---

## Konfiguracja i kompilacja

### Wymagania wstępne

Aby uruchomić ten program, potrzebujesz środowiska programistycznego C++. Gra jest kompatybilna z większością systemów operacyjnych (Windows, Linux). Konfiguracja zależy od twojego systemu, ale generalnie będziesz potrzebować:

- **Kompilatora C++** (np. g++, clang lub Visual Studio).
- Terminala lub interfejsu wiersza poleceń do kompilacji i uruchamiania programu.

### Instrukcje kompilacji

1. **Pobierz kod**:
   Sklonuj lub pobierz repozytorium z GitHub na swój lokalny komputer.
   
2. **Otwórz terminal**:
   Przejdź do folderu, w którym znajduje się kod gry.

3. **Kompiluj kod**:
   W terminalu uruchom następujące polecenie, aby skompilować program (zakładając, że masz zainstalowany `g++`):

   ```
   g++ -o MeM MeM.cpp
   ```

   To stworzy plik wykonywalny o nazwie `MeM`.

   [Możesz także pobrać skompilowany plik, aby pominąć ten krok.](https://github.com/Student-FastDev/MeM/releases)

5. **Uruchom grę**:
   Po skompilowaniu uruchom grę, wpisując:

   ```
   ./MeM
   ```

   Jeśli jesteś na systemie Windows, uruchom jako:

   ```
   MeM.exe
   ```

---

## Instrukcje do gry

### Opcje głównego menu

Gdy uruchomisz grę, zobaczysz następujące główne menu:

```
 _  _  ____  _  _ 
( \/ )(  __)( \/ )
/ \/ \ ) _) / \/ \
\_)(_/(____)\_)(_/ 

Welcome to Memory Game!

(1) 2-Players Mode
(2) Vs. Computer Mode
(3) Settings
(4) Exit

Input: 
```

### Jak grać

- **Cel**: Celem gry jest odkrycie par pasujących kart na planszy. Gracz z największą liczbą dopasowanych par wygrywa.
  
- **Tryb 2-graczy**:
  1. Wybierz "1", aby grać w trybie 2-graczy.
  2. Wybierz rozmiar planszy, wpisując liczbę wierszy i kolumn.
  3. Gracze na zmianę wybierają dwie karty, próbując dopasować symbole.
  4. Jeśli karta pasuje, gracz zdobywa punkt, a (opcjonalnie) dodatkową turę.
  5. Gra kończy się, gdy wszystkie pary zostaną dopasowane.

- **Tryb vs. komputer**:
  1. Wybierz "2", aby grać przeciwko komputerowi.
  2. Wybierz rozmiar planszy, wpisując liczbę

 wierszy i kolumn.
  3. Na przemian wykonujesz ruchy przeciwko komputerowi. Gra kończy się, gdy wszystkie pary zostaną dopasowane.

### Menu ustawień

- Wybierz "3" z głównego menu, aby dostosować ustawienia gry:
  - Włącz lub wyłącz **animacje odkrywania kart**.
  - Włącz lub wyłącz **nagrody za dodatkowe tury** za poprawne dopasowania.

---

## Kluczowe funkcje

1. **Płynna animacja odkrywania kart**:
   - Każda karta może być odkryta z płynna animacją pokazującą różne etapy przejścia.
   - Możesz przełączać tę funkcję w menu ustawień.

2. **Nagrody za dodatkowe tury**:
   - Jeśli gracz znajdzie dopasowaną parę, otrzymuje dodatkową turę (jeśli włączono w ustawieniach).

3. **Przeciwnik AI**:
   - W trybie vs. komputer komputer używa losowego algorytmu do wyboru kart.

4. **Animacje zwycięstwa**:
   - Jeśli gracz wygra, wyświetla się animacja trofeum.
   - Jeśli komputer wygra, wyświetla się animacja „przegranej twarzy”.

5. **Dostosowywany rozmiar planszy**:
   - Gracze mogą dostosować liczbę wierszy i kolumn planszy.

---
