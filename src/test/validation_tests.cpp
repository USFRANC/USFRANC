// Copyright (c) 2014-2019 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <net.h>
#include <signet.h>
#include <validation.h>

#include <test/util/setup_common.h>

#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(validation_tests, TestingSetup)

BOOST_AUTO_TEST_CASE(block_subsidy_test)
{
    const auto chainParams = CreateChainParams(*m_node.args, CBaseChainParams::MAIN);
    const auto& consensusParams = chainParams->GetConsensus();

    BOOST_CHECK_EQUAL(GetBlockSubsidy(0, consensusParams), CAmount{0});
    BOOST_CHECK_EQUAL(GetBlockSubsidy(1, consensusParams), MAX_MONEY);
    BOOST_CHECK_EQUAL(GetBlockSubsidy(2, consensusParams), CAmount{0});
}

BOOST_AUTO_TEST_CASE(subsidy_limit_test)
{
    const auto chainParams = CreateChainParams(*m_node.args, CBaseChainParams::MAIN);
    CAmount nSum = 0;
    for (int nHeight = 0; nHeight < 1000; nHeight++) {
        CAmount nSubsidy = GetBlockSubsidy(nHeight, chainParams->GetConsensus());
        BOOST_CHECK(MoneyRange(nSubsidy));
        nSum += nSubsidy;
        BOOST_CHECK(MoneyRange(nSum));
    }
    BOOST_CHECK_EQUAL(nSum, MAX_MONEY);
}

BOOST_AUTO_TEST_SUITE_END()
