<div align="center">

# 🎮 Switch Emby 客户端

<p align="center">
  <strong>为 Nintendo Switch 打造的功能完整的 Emby 媒体客户端</strong>
</p>

<p align="center">
  基于 C++17 开发 | Borealis UI 框架 | MPV 播放器
</p>

---

</div>

## ✨ 项目简介

Switch Emby 是一款专为 Nintendo Switch 设计的全功能 Emby 媒体客户端。通过原生 Switch UI 和硬件加速播放，让你在掌机上享受流畅的家庭媒体库体验。无论是电影、电视剧还是音乐，都能轻松访问和播放。

## 🌟 核心特性

### 📺 媒体功能
- **🎬 完整 Emby API 支持** - 无缝对接 Emby 服务器所有功能
- **📚 媒体浏览** - 支持电影、电视剧、音乐等多种媒体类型
- **▶️ 硬件加速播放** - 利用 Switch 硬件解码，流畅播放高清视频
- **🔄 断点续播** - 跨设备同步播放进度，随时继续观看

### 🎨 用户体验
- **💎 原生 Switch UI** - 完美适配 Switch 操作习惯的精美界面
- **🌐 多语言支持** - 内置英语、中文、日语界面
- **🎭 多主题切换** - 提供默认、深色、浅色等多种主题

### 🎵 播放控制
- **📝 字幕支持** - 多语言字幕自由切换
- **🎵 音轨切换** - 支持多音轨选择
- **⚙️ 播放设置** - 丰富的播放参数调整

## 🚀 快速开始

### 📥 安装步骤

1. **下载应用**
   - 前往 [Releases](https://github.com/yourusername/switchemby/releases) 页面
   - 下载最新版本的 `switchemby.nro` 文件

2. **安装到 Switch**
   - 将 `switchemby.nro` 复制到 SD 卡的 `/switch/switchemby/` 目录
   - 如果目录不存在，请手动创建

3. **启动应用**
   - 通过 Switch 自制程序菜单（Homebrew Menu）启动应用

### 🎯 使用指南

1. **添加服务器**
   - 首次启动时，输入你的 Emby 服务器地址（格式：IP:端口）
   - 例如：`192.168.1.100:8096`

2. **登录账户**
   - 输入 Emby 账户的用户名和密码
   - 支持记住登录状态

3. **开始使用**
   - 浏览你的媒体库
   - 选择想要观看的内容
   - 享受流畅的播放体验

## 🛠️ 构建说明

### 🤖 自动化构建（推荐）

本项目使用 GitHub Actions 自动构建，推送代码后即可下载构建产物：

| 平台 | 文件名 | 说明 |
|------|--------|------|
| 🎮 Nintendo Switch | `switchemby.nro` | Switch 自制程序格式 |
| 🪟 Windows | `switchemby.exe` | Windows 可执行文件 |
| 🐧 Linux | `switchemby` | Linux 可执行文件 |
| 🍎 macOS | `switchemby.app` | macOS 应用程序包 |

### 💻 本地开发（可选）

#### 环境准备

**Switch 平台：**
```bash
# 安装 devkitPro 和 devkitA64
# 安装必要的库
dkp-pacman -S switch-dev switch-portlibs switch-mpv switch-curl
```

**桌面平台：**
- CMake 3.13 或更高版本
- 支持 C++17 的编译器（GCC 7+, Clang 5+, MSVC 2017+）
- MPV 媒体播放库
- libcurl 网络库

#### 构建命令

```bash
# 克隆仓库（包含子模块）
git clone --recursive https://github.com/yourusername/switchemby.git
cd switchemby

# Switch 平台构建
mkdir build && cd build
cmake .. -DPLATFORM_SWITCH=ON
make

# 桌面平台构建
mkdir build && cd build
cmake .. -DPLATFORM_DESKTOP=ON
make
```

## ⚙️ 配置说明

配置文件位置：`/switch/switchemby/config.json`

你可以在配置文件中自定义：
- 服务器地址和端口
- 默认语言和主题
- 播放器设置
- 网络参数

## 🎨 主题定制

应用内置多个主题，位于 `app/resources/themes/` 目录：
- `default.json` - 默认主题
- `dark.json` - 深色主题

你也可以创建自己的主题文件来个性化界面。

## 🌍 多语言支持

语言文件位于 `app/resources/i18n/` 目录：
- `en-US.json` - 英语
- `zh-CN.json` - 简体中文

欢迎贡献更多语言翻译！

## 📋 系统要求

- Nintendo Switch（需要自制系统环境）
- Atmosphere 或其他 CFW
- 稳定的网络连接
- Emby 服务器（版本 4.0+）

## 🤝 贡献指南

欢迎提交 Issue 和 Pull Request！

1. Fork 本仓库
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 开启 Pull Request

## 📄 开源协议

本项目采用 MIT 协议开源 - 详见 [LICENSE](LICENSE) 文件

## 🙏 致谢

本项目的开发离不开以下优秀的开源项目：

- **[switchfin](https://github.com/dragonflylee/switchfin)** - 项目基础和灵感来源
- **[Borealis](https://github.com/natinusala/borealis)** - 强大的 Switch UI 框架
- **[MPV](https://mpv.io/)** - 高性能的媒体播放器

感谢所有贡献者和支持者！

---

<div align="center">

**⭐ 如果这个项目对你有帮助，请给个 Star 支持一下！⭐**

Made with ❤️ for Nintendo Switch

</div>
