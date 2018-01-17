// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <CryptoNoteCore/IMainChainStorage.h>
#include <CryptoNoteCore/Currency.h>

#include <vector>

namespace CryptoNote {

class VectorMainChainStorage: public IMainChainStorage {
public:
  virtual void pushBlock(const RawBlock& rawBlock) override;
  virtual void popBlock() override;
  virtual RawBlock getBlockByIndex(uint32_t index) const override;
  virtual uint32_t getBlockCount() const override;
  virtual void clear() override;

private:
  std::vector<RawBlock> storage;
};

std::unique_ptr<IMainChainStorage> createVectorMainChainStorage(const Currency& currency);

}
