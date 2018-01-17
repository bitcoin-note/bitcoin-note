// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <boost/optional.hpp>
#include <CryptoNote.h>

namespace Crypto {

class cn_context;

}

namespace CryptoNote {

class CachedBlock {
public:
  explicit CachedBlock(const BlockTemplate& block);
  const BlockTemplate& getBlock() const;
  const Crypto::Hash& getTransactionTreeHash() const;
  const Crypto::Hash& getBlockHash() const;
  const Crypto::Hash& getBlockLongHash(Crypto::cn_context& cryptoContext) const;
  const Crypto::Hash& getAuxiliaryBlockHeaderHash() const;
  const BinaryArray& getBlockHashingBinaryArray() const;
  const BinaryArray& getParentBlockBinaryArray(bool headerOnly) const;
  const BinaryArray& getParentBlockHashingBinaryArray(bool headerOnly) const;
  uint32_t getBlockIndex() const;

private:
  const BlockTemplate& block;
  mutable boost::optional<BinaryArray> blockHashingBinaryArray;
  mutable boost::optional<BinaryArray> parentBlockBinaryArray;
  mutable boost::optional<BinaryArray> parentBlockHashingBinaryArray;
  mutable boost::optional<BinaryArray> parentBlockBinaryArrayHeaderOnly;
  mutable boost::optional<BinaryArray> parentBlockHashingBinaryArrayHeaderOnly;
  mutable boost::optional<uint32_t> blockIndex;
  mutable boost::optional<Crypto::Hash> transactionTreeHash;
  mutable boost::optional<Crypto::Hash> blockHash;
  mutable boost::optional<Crypto::Hash> blockLongHash;
  mutable boost::optional<Crypto::Hash> auxiliaryBlockHeaderHash;
};

}
