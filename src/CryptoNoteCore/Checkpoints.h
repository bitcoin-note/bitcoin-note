// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once
#include <map>
#include "CryptoNoteBasicImpl.h"
#include <Logging/LoggerRef.h>

namespace CryptoNote
{
  class Checkpoints
  {
  public:
    Checkpoints(Logging::ILogger& log);

    bool addCheckpoint(uint32_t index, const std::string& hash_str);
    bool isInCheckpointZone(uint32_t index) const;
    bool checkBlock(uint32_t index, const Crypto::Hash& h) const;
    bool checkBlock(uint32_t index, const Crypto::Hash& h, bool& isCheckpoint) const;
    bool isAlternativeBlockAllowed(uint32_t blockchainSize, uint32_t blockIndex) const;
    std::vector<uint32_t> getCheckpointHeights() const;

  private:
    std::map<uint32_t, Crypto::Hash> points;
    Logging::LoggerRef logger;
  };
}
