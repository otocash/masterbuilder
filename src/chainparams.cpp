// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xa4;
        pchMessageStart[1] = 0x87;
        pchMessageStart[2] = 0xf7;
        pchMessageStart[3] = 0x51;
        vAlertPubKey = ParseHex("04cdd273904fee60d22ac8b52ebbb77e82b9acb37a134c83531987f3f0ee4291d0047ae55edeb2609d57e0200aba8297bf343384db4ed2cbaff1668921109ed8e0");
        nDefaultPort = 7011;
        nRPCPort = 7012;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        const char* pszTimestamp = "01/03/2018 - A future Currency Is With OTOCASH Cryptocurrency";
        std::vector<CTxIn> vin;
        std::vector<CTxOut> vout;
        vin.resize(1);
        vout.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        vout[0].nValue = 0;
        vout[0].scriptPubKey = CScript() << ParseHex("04c629dd47950d15c4f63db4e67247335e09dec8b4ca4c157a23858e2503709e5fe3ba75d5b5263b046ae4b20af135a4dc79e66123ad9a15e65a98798bfee60724") << OP_CHECKSIG;
        CTransaction txNew(1, 1556955948, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1556955948;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 2892878;


        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000f6770817176d109ab3e5db22682e4689ebcf4a3be989c9c8dff1d98c3f3"));
        assert(genesis.hashMerkleRoot == uint256("0x39e5d5729452aecd74b4217dd692a029c2af8e604c83f99428edcf393f9db48c"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 65); // T
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 127); // t
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 45); // K
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

       vSeeds.push_back(CDNSSeedData("111.90.151.137", "111.90.151.137"));
       vSeeds.push_back(CDNSSeedData("128.199.225.197", "128.199.225.197"));
       vSeeds.push_back(CDNSSeedData("185.136.163.114", "185.136.163.114"));
       vSeeds.push_back(CDNSSeedData("161.129.65.4", "161.129.65.4"));
	    
        nLastPOWBlock = 20;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xb7;
        pchMessageStart[1] = 0x57;
        pchMessageStart[2] = 0x27;
        pchMessageStart[3] = 0xf9;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        vAlertPubKey = ParseHex("04c629dd47950d15c4f63db4e67247335e09dec8b4ca4c157a23858e2503709e5fe3ba75d5b5263b046ae4b20af135a4dc79e66123ad9a15e65a98798bfee60724");
        nDefaultPort = 17011;
        nRPCPort = 17012;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 2892878;



        //hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x00000f6770817176d109ab3e5db22682e4689ebcf4a3be989c9c8dff1d98c3f3"));

        vFixedSeeds.clear();
        vSeeds.clear();

        vSeeds.push_back(CDNSSeedData("185.136.169.110", "185.136.169.110"));
	    
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 63); // S
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 125); // s
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 58); // Q
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        nLastPOWBlock = 5;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;



static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);

if (fTestNet) {
              
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
