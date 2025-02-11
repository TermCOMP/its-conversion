
// Generated from Koat.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "KoatListener.h"


/**
 * This class provides an empty implementation of KoatListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  KoatBaseListener : public KoatListener {
public:

  virtual void enterMain(KoatParser::MainContext * /*ctx*/) override { }
  virtual void exitMain(KoatParser::MainContext * /*ctx*/) override { }

  virtual void enterFs(KoatParser::FsContext * /*ctx*/) override { }
  virtual void exitFs(KoatParser::FsContext * /*ctx*/) override { }

  virtual void enterVar(KoatParser::VarContext * /*ctx*/) override { }
  virtual void exitVar(KoatParser::VarContext * /*ctx*/) override { }

  virtual void enterGoal(KoatParser::GoalContext * /*ctx*/) override { }
  virtual void exitGoal(KoatParser::GoalContext * /*ctx*/) override { }

  virtual void enterStart(KoatParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(KoatParser::StartContext * /*ctx*/) override { }

  virtual void enterSink(KoatParser::SinkContext * /*ctx*/) override { }
  virtual void exitSink(KoatParser::SinkContext * /*ctx*/) override { }

  virtual void enterVardecl(KoatParser::VardeclContext * /*ctx*/) override { }
  virtual void exitVardecl(KoatParser::VardeclContext * /*ctx*/) override { }

  virtual void enterTranss(KoatParser::TranssContext * /*ctx*/) override { }
  virtual void exitTranss(KoatParser::TranssContext * /*ctx*/) override { }

  virtual void enterTrans(KoatParser::TransContext * /*ctx*/) override { }
  virtual void exitTrans(KoatParser::TransContext * /*ctx*/) override { }

  virtual void enterLhs(KoatParser::LhsContext * /*ctx*/) override { }
  virtual void exitLhs(KoatParser::LhsContext * /*ctx*/) override { }

  virtual void enterCom(KoatParser::ComContext * /*ctx*/) override { }
  virtual void exitCom(KoatParser::ComContext * /*ctx*/) override { }

  virtual void enterRhs(KoatParser::RhsContext * /*ctx*/) override { }
  virtual void exitRhs(KoatParser::RhsContext * /*ctx*/) override { }

  virtual void enterTo(KoatParser::ToContext * /*ctx*/) override { }
  virtual void exitTo(KoatParser::ToContext * /*ctx*/) override { }

  virtual void enterLb(KoatParser::LbContext * /*ctx*/) override { }
  virtual void exitLb(KoatParser::LbContext * /*ctx*/) override { }

  virtual void enterUb(KoatParser::UbContext * /*ctx*/) override { }
  virtual void exitUb(KoatParser::UbContext * /*ctx*/) override { }

  virtual void enterCond(KoatParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(KoatParser::CondContext * /*ctx*/) override { }

  virtual void enterExpr(KoatParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(KoatParser::ExprContext * /*ctx*/) override { }

  virtual void enterFormula(KoatParser::FormulaContext * /*ctx*/) override { }
  virtual void exitFormula(KoatParser::FormulaContext * /*ctx*/) override { }

  virtual void enterLit(KoatParser::LitContext * /*ctx*/) override { }
  virtual void exitLit(KoatParser::LitContext * /*ctx*/) override { }

  virtual void enterRelop(KoatParser::RelopContext * /*ctx*/) override { }
  virtual void exitRelop(KoatParser::RelopContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

