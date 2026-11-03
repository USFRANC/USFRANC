# Multiprocess USFranc

On unix systems, the `--enable-multiprocess` build option can be passed to `./configure` to build new `usfranc-node`, `usfranc-wallet`, and `usfranc-gui` executables alongside existing `usfrancd` and `usfranc-qt` executables.

`usfranc-node` is a drop-in replacement for `usfrancd`, and `usfranc-gui` is a drop-in replacement for `usfranc-qt`, and there are no differences in use or external behavior between the new and old executables. Internally, `usfranc-gui` will spawn a `usfranc-node` process to run P2P and RPC code, communicating with it across a socket pair, and `usfranc-node` will spawn `usfranc-wallet` to run wallet code, also communicating over a socket pair. This lets node, wallet, and GUI code run in separate address spaces for better isolation, and allows starting and stopping components independently on different machines and environments.

## Debugging

The `-debug=ipc` command line option can be used to see requests and responses between processes.

## Installation

The multiprocess feature requires [Cap'n Proto](https://capnproto.org/) and [libmultiprocess](https://github.com/chaincodelabs/libmultiprocess) as dependencies. A simple way to get started using it without installing these dependencies manually is to use the [depends system](../depends) with the `MULTIPROCESS=1` [dependency option](../depends#dependency-options) passed to make:

```
cd <USFRANC_SOURCE_DIRECTORY>
make -C depends NO_QT=1 MULTIPROCESS=1
./configure --prefix=$PWD/depends/x86_64-pc-linux-gnu
make
src/usfranc-node -regtest -printtoconsole -debug=ipc
BITCOIND=usfranc-node test/functional/test_runner.py
```

The configure script will pick up settings and library locations from the depends directory, so there is no need to pass `--enable-multiprocess` as a separate flag when using the depends system (it's controlled by the `MULTIPROCESS=1` option).

Alternately, you can install [Cap'n Proto](https://capnproto.org/) and [libmultiprocess](https://github.com/chaincodelabs/libmultiprocess) packages on your system, and just run `./configure --enable-multiprocess` without using the depends system. The configure script will be able to locate the installed packages via [pkg-config](https://www.freedesktop.org/wiki/Software/pkg-config/). See [build-unix.md](build-unix.md) and [build-osx.md](build-osx.md) for information about installing dependencies in general.
