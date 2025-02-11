
// Generated from Koat.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "KoatVisitor.h"


/**
 * This class provides an empty implementation of KoatVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  KoatBaseVisitor : public KoatVisitor {
public:

  virtual std::any visitMain(KoatParser::MainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFs(KoatParser::FsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar(KoatParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGoal(KoatParser::GoalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStart(KoatParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSink(KoatParser::SinkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVardecl(KoatParser::VardeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTranss(KoatParser::TranssContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrans(KoatParser::TransContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLhs(KoatParser::LhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCom(KoatParser::ComContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRhs(KoatParser::RhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTo(KoatParser::ToContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLb(KoatParser::LbContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUb(KoatParser::UbContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCond(KoatParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(KoatParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormula(KoatParser::FormulaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLit(KoatParser::LitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelop(KoatParser::RelopContext *ctx) override {
    return visitChildren(ctx);
  }


};

