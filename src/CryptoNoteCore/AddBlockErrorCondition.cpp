// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "AddBlockErrorCondition.h"

namespace CryptoNote {
namespace error {

AddBlockErrorConditionCategory AddBlockErrorConditionCategory::INSTANCE;


std::error_condition make_error_condition(AddBlockErrorCondition e) {
  return std::error_condition(
      static_cast<int>(e),
      AddBlockErrorConditionCategory::INSTANCE);
}

}
}
