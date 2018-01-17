// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once
#include <cstdint>
#include <CryptoNoteCore/Currency.h>

namespace CryptoNote {

class IUpgradeDetector {
public:
  enum : uint32_t {
    UNDEF_HEIGHT = static_cast<uint32_t>(-1)
  };

  virtual uint8_t targetVersion() const = 0;
  virtual uint32_t upgradeIndex() const = 0;
  virtual ~IUpgradeDetector() { }
};

std::unique_ptr<IUpgradeDetector> makeUpgradeDetector(uint8_t targetVersion, uint32_t upgradeIndex);

}
