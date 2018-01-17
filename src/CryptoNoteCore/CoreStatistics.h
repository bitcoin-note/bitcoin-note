// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "Serialization/ISerializer.h"

namespace CryptoNote {

struct CoreStatistics {
  uint64_t transactionPoolSize;
  uint64_t blockchainHeight;
  uint64_t miningSpeed;
  uint64_t alternativeBlockCount;
  std::string topBlockHashString;

  void serialize(ISerializer& s) {    
    s(transactionPoolSize, "tx_pool_size");
    s(blockchainHeight, "blockchain_height");
    s(miningSpeed, "mining_speed");
    s(alternativeBlockCount, "alternative_blocks");
    s(topBlockHashString, "top_block_id_str");
  }
};

}
