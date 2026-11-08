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

USFranc Core is an independently developed blockchain project derived from the open-source Litecoin Core codebase and released under the terms of the MIT License, subject to the applicable licence conditions of the original source code.

The USFranc development team has extended, modified and further developed the original Litecoin architecture, introducing its own technical innovations, additional functionalities, security enhancements and custom blockchain infrastructure to establish the USFranc network.

Original USFranc Developments
-------
Among the principal technological developments introduced by the USFranc project are:

USFranc Limit Price Order Book (LPOB): 
-------
An original trading infrastructure developed specifically for the USFranc ecosystem, providing a direct order book mechanism for buyers and sellers.

Liquidity Pool Integration (LP): 
-------
A dedicated liquidity mechanism designed to operate alongside the LPOB, supporting market liquidity and facilitating transactions.

Blockchain Architecture: 
-------
Additional modifications and developments to the underlying Litecoin-derived blockchain infrastructure.

Security Infrastructure:
-------
 Integration of USFranc security developments, including Bitss Web Application Protection (WAP) and VWAR security technologies, where applicable.

USFranc Ecosystem Integration: 
-------
Custom infrastructure designed to support the USFranc blockchain, wallet services, trading mechanisms and future ecosystem developments.

Development and Jurisdiction
-------
USFranc is a European-based blockchain development project operating within a European and United Kingdom-oriented business and regulatory framework.
Its development, technical architecture, software enhancements and ecosystem are managed independently, with a dedicated development roadmap and long-term infrastructure objectives.

Open-Source Licensing
-------
The original Litecoin-derived components remain subject to their applicable open-source licensing conditions.
The MIT License permits the use, modification, distribution and commercial use of the licensed code, provided that the required copyright and licence notices are retained.
Original USFranc contributions are identified separately where applicable. Any components released under the MIT License remain subject to that licence. Components expressly designated as proprietary or separately licensed are governed by their respective intellectual property and licensing terms.
Nothing in this notice removes or restricts rights granted under the applicable open-source licences.

Licensing Information
-------
For further information regarding the licensing terms applicable to USFranc Core, please consult the COPYING file included in this repository.
The original MIT License is also available at:
https://opensource.org/licenses/MIT
Project: USFranc Core
Ticker: USFF
Original Blockchain Foundation: Litecoin Core
Original Trading Innovation: USFranc Limit Price Order Book (LPOB)
Development: USFranc Development Team

Development Process
-------------------

The `master` branch is regularly built (see `doc/build-*.md` for instructions) and tested, but it is not guaranteed to be
completely stable. [Tags](https://github.com/USFRANC-CORE/usfranc/tags) are created
regularly from release branches to indicate new official, stable release versions of USFranc Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md)
and useful hints for developers can be found in [doc/developer-notes.md](doc/developer-notes.md).



Documentation & Security
------------------------

* **White Paper:** [Universal_Standard_Franc_USFF_White_Paper_v1.1.md](Universal_Standard_Franc_USFF_White_Paper_v1.1.md)
* **Security Policy:** [SECURITY.md](SECURITY.md)
