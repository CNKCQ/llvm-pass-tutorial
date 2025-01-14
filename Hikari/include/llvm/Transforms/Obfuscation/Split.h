//===- FlatteningIncludes.h - Flattening Obfuscation pass------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains includes and defines for the split basicblock pass
//
//===----------------------------------------------------------------------===//

#ifndef _SPLIT_INCLUDES_
#define _SPLIT_INCLUDES_


// LLVM include
#include "llvm/Pass.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Transforms/Utils/Local.h" // For DemoteRegToStack and DemotePHIToStack
#include "llvm/Transforms/IPO.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"
#include "Transforms/Obfuscation/Utils.h"
#include "Transforms/Obfuscation/CryptoUtils.h"

// Namespace
namespace llvm {
	FunctionPass *createSplitBasicBlockPass();
	FunctionPass *createSplitBasicBlockPass(bool flag);
	void initializeSplitBasicBlockPass(PassRegistry &Registry);
#if LLVM_VERSION_MAJOR >= 13
	class SplitBasicBlockPass : public PassInfoMixin<SplitBasicBlockPass>{ 
        public:
            PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
            static bool isRequired() { return true; }
    };
#endif
}
#endif
