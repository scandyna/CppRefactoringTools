// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2024-2024 Philippe Steinmann.
 **
 *****************************************************************************************/
// See https://clang.llvm.org/docs/LibTooling.html
// Declares clang::SyntaxOnlyAction.
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"

#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
// #include "clang/Tooling/Tooling.h"

#include <QString>
#include <vector>
#include <string>
#include <memory>

#include <QDebug>

using namespace clang::tooling;
using namespace llvm;

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
// static llvm::cl::OptionCategory myToolCategory("my-tool options");

// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
// static llvm::cl::extrahelp commonHelp(CommonOptionsParser::HelpMessage);

// A help message for this specific tool can be added afterwards.
// static llvm::cl::extrahelp moreHelp("\nMore help text...\n");

/// See https://clang.llvm.org/docs/LibASTMatchers.html

using namespace clang::ast_matchers;

StatementMatcher LoopMatcher =
  forStmt(
    hasLoopInit(
      declStmt(
        hasSingleDecl(
          varDecl(
            hasInitializer(
              integerLiteral( equals(0) )
            )
          )
        )
      )
    )
  ).bind("forLoop");

class LoopPrinter : public clang::ast_matchers::MatchFinder::MatchCallback
{
 public :

  void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override
  {
    if( const clang::ForStmt *fs = result.Nodes.getNodeAs<clang::ForStmt>("forLoop") ){
      fs->dump();
    }
  }
};

DeclarationMatcher myClassMatcher =
  recordDecl(
    hasName("::C")
  ).bind("myClassMatcher");


class MyClassPrinter : public clang::ast_matchers::MatchFinder::MatchCallback
{
 public :

  void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override
  {
    const auto *fs = result.Nodes.getNodeAs<clang::CXXRecordDecl>("myClassMatcher");
    if(fs){
      fs->dump();
    }
  }
};


int matcherSandbox(clang::tooling::ClangTool & tool)
{
  MyClassPrinter printer;
  clang::ast_matchers::MatchFinder finder;
  finder.addMatcher(myClassMatcher, &printer);

  return tool.run( newFrontendActionFactory(&finder).get() );
}


/// clang-check-10 -ast-dump /home/philippe/dev/CppRefactoringTools/ClangSandbox/source.cpp


/** See https://clang.llvm.org/docs/RAVFrontendAction.html
 */

class FindNamedClassVisitor : public clang::RecursiveASTVisitor<FindNamedClassVisitor>
{
 public:

  bool VisitCXXRecordDecl(clang::CXXRecordDecl *declaration) {
    // For debugging, dumping the AST nodes will show which nodes are already
    // being visited.
    declaration->dump();

    // The return value indicates whether we want the visitation to proceed.
    // Return false to stop the traversal of the AST.
    return true;
  }
};

class FindNamedClassConsumer : public clang::ASTConsumer
{
 public:

  virtual
  void HandleTranslationUnit(clang::ASTContext & context)
  {
    // Traversing the translation unit decl via a RecursiveASTVisitor
    // will visit all nodes in the AST.
    mVisitor.TraverseDecl( context.getTranslationUnitDecl() );
  }

 private:

  // A RecursiveASTVisitor implementation.
  FindNamedClassVisitor mVisitor;
};


class FindNamedClassAction : public clang::ASTFrontendAction
{
 public:

  std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) override
  {
    return std::make_unique<FindNamedClassConsumer>();
  }
};


int dumpClasses(clang::tooling::ClangTool & tool)
{
  return tool.run( newFrontendActionFactory<FindNamedClassAction>().get() );
}

int dumpAST(clang::tooling::ClangTool & tool)
{
  return tool.run( newFrontendActionFactory<clang::ASTDumpAction>().get() );
}

void runToolOnCodeExample()
{
  using Action = clang::ASTDumpAction;

  bool result = clang::tooling::runToolOnCode( std::make_unique<Action>(), "int i;" );
  if(!result){
    qDebug() << "failed";
  }
}


std::string sandboxSourceFilePath()
{
  return std::string(CLANG_SANDBOX_SOURCE_DIR) + std::string("/source.cpp");
}

std::string projectBuildDir()
{
  return std::string(PROJECT_BUILD_DIR) + std::string("/../Kdevelop");
}

int main(int argc, const char **argv)
{
  // llvm::cl::OptionCategory myToolCategory("my-tool options");
  // CommonOptionsParser optionsParser(argc, argv, myToolCategory);
  
  // sandbox();
  // return 0;
  
  // clang::tooling::runToolOnCode(std::make_unique<FindNamedClassAction>(), argv[1]);
  
  std::vector<std::string> sourceFiles{sandboxSourceFilePath()};
  std::string errorMessage;
  
  /// \todo see file:///usr/share/doc/cmake-data/html/variable/CMAKE_EXPORT_COMPILE_COMMANDS.html
  auto compilationDatabase = clang::tooling::CompilationDatabase::loadFromDirectory(projectBuildDir(), errorMessage);
  
  if(!compilationDatabase){
    qDebug() << "error loading compilation database: " << QString::fromStdString(errorMessage);
    return -1;
  }

  ClangTool tool(*compilationDatabase, sourceFiles);


  qDebug() << "------------------- Dump classes -----------------------";
  int result1 = dumpClasses(tool);

  qDebug() << "------------------- Matcher sandbox -----------------------";
  int result2 = matcherSandbox(tool);

  return result1 + result2;

  // return dumpAST(tool);

  // return tool.run( std::make_unique<FindNamedClassAction>() );
  // return tool.run( newFrontendActionFactory<FindNamedClassAction>().get() );
  // return tool.run( newFrontendActionFactory<clang::SyntaxOnlyAction>().get() );
}

// #include <clang/Tooling/Tooling.h>
// 
// int main(int argc, char **argv)
// {
// 
// }
