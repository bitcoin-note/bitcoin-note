// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "IBlockchainCacheFactory.h"

#include "BlockchainCache.h"

namespace CryptoNote {

class MemoryBlockchainCacheFactory: public IBlockchainCacheFactory {
public:
  MemoryBlockchainCacheFactory(const std::string& filename, Logging::ILogger& logger);
  virtual ~MemoryBlockchainCacheFactory() override;

  std::unique_ptr<IBlockchainCache> createRootBlockchainCache(const Currency& currency) override;
  std::unique_ptr<IBlockchainCache> createBlockchainCache(const Currency& currency, IBlockchainCache* parent, uint32_t startIndex = 0) override;

private:
  std::string filename;
  Logging::ILogger& logger;
};

} //namespace CryptoNote
