// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <boost/optional.hpp>
#include <CryptoNote.h>

namespace CryptoNote {

class CachedTransaction {
public:
  explicit CachedTransaction(Transaction&& transaction);
  explicit CachedTransaction(const Transaction& transaction);
  explicit CachedTransaction(const BinaryArray& transactionBinaryArray);
  const Transaction& getTransaction() const;
  const Crypto::Hash& getTransactionHash() const;
  const Crypto::Hash& getTransactionPrefixHash() const;
  const BinaryArray& getTransactionBinaryArray() const;
  uint64_t getTransactionFee() const;

private:
  Transaction transaction;
  mutable boost::optional<BinaryArray> transactionBinaryArray;
  mutable boost::optional<Crypto::Hash> transactionHash;
  mutable boost::optional<Crypto::Hash> transactionPrefixHash;
  mutable boost::optional<uint64_t> transactionFee;
};

}
