// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "txdb.h"
#include "main.h"
#include "uint256.h"


static const int nCheckpointSpan = 500;

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        ( 0,   uint256("0x00000f6770817176d109ab3e5db22682e4689ebcf4a3be989c9c8dff1d98c3f3") )
        ( 1,   uint256("0x00000f50743dfc2ce3213284fc1549a31b9359fa354ae87a9237d01e7fedb354") )
        ( 2,   uint256("0x000007d99e813a2d000a6466a597ed77670d13fb7d768fabad4af6b6328d329e") )
        ( 3,   uint256("0x00000358723feab5df6764cd0aa4595bb611061526d81a07a2715551f460222c") )
        ( 4,   uint256("0x00000a9f5ac56949f3ed4f2bf09767595c4237ada1ff0bc5d0000d02f6cbe622") )
        ( 5,   uint256("0x000001c7293ab22ac9cda78db86ea9ceab13aca0c3c8d256e0b2e2d19db72455") )
        ( 6,   uint256("0x000003706eebb9ac2334fe9271d4969e8ec88d28ac54a5414fa813199fa3dc16") )
        ( 7,   uint256("0x000009cd71dcace221c1668d1b25b1e81b381ba21f6de99dd28007aa40dda116") )
        ( 8,   uint256("0x00000aca29baf27e0b8c1eb0c081b669df4fba0f8bda1ff92d622cc12ce56459") )
        ( 9,   uint256("0x00000607da9f44a98d991b101f3fb256f4d0de72589f70f47b17ac97e0232ab2") )
        ( 10,   uint256("0x000007e121e6678d4eb43c167fe1ab222a55bddb439c91df915e339a1078d0d0") )
        ( 11,   uint256("0x0000093282628bb2e55d405e1bc70483b0a4b89bb162baef7ed941d607d259ad") )
        ( 12,   uint256("0x000000b081504389359bce599bc10fd0d705f2e70d53cae130f52be257c83890") )
        ( 13,   uint256("0x000002ac49a154e69d4b86a628921ca0fc4daaccbbef2037676e982200996d50") )
        ( 14,   uint256("0x00000a1c43021fdba4819121fb51d4615bd422de7490f1b7858a73be927d8a8d") )
        ( 15,   uint256("0x000002e897fee2b15cb84cc386380cd2e0cfe9783e7781b4bae181976f8a1530") )
        ( 16,   uint256("0x0000005d1670455e319ea2efc80bdb95c54564e1551b77c69450fd1a3337cbe4") )
        ( 17,   uint256("0x00000ff7357a4fdd2b8a294fff8107eace4df2eaf0350e36a7a69b34c1f17466") )
        ( 18,   uint256("0x00000a661136ed78004ccc6abba15ef086cce0807c9406a025498326cf3cf051") )
        ( 19,   uint256("0x000002f3a9da894d87603064a21e5a0d59d8837a71b4d5146d63236feae02bb5") )
        ( 20,   uint256("0x0000090e2f9b40aa0bb08463512260b339461b68ef0c9510be2242a9e3e6c2e6") )
    ;

    // TestNet has no checkpoints
    static MapCheckpoints mapCheckpointsTestnet;

    bool CheckHardened(int nHeight, const uint256& hash)
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        if (checkpoints.empty())
            return 0;
        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    // Automatically select a suitable sync-checkpoint
    const CBlockIndex* AutoSelectSyncCheckpoint()
    {
        const CBlockIndex *pindex = pindexBest;
        // Search backward for a block within max span and maturity window
        while (pindex->pprev && pindex->nHeight + nCheckpointSpan > pindexBest->nHeight)
            pindex = pindex->pprev;
        return pindex;
    }

    // Check against synchronized checkpoint
    bool CheckSync(int nHeight)
    {
        const CBlockIndex* pindexSync = AutoSelectSyncCheckpoint();

        if (nHeight <= pindexSync->nHeight)
            return false;
        return true;
    }
}
