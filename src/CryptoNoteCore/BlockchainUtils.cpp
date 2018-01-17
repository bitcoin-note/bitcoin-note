// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "BlockchainUtils.h"

namespace CryptoNote {
namespace Utils {

bool restoreCachedTransactions(const std::vector<BinaryArray>& binaryTransactions,
                               std::vector<CachedTransaction>& transactions) {
  transactions.reserve(binaryTransactions.size());

  for (auto binaryTransaction : binaryTransactions) {
    Transaction transaction;
    if (!fromBinaryArray(transaction, binaryTransaction)) {
      return false;
    }

    transactions.emplace_back(std::move(transaction));
  }

  return true;
}

}
}
