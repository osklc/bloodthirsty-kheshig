# 🐺 Bloodthirsty Kheshig

Bloodthirsty Kheshig is a turn-based arena combat game developed in C, running natively in the Windows terminal. Explore the ruthless world of the steppe, develop your character, and survive strategic battles to become a legend.

---

## 📖 Table of Contents
- [Features](#-features)
- [Requirements](#️-requirements)
- [Quick Start](#-quick-start)
- [Installation & Building](#-installation)
- [How to Play](#-how-to-play)
- [Game Zones](#️-game-zones)
- [Development Status](#-development-status)
- [Roadmap](#-roadmap)
- [Technical Details](#️-technical-details)

---

## ✨ Features

### Current Release (v0.1.0-alpha)
- **Main Menu System** - Navigate between 4 game zones
- **Character Stat Tracking** - Health, Durability, and Gold management
- **Save System (Save/Load)** - Automatic progress saving via binary .dat files
- **Dynamic Battle Log** - Real-time combat log to track damage and events
- **Multiple Game Zones**:
  - ⚔️ War Menu - Combat encounters
  - 🏪 Market Menu - Trading hub
  - 🔨 Blacksmith Menu - Equipment enhancement
  - 🎰 Gambling Menu - Risk/reward mechanics
- **Keyboard-based Navigation** - WASD controls and menu selection
- **Console UI** - Colorized text interface with ANSI escape codes

---

## 🖥️ Requirements

- **OS**: Windows (tested on Windows 10/11)
- **Compiler**: GCC (via MSYS2 or MinGW)
- **Build Tool**: Make (via MSYS2)
- **Terminal**: Windows PowerShell or CMD

### Tested Environments
- Dev C++ with MinGW
- VS Code with GCC
- MSYS2 (latest version)
- GCC 11+

---

## 🚀 Quick Start

### ⚡ For Everyone: Play Without Installing Anything

**Download and run the compiled executable:**

1. Go to [Releases](https://github.com/osklc/Turn-Based-Arena-Fighter-in-the-C-Terminal/releases)
2. Download the latest version from the Releases page.
3. Extract the .zip file
3. Run Bloodthirsty_Kheshig.exe

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

## 🚀 Development Status

### Current Version: v0.2.0 (Pre-Alpha)
- ✅ Menu Navigation
- ✅ Combat Mechanics (Basic Attacks, Enemy AI)
- ✅ Save System (Save/Load)
- ✅ Colored UI & Battle Log
- ❌ Market & Blacksmith (Not implemented yet)

### Status: **Non-Production Ready**
This is an early-stage prototype for educational and development purposes.

---

## 📋 Roadmap

### v0.2.0 - Core Systems & Persistence (Completed)
- [x] Combat Mechanics: Functional turn-based battle system.
- [x] Save System: Persisting character data to disk using .dat format.
- [x] Persistence: Loading character progress between sessions.
- [x] Dynamic UI: Live health bars and scrolling battle logs.

### v0.3.0 - Combat & AI (The "Tactical" Update)
- [ ] Implement functional Market Menu mechanics
- [ ] Implement functional Blacksmith Menu mechanics
- [ ] Implement functional Gambling (Mini-Game) mechanics
- [ ] Stamina System: Attacks will consume energy, requiring strategic pauses.
- [ ] Loot Drop: Enemies will have a chance to drop rare items (Stat boosters).
- [ ] Dynamic XP & Gold: Rewards will vary based on RNG (Random Number Generation).
- [ ] Level Scaling: XP required for next level will increase exponentially.
- [ ] Balancing: Refined damage/defense formulas for fairer fights.
- [ ] Expanded Market: Introduction of XP Potions and special scrolls.

### v0.4.0+ - Atmosphere & Story
- [ ] ANSI Art Storytelling: Visual narrative using colored ASCII art for regions and bosses.
- [ ] Advanced Enemy AI: Enemies may flee or heal when low on health.
- [ ] Multiple character classes (Warrior, Archer, Shaman)
- [ ] Quest system
- [ ] "Endless Mode" (Survival)

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
- `time.h` - Time functions (RNG seeding, delays)
- `string.h` - String handling and memory operations

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

- Menu systems are UI prototypes (not fully functional)
- Limited visual feedback in combat zones
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

**Last Updated**: January 28, 2026  
**Current Version**: v0.2.0 (Pre-Alpha) (Non-Production Ready)