// Copyright 2013 the V8 project authors. All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//     * Neither the name of Google Inc. nor the names of its
//       contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef V8_HYDROGEN_CHECK_ELIMINATION_H_
#define V8_HYDROGEN_CHECK_ELIMINATION_H_

#include "hydrogen.h"
#include "hydrogen-alias-analysis.h"

namespace v8 {
namespace internal {


// Remove CheckMaps instructions through flow- and branch-sensitive analysis.
class HCheckEliminationPhase : public HPhase {
 public:
  explicit HCheckEliminationPhase(HGraph* graph)
      : HPhase("H_Check Elimination", graph), aliasing_() {
#ifdef DEBUG
    redundant_ = 0;
    removed_ = 0;
    removed_cho_ = 0;
    narrowed_ = 0;
    loads_ = 0;
    empty_ = 0;
    compares_true_ = 0;
    compares_false_ = 0;
    transitions_ = 0;
#endif
  }

  void Run();

  friend class HCheckTable;

 private:
  void PrintStats();

  HAliasAnalyzer* aliasing_;
#ifdef DEBUG
  int redundant_;
  int removed_;
  int removed_cho_;
  int narrowed_;
  int loads_;
  int empty_;
  int compares_true_;
  int compares_false_;
  int transitions_;
#endif
};


} }  // namespace v8::internal

#endif  // V8_HYDROGEN_CHECK_ELIMINATION_H_
