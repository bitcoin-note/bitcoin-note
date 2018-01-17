// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <vector>
#include <string>
#include <utility>

namespace CryptoNote {

class IWriteBatch {
public:
  virtual std::vector<std::pair<std::string, std::string>> extractRawDataToInsert() = 0;
  virtual std::vector<std::string> extractRawKeysToRemove() = 0;
};

} //namespace CryptoNote
