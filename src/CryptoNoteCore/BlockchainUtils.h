// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <vector>

#include "CachedTransaction.h"
#include "CryptoNote.h"
#include "CryptoNoteTools.h"

namespace CryptoNote {
namespace Utils {

bool restoreCachedTransactions(const std::vector<BinaryArray>& binaryTransactions, std::vector<CachedTransaction>& transactions);

} //namespace Utils
} //namespace CryptoNote
