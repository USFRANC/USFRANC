USFranc Core
=============

Setup
---------------------
USFranc Core (`USFrancCore`) is the reference USFranc client and builds the backbone of the network. It downloads and, by default, stores the entire history of USFranc transactions. Depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few minutes to several hours.

To download USFranc Core, visit [usfranc.com](https://usfranc.com/).

Running
---------------------
The following are some helpful notes on how to run USFranc Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/usfranc-qt` (GUI) or
- `bin/usfrancd` (headless)

### Windows

Unpack the files into a directory, and then run `usfranc-qt.exe`.

### macOS

Drag USFranc Core to your applications folder, and then run USFranc Core.

### Need Help?

* Visit [https://usfranc.com](https://usfranc.com/) for documentation, help, and network information.

Building
---------------------
The following are developer notes on how to build USFranc Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [FreeBSD Build Notes](build-freebsd.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [NetBSD Build Notes](build-netbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The USFranc repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Productivity Notes](productivity.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [JSON-RPC Interface](JSON-RPC-interface.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [usfranc.conf Configuration File](bitcoin-conf.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Memory](reduce-memory.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)
- [PSBT support](psbt.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
