// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <array>
#include <memory>
#include <cstdint>

#include <boost/optional.hpp>

#include "INode.h"
#include "ITransaction.h"

namespace CryptoNote {

struct BlockchainInterval {
  uint32_t startHeight;
  std::vector<Crypto::Hash> blocks;
};

struct CompleteBlock {
  Crypto::Hash blockHash;
  boost::optional<CryptoNote::BlockTemplate> block;
  // first transaction is always coinbase
  std::list<std::shared_ptr<ITransactionReader>> transactions;
};

}
