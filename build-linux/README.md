# Building on MacOS
## Requirements
- Homebrew
- XCode (Command line utils are not enough, you'll need the full suite=
- Angle (Instructions below)
## Installing dependencies
    brew install automake gtk+ sdl2 sdl2_ttf sdl2_gfx sdl2_image sdl2_mixer libxi glew

Instead of the Homebrew gtk+ package, you could also [compile GTK yourself](https://wiki.gnome.org/Projects/GTK/OSX/Building). Next step is building [Angle](https://github.com/google/angle), as Apple removed OpenGL support from MacOS:

    git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
    PATH=/path/to/depot_tools_repository:$PATH
    mkdir angle
    cd angle
    fetch angle
    gn args out/Release
    
The last command pulls up your editor. You want to add `is_debug = false` to the file, in order to build the latest release version.

    gn gen out/Release
    autoninja -C out/Release

If these steps don't work for you, [check the instructions from Google](https://chromium.googlesource.com/angle/angle/+/HEAD/doc/DevSetup.md).

Next up is installing Valgrind using [this Brew formulae](https://github.com/LouisBrunner/valgrind-macos):

    brew tap LouisBrunner/valgrind
    brew install --HEAD LouisBrunner/valgrind/valgrind

If this formulae doesn't work, [try this one](https://github.com/gabrieldejesus/valgrind-macos).

## Building Principia

First step is to clone this repository and navigate to `build-linux`. Next, **copy or symlink** the Angle libraries `libGLESv2.dylib` and `libEGL.dylib` to the current directory. They are located in `/path/to/angle/repository/out/Release`. Now, we can finally start building:

    ./autogen.sh
    ./configure
    ./go -cs

If the build succeeds, try to run it with `./principia`

## Current status/problems

- I removed the rt library, because it doesn't exist on MacOS. We'll need to see if that causes bugs.
- Build succeeds with a lot of warnings
- Trying to run Principia still results in an error:
```
III: Created fifo
III: Starting fifo listener thread
III: chdirring to ?
III: attempting to open /tmp/principia.run O_RDONLY
Initializing SDL... OK
III: set initial res to 1280x720
III: num workers (real): 8
III: num workers (user): 8
III: Modified cam settings.
            _            _       _       
 _ __  _ __(_)_ __   ___(_)_ __ (_) __ _ 
| '_ \| '__| | '_ \ / __| | '_ \| |/ _` |
| |_) | |  | | | | | (__| | |_) | | (_| |
| .__/|_|  |_|_| |_|\___|_| .__/|_|\__,_|
|_|                       |_|            
Version: 34. Jan  9 2023/14:27:49
Creating window... OK
Initializing GLEW... ERROR: Missing GL version
```
