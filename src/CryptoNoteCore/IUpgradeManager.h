// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>

namespace CryptoNote {

class IUpgradeManager {
public:
  virtual ~IUpgradeManager() {}

  virtual void addMajorBlockVersion(uint8_t targetVersion, uint32_t upgradeHeight) = 0;
  virtual uint8_t getBlockMajorVersion(uint32_t blockIndex) const = 0;
};

}
