// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "UpgradeManager.h"

#include "CryptoNoteConfig.h"

namespace CryptoNote {

UpgradeManager::UpgradeManager() {
}

UpgradeManager::~UpgradeManager() {
}

void UpgradeManager::addMajorBlockVersion(uint8_t targetVersion, uint32_t upgradeHeight) {
  assert(m_upgradeDetectors.empty() || m_upgradeDetectors.back()->targetVersion() < targetVersion);
  m_upgradeDetectors.emplace_back(makeUpgradeDetector(targetVersion, upgradeHeight));
}

uint8_t UpgradeManager::getBlockMajorVersion(uint32_t blockIndex) const {
  for (auto it = m_upgradeDetectors.rbegin(); it != m_upgradeDetectors.rend(); ++it) {
    if (it->get()->upgradeIndex() < blockIndex) {
      return it->get()->targetVersion();
    }
  }

  return BLOCK_MAJOR_VERSION_1;
}

}
