// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 39 "src/parser/parser.yy"

  #include "../lexer/lexer.hpp"
  #include "../globals.h"
  namespace STAB {
    template <typename RHS>
    void calcLocation(location& current, const RHS& rhs, const std::size_t n);
  }
  #define YYLLOC_DEFAULT(Cur, Rhs, N) calcLocation(Cur, Rhs, N)
  #define yylex lexer.yylex

#line 57 "src/parser/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 17 "src/parser/parser.yy"
namespace STAB {
#line 150 "src/parser/parser.cpp"

  /// Build a parser object.
  Parser::Parser (Lexer& lexer_yyarg, const bool debug_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      debug (debug_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_fnCall: // fnCall
        value.copy< CallExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.copy< ExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_varInitialization: // varInitialization
        value.copy< STAB::VariableDeclAssignExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_functionDefinition: // functionDefinition
      case symbol_kind::S_functionPrototype: // functionPrototype
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_loop: // loop
      case symbol_kind::S_while: // while
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_assignExpr: // assignExpr
      case symbol_kind::S_returnStmt: // returnStmt
      case symbol_kind::S_fnCallStmt: // fnCallStmt
        value.copy< StatementAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_EQ: // "op"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_DATA_TYPE: // "type"
      case symbol_kind::S_NUMBER: // "num"
      case symbol_kind::S_STRING: // "str"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argList: // argList
      case symbol_kind::S_args: // args
        value.copy< std::vector<ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_paramsWithVar: // paramsWithVar
        value.copy< std::vector<STAB::VariableDeclExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stmts: // stmts
        value.copy< std::vector<StatementAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_paramList: // paramList
      case symbol_kind::S_params: // params
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_fnCall: // fnCall
        value.move< CallExprAST* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< ExprAST* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_varInitialization: // varInitialization
        value.move< STAB::VariableDeclAssignExprAST* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_functionDefinition: // functionDefinition
      case symbol_kind::S_functionPrototype: // functionPrototype
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_loop: // loop
      case symbol_kind::S_while: // while
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_assignExpr: // assignExpr
      case symbol_kind::S_returnStmt: // returnStmt
      case symbol_kind::S_fnCallStmt: // fnCallStmt
        value.move< StatementAST* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_EQ: // "op"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_DATA_TYPE: // "type"
      case symbol_kind::S_NUMBER: // "num"
      case symbol_kind::S_STRING: // "str"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argList: // argList
      case symbol_kind::S_args: // args
        value.move< std::vector<ExprAST*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_paramsWithVar: // paramsWithVar
        value.move< std::vector<STAB::VariableDeclExprAST*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stmts: // stmts
        value.move< std::vector<StatementAST*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_paramList: // paramList
      case symbol_kind::S_params: // params
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_fnCall: // fnCall
        value.YY_MOVE_OR_COPY< CallExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< ExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_varInitialization: // varInitialization
        value.YY_MOVE_OR_COPY< STAB::VariableDeclAssignExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_functionDefinition: // functionDefinition
      case symbol_kind::S_functionPrototype: // functionPrototype
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_loop: // loop
      case symbol_kind::S_while: // while
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_assignExpr: // assignExpr
      case symbol_kind::S_returnStmt: // returnStmt
      case symbol_kind::S_fnCallStmt: // fnCallStmt
        value.YY_MOVE_OR_COPY< StatementAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_EQ: // "op"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_DATA_TYPE: // "type"
      case symbol_kind::S_NUMBER: // "num"
      case symbol_kind::S_STRING: // "str"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argList: // argList
      case symbol_kind::S_args: // args
        value.YY_MOVE_OR_COPY< std::vector<ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_paramsWithVar: // paramsWithVar
        value.YY_MOVE_OR_COPY< std::vector<STAB::VariableDeclExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stmts: // stmts
        value.YY_MOVE_OR_COPY< std::vector<StatementAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_paramList: // paramList
      case symbol_kind::S_params: // params
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_fnCall: // fnCall
        value.move< CallExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< ExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_varInitialization: // varInitialization
        value.move< STAB::VariableDeclAssignExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_functionDefinition: // functionDefinition
      case symbol_kind::S_functionPrototype: // functionPrototype
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_loop: // loop
      case symbol_kind::S_while: // while
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_assignExpr: // assignExpr
      case symbol_kind::S_returnStmt: // returnStmt
      case symbol_kind::S_fnCallStmt: // fnCallStmt
        value.move< StatementAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_EQ: // "op"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_DATA_TYPE: // "type"
      case symbol_kind::S_NUMBER: // "num"
      case symbol_kind::S_STRING: // "str"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argList: // argList
      case symbol_kind::S_args: // args
        value.move< std::vector<ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_paramsWithVar: // paramsWithVar
        value.move< std::vector<STAB::VariableDeclExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stmts: // stmts
        value.move< std::vector<StatementAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_paramList: // paramList
      case symbol_kind::S_params: // params
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_fnCall: // fnCall
        value.copy< CallExprAST* > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.copy< ExprAST* > (that.value);
        break;

      case symbol_kind::S_varInitialization: // varInitialization
        value.copy< STAB::VariableDeclAssignExprAST* > (that.value);
        break;

      case symbol_kind::S_functionDefinition: // functionDefinition
      case symbol_kind::S_functionPrototype: // functionPrototype
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_loop: // loop
      case symbol_kind::S_while: // while
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_assignExpr: // assignExpr
      case symbol_kind::S_returnStmt: // returnStmt
      case symbol_kind::S_fnCallStmt: // fnCallStmt
        value.copy< StatementAST* > (that.value);
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_EQ: // "op"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_DATA_TYPE: // "type"
      case symbol_kind::S_NUMBER: // "num"
      case symbol_kind::S_STRING: // "str"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_argList: // argList
      case symbol_kind::S_args: // args
        value.copy< std::vector<ExprAST*> > (that.value);
        break;

      case symbol_kind::S_paramsWithVar: // paramsWithVar
        value.copy< std::vector<STAB::VariableDeclExprAST*> > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stmts: // stmts
        value.copy< std::vector<StatementAST*> > (that.value);
        break;

      case symbol_kind::S_paramList: // paramList
      case symbol_kind::S_params: // params
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_fnCall: // fnCall
        value.move< CallExprAST* > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.move< ExprAST* > (that.value);
        break;

      case symbol_kind::S_varInitialization: // varInitialization
        value.move< STAB::VariableDeclAssignExprAST* > (that.value);
        break;

      case symbol_kind::S_functionDefinition: // functionDefinition
      case symbol_kind::S_functionPrototype: // functionPrototype
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_loop: // loop
      case symbol_kind::S_while: // while
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_assignExpr: // assignExpr
      case symbol_kind::S_returnStmt: // returnStmt
      case symbol_kind::S_fnCallStmt: // fnCallStmt
        value.move< StatementAST* > (that.value);
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_EQ: // "op"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_DATA_TYPE: // "type"
      case symbol_kind::S_NUMBER: // "num"
      case symbol_kind::S_STRING: // "str"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_argList: // argList
      case symbol_kind::S_args: // args
        value.move< std::vector<ExprAST*> > (that.value);
        break;

      case symbol_kind::S_paramsWithVar: // paramsWithVar
        value.move< std::vector<STAB::VariableDeclExprAST*> > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stmts: // stmts
        value.move< std::vector<StatementAST*> > (that.value);
        break;

      case symbol_kind::S_paramList: // paramList
      case symbol_kind::S_params: // params
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 33 "src/parser/parser.yy"
{
  #if YYDEBUG != 0 
    set_debug_level(debug);
  #endif
}

#line 874 "src/parser/parser.cpp"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_fnCall: // fnCall
        yylhs.value.emplace< CallExprAST* > ();
        break;

      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< ExprAST* > ();
        break;

      case symbol_kind::S_varInitialization: // varInitialization
        yylhs.value.emplace< STAB::VariableDeclAssignExprAST* > ();
        break;

      case symbol_kind::S_functionDefinition: // functionDefinition
      case symbol_kind::S_functionPrototype: // functionPrototype
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_loop: // loop
      case symbol_kind::S_while: // while
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_assignExpr: // assignExpr
      case symbol_kind::S_returnStmt: // returnStmt
      case symbol_kind::S_fnCallStmt: // fnCallStmt
        yylhs.value.emplace< StatementAST* > ();
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_EQ: // "op"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_DATA_TYPE: // "type"
      case symbol_kind::S_NUMBER: // "num"
      case symbol_kind::S_STRING: // "str"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_argList: // argList
      case symbol_kind::S_args: // args
        yylhs.value.emplace< std::vector<ExprAST*> > ();
        break;

      case symbol_kind::S_paramsWithVar: // paramsWithVar
        yylhs.value.emplace< std::vector<STAB::VariableDeclExprAST*> > ();
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stmts: // stmts
        yylhs.value.emplace< std::vector<StatementAST*> > ();
        break;

      case symbol_kind::S_paramList: // paramList
      case symbol_kind::S_params: // params
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // functionDefinition: FN "identifier" LBRACE paramsWithVar RBRACE FN_ARROW "type" LCURLY stmts RCURLY
#line 79 "src/parser/parser.yy"
                                                                                             {
			auto fnScope = new Scope(currentScope);
			currentScope = fnScope;
                        std::vector<std::string> argTypes;
			std::vector<STAB::VariableDeclExprAST*> declVars;
                        for(const auto elt: yystack_[6].value.as < std::vector<STAB::VariableDeclExprAST*> > ()){
			  argTypes.emplace_back(elt->getType());
			  declVars.emplace_back(elt);
			}
			auto proto = new STAB::PrototypeAST(yystack_[3].value.as < std::string > (), yystack_[8].value.as < std::string > (), argTypes);
			yylhs.value.as < StatementAST* > () = new STAB::FunctionAST(proto,declVars, yystack_[1].value.as < std::vector<StatementAST*> > (), fnScope);
			currentScope = globalScope;
                    }
#line 1083 "src/parser/parser.cpp"
    break;

  case 3: // functionPrototype: FN "identifier" LBRACE paramList RBRACE FN_ARROW "type" SEMI_COLON
#line 93 "src/parser/parser.yy"
                                                                                {
                       std::vector<std::string> Args;
		       for(const auto elt: yystack_[4].value.as < std::vector<std::string> > ()){
		         Args.emplace_back(elt);
		       }
                       yylhs.value.as < StatementAST* > () = new STAB::PrototypeAST(yystack_[1].value.as < std::string > (), yystack_[6].value.as < std::string > (), Args);
                   }
#line 1095 "src/parser/parser.cpp"
    break;

  case 4: // varDeclaration: "type" "identifier" SEMI_COLON
#line 102 "src/parser/parser.yy"
                                         {
                  yylhs.value.as < StatementAST* > () = new STAB::VariableDeclExprAST(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::string > ());
                }
#line 1103 "src/parser/parser.cpp"
    break;

  case 5: // varInitialization: "type" "identifier" ASSIGN expr SEMI_COLON
#line 106 "src/parser/parser.yy"
                                                        {
                     auto type = yystack_[4].value.as < std::string > ();
		     auto name = yystack_[3].value.as < std::string > ();
		     auto val = yystack_[1].value.as < ExprAST* > ();
		     auto varDecl = new VariableDeclExprAST(type, name);
		     yylhs.value.as < STAB::VariableDeclAssignExprAST* > () = new VariableDeclAssignExprAST(varDecl, val);
		  }
#line 1115 "src/parser/parser.cpp"
    break;

  case 6: // loop: LOOP LCURLY stmts RCURLY
#line 115 "src/parser/parser.yy"
                               {
       yylhs.value.as < StatementAST* > () = new LoopStatementAST(yystack_[1].value.as < std::vector<StatementAST*> > ());

     }
#line 1124 "src/parser/parser.cpp"
    break;

  case 8: // while: WHILE expr LCURLY stmts RCURLY
#line 123 "src/parser/parser.yy"
                                      {
         if (currentScope == globalScope){
           std::cerr << "\nCannot write a loop statement in the global scope\n"; 
         }
       yylhs.value.as < StatementAST* > () = new WhileStatementAST(yystack_[3].value.as < ExprAST* > (), yystack_[1].value.as < std::vector<StatementAST*> > ());

      }
#line 1136 "src/parser/parser.cpp"
    break;

  case 9: // program: stmts
#line 131 "src/parser/parser.yy"
              {
       globalScope = new Scope(nullptr);
       currentScope = globalScope;

       std::vector<std::string> Args;
       std::vector<STAB::VariableDeclExprAST*> declVars;
  
       yylhs.value.as < std::vector<StatementAST*> > () = yystack_[0].value.as < std::vector<StatementAST*> > ();

       }
#line 1151 "src/parser/parser.cpp"
    break;

  case 10: // stmts: stmts stmt
#line 141 "src/parser/parser.yy"
                 {
       yystack_[1].value.as < std::vector<StatementAST*> > ().emplace_back(yystack_[0].value.as < StatementAST* > ());
       yylhs.value.as < std::vector<StatementAST*> > () = yystack_[1].value.as < std::vector<StatementAST*> > ();
     }
#line 1160 "src/parser/parser.cpp"
    break;

  case 11: // stmts: %empty
#line 145 "src/parser/parser.yy"
              {
       yylhs.value.as < std::vector<StatementAST*> > () = std::vector<STAB::StatementAST*>();
     }
#line 1168 "src/parser/parser.cpp"
    break;

  case 12: // stmt: functionDefinition
#line 151 "src/parser/parser.yy"
                        {
        yylhs.value.as < StatementAST* > () = yystack_[0].value.as < StatementAST* > ();
      }
#line 1176 "src/parser/parser.cpp"
    break;

  case 13: // stmt: loop
#line 154 "src/parser/parser.yy"
            {
        yylhs.value.as < StatementAST* > () = yystack_[0].value.as < StatementAST* > ();
      }
#line 1184 "src/parser/parser.cpp"
    break;

  case 15: // stmt: while
#line 158 "src/parser/parser.yy"
              {
         yylhs.value.as < StatementAST* > () = yystack_[0].value.as < StatementAST* > ();
      }
#line 1192 "src/parser/parser.cpp"
    break;

  case 17: // stmt: varDeclaration
#line 162 "src/parser/parser.yy"
                      {
        yylhs.value.as < StatementAST* > () = yystack_[0].value.as < StatementAST* > ();
      }
#line 1200 "src/parser/parser.cpp"
    break;

  case 18: // stmt: varInitialization
#line 165 "src/parser/parser.yy"
                         {
         yylhs.value.as < StatementAST* > () = yystack_[0].value.as < STAB::VariableDeclAssignExprAST* > ();
      }
#line 1208 "src/parser/parser.cpp"
    break;

  case 19: // stmt: assignExpr
#line 168 "src/parser/parser.yy"
                  {
         yylhs.value.as < StatementAST* > () = yystack_[0].value.as < StatementAST* > ();
      }
#line 1216 "src/parser/parser.cpp"
    break;

  case 22: // stmt: returnStmt
#line 173 "src/parser/parser.yy"
                  {
          yylhs.value.as < StatementAST* > () = yystack_[0].value.as < StatementAST* > (); 
      }
#line 1224 "src/parser/parser.cpp"
    break;

  case 23: // stmt: functionPrototype
#line 176 "src/parser/parser.yy"
                          {
        yylhs.value.as < StatementAST* > () = yystack_[0].value.as < StatementAST* > ();
      }
#line 1232 "src/parser/parser.cpp"
    break;

  case 24: // stmt: fnCallStmt
#line 179 "src/parser/parser.yy"
                   {
         yylhs.value.as < StatementAST* > () = yystack_[0].value.as < StatementAST* > (); 
      }
#line 1240 "src/parser/parser.cpp"
    break;

  case 25: // expr: expr PLUS expr
#line 184 "src/parser/parser.yy"
                      {
        yylhs.value.as < ExprAST* > () = new BinaryExprAST(yystack_[1].value.as < std::string > (), yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ());
      }
#line 1248 "src/parser/parser.cpp"
    break;

  case 26: // expr: expr MINUS expr
#line 187 "src/parser/parser.yy"
                       {
        yylhs.value.as < ExprAST* > () = new BinaryExprAST(yystack_[1].value.as < std::string > (), yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ());
     }
#line 1256 "src/parser/parser.cpp"
    break;

  case 27: // expr: expr TIMES expr
#line 190 "src/parser/parser.yy"
                       {
        yylhs.value.as < ExprAST* > () = new BinaryExprAST(yystack_[1].value.as < std::string > (), yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ());
     }
#line 1264 "src/parser/parser.cpp"
    break;

  case 28: // expr: expr DIV expr
#line 193 "src/parser/parser.yy"
                     {
        yylhs.value.as < ExprAST* > () = new BinaryExprAST(yystack_[1].value.as < std::string > (), yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ());
     }
#line 1272 "src/parser/parser.cpp"
    break;

  case 29: // expr: LBRACE expr RBRACE
#line 196 "src/parser/parser.yy"
                          {
        yylhs.value.as < ExprAST* > () = yystack_[1].value.as < ExprAST* > (); 
     }
#line 1280 "src/parser/parser.cpp"
    break;

  case 30: // expr: expr GT expr
#line 199 "src/parser/parser.yy"
                    {
        yylhs.value.as < ExprAST* > () = new BinaryExprAST(yystack_[1].value.as < std::string > (), yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ());
     }
#line 1288 "src/parser/parser.cpp"
    break;

  case 31: // expr: expr LT expr
#line 202 "src/parser/parser.yy"
                    {
        yylhs.value.as < ExprAST* > () = new BinaryExprAST(yystack_[1].value.as < std::string > (), yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ());
     }
#line 1296 "src/parser/parser.cpp"
    break;

  case 32: // expr: expr LE expr
#line 205 "src/parser/parser.yy"
                    {
        yylhs.value.as < ExprAST* > () = new BinaryExprAST(yystack_[1].value.as < std::string > (), yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ());
     }
#line 1304 "src/parser/parser.cpp"
    break;

  case 33: // expr: expr GE expr
#line 208 "src/parser/parser.yy"
                   {
        yylhs.value.as < ExprAST* > () = new BinaryExprAST(yystack_[1].value.as < std::string > (), yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ());
     }
#line 1312 "src/parser/parser.cpp"
    break;

  case 34: // expr: expr "op" expr
#line 211 "src/parser/parser.yy"
                   {
       yylhs.value.as < ExprAST* > () = new BinaryExprAST(yystack_[1].value.as < std::string > (), yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ());
     }
#line 1320 "src/parser/parser.cpp"
    break;

  case 35: // expr: expr NE expr
#line 214 "src/parser/parser.yy"
                   {
        yylhs.value.as < ExprAST* > () = new BinaryExprAST(yystack_[1].value.as < std::string > (), yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ());
     }
#line 1328 "src/parser/parser.cpp"
    break;

  case 36: // expr: "str"
#line 217 "src/parser/parser.yy"
              {
        std::string val = yystack_[0].value.as < std::string > ();
	auto length = val.length();
	std::string without_quotation;
	for(int i = 1; i < length - 1 ; ++i){
	 without_quotation += val[i];
	}
	yylhs.value.as < ExprAST* > () = new StringExprAST(without_quotation);
     }
#line 1342 "src/parser/parser.cpp"
    break;

  case 37: // expr: "identifier"
#line 226 "src/parser/parser.yy"
          {
       yylhs.value.as < ExprAST* > () = new VariableExprAST(yystack_[0].value.as < std::string > ());
     }
#line 1350 "src/parser/parser.cpp"
    break;

  case 38: // expr: "num"
#line 229 "src/parser/parser.yy"
              {
        auto val = std::stoi(yystack_[0].value.as < std::string > ());
        yylhs.value.as < ExprAST* > () = new NumberExprAST(val);
     }
#line 1359 "src/parser/parser.cpp"
    break;

  case 39: // expr: fnCall
#line 233 "src/parser/parser.yy"
              {
        yylhs.value.as < ExprAST* > () = new CallExprAST(yystack_[0].value.as < CallExprAST* > ()->getFnName(), yystack_[0].value.as < CallExprAST* > ()->getArgs());
     }
#line 1367 "src/parser/parser.cpp"
    break;

  case 40: // assignExpr: "identifier" ASSIGN expr SEMI_COLON
#line 238 "src/parser/parser.yy"
                                                   {
             yylhs.value.as < StatementAST* > () = new VariableAssignExprAST(yystack_[3].value.as < std::string > (), yystack_[1].value.as < ExprAST* > ());
           }
#line 1375 "src/parser/parser.cpp"
    break;

  case 41: // returnStmt: RETURN expr SEMI_COLON
#line 243 "src/parser/parser.yy"
                                   {
              yylhs.value.as < StatementAST* > () = new ReturnStmtAST(yystack_[1].value.as < ExprAST* > ());
           }
#line 1383 "src/parser/parser.cpp"
    break;

  case 48: // ifStmt: IF expr LCURLY stmt RCURLY elseifStmt elseStmt
#line 259 "src/parser/parser.yy"
                                                        {
	 }
#line 1390 "src/parser/parser.cpp"
    break;

  case 49: // paramList: params
#line 263 "src/parser/parser.yy"
                  {
	     for (const auto elt: yystack_[0].value.as < std::vector<std::string> > ())
	         yylhs.value.as < std::vector<std::string> > ().emplace_back(elt);
	  }
#line 1399 "src/parser/parser.cpp"
    break;

  case 50: // params: params COMMA "type"
#line 269 "src/parser/parser.yy"
                               {
	 for(const auto elt: yystack_[2].value.as < std::vector<std::string> > ())
	    yylhs.value.as < std::vector<std::string> > ().emplace_back(elt);
	 yylhs.value.as < std::vector<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ());
       }
#line 1409 "src/parser/parser.cpp"
    break;

  case 51: // params: "type"
#line 274 "src/parser/parser.yy"
                   {
       yylhs.value.as < std::vector<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ());
       }
#line 1417 "src/parser/parser.cpp"
    break;

  case 52: // paramsWithVar: paramsWithVar COMMA "type" "identifier"
#line 279 "src/parser/parser.yy"
                                                {
                for(const auto elt: yystack_[3].value.as < std::vector<STAB::VariableDeclExprAST*> > ())
		   yylhs.value.as < std::vector<STAB::VariableDeclExprAST*> > ().emplace_back(elt);
	     }
#line 1426 "src/parser/parser.cpp"
    break;

  case 53: // paramsWithVar: "type" "identifier"
#line 283 "src/parser/parser.yy"
                            {
	       auto newDecl = new STAB::VariableDeclExprAST(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ());
	       yylhs.value.as < std::vector<STAB::VariableDeclExprAST*> > ().emplace_back(newDecl);
	     }
#line 1435 "src/parser/parser.cpp"
    break;

  case 55: // argList: %empty
#line 291 "src/parser/parser.yy"
                 {
        }
#line 1442 "src/parser/parser.cpp"
    break;

  case 56: // argList: args
#line 293 "src/parser/parser.yy"
               {
	 for(const auto elt: yystack_[0].value.as < std::vector<ExprAST*> > ()){
	   yylhs.value.as < std::vector<ExprAST*> > ().emplace_back(elt);
	 }
	}
#line 1452 "src/parser/parser.cpp"
    break;

  case 57: // args: args COMMA expr
#line 300 "src/parser/parser.yy"
                       {
       for(const auto elt: yystack_[2].value.as < std::vector<ExprAST*> > ())
           yylhs.value.as < std::vector<ExprAST*> > ().emplace_back(elt);
       yylhs.value.as < std::vector<ExprAST*> > ().emplace_back(yystack_[0].value.as < ExprAST* > ());
     }
#line 1462 "src/parser/parser.cpp"
    break;

  case 58: // args: expr
#line 305 "src/parser/parser.yy"
            {
       yylhs.value.as < std::vector<ExprAST*> > ().emplace_back(yystack_[0].value.as < ExprAST* > ());
     }
#line 1470 "src/parser/parser.cpp"
    break;

  case 59: // fnCallStmt: "identifier" LBRACE argList RBRACE SEMI_COLON
#line 309 "src/parser/parser.yy"
                                                {
     std::vector<STAB::ExprAST*> Args;
     for (const auto elt: yystack_[2].value.as < std::vector<ExprAST*> > ()){
         Args.emplace_back(elt);
       }
      yylhs.value.as < StatementAST* > () = new CallStatementAST(yystack_[4].value.as < std::string > (), Args);
    }
#line 1482 "src/parser/parser.cpp"
    break;

  case 60: // fnCall: "identifier" LBRACE argList RBRACE
#line 317 "src/parser/parser.yy"
                                 {
   std::vector<STAB::ExprAST*> Args;
   for (const auto elt: yystack_[1].value.as < std::vector<ExprAST*> > ()){
      Args.emplace_back(elt);
   }
   yylhs.value.as < CallExprAST* > () = new CallExprAST(yystack_[3].value.as < std::string > (), Args);
 }
#line 1494 "src/parser/parser.cpp"
    break;


#line 1498 "src/parser/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "MOD", "LBRACE", "RBRACE",
  "LCURLY", "RCURLY", "LBIG", "RBIG", "ASSIGN", "IF", "ELSE", "ELSE_IF",
  "LOOP", "FOR", "WHILE", "AND", "OR", "XOR", "MATCH", "IMPORT", "IN",
  "CONTROL_FLOW", "COMMA", "FN_ARROW", "MATCH_ARROW", "RETURN", "BREAK",
  "SKIP", "SEMI_COLON", "PLUS", "MINUS", "TIMES", "DIV", "GT", "LT", "GE",
  "LE", "NE", "op", "identifier", "type", "num", "str", "FN", "$accept",
  "functionDefinition", "functionPrototype", "varDeclaration",
  "varInitialization", "loop", "for", "while", "program", "stmts", "stmt",
  "expr", "assignExpr", "returnStmt", "breakStmt", "skipStmt", "elseStmt",
  "elseifStmt", "ifStmt", "paramList", "params", "paramsWithVar",
  "argList", "args", "fnCallStmt", "fnCall", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -42;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     -42,    19,   172,   -42,    -2,    14,   -20,    -2,    -2,    -8,
      -7,    50,    -1,    15,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,    -2,    32,
     -42,   -42,   123,   -42,   -42,    16,   135,   -22,   -42,   -42,
      -2,    -2,    -3,    51,   113,    -2,   172,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    56,    17,   -42,
     -42,   171,    52,    35,   188,    -2,   -42,    20,   -42,    59,
      58,    -5,    -5,    95,    95,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,    60,    75,    38,    -2,   -42,   199,    28,    68,
      55,     1,   -42,    61,   172,   -42,   -42,   171,   -42,   -42,
      62,    33,    67,    34,    -2,    81,    73,    53,   -42,    54,
      65,   158,    88,   -42,   -42,    69,   101,   -42,   172,   172,
     -42,   -42,   103,   104,    98,    61,   -42,   -42,   -42
  };

  const signed char
  Parser::yydefact_[] =
  {
      11,     0,     9,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    23,    17,    18,    13,    14,
      15,    10,    19,    22,    20,    21,    16,    24,     0,    37,
      38,    36,     0,    39,    11,     0,     0,     0,    42,    43,
      55,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      41,    58,     0,    56,     0,     0,     4,    54,    29,     0,
       0,    25,    26,    27,    28,    30,    31,    33,    32,    35,
      34,     6,     0,     0,     0,     0,    40,     0,    51,     0,
      49,     0,    60,    46,     0,     8,    59,    57,     5,    53,
       0,     0,     0,     0,     0,    44,     0,     0,    50,     0,
       0,     0,     0,    48,     7,     0,     0,    52,     0,     0,
       3,    11,     0,     0,     0,    46,    45,     2,    47
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -33,
     -41,    -4,   -42,   -42,   -42,   -42,   -42,   -17,   -42,   -42,
     -42,   -42,    70,   -42,   -42,   -42
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,    14,    15,    16,    17,    18,    19,    20,     1,     2,
      21,    61,    22,    23,    24,    25,   113,   105,    26,    89,
      90,    91,    62,    63,    27,    33
  };

  const unsigned char
  Parser::yytable_[] =
  {
      32,    57,    28,    36,    37,    70,   102,    65,    60,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     3,
      34,    35,    38,    39,    44,   103,    83,    66,    49,    50,
      51,    52,    53,    54,    55,    56,    45,    64,    58,    29,
      42,    30,    31,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   106,    40,    67,    43,    84,    82,    85,
      41,    87,    88,    81,    92,    93,    94,     4,    96,    99,
       5,     6,     7,   100,   104,   108,   110,   122,   123,   101,
     114,    97,    95,     8,     9,    10,     4,   107,   124,     5,
       6,     7,   109,   112,   119,   115,   116,    11,    12,   120,
     111,    13,     8,     9,    10,   127,   117,   121,   128,     4,
     125,   126,     5,     6,     7,    69,    11,    12,    68,     0,
      13,     0,     0,     0,     0,     8,     9,    10,     0,    46,
      51,    52,    53,    54,    55,    56,     0,     0,     0,    11,
      12,    59,     0,    13,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,   118,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     5,     6,     7,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     8,
       9,    10,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,    11,    12,     0,     0,    13,    86,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    98,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56
  };

  const signed char
  Parser::yycheck_[] =
  {
       4,    34,     4,     7,     8,    46,     5,    10,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
       6,    41,    30,    30,    28,    24,    59,    30,    33,    34,
      35,    36,    37,    38,    39,    40,     4,    41,    22,    41,
      41,    43,    44,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    94,     4,     4,    41,     5,    41,    24,
      10,    65,    42,     7,     5,     7,     6,    11,    30,    41,
      14,    15,    16,     5,    13,    42,    42,   118,   119,    24,
       7,    85,     7,    27,    28,    29,    11,    25,   121,    14,
      15,    16,    25,    12,     6,    42,    42,    41,    42,    30,
     104,    45,    27,    28,    29,     7,    41,     6,   125,    11,
       7,     7,    14,    15,    16,    45,    41,    42,     5,    -1,
      45,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,     6,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    41,
      42,     6,    -1,    45,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     6,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    14,    15,    16,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    27,
      28,    29,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    41,    42,    -1,    -1,    45,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    54,    55,     0,    11,    14,    15,    16,    27,    28,
      29,    41,    42,    45,    47,    48,    49,    50,    51,    52,
      53,    56,    58,    59,    60,    61,    64,    70,     4,    41,
      43,    44,    57,    71,     6,    41,    57,    57,    30,    30,
       4,    10,    41,    41,    57,     4,     6,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    55,    22,     6,
      30,    57,    68,    69,    57,    10,    30,     4,     5,    68,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,     7,    41,    55,     5,    24,    30,    57,    42,    65,
      66,    67,     5,     7,     6,     7,    30,    57,    30,    41,
       5,    24,     5,    24,    13,    63,    56,    25,    42,    25,
      42,    57,    12,    62,     7,    42,    42,    41,     6,     6,
      30,     6,    56,    56,    55,     7,     7,     7,    63
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    59,    60,    61,    62,    62,    63,    63,    64,    65,
      66,    66,    67,    67,    67,    68,    68,    69,    69,    70,
      71
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,    10,     8,     3,     5,     4,     7,     5,     1,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       4,     3,     2,     2,     0,     4,     0,     6,     7,     1,
       3,     1,     4,     2,     0,     0,     1,     3,     1,     5,
       4
  };




#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    79,    79,    93,   102,   106,   115,   121,   123,   131,
     141,   145,   151,   154,   157,   158,   161,   162,   165,   168,
     171,   172,   173,   176,   179,   184,   187,   190,   193,   196,
     199,   202,   205,   208,   211,   214,   217,   226,   229,   233,
     238,   243,   248,   250,   252,   253,   256,   257,   259,   263,
     269,   274,   279,   283,   287,   291,   293,   300,   305,   309,
     317
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

#line 17 "src/parser/parser.yy"
} // STAB
#line 2031 "src/parser/parser.cpp"

#line 325 "src/parser/parser.yy"


namespace STAB {
 template <typename RHS>
 inline void calcLocation(location& current, const RHS& rhs, const std::size_t n){
 current = location(YYRHSLOC(rhs, 1).first, YYRHSLOC(rhs, n).second);
 }
//void Parser::report_syntax_error(const context& ctx) const {
 // std::cerr << ctx.location() << ": Syntax Error Something went wrong"; 
 //}
 void Parser::error(const location &loc, const std::string &message){
  std::cerr << "Error at lines " << loc << ": " << message << std::endl;
  }
}
