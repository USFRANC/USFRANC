USFranc Core v0.1.0 Release Notes
=================================

USFranc Core (`USFrancCore`) version `0.1.0` (derived from `0.21.2.2` core architecture, protocol version `70017`) is the official reference implementation of the Universal Standard Franc (`USFF`) Layer-1 blockchain.

Official website: <https://usfranc.com/>

Please report bugs using the issue tracker at GitHub:

  <https://github.com/USFRANC-CORE/usfranc/issues>

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes in some cases), then run the
installer (on Windows) or copy over `/Applications/USFranc-Qt` (on macOS)
or `usfrancd`/`usfranc-qt` (on Linux).

Compatibility
==============

USFranc Core is supported and tested on operating systems
using the Linux kernel, macOS 10.14+, and Windows 10 and newer. USFranc
Core should also work on most other Unix-like systems.

v0.1.0 Network & Consensus Specifications
=========================================

- **Asset Name & Ticker:** Universal Standard Franc (`USFF`)
- **Consensus Algorithm:** Proof-of-Work Scrypt ($N=1024, r=1, p=1$)
- **Target Block Time:** 150 seconds (2.5 minutes)
- **Difficulty Adjustment:** Every 2,016 blocks (302,400 seconds / 3.5 days)
- **Maximum Supply (`MAX_MONEY`):** 90,000,000,000 USFF (100% issued at Block 1; 0 ongoing block subsidy from Block 2+)
- **Coinbase Maturity:** 100 blocks
- **Genesis Block Hash:** `0xd0305d20bf497f5d4943d54c6a711dfab305368be023454c23e52794a1fdaed4`
- **Genesis Merkle Root:** `0x791624844c46b68572e0cd521f65e7518c10c2734647521a50c5e18dcf0c7c6b`
- **Mainnet Ports:** P2P `19777` | RPC `9332` | Tor `9333`
- **Address Prefixes (Mainnet):** P2PKH `U` (`68`), P2SH `M` (`50`) / `3` (`5`), Bech32 `usff1q` (`usff`)
- **Softforks Active from Block 0:** BIP16, BIP34, BIP65, BIP66, CSV (BIP68/112/113), SegWit (BIP141/143/147)
