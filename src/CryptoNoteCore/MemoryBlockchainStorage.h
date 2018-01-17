// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <CryptoNoteCore/BlockchainStorage.h>

namespace CryptoNote {

class MemoryBlockchainStorage : public BlockchainStorage::IBlockchainStorageInternal {
public:
  explicit MemoryBlockchainStorage(uint32_t reserveSize);
  virtual ~MemoryBlockchainStorage() override;

  virtual void pushBlock(RawBlock&& rawBlock) override;

  //Returns MemoryBlockchainStorage with elements from [splitIndex, blocks.size() - 1].
  //Original MemoryBlockchainStorage will contain elements from [0, splitIndex - 1].
  virtual std::unique_ptr<BlockchainStorage::IBlockchainStorageInternal> splitStorage(uint32_t splitIndex) override;

  virtual RawBlock getBlockByIndex(uint32_t index) const override;
  virtual uint32_t getBlockCount() const override;

private:
  std::vector<RawBlock> blocks;
};

}
