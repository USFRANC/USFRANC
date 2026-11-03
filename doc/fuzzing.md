# Fuzzing USFranc Core using libFuzzer

## Quickstart guide

To quickly get started fuzzing USFranc Core using [libFuzzer](https://llvm.org/docs/LibFuzzer.html):

```sh
$ git clone https://github.com/USFRANC-CORE/usfranc
$ cd usfranc/
$ ./autogen.sh
$ CC=clang CXX=clang++ ./configure --enable-fuzz --with-sanitizers=address,fuzzer,undefined
$ make
$ src/test/fuzz/process_message
# abort fuzzing using ctrl-c
```

## Fuzzing harnesses, fuzzing output and fuzzing corpora

`process_message` (`src/test/fuzz/process_message.cpp`) is a fuzzing harness for the `ProcessMessage(...)` function (`net_processing`). The available fuzzing harnesses are found in `src/test/fuzz/`.

The fuzzer will output `NEW` every time it has created a test input that covers new areas of the code under test. For more information on how to interpret the fuzzer output, see the [libFuzzer documentation](https://llvm.org/docs/LibFuzzer.html).

If you specify a corpus directory then any new coverage increasing inputs will be saved there:

```sh
$ mkdir -p process_message-seeded-from-thin-air/
$ src/test/fuzz/process_message process_message-seeded-from-thin-air/
```

## macOS hints for libFuzzer

The default Clang/LLVM version supplied by Apple on macOS does not include
fuzzing libraries, so macOS users will need to install a full version, for
example using `brew install llvm`.

Should you run into problems with the address sanitizer, it is possible you
may need to run `./configure` with `--disable-asm` to avoid errors
with certain assembly code from USFranc Core's code. See [developer notes on sanitizers](developer-notes.md#sanitizers)
for more information.

Full configure that was tested on macOS with `brew` installed `llvm`:

```sh
./configure --enable-fuzz --with-sanitizers=fuzzer,address,undefined CC=/usr/local/opt/llvm/bin/clang CXX=/usr/local/opt/llvm/bin/clang++ --disable-asm
```

# Fuzzing USFranc Core using american fuzzy lop (`afl-fuzz`)

## Quickstart guide

To quickly get started fuzzing USFranc Core using [`afl-fuzz`](https://github.com/google/afl):

```sh
$ git clone https://github.com/USFRANC-CORE/usfranc
$ cd usfranc/
$ git clone https://github.com/google/afl
$ make -C afl/
$ make -C afl/llvm_mode/
$ ./autogen.sh
$ CC=$(pwd)/afl/afl-clang-fast CXX=$(pwd)/afl/afl-clang-fast++ ./configure --enable-fuzz
$ make
$ mkdir -p inputs/ outputs/
$ echo A > inputs/thin-air-input
$ afl/afl-fuzz -i inputs/ -o outputs/ -- src/test/fuzz/bech32
```

# Fuzzing USFranc Core using Honggfuzz

## Quickstart guide

To quickly get started fuzzing USFranc Core using [Honggfuzz](https://github.com/google/honggfuzz):

```sh
$ git clone https://github.com/USFRANC-CORE/usfranc
$ cd usfranc/
$ ./autogen.sh
$ git clone https://github.com/google/honggfuzz
$ cd honggfuzz/
$ make
$ cd ..
$ CC=$(pwd)/honggfuzz/hfuzz_cc/hfuzz-clang CXX=$(pwd)/honggfuzz/hfuzz_cc/hfuzz-clang++ ./configure --enable-fuzz --with-sanitizers=address,undefined
$ make
$ mkdir -p inputs/
$ honggfuzz/honggfuzz -i inputs/ -- src/test/fuzz/process_message
```
