// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <CryptoNoteCore/BlockchainCache.h>
#include <map>

namespace CryptoNote {

struct KeyOutputInfo {
  Crypto::PublicKey publicKey;
  Crypto::Hash transactionHash;
  uint64_t unlockTime;
  uint16_t outputIndex;

  void serialize(CryptoNote::ISerializer& s);
};

// inherit here to avoid breaking IBlockchainCache interface
struct ExtendedTransactionInfo : CachedTransactionInfo {
  //CachedTransactionInfo tx;
  std::map<IBlockchainCache::Amount, std::vector<IBlockchainCache::GlobalOutputIndex>> amountToKeyIndexes; //global key output indexes spawned in this transaction
  void serialize(ISerializer& s);
};

}
