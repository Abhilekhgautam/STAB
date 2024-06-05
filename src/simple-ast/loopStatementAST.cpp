//
// Created by abhilekh on 5/23/24.
//

#include "./ast.h"

namespace STAB{
    llvm::Value* STAB::LoopStatementAST::codegen(Scope* s){
        llvm::Function* F = s->getFnBlock();
	
        // block to insert the code for loop body
        llvm::BasicBlock* loopBody = llvm::BasicBlock::Create(*TheContext, "loopBody", F);
        // block to insert the code after the loop ends;
        llvm::BasicBlock* afterLoop = llvm::BasicBlock::Create(*TheContext, "afterLoop", F);

        // get into loop body
        Builder->CreateBr(loopBody);
        Builder->SetInsertPoint(loopBody);

        auto loopScope = new Scope(s);

	loopScope->setFnBlock(F);

        for (const auto elt: body){
            elt->codegen(loopScope);
        }

	auto dummyNum = new NumberExprAST(0);
	auto cond = dummyNum->codegen(loopScope);

	cond = Builder->CreateICmpEQ(cond, llvm::ConstantInt::get(*TheContext, llvm::APInt(32, 0, true)));

        // this is an infinte loop
        // again enter the loop body
        Builder->CreateCondBr(cond,loopBody, afterLoop);
        Builder->SetInsertPoint(afterLoop);

        return F;
    }
}

