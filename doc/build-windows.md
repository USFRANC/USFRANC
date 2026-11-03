WINDOWS BUILD NOTES
====================

Below are some notes on how to build USFranc Core for Windows.

The options known to work for building USFranc Core on Windows are:

* On Linux, using the [Mingw-w64](https://mingw-w64.org/doku.php) cross compiler tool chain. Ubuntu 18.04+ is recommended
to build the USFranc Core Windows release binaries.
* On Windows, using [Windows
Subsystem for Linux (WSL)](https://docs.microsoft.com/windows/wsl/about) and the Mingw-w64 cross compiler tool chain.
* On Windows, using a native compiler tool chain such as [Visual Studio](https://www.visualstudio.com). See [README.md](/build_msvc/README.md).

Other options which may work, but which have not been extensively tested are (please contribute instructions):

* On Windows, using a POSIX compatibility layer application such as [cygwin](https://www.cygwin.com/) or [msys2](https://www.msys2.org/).

Installing Windows Subsystem for Linux
---------------------------------------

With Windows 10/11, Microsoft provides the [Windows
Subsystem for Linux (WSL)](https://docs.microsoft.com/windows/wsl/about). This
feature allows you to run a bash shell directly on Windows in an Ubuntu-based
environment. Within this environment you can cross compile for Windows without
the need for a separate Linux VM or server.

After the bash shell is active, you can follow the instructions below, starting
with the "Cross-compilation" section. Compiling the 64-bit version is
recommended.

Cross-compilation for Ubuntu and Windows Subsystem for Linux
------------------------------------------------------------

The steps below can be performed on Ubuntu (including in a VM) or WSL. The depends system
will also work on other Linux distributions, however the commands for
installing the toolchain will be different.

First, install the general dependencies:

    sudo apt update
    sudo apt upgrade
    sudo apt install build-essential libtool autotools-dev automake pkg-config bsdmainutils curl git

A host toolchain (`build-essential`) is necessary because some dependency
packages need to build host utilities that are used in the build process.

See [dependencies.md](dependencies.md) for a complete overview.

If you want to build the windows installer with `make deploy` you need [NSIS](https://nsis.sourceforge.io/Main_Page):

    sudo apt install nsis

Acquire the source in the usual way:

    git clone https://github.com/USFRANC-CORE/usfranc.git
    cd usfranc

## Building for 64-bit Windows

The first step is to install the mingw-w64 cross-compilation tool chain:

    sudo apt install g++-mingw-w64-x86-64

Set the default mingw32 g++ compiler option to posix:

    sudo update-alternatives --config x86_64-w64-mingw32-g++

Once the toolchain is installed the build steps are common:

Note that for WSL the USFranc Core source path MUST be somewhere in the default mount file system, for
example `/usr/src/usfranc`, AND not under `/mnt/d/`. If this is not the case the dependency autoconf scripts will fail.
This means you cannot use a directory that is located directly on the host Windows file system to perform the build.

Build using:

    PATH=$(echo "$PATH" | sed -e 's/:\/mnt.*//g') # strip out problematic Windows %PATH% imported var
    sudo bash -c "echo 0 > /proc/sys/fs/binfmt_misc/status" # Disable WSL support for Win32 applications.
    cd depends
    make HOST=x86_64-w64-mingw32
    cd ..
    ./autogen.sh
    CONFIG_SITE=$PWD/depends/x86_64-w64-mingw32/share/config.site ./configure --prefix=/
    make
    sudo bash -c "echo 1 > /proc/sys/fs/binfmt_misc/status" # Enable WSL support for Win32 applications.

## Depends system

For further documentation on the depends system see [README.md](../depends/README.md) in the depends directory.

Installation
-------------

After building using the Windows subsystem it can be useful to copy the compiled
executables to a directory on the Windows drive in the same directory structure
as they appear in the release `.zip` archive. This will install to `c:\workspace\usfranc`, for example:

    make install DESTDIR=/mnt/c/workspace/usfranc

You can also create an installer using:

    make deploy
