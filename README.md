USFranc Core integration/staging tree
=====================================

https://usfranc.com

What is USFranc?
----------------

USFranc (Universal Standard Franc, ticker: `USFF`) is a decentralized Layer-1 digital currency that enables fast, secure peer-to-peer payments to anyone, anywhere in the world. USFranc uses peer-to-peer UTXO technology and Scrypt Proof-of-Work consensus to operate with no central authority: managing transactions and validating blocks are carried out collectively by the network. USFranc Core (`USFrancCore`) is the name of the open source reference software which enables the use of this currency.

### Core Specifications

* **Ticker Symbol:** `USFF`
* **Consensus Algorithm:** Proof-of-Work (Scrypt: $N=1024, r=1, p=1$)
* **Target Block Time:** 150 seconds (2.5 minutes)
* **Difficulty Retargeting:** Every 2,016 blocks (302,400 seconds / 3.5 days)
* **Maximum Supply:** 90,000,000,000 USFF (100% issued at Block 1; 0 ongoing block subsidy)
* **Decimal Precision:** 8 decimal places (`1 USFF = 100,000,000` base units)
* **Default Ports (Mainnet):** P2P `19777` | RPC `9332` | Tor `9333`
* **Address Formats (Mainnet):**
  * Legacy P2PKH: starts with `U` (prefix `68`)
  * SegWit P2SH: starts with `M` (prefix `50`) / Legacy P2SH `3` (prefix `5`)
  * Native SegWit Bech32: starts with `usff1q` (HRP `usff`)

For more information, as well as binary builds of the USFranc Core software, see [https://usfranc.com](https://usfranc.com).

License
-------

USFranc Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built (see `doc/build-*.md` for instructions) and tested, but it is not guaranteed to be
completely stable. [Tags](https://github.com/USFRANC-CORE/usfranc/tags) are created
regularly from release branches to indicate new official, stable release versions of USFranc Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md)
and useful hints for developers can be found in [doc/developer-notes.md](doc/developer-notes.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Documentation & Security
------------------------

* **White Paper:** [Universal_Standard_Franc_USFF_White_Paper_v1.1.md](Universal_Standard_Franc_USFF_White_Paper_v1.1.md)
* **Security Policy:** [SECURITY.md](SECURITY.md)
