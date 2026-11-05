<div align="center">

# USFF LPOB™
### LIQUIDITY POOL & ORDER BOOK PROTOCOL
**A multi-chain attachable trading protocol with proportional liquidity access**

---

![USFF LPOB Protocol Banner](doc/images/lpob_banner.png)

</div>

<br>

<div align="center">

| 🟢 **50%** | 🟡 **25%** | 🔵 **25%** |
| :---: | :---: | :---: |
| **Recommended initial LP allocation** | **Minimum initial LP allocation** | **Applicable fees credited to LP** |

</div>

---

## 📋 Executive Summary

**USFF LPOB™** is an integrated trading and liquidity protocol. It combines an **order book** for direct buyer–seller matching, a **liquidity pool** for reserve-based trades, and a **Smart Router** that compares available execution routes. 

Its defining liquidity rule is proportional: a holder’s percentage of the total minted supply determines the corresponding percentage of the relevant LP reserve that the holder may access when selling back to that pool, subject to the protocol’s execution and reserve rules.

> [!IMPORTANT]
> **CORE PRINCIPLE:** If a holder owns **1%** of the total minted supply, the holder’s proportional LP entitlement for a sale is calculated as **1%** of the relevant LP reserve — *not as an arbitrary fixed token amount*.

The protocol can attach to compatible coins and tokens on external blockchains. A token created natively on the USFF blockchain must be connected to LPOB as part of its token-market infrastructure.

---

## 🎯 What LPOB is Designed to Do

LPOB is not merely an order book and it is not merely a liquidity pool. It is the protocol layer that coordinates both mechanisms and the rules that connect them. It aims to provide a consistent framework for listing, trading, liquidity access, fee routing, reserve controls, and market creation.

* **Order Book:** Lets buyers and sellers publish bids and asks and match directly.
* **Liquidity Pool:** Provides an alternative route to buy or sell against available reserves.
* **Smart Router:** Compares order-book and LP execution terms for the requested amount.
* **Proportional Liquidity:** Calculates the holder’s share of LP reserves from their ownership percentage of total minted supply.
* **Attachable Architecture:** Can integrate compatible external assets and is mandatory for native USFF-chain tokens.
* **Pool Factory:** Can support the creation of separate markets and pools by approved third parties.

---

## 🏗️ System Architecture

```
+----------------------------------------------------------------------------------------------------+
|                               USERS • HOLDERS • BUYERS • SELLERS                                   |
+----------------------------------------------------------------------------------------------------+
                                                  │
                                                  ▼
+----------------------------------------------------------------------------------------------------+
|                                    USFF LPOB™ PROTOCOL LAYER                                       |
+--------------------------+-----------------------+------------------------+------------------------+
|        ORDER BOOK        |     SMART ROUTER      |     LIQUIDITY POOL     |  TOKEN / CHAIN ADAPTER |
+--------------------------+-----------------------+------------------------+------------------------+
| Bids / asks matching     | Route comparison      | Reserves               | External chains        |
| Waiting orders           | Net price execution   | LP buys / sells        | Native USFF chain      |
| Priority rules           | User choice           | Proportional rule      | Asset connection       |
+--------------------------+-----------------------+------------------------+------------------------+
                                                  │
                                                  ▼
+----------------------------------------------------------------------------------------------------+
|        SETTLEMENT • FEE ROUTING • PROPORTIONAL LIMITS • RESERVE ACCOUNTING • TRANSPARENCY          |
+----------------------------------------------------------------------------------------------------+
```

> [!NOTE]
> The exact adapter, bridge, custody, or smart-contract method depends on the external chain. An external asset is not automatically compatible merely because it is a coin or token; its integration must be technically supported and security-reviewed.

---

## ⏱️ Two Operating Phases

### Phase 1 — Initial Mint and First-Sale Distribution
During initial distribution, qualifying first-sale proceeds are allocated according to the launch policy:
* **Recommended initial allocation to the LP:** **50%**
* **Minimum initial allocation to the LP:** **25%**

The protocol must identify the proceeds base, accepted reserve asset, timing, and custody path in its launch rules. The order book may also be active during this period.

### Phase 2 — Ongoing Secondary-Market Operation
When the initial mint / first-sale distribution has been completed, LPOB becomes the ongoing protocol governing secondary trading:
* The order book remains active as the offer and matching layer.
* The LP remains available as an alternative reserve-based route.
* LPOB coordinates both; it does not force every seller to transact through the LP.

```
┌────────────────────────────────────────────────────────────────────────┐
│ PHASE 1 — INITIAL DISTRIBUTION                                         │
│ Qualifying first-sale proceeds ➔ Launch allocation ➔ Initial LP pool   │
│ (50% recommended / 25% minimum)                                        │
└───────────────────────────────────┬────────────────────────────────────┘
                                    │
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ INITIAL LP FUNDING ESTABLISHED                                         │
└───────────────────────────────────┬────────────────────────────────────┘
                                    │
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ PHASE 2 — SECONDARY MARKET                                             │
│ LPOB manages the market: order-book offers and matches continue;       │
│ LP quotes and proportional LP execution remain available.              │
└───────────────────────────────────┬────────────────────────────────────┘
                                    │
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ ORDER BOOK + LP OPERATE TOGETHER UNDER LPOB                            │
└────────────────────────────────────────────────────────────────────────┘
```

> **Definition:** *"LPOB takes over"* means the protocol becomes the operating framework for all ongoing secondary trading. It does not switch off the order book or make the LP the compulsory counterparty.

---

## 🧮 The Proportional Liquidity Rule — Core Mechanism

The holder’s percentage is calculated against the **total minted supply** of the relevant coin or token. When the holder chooses to sell back to that token’s LP, LPOB uses that ownership percentage to calculate the corresponding proportional amount of the relevant LP reserve.

### Mathematical Formulation

$$\text{Holder Ownership Percentage} = \frac{\text{Holder's Eligible Token Balance}}{\text{Total Minted Supply}}$$

$$\text{Proportional LP Amount} = \text{Holder Ownership Percentage} \times \text{Relevant LP Reserve}$$

*The **relevant reserve** means the quote-asset side of the pool that would be paid to the seller. If the pool contains multiple assets or pairs, the applicable pool and reserve must be identified before calculating the quote.*

### Worked Example

| Parameter | Value |
| :--- | :--- |
| **Total Minted Supply** | `1,000,000,000 tokens` |
| **Holder's Token Balance** | `10,000,000 tokens` |
| **Holder's Share of Total Minted Supply** | **1%** |
| **LP Quote-Asset Reserve** | **€1,000,000** |
| **Proportional LP Amount** | **1% × €1,000,000 = €10,000** |

> In this example, the holder’s $10\text{M}$ tokens represent $1\%$ of the $1\text{B}$ total minted tokens. The holder’s proportional LP amount is therefore $1\%$ of the $€1\text{M}$ quote-asset reserve, or **$€10,000$**, before any applicable fees and execution adjustments.

---

## 🔄 How Proportional Access Works in Practice

The proportional calculation is the protocol’s allocation rule for determining the holder’s share of the relevant LP reserve. It is **not** a statement that the pool must hold enough funds to pay every holder simultaneously. Actual execution must account for available reserves, competing transactions, applicable fees, slippage, and protocol limits.

```
[1. Holder Connects Wallet]
             │
             ▼
[2. LPOB Reads Eligible Token Balance & Total Minted Supply]
             │
             ▼
[3. LPOB Calculates Ownership Percentage]
             │
             ▼
[4. LPOB Identifies the Relevant LP & Quote-Asset Reserve]
             │
             ▼
[5. Proportional Amount is Calculated]
             │
             ▼
[6. Executable Quote is Adjusted for Reserves, Fees, Slippage & Limits]
             │
             ▼
[7. Holder Accepts, Rejects, Waits, or Retains Tokens]
```

### Key Design Distinctions

#### 1. Proportional Entitlement vs. Executable Settlement
The ownership percentage determines the proportional LP amount under the model. The executable amount is then checked against the actual available reserve and the pool’s execution rules. If the LP cannot satisfy the calculated amount:
* The protocol must clearly show the executable portion.
* Indicate whether partial execution is supported.
* State what happens to the unfilled balance.
* **The protocol must not present an unavailable amount as guaranteed cash.**

#### 2. Explicit Supply Definitions
The current rule described here uses **total minted supply** as the denominator. Before implementation, the specification must state how burns, locked tokens, treasury holdings, team holdings, vesting balances, and tokens held by the LP itself are treated.
* Unless the rule is deliberately modified, the formula remains based on total minted supply, not circulating supply.
* If tokens are burned, the system must define whether the original minted-supply denominator remains fixed or is adjusted by an explicit protocol rule.
* The numerator must be defined as the holder’s eligible wallet balance at quote time or snapshot execution, preventing double counting in escrows or locked contracts.

---

## 🔀 Seller Route Decision: Order Book vs. LP

A holder seeking to sell can compare the order-book route with the proportional LP route. The seller retains complete control over execution.

```
                    ┌────────────────────────────┐
                    │ SELLER SELECTS TOKEN AMOUNT│
                    └─────────────┬──────────────┘
                                  │
                                  ▼
        ┌──────────────────────────────────────────────────┐
        │ LPOB CHECKS BUYER OFFERS & PROPORTIONAL LP QUOTE │
        └──────────────┬───────────────────┬───────────────┘
                       │                   │
           ┌───────────┴───────┐   ┌───────┴───────────┐
           │  ORDER BOOK ROUTE │   │  PROPORTIONAL LP  │
           │ • Buyer match ask │   │ • Ownership % × LP│
           │ • Direct settle   │   │ • Execution check │
           │ • Wait if needed  │   │ • Accept / reject │
           └───────────┬───────┘   └───────┬───────────┘
                       │                   │
                       └───────────┬───────┘
                                   │
                                   ▼
                   ┌───────────────────────────────┐
                   │        SELLER DECIDES         │
                   │ [Accept Match] [Accept LP]    │
                   │ [Wait / Amend / Cancel]       │
                   └───────────────────────────────┘
```

---

## 📖 Order-Book Mechanics & Principal Settlement

The order book is the direct matching component. A seller places an ask and a buyer places a bid or accepts an ask. Once compatible orders match and settlement succeeds, the buyer receives the tokens and the seller receives the payment asset.

| Role / Step | Flow & Responsibility | Destination / Effect |
| :--- | :--- | :--- |
| **Seller** | Offers USFF; sets ask price and quantity | Payment asset goes to seller |
| **Order Book / Engine** | Displays order book; matches compatible orders under priority rules | **Matched Settlement** |
| **Buyer** | Places bid or accepts ask; provides payment asset | USFF tokens go to buyer |

> [!NOTE]
> **LP principal reserves are not used for matched order-book principal transfers.** Eligible transaction fees may still be charged, and the designated LP fee share ($25\%$) is credited once.

### Core Order-Book Features
* **Bids and Asks:** Dual quote displays with exact price and quantity.
* **Priority Matching:** Algorithmic matching of compatible orders under published rules.
* **Waiting Orders:** Supported order queues when no buyer is available at the target ask.
* **Order Lifecycle:** Flexible amendments and cancellations based on state.
* **Partial Fills:** Scalable partial execution supported by the matching engine.
* **Direct Settlement:** Direct peer-to-peer asset transfers preserving LP reserves.

---

## 💧 Liquidity-Pool Mechanics & Reserve Movements

The LP provides a separate route in which the pool itself acts as the direct counterparty. Its quote depends on the pool’s current reserve balances and configured pricing curve.

```
┌─────────────────────────────────┐        ┌─────────────────────────────────┐
│     USER BUYS FROM LP           │        │      USER SELLS TO LP           │
├─────────────────────────────────┤        ├─────────────────────────────────┤
│ • Payment asset enters LP       │        │ • Tokens enter LP               │
│ • Tokens leave LP               │        │ • Payment asset leaves LP       │
│ • Quote reserve INCREASES (▲)   │        │ • Token reserve INCREASES (▲)   │
│ • Token reserve DECREASES (▼)   │        │ • Quote reserve DECREASES (▼)   │
└────────────────┬────────────────┘        └────────────────┬────────────────┘
                 │                                          │
                 └───────────────────┬──────────────────────┘
                                     ▼
                  ┌─────────────────────────────────────┐
                  │ POOL RESERVES & PRICE STATE UPDATED │
                  └─────────────────────────────────────┘
```

### LP Route Controls & Safeguards
1. **Live Quote Calculation:** Derived dynamically from current pool reserves and configured pricing curves.
2. **Dual Display:** Clearly demarcates proportional mathematical claims from executable quotes.
3. **Pre-trade Visibility:** Full breakdown of fees, price impact, slippage, and reserve constraints prior to signing.
4. **Revalidation at Execution:** Guards against stale-quote settlement through state re-checks.
5. **Non-Custodial Choice:** Allows instant rejection, reverting back to order-book queuing or asset retention.

---

## 🧠 Smart Router: Comparison & Execution Choice

The Smart Router is the LPOB comparison engine. It reads available order-book depth alongside the LP's proportional quote for the desired token quantity, evaluating **net proceeds** rather than gross headline rates.

```
             ┌────────────────────────────────────────┐
             │ INPUT: SELL / BUY INTENT + TOKEN AMT   │
             └───────────────────┬────────────────────┘
                                 │
         ┌───────────────────────┴───────────────────────┐
         ▼                                               ▼
┌───────────────────────────────┐               ┌───────────────────────────────┐
│     ORDER-BOOK METRICS        │               │   LP / PROPORTIONAL METRICS   │
│ • Best available bid / ask    │               │ • Holder ownership percentage │
│ • Matched fill quantity       │               │ • Relevant LP reserve pool    │
│ • Queue / waiting order status│               │ • Theoretical proportional val│
│ • Applicable net routing fees │               │ • Executable reserve/slippage │
└──────────────┬────────────────┘               └───────────────┬───────────────┘
               │                                                │
               └───────────────────────┬────────────────────────┘
                                       │
                                       ▼
             ┌────────────────────────────────────────┐
             │ SMART ROUTER NORMALISES THE OPTIONS    │
             │ Compares net proceeds, fees, slippage, │
             │ executable quantity, & conditions.     │
             └───────────────────┬────────────────────┘
                                 │
                                 ▼
             ┌────────────────────────────────────────┐
             │ USER SELECTS FINAL CONFIRMED ROUTE     │
             └────────────────────────────────────────┘
```

### Strategic Benefits of the Smart Router
* **Identifies Direct Superiority:** Instantly highlights when a peer buyer offers better net proceeds than the LP quote.
* **Alternative Liquidity Provision:** Unlocks execution via the LP when order-book buy interest is absent.
* **Holistic Net Settlement:** Factors in execution fees, network gas, and price impact.
* **Volume Distribution Awareness:** Detects when favorable rates apply only to partial fills.
* **Sovereign Execution:** Guarantees that final transaction routing strictly obeys user confirmation.

---

## 💰 Initial LP Funding & Ongoing Fee Contributions

LPOB integrates dual, decoupled liquidity-support pillars:

```
┌───────────────────────────────────────────┐
│ INITIAL QUALIFYING FIRST-SALE PROCEEDS    │
│ 50% Recommended • 25% Minimum             │
└─────────────────────┬─────────────────────┘
                      │
                      ▼
┌───────────────────────────────────────────┐
│ INITIAL LIQUIDITY RESERVES                │
└─────────────────────▲─────────────────────┘
                      │
┌─────────────────────┴─────────────────────┐
│ ONGOING ELIGIBLE TRANSACTION FEES         │
│ 25% of Applicable Fees Credited to LP     │
└───────────────────────────────────────────┘
```

> [!WARNING]
> The **25% fee allocation** represents **25% of the transaction fee charged**, *not 25% of the transaction principal*. The protocol prevents double-crediting. Direct order-book matches do not alter LP principal reserves, though their fee cut strengthens the LP.

---

## 📊 Proportional Access Multi-Tier Matrix

*Assumed Denominator: $1,000,000,000\text{ USFF}$ total minted supply with an active LP Quote Reserve of $€1,000,000$.*

| Holder Supply Share (%) | Token Balance | Applicable Quote Reserve | Calculated Proportional Share (€) |
| :---: | :---: | :---: | :---: |
| **0.10%** | $1,000,000$ | $€1,000,000$ | **€1,000** |
| **1.00%** | $10,000,000$ | $€1,000,000$ | **€10,000** |
| **2.50%** | $25,000,000$ | $€1,000,000$ | **€25,000** |
| **5.00%** | $50,000,000$ | $€1,000,000$ | **€50,000** |

*Note: This matrix illustrates theoretical arithmetic. Simultaneous full liquidations are subject to execution queues, dynamic pool rebalancing, and reserve limits.*

---

## 🌐 Multi-Chain Attachment & Native USFF Requirement

```
                    ┌────────────────────────────┐
                    │    LPOB™ CORE PROTOCOL     │
                    └─────────────┬──────────────┘
                                  │
         ┌────────────────────────┴────────────────────────┐
         ▼                                                 ▼
┌─────────────────────────────────┐       ┌─────────────────────────────────┐
│    EXTERNAL ASSET INTEGRATION   │       │    NATIVE USFF-CHAIN ASSET      │
├─────────────────────────────────┤       ├─────────────────────────────────┤
│ • Compatible external assets    │       │ • Native USFF mint standard     │
│ • Integration adapter / bridge  │       │ • Mandatory LPOB attachment     │
│ • Independent security audit    │       │ • Order book + LP provision     │
│ • Retains native origin chain   │       │ • Native protocol enforcement   │
└─────────────────────────────────┘       └─────────────────────────────────┘
```

### External Chains
Compatible external tokens integrate via verified cross-chain adapters, bridges, or smart-contract custody. External connectivity does not imply native migration to the USFF blockchain.

### Native USFF Chains
Any token created natively on the USFF blockchain **must attach to LPOB** by design. Mint allocations, quote reserves, and proportional denominators are read directly on-chain.

---

## 🏭 Pool Factory & Independent Markets

The **Pool Factory** enables approved ecosystem participants to deploy autonomous token markets leveraging standardized LPOB architecture.

```
                    ┌────────────────────────────┐
                    │       USFF LPOB CORE       │
                    └─────────────┬──────────────┘
                                  │
                                  ▼
                    ┌────────────────────────────┐
                    │        POOL FACTORY        │
                    └─────────────┬──────────────┘
                                  │
         ┌────────────────────────┼────────────────────────┐
         ▼                        ▼                        ▼
┌─────────────────┐      ┌─────────────────┐      ┌─────────────────┐
│    MARKET A     │      │    MARKET B     │      │    MARKET C     │
│ • Custom Pair   │      │ • Custom Pair   │      │ • Custom Pair   │
│ • Own Reserves  │      │ • Own Reserves  │      │ • Own Reserves  │
│ • Local Params  │      │ • Local Params  │      │ • Local Params  │
└─────────────────┘      └─────────────────┘      └─────────────────┘
```

* **Independent Reserves:** Pools operate with segregated reserves without automatic liquidity bleed.
* **Shared Architecture:** Standardizes security, routing, and order-book logic across all child markets.

---

## 🚀 Key Strategic Advantages

| Advantage | Why It Matters |
| :--- | :--- |
| **Proportional Liquidity Access** | Total minted supply maps directly to an equitable share of active LP reserves. |
| **Dynamic Execution Choice** | Holders choose between matched buyers, instant LP routes, or pending orders. |
| **Multi-Source Execution** | Eliminates single-point dependency on market makers or AMMs. |
| **Smart Price Comparison** | Protects traders from hidden slippage, thin books, and unexpected fee impacts. |
| **Capital Preservation** | Order-book matches bypass LP principal, preserving liquidity pool depth. |
| **Defined Initial Funding** | Establishes a predictable, enforceable liquidity foundation from launch. |
| **Sustainable Fee Recycling** | Continuous $25\%$ transaction fee routing fuels long-term reserve depth. |
| **Runaway Protection** | Reserve-use controls prevent catastrophic pool drains from whale exits. |
| **Cross-Chain Compatibility** | Connects external ecosystems to LPOB liquidity mechanics. |
| **Universal Native Standard** | Standardizes all native USFF tokens under uniform liquidity rules. |
| **Ecosystem Scalability** | Factory contracts allow permissioned expansion of independent markets. |
| **On-Chain Auditability** | Explicit separation of matched trades, LP reserves, and fee distributions. |

---

## 📑 Transaction & Reserve Accounting Matrix

| Transaction Type | Principal Flow | LP Reserve Impact | Fee Routing Treatment |
| :--- | :--- | :--- | :--- |
| **Order-Book Match** | Buyer pays Seller; Seller releases tokens | **Zero direct change** | $25\%$ of fee routed to LP |
| **Buy from LP** | Quote asset enters LP; Tokens exit LP | Quote $\uparrow$ \| Token $\downarrow$ | Eligible fee share credited once |
| **Sell to LP** | Tokens enter LP; Quote asset exits LP | Token $\uparrow$ \| Quote $\downarrow$ | Eligible fee share credited once |
| **Initial First Sale** | Buyer pays under launch terms | **Initial LP funded** | Segregated from trading fee pool |

---

## ⚠️ Safeguards, Risks & Implementation Decisions

### Critical Implementation Specifications
1. **Supply Denominator Audit:** Formally codify treatment of burned tokens, unvested team cliffs, and LP-held token balances.
2. **Cap & Execution Guardrails:** Establish maximum allowable slippage and per-block withdrawal caps.
3. **Partial-Fill Fallbacks:** Define smart-contract behaviors when proportional calculations exceed instant executable depth.
4. **Adapter Security:** Perform complete formal verification of cross-chain bridges and adapters.
5. **Circuit Breakers:** Implement multi-sig governance pause and emergency halt capabilities for reserve protection.

### Accurate Representation & Disclaimers
* **Not a Guarantee:** The proportional formula calculates fair entitlement; it is not an absolute liquidity guarantee during mass bank-run conditions.
* **Variable Pricing:** The LP does not act as a price peg or offer a fixed redemption floor. Quotes fluctuate dynamically with pool depth.
* **Unmatched Asks:** An order-book ask constitutes an intent to sell, not completed execution, until settled with a matching bid.

---

## 🌐 Summary Overview

> **USFF LPOB™ — Proportional Liquidity. Two Trading Routes. One Integrated Protocol.**
>
> USFF LPOB is an integrated trading and liquidity protocol that combines direct order-book matching with a reserve-based liquidity pool. Its proportional liquidity mechanism calculates a holder’s share of the relevant LP reserve according to the holder’s percentage of the token’s total minted supply. The Smart Router compares available buyer offers with the LP quote, taking account of net proceeds, fees, slippage, and executable quantity.
>
> Designed for multi-chain asset attachment and required for native USFF tokens, LPOB provides scalable, transparent market infrastructure via its modular Pool Factory.

---

<div align="center">
<sub>USFF LPOB™ Protocol Specification • Working Document • Subject to Final Smart Contract Audits & Governance Rules</sub>
</div>
