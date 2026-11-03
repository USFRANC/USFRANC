// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2025 The USFranc Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <chainparamsseeds.h>
#include <consensus/merkle.h>
#include <hash.h>
#include <tinyformat.h>
#include <util/system.h>
#include <util/strencodings.h>
#include <versionbitsinfo.h>

#include <assert.h>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) 
        << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "USFranc 2025 is born!";
    const CScript genesisOutputScript = CScript() 
        << ParseHex("04718e2f424a96064acfd4acde7181d3e3f790992ab4d334891444f68b34b6e918a0d5b92b65c473890fea0a7f7420a13300d412ba579bdb1c9395a984611e6cfd") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

/**
 * Main network
 */
class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = CBaseChainParams::MAIN;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 0; // zero mining rewards
        consensus.BIP16Height = 0;
        consensus.BIP34Height = 0;
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 0;
        consensus.BIP66Height = 0;
        consensus.CSVHeight = 0;
        consensus.SegwitHeight = 0;
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3.5 * 24 * 60 * 60;
        consensus.nPowTargetSpacing = 2.5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 6048;
        consensus.nMinerConfirmationWindow = 8064;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // Mainnet genesis block
        genesis = CreateGenesisBlock(1789461080, 2811064, 0x1e0ffff0, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0xd0305d20bf497f5d4943d54c6a711dfab305368be023454c23e52794a1fdaed4"));
        assert(genesis.hashMerkleRoot == uint256S("0x791624844c46b68572e0cd521f65e7518c10c2734647521a50c5e18dcf0c7c6b"));
       // printf("Genesis Hash: %s\n", genesis.GetHash().ToString().c_str());
	//printf("Merkle Root: %s\n", genesis.hashMerkleRoot.ToString().c_str());


        pchMessageStart[0] = 0xf5;
        pchMessageStart[1] = 0xc6;
        pchMessageStart[2] = 0xb8;
        pchMessageStart[3] = 0xd9;
        nDefaultPort = 19777;
        nPruneAfterHeight = 100000;

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,68);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,5);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,50);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,176);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};

        bech32_hrp = "usff";
        mweb_hrp = "usffmweb";

        vSeeds.emplace_back("dnsseed.bfinit.dev");
        vSeeds.emplace_back("dnsseed.wsxtra.com");
        vSeeds.emplace_back("dnsseed.bfinit.org");
        vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_main), std::end(chainparams_seed_main));

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        m_is_test_chain = false;
        m_is_mockable_chain = false;

        checkpointData = {
            {
                {0, consensus.hashGenesisBlock},
            }
        };

        chainTxData = ChainTxData{
            genesis.nTime,
            1,
            0
        };
    }
};

/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = CBaseChainParams::TESTNET;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 0;
        consensus.BIP16Height = 0;
        consensus.BIP34Height = 0;
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 0;
        consensus.BIP66Height = 0;
        consensus.CSVHeight = 0;
        consensus.SegwitHeight = 0;
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3.5 * 24 * 60 * 60;
        consensus.nPowTargetSpacing = 2.5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = false;

        // Testnet genesis
    genesis = CreateGenesisBlock(1789461080, 2811064, 0x1e0ffff0, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
    assert(consensus.hashGenesisBlock == uint256S("0xd0305d20bf497f5d4943d54c6a711dfab305368be023454c23e52794a1fdaed4"));
    assert(genesis.hashMerkleRoot == uint256S("0x791624844c46b68572e0cd521f65e7518c10c2734647521a50c5e18dcf0c7c6b"));

        pchMessageStart[0] = 0xf6;
        pchMessageStart[1] = 0xd4;
        pchMessageStart[2] = 0xc9;
        pchMessageStart[3] = 0xf2;
        nDefaultPort = 19778;
        nPruneAfterHeight = 1000;

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,58);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tusff";
        mweb_hrp = "tusffweb";

        vSeeds.clear();
        vFixedSeeds.clear();

        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        m_is_test_chain = true;
        m_is_mockable_chain = false;

        checkpointData = {
            {
                {0, consensus.hashGenesisBlock},
            }
        };

        chainTxData = ChainTxData{
            genesis.nTime,
            1,
            0
        };
    }
};

/**
 * RegTest Params
 */
class CRegTestParams : public CChainParams {
public:
    explicit CRegTestParams(const ArgsManager& args) {
        strNetworkID =  CBaseChainParams::REGTEST;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 0;
        consensus.BIP16Height = 0;
        consensus.BIP34Height = 0;
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 0;
        consensus.BIP66Height = 0;
        consensus.CSVHeight = 0;
        consensus.SegwitHeight = 0;
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3.5 * 24 * 60 * 60;
        consensus.nPowTargetSpacing = 2.5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 108;
        consensus.nMinerConfirmationWindow = 144;

        // Regtest genesis
        genesis = CreateGenesisBlock(1789461080, 0, 0x207fffff, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x67156f014a7dc0ac29e46529086a43fe506bba6d0ba2afaedea522abbfc9412d"));
        assert(genesis.hashMerkleRoot == uint256S("0x791624844c46b68572e0cd521f65e7518c10c2734647521a50c5e18dcf0c7c6b"));

        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nDefaultPort = 19779;
        nPruneAfterHeight = 1000;

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,58);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "rusff";
        mweb_hrp = "rusffweb";

        vSeeds.clear();
        vFixedSeeds.clear();

        fDefaultConsistencyChecks = true;
        fRequireStandard = true;
        m_is_test_chain = true;
        m_is_mockable_chain = true;

        checkpointData = {
            {
                {0, consensus.hashGenesisBlock},
            }
        };

        chainTxData = ChainTxData{
            genesis.nTime,
            1,
            0
        };

        UpdateActivationParametersFromArgs(args);
    }

    void UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout, int64_t nStartHeight, int64_t nTimeoutHeight)
    {
        consensus.vDeployments[d].nStartTime = nStartTime;
        consensus.vDeployments[d].nTimeout = nTimeout;
        consensus.vDeployments[d].nStartHeight = nStartHeight;
        consensus.vDeployments[d].nTimeoutHeight = nTimeoutHeight;
    }

    void UpdateActivationParametersFromArgs(const ArgsManager& args) {
        if (args.IsArgSet("-segwitheight")) {
            int64_t height = args.GetArg("-segwitheight", consensus.SegwitHeight);
            if (height < -1 || height >= std::numeric_limits<int>::max()) {
                throw std::runtime_error(strprintf("Activation height %ld for segwit is out of valid range. Use -1 to disable segwit.", height));
            } else if (height == -1) {
                LogPrintf("Segwit disabled for testing\n");
                height = std::numeric_limits<int>::max();
            }
            consensus.SegwitHeight = static_cast<int>(height);
        }

        if (!args.IsArgSet("-vbparams")) return;

        for (const std::string& strDeployment : args.GetArgs("-vbparams")) {
            std::vector<std::string> vDeploymentParams;
            boost::split(vDeploymentParams, strDeployment, boost::is_any_of(":"));
            if (vDeploymentParams.size() != 3) {
                throw std::runtime_error("Version bits parameters malformed, expecting deployment:start:end");
            }
            int64_t nStartTime = std::stoll(vDeploymentParams[1]);
            int64_t nTimeout = std::stoll(vDeploymentParams[2]);
            Consensus::DeploymentPos dep = Consensus::DEPLOYMENT_TESTDUMMY;
            UpdateVersionBitsParameters(dep, nStartTime, nTimeout, 0, 0);
        }
    }
};
//
// Global ChainParams
//
static std::unique_ptr<const CChainParams> globalChainParams;

const CChainParams &Params()
{
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<const CChainParams> CreateChainParams(const ArgsManager& args, const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN) {
        return std::make_unique<CMainParams>();
    } else if (chain == CBaseChainParams::TESTNET) {
        return std::make_unique<CTestNetParams>();
    } else if (chain == CBaseChainParams::SIGNET) {
        // SigNet temporarily uses testnet params — can be customized later
        return std::make_unique<CTestNetParams>();
    } else if (chain == CBaseChainParams::REGTEST) {
        return std::make_unique<CRegTestParams>(args);
    } else {
        throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
    }
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    globalChainParams = CreateChainParams(gArgs, network);
}
