// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <vector>

#include "crypto/hash.h"

namespace CryptoNote {

typedef std::uint64_t Difficulty;
  bool check_hash(const Crypto::Hash &hash, Difficulty difficulty);
}
