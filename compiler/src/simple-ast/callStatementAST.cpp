//
// Created by abhilekh on 5/26/24.
//

#include "./ast.h"
#include <regex>

std::string replaceBracesWithPercentD(const std::string& input) {
    std::regex braces("\\{\\}");
    return std::regex_replace(input, braces, "%d");
}

namespace STAB{
    llvm::Value* STAB::CallStatementAST::codegen(Scope* s){
        llvm::Function* calleeFn = TheModule->getFunction(Callee);
        if (Callee == "println"){
	     auto printlnFunc = TheModule->getOrInsertFunction("println", llvm::FunctionType::get(llvm::IntegerType::getInt32Ty(*TheContext), llvm::PointerType::get(llvm::Type::getInt8Ty(*TheContext), 0), true));
	     std::vector<llvm::Value*> ArgsV;
             for (unsigned i = 0, e = Args.size(); i != e; ++i){
		  if(i == 0 && Args[0]->getType() == "string"){
	              STAB::StringExprAST* strVal = dynamic_cast<STAB::StringExprAST*>(Args[0]);
		      std::string val = strVal->getVal();
		      auto replaced_val = replaceBracesWithPercentD(val);
		      replaced_val += '\n';
		      Args[0] = new STAB::StringExprAST(replaced_val);
		  }
		  // add new line for println
                  auto temp = Args[i]->codegen(s);
		  ArgsV.push_back(temp);
	     }

             return Builder->CreateCall(printlnFunc, ArgsV, "printlnCall");
	}

	if (!calleeFn){
            color("red","Error: ");
	    color("blue","No function ");
	    std::cout << Callee;
	    color("blue"," defined",true);
	    std::exit(0);
        }
        // check the number of arguments passed
        if(calleeFn->arg_size() != Args.size()){
	    color("red", "Error: ");
            color("blue","Function ");
	    std::cout << Callee;
	    color("blue"," expects ");
	    std::cout << calleeFn->arg_size();
	    color("blue"," arguments but ");
	    std::cout << Args.size();
	    color("blue"," were passed", true);
	    std::exit(0);
        }

        std::vector<llvm::Value*> args;
        for(const auto expr: Args){
            args.emplace_back(expr->codegen(s));
        }
        return Builder->CreateCall(calleeFn, args, "calltmp");
    }
}
