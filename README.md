# android-rpc
A C-based Remote Procedure Call client that uses ADB over WiFi to execute shell commands on an android device remotely. Launch apps, open camera, simulate inputs, and more using a pc with no extra software dependencies on the phone.

Built as a simple **RPC client**:
- PC (client) → connects wirelessly to phone (ADB server)
- Sends commands like "open camera", "launch Settings", "simulate key press"
- Phone executes them remotely and returns output

Perfect for automation demos, app testing, accessibility experiments, or just controlling your phone without touching it.

## Features
- Wireless control via official ADB (no root, no custom apps)
- Simple one-file C program (`remote_activate.c`)
- Automatic ADB connect → execute → disconnect flow
- Tested on Windows 10/11 with VS Code + MinGW
- Works on same Wi-Fi network (no internet needed)

## Prerequisites

Before you begin, make sure you have:

- **Operating System**: Windows 10 or 11
- **Android Phone**: Android 11 or newer (recommended for reliable Wireless debugging + pairing code support)
- **Network**: PC and phone connected to the **same Wi-Fi network** (no mobile data or VPN)
- **Tools on PC**:
  - Git (optional, for cloning the repo)
  - Visual Studio Code (recommended editor)
  - MinGW-w64 GCC compiler (to build the C program)
  - Android SDK Platform-Tools (includes `adb.exe`)
- **Phone Settings Access**:
  - Ability to enable Developer options and Wireless debugging
  - Phone not in battery saver mode during initial setup (can interfere with ADB)

## Installation & Setup

### 1. Install ADB (Android Debug Bridge)
1. Download the latest **Platform-Tools** ZIP file:  
   https://developer.android.com/tools/releases/platform-tools  
   (Click "Download SDK Platform-Tools for Windows")
2. Extract the ZIP contents to a simple folder, for example:  
   `C:\platform-tools`
3. Add the folder to your system PATH:
   - Right-click **This PC** → **Properties** → **Advanced system settings** → **Environment Variables**
   - In **System variables**, select **Path** → **Edit** → **New** → paste `C:\platform-tools` → OK all windows
4. Open PowerShell or Command Prompt and verify:
   ```powershell
   adb version
