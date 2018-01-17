// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once
#include <set>
#include <unordered_set>
#include "CachedTransaction.h"
#include <CryptoNote.h>
#include <crypto/crypto.h>

namespace CryptoNote {

struct TransactionValidatorState {
  std::unordered_set<Crypto::KeyImage> spentKeyImages;
};

void mergeStates(TransactionValidatorState& destionation, const TransactionValidatorState& source);
bool hasIntersections(const TransactionValidatorState& destionation, const TransactionValidatorState& source);
void excludeFromState(TransactionValidatorState& state, const CachedTransaction& transaction);

}
