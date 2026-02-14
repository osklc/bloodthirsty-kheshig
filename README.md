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

### Current Release (v0.3.0-pre-alpha)
- **Main Menu System** - Navigate between 5 game zones
- **Character Stat Tracking** - Health, XP, Level, Attack, Defense, and Gold management
- **Save System (Save/Load)** - Automatic progress saving via binary .dat files
- **Dynamic Battle Log** - Real-time combat log to track damage and events
- **Multiple Game Zones**:
  - ⚔️ War Menu - Combat encounters with multiple difficulty levels
  - 🏪 Market Menu - Buy potions, damage scrolls, and armor
  - 🔨 Blacksmith Menu - Upgrade weapons and armor
  - 🎰 Gambling Menu - Risk/reward mini-games
  - 🏨 The Inn - Rest, gamble, and work when broke
- **Keyboard-based Navigation** - W/S for vertical menu navigation, F to select, Q to go back
- **Console UI** - Colorized text interface with ANSI escape codes and health bars

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
.\bin\Bloodthirsty-Kheshig.exe
```

### Controls
| Key | Action |
|-----|--------|
| **W** / **S** | Move up/down in menus and zones |
| **F** | Select/Enter current option |
| **Q** | Quit/Go back to previous menu |

### Main Menu
- View your character stats (HP, Level, XP, Gold, Attack, Defense, Day/Time) at the top
- Navigate between zones using **W** and **S** keys
- Press **F** to enter a selected zone
- Press **Q** to exit the game

### In-Game Menus
- Use **W** and **S** to move up and down the menu list
- Press **F** to select an item or action
- Press **Q** to return to the main menu

---

## 🗺️ Game Zones

### ⚔️ War Menu
Enter combat encounters across three difficulty zones with scaling difficulty. Defeat enemies to earn XP and Gold.
- **Northern Forests** (Level 0-10): Early-game zone with balanced difficulty (~60-80% win chance)
- **Enchanted Groves** (Level 11-20): Mid-game zone requiring gear upgrades (~40-50% win chance)
- **Spirit Realm** (Level 21+): Late-game zone for experienced warriors (~20-30% win chance)
- **Current Status**: ✅ Fully Functional turn-based combat system
- **Features**: Balanced enemy AI, zone-based difficulty scaling, dynamic combat log, experience and gold rewards

### 🏪 Market Menu
Buy health potions, damage scrolls, and armor to strengthen your character.
- **Current Status**: ✅ Fully Functional
- **Features**: Buy Health Potion (Health+50) - 20G, Buy Damage Scroll (ATK+3) - 120G, Buy Armor (DEF+3) - 120G, Sell Items

### 🔨 Blacksmith Menu
Upgrade your weapons and armor with random stat boosts.
- **Current Status**: ✅ Fully Functional
- **Features**: Sword Upgrade (ATK+1 to ATK+3) - 90G, Armor Upgrade (DEF+1 to DEF+3) - 90G

### 🎰 Gambling Menu
Test your luck with gambling games to increase or lose gold.
- **Current Status**: ✅ Fully Functional
- **Features**: Coin Flip (50% chance, 30G bet), Dice Roll (50% chance, 50G bet), High Stakes (30% chance, 100G bet)

### 🏨 The Inn
Rest, gamble, and earn money when desperate.
- **Rest** - (10G) Restore 30 HP (1 time period)
- **Gamble** - Play mini-games for risk/reward opportunities
- **Work at Inn** - Available when you have 0 gold, earn 15G per period (1 time period)
- **Current Status**: ✅ Fully Functional
- **Features**: Emergency income when broke, gambling opportunities, health restoration

---

## 🚀 Development Status

### Current Version: v0.3.0 (Pre-Alpha)
- ✅ Menu Navigation with 5 zones (unified W/S vertical navigation)
- ✅ Combat Mechanics (Attacks, Defense, balanced Enemy AI)
- ✅ Zone-Based Enemy Progression (Northern Forests, Enchanted Groves, Spirit Realm)
- ✅ Save System (Save/Load)
- ✅ Colored UI & Dynamic Battle Log with health bars
- ✅ Market Menu (Buy/Sell items)
- ✅ Blacksmith Menu (Equipment upgrades with RNG)
- ✅ The Inn (Rest, Gamble, or Work when broke)
- ✅ Gambling Menu (Coin Flip, Dice Roll, High Stakes)

### Status: **Playable Pre-Alpha**
Core game mechanics are functional. This is an early-stage project for educational purposes.

---

## 📋 Roadmap

### v0.2.0 - Core Systems & Persistence (Completed)
- [x] Combat Mechanics: Functional turn-based battle system
- [x] Save System: Persisting character data to disk using .dat format
- [x] Persistence: Loading character progress between sessions
- [x] Dynamic UI: Live health bars and scrolling battle logs

### v0.3.0 - Combat & AI (The "Tactical" Update)
- [x] Implement functional Market Menu mechanics
- [x] Implement functional Blacksmith Menu mechanics
- [x] Implement functional Gambling (Mini-Game) mechanics
- [x] Balanced Enemy AI: Scaled attack/defense values for fair gameplay
- [x] Zone-Based Difficulty: Northern Forests → Enchanted Groves → Spirit Realm progression
- [x] Work at Inn: Earn gold when broke without combat
- [x] Unified Menu Navigation: All menus use W/S for selection
- [x] Level Scaling: XP required for next level will increase exponentially
- [x] Stamina System: Attacks will consume energy, requiring strategic pauses
- [x] Dynamic XP & Gold: Rewards will vary based on RNG (Random Number Generation)
- [x] Loot Drop: Enemies will have a chance to drop rare items (Stat boosters)
- [x] Expanded Market: Introduction of XP Potions and special scrolls

### v0.4.0+ - Atmosphere & Story (The "Possession" Update)
- [ ] Boss System: Bosses will be added, and separate mechanics will be added for each boss.
- [ ] **Possession Bar System**: A corruption/possession meter that fills during battles and story progression
- [ ] **Demonic Transformation**: When the Possession Bar fills completely, an ancient demon possesses Kheshig during combat
- [ ] **Mage Form**: Upon possession, Kheshig transforms into a sorcerer with:
  - Mana system (replaces Stamina) for spell casting
  - Magical attacks with higher damage scaling
  - Unique visual feedback and combat mechanics
- [ ] **Story Integration**: Narrative consequences and choices related to the possession mechanic
- [ ] **ANSI Art Storytelling**: Visual narrative using colored ASCII art for regions, bosses, and story events
- [ ] **Advanced Enemy AI**: Enemies may flee or heal when low on health
- [ ] **Multiple Character Classes**: Warrior (default) and Wizard (post-possession variant)
- [ ] **Quest System**: Story-driven quests with rewards and progression (day based)

---

## 🛠️ Technical Details

### Project Structure
```
Turn-Based Arena Fighter in terminal/
├── main.c                          # Main game loop and menu system
├── include/
│   ├── BLACKSMITHMENU_.h           # Blacksmith header
│   ├── GAMBLINGMENU_.h             # Gambling header
│   ├── MARKETMENU_.h               # Market header
│   ├── WARMENU_.h                  # War/combat header
│   └── INNMENU_.h                  # Inn header
├── src/
│   ├── BLACKSMITHMENU_.c           # Blacksmith functionality
│   ├── GAMBLINGMENU_.c             # Gambling system
│   ├── MARKETMENU_.c               # Market/trading system
│   ├── WARMENU_.c                  # War/combat system
│   ├── INNMENU_.c                  # Inn rest system
│   └── resource.rc                 # Resource file
├── bin/                            # Compiled executables
├── assets/                         # Game assets
├── make.bat                        # Windows batch build script
└── README.md                       # This file
```

### Build System
- **Compiler**: GCC with `-Wall` (all warnings) and `-g` (debug symbols)
- **Target**: Windows executable (Bloodthirsty-Kheshig.exe)
- **Build Tool**: Batch script (make.bat) with GCC integration

### Libraries Used
- `stdio.h` - Standard I/O
- `stdlib.h` - Standard library
- `conio.h` - Console I/O
- `windows.h` - Windows API (cursor control, console management)
- `time.h` - Time functions (RNG seeding, delays)
- `string.h` - String handling and memory operations

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

**Last Updated**: February 15, 2026  
**Current Version**: v0.3.0 (Pre-Alpha)
