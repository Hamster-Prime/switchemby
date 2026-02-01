# Switch Emby Client

A feature-rich Emby client for Nintendo Switch, built with C++17, Borealis UI framework, and MPV player.

## Features

- 🎬 Full Emby API support
- 📺 Media browsing (Movies, TV Shows, Music)
- ▶️ Hardware-accelerated playback
- 📝 Subtitle support with multiple languages
- 🎵 Audio track switching
- 🔄 Resume playback from any device
- 🎨 Beautiful native Switch UI
- 🌐 Multi-language support (English, Chinese, Japanese)
- 🎭 Multiple themes (Default, Dark, Light)

## Building

### Automated Build (Recommended)

All builds are automated through GitHub Actions. Simply push to the repository and download the artifacts:

- `switchemby.nro` - Nintendo Switch
- `switchemby.exe` - Windows
- `switchemby` - Linux
- `switchemby.app` - macOS

### Local Development (Optional)

#### Prerequisites

**For Switch:**
- devkitPro with devkitA64
- Switch libraries: `dkp-pacman -S switch-dev switch-portlibs switch-mpv switch-curl`

**For Desktop:**
- CMake 3.13+
- C++17 compiler
- MPV library
- libcurl

#### Build Commands

```bash
# Clone with submodules
git clone --recursive https://github.com/yourusername/switchemby.git
cd switchemby

# Switch build
mkdir build && cd build
cmake .. -DPLATFORM_SWITCH=ON
make

# Desktop build
mkdir build && cd build
cmake .. -DPLATFORM_DESKTOP=ON
make
```

## Installation

1. Download `switchemby.nro` from releases
2. Copy to `/switch/switchemby/` on your SD card
3. Launch via Homebrew Menu

## Usage

1. Add your Emby server (IP:Port)
2. Login with your credentials
3. Browse and enjoy your media library

## Configuration

Config file location: `/switch/switchemby/config.json`

## License

MIT License - See LICENSE file for details

## Credits

- Based on [switchfin](https://github.com/dragonflylee/switchfin)
- UI Framework: [Borealis](https://github.com/natinusala/borealis)
- Media Player: [MPV](https://mpv.io/)
