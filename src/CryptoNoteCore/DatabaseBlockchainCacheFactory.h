// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "IBlockchainCacheFactory.h"
#include <Logging/LoggerMessage.h>

namespace CryptoNote {

class IDataBase;

class DatabaseBlockchainCacheFactory: public IBlockchainCacheFactory {
public:
  explicit DatabaseBlockchainCacheFactory(IDataBase& database, Logging::ILogger& logger);
  virtual ~DatabaseBlockchainCacheFactory();

  virtual std::unique_ptr<IBlockchainCache> createRootBlockchainCache(const Currency& currency) override;
  virtual std::unique_ptr<IBlockchainCache> createBlockchainCache(const Currency& currency, IBlockchainCache* parent, uint32_t startIndex = 0) override;

private:
  IDataBase& database;
  Logging::ILogger& logger;
};

} //namespace CryptoNote
