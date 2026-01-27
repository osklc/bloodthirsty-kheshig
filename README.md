# 🎮 Turn-Based Arena Fighter

A turn-based arena combat game written in C, running in the Windows console terminal. Battle through different zones, manage your character's stats, and engage in strategic gameplay.

---

## 📖 Table of Contents
- [Features](#-features)
- [Requirements](#️-requirements)
- [Quick Start](#-quick-start)
- [Installation](#-installation)
- [Building](#-building)
- [How to Play](#-how-to-play)
- [Game Zones](#️-game-zones)
- [Character Stats](#-character-stats)
- [Development Status](#-development-status)
- [Roadmap](#-roadmap)
- [Technical Details](#️-technical-details)

---

## ✨ Features

### Current Release (v0.1.0-alpha)
- **Main Menu System** - Navigate between 4 game zones
- **Character Stat Tracking** - Health, Durability, and Gold management
- **Multiple Game Zones**:
  - ⚔️ War Menu - Combat encounters
  - 🏪 Market Menu - Trading hub
  - 🔨 Blacksmith Menu - Equipment enhancement
  - 🎰 Gambling Menu - Risk/reward mechanics
- **Keyboard-based Navigation** - WASD controls and menu selection
- **Console UI** - Colorized text interface with ANSI escape codes

---

## 🖥️ Requirements

- **OS**: Windows (tested on Windows 10+)
- **Compiler**: GCC (via MSYS2 or MinGW)
- **Build Tool**: Make (via MSYS2)
- **Terminal**: Windows PowerShell or CMD

### Tested Environments
- Dev C++ with MinGW
- MSYS2 (latest version)
- GCC 11+

---

## 🚀 Quick Start

### ⚡ For Everyone: Play Without Installing Anything

**Download and run the compiled executable:**

1. Go to [Releases](https://github.com/osklc/Turn-Based-Arena-Fighter-in-the-C-Terminal/releases)
2. Download `game.exe` from the latest release
3. Run it directly

**No installation, no compilation needed!** The executable is ready to play.

### For Developers: Build from Source

See [Building](#-building) section below to compile the game yourself.

---

## 📥 Installation

### For Source Code Development

#### Prerequisites
1. Install MSYS2 from https://www.msys2.org/
2. Ensure GCC is installed: `gcc --version`

### Clone the Repository
```bash
git clone <your-repo-url>
cd "Turn-Based Arena Fighter in terminal"
```

---

## 🔨 Building

### Using the Makefile (Recommended)
```bash
.\make.bat          # Compile all modules
```

### Manual Compilation
```bash
gcc -Wall -g -o game.exe main.c menus/BLACKSMITHMENU_.c menus/GAMBLINGMENU_.c menus/MARKETMENU_.c menus/WARMENU_.c menus/CURSORCONTROL_.c
```

### Clean Build
```bash
make clean          # Remove compiled files
make rebuild        # Clean and recompile
```

---

## 🎮 How to Play

### Running the Game
```bash
.\game.exe
```

### Controls
| Key | Action |
|-----|--------|
| **A** / **D** | Move left/right between zones |
| **F** | Select/Enter current zone |
| **Q** | Quit game |

### Main Menu
- View your character stats at the top of the menu
- Navigate between zones using **A** and **D** keys
- Press **F** to enter a selected zone
- Press **Q** to exit the game

---

## 🗺️ Game Zones

### ⚔️ War Menu
Enter combat encounters, defeat enemies, and earn experience and rewards.
- **Current Status**: Prototype UI (mechanics in development)
- **Future**: Full turn-based combat system with enemy AI

### 🏪 Market Menu
Buy and sell items, manage inventory, and trade with merchants.
- **Current Status**: Prototype UI (mechanics in development)
- **Future**: Dynamic pricing, quest rewards, rare items

### 🔨 Blacksmith Menu
Enhance your equipment, repair damaged gear, and forge new weapons.
- **Current Status**: Prototype UI (mechanics in development)
- **Future**: Durability system, equipment tiers, crafting recipes

### 🎰 Gambling Menu
Test your luck with gambling games to increase or lose gold.
- **Current Status**: Prototype UI (mechanics in development)
- **Future**: Multiple gambling games, progressive betting

---

## 📊 Character Stats

| Stat | Description | Initial Value |
|------|-------------|---|
| **Health** | Character's hitpoints | 100 |
| **Durability** | Equipment durability/integrity | 100 |
| **Gold** | Currency for trading and upgrades | 0 |
---

## 🚀 Development Status

### Current Version: v0.1.0-alpha
- ✅ Menu navigation system
- ✅ Character stat display
- ✅ Console UI with colors
- ✅ Automated build system
- ❌ Functional game mechanics
- ✅ Save/Load system
- ❌ Combat calculations
- ❌ AI opponents

### Status: **Non-Production Ready**
This is an early-stage prototype for educational and development purposes.

---

## 📋 Roadmap

### v0.2.0 - Menu Systems & Save System
- [x] Implement functional War Menu mechanics
- [ ] Implement functional Market Menu mechanics
- [ ] Implement functional Blacksmith Menu mechanics
- [ ] Implement functional Gambling Menu mechanics
- [x] **Create save file system (.dat format)** - Character stats will be persisted to disk
- [x] **Character stats persistence** - Load and save character progress between sessions
- [x] Load game state from save files

### v0.3.0 - Combat & AI
- [ ] Turn-based combat system
- [ ] Enemy AI implementation
- [ ] Combat calculations and balance
- [ ] Experience and leveling system
- [ ] Add Stamina

### v0.4.0+ - Advanced Features
- [ ] Multiple character classes
- [ ] Leaderboard system
- [ ] Enhanced graphics and UI
- [ ] Sound effects and music
- [ ] Multiplayer support
- [ ] Expanded content and storyline

---

## 🛠️ Technical Details

### Project Structure
```
Turn-Based Arena Fighter/
├── main.c                          # Main game loop and menu system
├── menus/
│   ├── BLACKSMITHMENU_.c/.h       # Blacksmith functionality
│   ├── GAMBLINGMENU_.c/.h         # Gambling system
│   ├── MARKETMENU_.c/.h           # Market/trading system
│   ├── WARMENU_.c/.h              # War/combat system
│   └── CURSORCONTROL_.c/.h        # Console control utilities
├── Makefile                        # Build configuration
├── make.bat                        # Windows batch build script
└── README.md                       # This file
```

### Build System
- **Compiler**: GCC with `-Wall` (all warnings) and `-g` (debug symbols)
- **Target**: Windows executable (game.exe)
- **Build Tool**: Make with MSYS2 integration

### Libraries Used
- `stdio.h` - Standard I/O
- `stdlib.h` - Standard library
- `conio.h` - Console I/O
- `windows.h` - Windows API (cursor control, console management)

### ANSI Escape Codes
The game uses ANSI escape codes for colored terminal output:
- `\033[31m` - Red text
- `\033[33m` - Yellow text
- `\033[36m` - Cyan text
- `\033[3m` - Italic text
- `\033[1m` - Bold text
- `\033[0m` - Reset formatting

---

## 🐛 Known Issues

- Character stats not saved between sessions
- Menu systems are UI prototypes (not fully functional)
- Limited visual feedback in combat zones
- No save/load functionality
- Combat balance not finalized

---

## 📝 Contributing

This is a personal learning project, but suggestions and improvements are welcome!

---

## 📄 License

This project is open source and available for educational purposes.

---

## 👨‍💻 Author

Created: January 2026

---

## 🔗 Resources

- [MSYS2 Installation Guide](https://www.msys2.org/)
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [Windows Console API](https://docs.microsoft.com/en-us/windows/console/console-functions)

---

**Last Updated**: January 27, 2026  
**Current Version**: v0.1.0-alpha (Non-Production Ready)