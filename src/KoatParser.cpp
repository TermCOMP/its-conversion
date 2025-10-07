
// Generated from Koat.g4 by ANTLR 4.11.1


#include "KoatListener.h"
#include "KoatVisitor.h"

#include "KoatParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct KoatParserStaticData final {
  KoatParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  KoatParserStaticData(const KoatParserStaticData&) = delete;
  KoatParserStaticData(KoatParserStaticData&&) = delete;
  KoatParserStaticData& operator=(const KoatParserStaticData&) = delete;
  KoatParserStaticData& operator=(KoatParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag koatParserOnceFlag;
KoatParserStaticData *koatParserStaticData = nullptr;

void koatParserInitialize() {
  assert(koatParserStaticData == nullptr);
  auto staticData = std::make_unique<KoatParserStaticData>(
    std::vector<std::string>{
      "main", "fs", "var", "goal", "start", "sink", "vardecl", "transs", 
      "trans", "lhs", "com", "rhs", "to", "lb", "ub", "cond", "expr", "formula", 
      "lit", "relop"
    },
    std::vector<std::string>{
      "", "", "'GOAL'", "'COMPLEXITY'", "'TERMINATION'", "'STARTTERM'", 
      "'SINKTERM'", "'FUNCTIONSYMBOLS'", "'VAR'", "'RULES'", "'+'", "'-'", 
      "'*'", "", "'('", "')'", "']'", "'['", "'{'", "'}'", "'->'", "','", 
      "", "", "'<'", "'<='", "", "'!='", "'>='", "'>'", "':|:'"
    },
    std::vector<std::string>{
      "", "COM", "GOAL", "CPX", "TERM", "START", "SINK", "FS", "VAR", "RULES", 
      "PLUS", "MINUS", "TIMES", "EXP", "LPAR", "RPAR", "RBRACK", "LBRACK", 
      "LCURL", "RCURL", "TO", "COMMA", "AND", "OR", "LT", "LEQ", "EQ", "NEQ", 
      "GEQ", "GT", "CONDSEP", "ID", "INT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,34,228,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,3,0,42,8,0,1,
  	0,1,0,3,0,46,8,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,
  	6,5,6,79,8,6,10,6,12,6,82,9,6,1,6,1,6,1,7,1,7,1,7,5,7,89,8,7,10,7,12,
  	7,92,9,7,1,7,1,7,1,8,1,8,1,8,1,8,3,8,100,8,8,1,9,1,9,1,9,1,9,1,9,5,9,
  	107,8,9,10,9,12,9,110,9,9,3,9,112,8,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,
  	5,10,121,8,10,10,10,12,10,124,9,10,3,10,126,8,10,1,10,1,10,3,10,130,8,
  	10,1,11,1,11,1,11,1,11,1,11,5,11,137,8,11,10,11,12,11,140,9,11,3,11,142,
  	8,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,3,12,161,8,12,1,13,1,13,1,14,1,14,1,15,1,15,1,15,
  	1,15,1,15,1,15,3,15,173,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,3,16,184,8,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,16,5,16,198,8,16,10,16,12,16,201,9,16,1,17,1,17,1,17,1,17,1,17,
  	1,17,3,17,209,8,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,217,8,17,10,17,
  	12,17,220,9,17,1,18,1,18,1,18,1,18,1,19,1,19,1,19,0,2,32,34,20,0,2,4,
  	6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,2,1,0,3,4,1,0,24,29,
  	232,0,41,1,0,0,0,2,50,1,0,0,0,4,52,1,0,0,0,6,54,1,0,0,0,8,59,1,0,0,0,
  	10,67,1,0,0,0,12,75,1,0,0,0,14,85,1,0,0,0,16,95,1,0,0,0,18,101,1,0,0,
  	0,20,129,1,0,0,0,22,131,1,0,0,0,24,160,1,0,0,0,26,162,1,0,0,0,28,164,
  	1,0,0,0,30,172,1,0,0,0,32,183,1,0,0,0,34,208,1,0,0,0,36,221,1,0,0,0,38,
  	225,1,0,0,0,40,42,3,6,3,0,41,40,1,0,0,0,41,42,1,0,0,0,42,43,1,0,0,0,43,
  	45,3,8,4,0,44,46,3,10,5,0,45,44,1,0,0,0,45,46,1,0,0,0,46,47,1,0,0,0,47,
  	48,3,12,6,0,48,49,3,14,7,0,49,1,1,0,0,0,50,51,5,31,0,0,51,3,1,0,0,0,52,
  	53,5,31,0,0,53,5,1,0,0,0,54,55,5,14,0,0,55,56,5,2,0,0,56,57,7,0,0,0,57,
  	58,5,15,0,0,58,7,1,0,0,0,59,60,5,14,0,0,60,61,5,5,0,0,61,62,5,14,0,0,
  	62,63,5,7,0,0,63,64,3,2,1,0,64,65,5,15,0,0,65,66,5,15,0,0,66,9,1,0,0,
  	0,67,68,5,14,0,0,68,69,5,6,0,0,69,70,5,14,0,0,70,71,5,7,0,0,71,72,3,2,
  	1,0,72,73,5,15,0,0,73,74,5,15,0,0,74,11,1,0,0,0,75,76,5,14,0,0,76,80,
  	5,8,0,0,77,79,5,31,0,0,78,77,1,0,0,0,79,82,1,0,0,0,80,78,1,0,0,0,80,81,
  	1,0,0,0,81,83,1,0,0,0,82,80,1,0,0,0,83,84,5,15,0,0,84,13,1,0,0,0,85,86,
  	5,14,0,0,86,90,5,9,0,0,87,89,3,16,8,0,88,87,1,0,0,0,89,92,1,0,0,0,90,
  	88,1,0,0,0,90,91,1,0,0,0,91,93,1,0,0,0,92,90,1,0,0,0,93,94,5,15,0,0,94,
  	15,1,0,0,0,95,96,3,18,9,0,96,97,3,24,12,0,97,99,3,20,10,0,98,100,3,30,
  	15,0,99,98,1,0,0,0,99,100,1,0,0,0,100,17,1,0,0,0,101,102,3,2,1,0,102,
  	111,5,14,0,0,103,108,3,4,2,0,104,105,5,21,0,0,105,107,3,4,2,0,106,104,
  	1,0,0,0,107,110,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,109,112,1,0,0,
  	0,110,108,1,0,0,0,111,103,1,0,0,0,111,112,1,0,0,0,112,113,1,0,0,0,113,
  	114,5,15,0,0,114,19,1,0,0,0,115,116,5,1,0,0,116,125,5,14,0,0,117,122,
  	3,22,11,0,118,119,5,21,0,0,119,121,3,22,11,0,120,118,1,0,0,0,121,124,
  	1,0,0,0,122,120,1,0,0,0,122,123,1,0,0,0,123,126,1,0,0,0,124,122,1,0,0,
  	0,125,117,1,0,0,0,125,126,1,0,0,0,126,127,1,0,0,0,127,130,5,15,0,0,128,
  	130,3,22,11,0,129,115,1,0,0,0,129,128,1,0,0,0,130,21,1,0,0,0,131,132,
  	3,2,1,0,132,141,5,14,0,0,133,138,3,32,16,0,134,135,5,21,0,0,135,137,3,
  	32,16,0,136,134,1,0,0,0,137,140,1,0,0,0,138,136,1,0,0,0,138,139,1,0,0,
  	0,139,142,1,0,0,0,140,138,1,0,0,0,141,133,1,0,0,0,141,142,1,0,0,0,142,
  	143,1,0,0,0,143,144,5,15,0,0,144,23,1,0,0,0,145,161,5,20,0,0,146,147,
  	5,11,0,0,147,148,5,18,0,0,148,149,3,26,13,0,149,150,5,21,0,0,150,151,
  	3,28,14,0,151,152,5,19,0,0,152,153,5,29,0,0,153,161,1,0,0,0,154,155,5,
  	11,0,0,155,156,5,18,0,0,156,157,3,26,13,0,157,158,5,19,0,0,158,159,5,
  	29,0,0,159,161,1,0,0,0,160,145,1,0,0,0,160,146,1,0,0,0,160,154,1,0,0,
  	0,161,25,1,0,0,0,162,163,3,32,16,0,163,27,1,0,0,0,164,165,3,32,16,0,165,
  	29,1,0,0,0,166,167,5,30,0,0,167,173,3,34,17,0,168,169,5,17,0,0,169,170,
  	3,34,17,0,170,171,5,16,0,0,171,173,1,0,0,0,172,166,1,0,0,0,172,168,1,
  	0,0,0,173,31,1,0,0,0,174,175,6,16,-1,0,175,176,5,14,0,0,176,177,3,32,
  	16,0,177,178,5,15,0,0,178,184,1,0,0,0,179,180,5,11,0,0,180,184,3,32,16,
  	7,181,184,3,4,2,0,182,184,5,32,0,0,183,174,1,0,0,0,183,179,1,0,0,0,183,
  	181,1,0,0,0,183,182,1,0,0,0,184,199,1,0,0,0,185,186,10,6,0,0,186,187,
  	5,13,0,0,187,198,3,32,16,7,188,189,10,5,0,0,189,190,5,12,0,0,190,198,
  	3,32,16,6,191,192,10,4,0,0,192,193,5,10,0,0,193,198,3,32,16,5,194,195,
  	10,3,0,0,195,196,5,11,0,0,196,198,3,32,16,4,197,185,1,0,0,0,197,188,1,
  	0,0,0,197,191,1,0,0,0,197,194,1,0,0,0,198,201,1,0,0,0,199,197,1,0,0,0,
  	199,200,1,0,0,0,200,33,1,0,0,0,201,199,1,0,0,0,202,203,6,17,-1,0,203,
  	204,5,14,0,0,204,205,3,34,17,0,205,206,5,15,0,0,206,209,1,0,0,0,207,209,
  	3,36,18,0,208,202,1,0,0,0,208,207,1,0,0,0,209,218,1,0,0,0,210,211,10,
  	3,0,0,211,212,5,22,0,0,212,217,3,34,17,4,213,214,10,2,0,0,214,215,5,23,
  	0,0,215,217,3,34,17,3,216,210,1,0,0,0,216,213,1,0,0,0,217,220,1,0,0,0,
  	218,216,1,0,0,0,218,219,1,0,0,0,219,35,1,0,0,0,220,218,1,0,0,0,221,222,
  	3,32,16,0,222,223,3,38,19,0,223,224,3,32,16,0,224,37,1,0,0,0,225,226,
  	7,1,0,0,226,39,1,0,0,0,20,41,45,80,90,99,108,111,122,125,129,138,141,
  	160,172,183,197,199,208,216,218
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  koatParserStaticData = staticData.release();
}

}

KoatParser::KoatParser(TokenStream *input) : KoatParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

KoatParser::KoatParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  KoatParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *koatParserStaticData->atn, koatParserStaticData->decisionToDFA, koatParserStaticData->sharedContextCache, options);
}

KoatParser::~KoatParser() {
  delete _interpreter;
}

const atn::ATN& KoatParser::getATN() const {
  return *koatParserStaticData->atn;
}

std::string KoatParser::getGrammarFileName() const {
  return "Koat.g4";
}

const std::vector<std::string>& KoatParser::getRuleNames() const {
  return koatParserStaticData->ruleNames;
}

const dfa::Vocabulary& KoatParser::getVocabulary() const {
  return koatParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView KoatParser::getSerializedATN() const {
  return koatParserStaticData->serializedATN;
}


//----------------- MainContext ------------------------------------------------------------------

KoatParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::StartContext* KoatParser::MainContext::start() {
  return getRuleContext<KoatParser::StartContext>(0);
}

KoatParser::VardeclContext* KoatParser::MainContext::vardecl() {
  return getRuleContext<KoatParser::VardeclContext>(0);
}

KoatParser::TranssContext* KoatParser::MainContext::transs() {
  return getRuleContext<KoatParser::TranssContext>(0);
}

KoatParser::GoalContext* KoatParser::MainContext::goal() {
  return getRuleContext<KoatParser::GoalContext>(0);
}

KoatParser::SinkContext* KoatParser::MainContext::sink() {
  return getRuleContext<KoatParser::SinkContext>(0);
}


size_t KoatParser::MainContext::getRuleIndex() const {
  return KoatParser::RuleMain;
}

void KoatParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void KoatParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}


std::any KoatParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::MainContext* KoatParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, KoatParser::RuleMain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(40);
      goal();
      break;
    }

    default:
      break;
    }
    setState(43);
    start();
    setState(45);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(44);
      sink();
      break;
    }

    default:
      break;
    }
    setState(47);
    vardecl();
    setState(48);
    transs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FsContext ------------------------------------------------------------------

KoatParser::FsContext::FsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::FsContext::ID() {
  return getToken(KoatParser::ID, 0);
}


size_t KoatParser::FsContext::getRuleIndex() const {
  return KoatParser::RuleFs;
}

void KoatParser::FsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFs(this);
}

void KoatParser::FsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFs(this);
}


std::any KoatParser::FsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitFs(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::FsContext* KoatParser::fs() {
  FsContext *_localctx = _tracker.createInstance<FsContext>(_ctx, getState());
  enterRule(_localctx, 2, KoatParser::RuleFs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    match(KoatParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

KoatParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::VarContext::ID() {
  return getToken(KoatParser::ID, 0);
}


size_t KoatParser::VarContext::getRuleIndex() const {
  return KoatParser::RuleVar;
}

void KoatParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void KoatParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}


std::any KoatParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::VarContext* KoatParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 4, KoatParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(KoatParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GoalContext ------------------------------------------------------------------

KoatParser::GoalContext::GoalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::GoalContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::GoalContext::GOAL() {
  return getToken(KoatParser::GOAL, 0);
}

tree::TerminalNode* KoatParser::GoalContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

tree::TerminalNode* KoatParser::GoalContext::CPX() {
  return getToken(KoatParser::CPX, 0);
}

tree::TerminalNode* KoatParser::GoalContext::TERM() {
  return getToken(KoatParser::TERM, 0);
}


size_t KoatParser::GoalContext::getRuleIndex() const {
  return KoatParser::RuleGoal;
}

void KoatParser::GoalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGoal(this);
}

void KoatParser::GoalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGoal(this);
}


std::any KoatParser::GoalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitGoal(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::GoalContext* KoatParser::goal() {
  GoalContext *_localctx = _tracker.createInstance<GoalContext>(_ctx, getState());
  enterRule(_localctx, 6, KoatParser::RuleGoal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(KoatParser::LPAR);
    setState(55);
    match(KoatParser::GOAL);
    setState(56);
    _la = _input->LA(1);
    if (!(_la == KoatParser::CPX

    || _la == KoatParser::TERM)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(57);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartContext ------------------------------------------------------------------

KoatParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KoatParser::StartContext::LPAR() {
  return getTokens(KoatParser::LPAR);
}

tree::TerminalNode* KoatParser::StartContext::LPAR(size_t i) {
  return getToken(KoatParser::LPAR, i);
}

tree::TerminalNode* KoatParser::StartContext::START() {
  return getToken(KoatParser::START, 0);
}

tree::TerminalNode* KoatParser::StartContext::FS() {
  return getToken(KoatParser::FS, 0);
}

KoatParser::FsContext* KoatParser::StartContext::fs() {
  return getRuleContext<KoatParser::FsContext>(0);
}

std::vector<tree::TerminalNode *> KoatParser::StartContext::RPAR() {
  return getTokens(KoatParser::RPAR);
}

tree::TerminalNode* KoatParser::StartContext::RPAR(size_t i) {
  return getToken(KoatParser::RPAR, i);
}


size_t KoatParser::StartContext::getRuleIndex() const {
  return KoatParser::RuleStart;
}

void KoatParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void KoatParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


std::any KoatParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::StartContext* KoatParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 8, KoatParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(KoatParser::LPAR);
    setState(60);
    match(KoatParser::START);
    setState(61);
    match(KoatParser::LPAR);
    setState(62);
    match(KoatParser::FS);
    setState(63);
    fs();
    setState(64);
    match(KoatParser::RPAR);
    setState(65);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SinkContext ------------------------------------------------------------------

KoatParser::SinkContext::SinkContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KoatParser::SinkContext::LPAR() {
  return getTokens(KoatParser::LPAR);
}

tree::TerminalNode* KoatParser::SinkContext::LPAR(size_t i) {
  return getToken(KoatParser::LPAR, i);
}

tree::TerminalNode* KoatParser::SinkContext::SINK() {
  return getToken(KoatParser::SINK, 0);
}

tree::TerminalNode* KoatParser::SinkContext::FS() {
  return getToken(KoatParser::FS, 0);
}

KoatParser::FsContext* KoatParser::SinkContext::fs() {
  return getRuleContext<KoatParser::FsContext>(0);
}

std::vector<tree::TerminalNode *> KoatParser::SinkContext::RPAR() {
  return getTokens(KoatParser::RPAR);
}

tree::TerminalNode* KoatParser::SinkContext::RPAR(size_t i) {
  return getToken(KoatParser::RPAR, i);
}


size_t KoatParser::SinkContext::getRuleIndex() const {
  return KoatParser::RuleSink;
}

void KoatParser::SinkContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSink(this);
}

void KoatParser::SinkContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSink(this);
}


std::any KoatParser::SinkContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitSink(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::SinkContext* KoatParser::sink() {
  SinkContext *_localctx = _tracker.createInstance<SinkContext>(_ctx, getState());
  enterRule(_localctx, 10, KoatParser::RuleSink);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(KoatParser::LPAR);
    setState(68);
    match(KoatParser::SINK);
    setState(69);
    match(KoatParser::LPAR);
    setState(70);
    match(KoatParser::FS);
    setState(71);
    fs();
    setState(72);
    match(KoatParser::RPAR);
    setState(73);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VardeclContext ------------------------------------------------------------------

KoatParser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::VardeclContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::VardeclContext::VAR() {
  return getToken(KoatParser::VAR, 0);
}

tree::TerminalNode* KoatParser::VardeclContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

std::vector<tree::TerminalNode *> KoatParser::VardeclContext::ID() {
  return getTokens(KoatParser::ID);
}

tree::TerminalNode* KoatParser::VardeclContext::ID(size_t i) {
  return getToken(KoatParser::ID, i);
}


size_t KoatParser::VardeclContext::getRuleIndex() const {
  return KoatParser::RuleVardecl;
}

void KoatParser::VardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardecl(this);
}

void KoatParser::VardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardecl(this);
}


std::any KoatParser::VardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitVardecl(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::VardeclContext* KoatParser::vardecl() {
  VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, getState());
  enterRule(_localctx, 12, KoatParser::RuleVardecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    match(KoatParser::LPAR);
    setState(76);
    match(KoatParser::VAR);
    setState(80);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == KoatParser::ID) {
      setState(77);
      match(KoatParser::ID);
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(83);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranssContext ------------------------------------------------------------------

KoatParser::TranssContext::TranssContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::TranssContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::TranssContext::RULES() {
  return getToken(KoatParser::RULES, 0);
}

tree::TerminalNode* KoatParser::TranssContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

std::vector<KoatParser::TransContext *> KoatParser::TranssContext::trans() {
  return getRuleContexts<KoatParser::TransContext>();
}

KoatParser::TransContext* KoatParser::TranssContext::trans(size_t i) {
  return getRuleContext<KoatParser::TransContext>(i);
}


size_t KoatParser::TranssContext::getRuleIndex() const {
  return KoatParser::RuleTranss;
}

void KoatParser::TranssContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTranss(this);
}

void KoatParser::TranssContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTranss(this);
}


std::any KoatParser::TranssContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitTranss(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::TranssContext* KoatParser::transs() {
  TranssContext *_localctx = _tracker.createInstance<TranssContext>(_ctx, getState());
  enterRule(_localctx, 14, KoatParser::RuleTranss);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(KoatParser::LPAR);
    setState(86);
    match(KoatParser::RULES);
    setState(90);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == KoatParser::ID) {
      setState(87);
      trans();
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(93);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TransContext ------------------------------------------------------------------

KoatParser::TransContext::TransContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::LhsContext* KoatParser::TransContext::lhs() {
  return getRuleContext<KoatParser::LhsContext>(0);
}

KoatParser::ToContext* KoatParser::TransContext::to() {
  return getRuleContext<KoatParser::ToContext>(0);
}

KoatParser::ComContext* KoatParser::TransContext::com() {
  return getRuleContext<KoatParser::ComContext>(0);
}

KoatParser::CondContext* KoatParser::TransContext::cond() {
  return getRuleContext<KoatParser::CondContext>(0);
}


size_t KoatParser::TransContext::getRuleIndex() const {
  return KoatParser::RuleTrans;
}

void KoatParser::TransContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrans(this);
}

void KoatParser::TransContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrans(this);
}


std::any KoatParser::TransContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitTrans(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::TransContext* KoatParser::trans() {
  TransContext *_localctx = _tracker.createInstance<TransContext>(_ctx, getState());
  enterRule(_localctx, 16, KoatParser::RuleTrans);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    lhs();
    setState(96);
    to();
    setState(97);
    com();
    setState(99);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == KoatParser::LBRACK

    || _la == KoatParser::CONDSEP) {
      setState(98);
      cond();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

KoatParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::FsContext* KoatParser::LhsContext::fs() {
  return getRuleContext<KoatParser::FsContext>(0);
}

tree::TerminalNode* KoatParser::LhsContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::LhsContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

std::vector<KoatParser::VarContext *> KoatParser::LhsContext::var() {
  return getRuleContexts<KoatParser::VarContext>();
}

KoatParser::VarContext* KoatParser::LhsContext::var(size_t i) {
  return getRuleContext<KoatParser::VarContext>(i);
}

std::vector<tree::TerminalNode *> KoatParser::LhsContext::COMMA() {
  return getTokens(KoatParser::COMMA);
}

tree::TerminalNode* KoatParser::LhsContext::COMMA(size_t i) {
  return getToken(KoatParser::COMMA, i);
}


size_t KoatParser::LhsContext::getRuleIndex() const {
  return KoatParser::RuleLhs;
}

void KoatParser::LhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLhs(this);
}

void KoatParser::LhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLhs(this);
}


std::any KoatParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::LhsContext* KoatParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 18, KoatParser::RuleLhs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    fs();
    setState(102);
    match(KoatParser::LPAR);
    setState(111);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == KoatParser::ID) {
      setState(103);
      var();
      setState(108);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == KoatParser::COMMA) {
        setState(104);
        match(KoatParser::COMMA);
        setState(105);
        var();
        setState(110);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(113);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComContext ------------------------------------------------------------------

KoatParser::ComContext::ComContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::ComContext::COM() {
  return getToken(KoatParser::COM, 0);
}

tree::TerminalNode* KoatParser::ComContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::ComContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

std::vector<KoatParser::RhsContext *> KoatParser::ComContext::rhs() {
  return getRuleContexts<KoatParser::RhsContext>();
}

KoatParser::RhsContext* KoatParser::ComContext::rhs(size_t i) {
  return getRuleContext<KoatParser::RhsContext>(i);
}

std::vector<tree::TerminalNode *> KoatParser::ComContext::COMMA() {
  return getTokens(KoatParser::COMMA);
}

tree::TerminalNode* KoatParser::ComContext::COMMA(size_t i) {
  return getToken(KoatParser::COMMA, i);
}


size_t KoatParser::ComContext::getRuleIndex() const {
  return KoatParser::RuleCom;
}

void KoatParser::ComContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCom(this);
}

void KoatParser::ComContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCom(this);
}


std::any KoatParser::ComContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitCom(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::ComContext* KoatParser::com() {
  ComContext *_localctx = _tracker.createInstance<ComContext>(_ctx, getState());
  enterRule(_localctx, 20, KoatParser::RuleCom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(129);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KoatParser::COM: {
        enterOuterAlt(_localctx, 1);
        setState(115);
        match(KoatParser::COM);
        setState(116);
        match(KoatParser::LPAR);
        setState(125);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == KoatParser::ID) {
          setState(117);
          rhs();
          setState(122);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == KoatParser::COMMA) {
            setState(118);
            match(KoatParser::COMMA);
            setState(119);
            rhs();
            setState(124);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(127);
        match(KoatParser::RPAR);
        break;
      }

      case KoatParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(128);
        rhs();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsContext ------------------------------------------------------------------

KoatParser::RhsContext::RhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::FsContext* KoatParser::RhsContext::fs() {
  return getRuleContext<KoatParser::FsContext>(0);
}

tree::TerminalNode* KoatParser::RhsContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::RhsContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

std::vector<KoatParser::ExprContext *> KoatParser::RhsContext::expr() {
  return getRuleContexts<KoatParser::ExprContext>();
}

KoatParser::ExprContext* KoatParser::RhsContext::expr(size_t i) {
  return getRuleContext<KoatParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> KoatParser::RhsContext::COMMA() {
  return getTokens(KoatParser::COMMA);
}

tree::TerminalNode* KoatParser::RhsContext::COMMA(size_t i) {
  return getToken(KoatParser::COMMA, i);
}


size_t KoatParser::RhsContext::getRuleIndex() const {
  return KoatParser::RuleRhs;
}

void KoatParser::RhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRhs(this);
}

void KoatParser::RhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRhs(this);
}


std::any KoatParser::RhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitRhs(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::RhsContext* KoatParser::rhs() {
  RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, getState());
  enterRule(_localctx, 22, KoatParser::RuleRhs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    fs();
    setState(132);
    match(KoatParser::LPAR);
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 6442469376) != 0) {
      setState(133);
      expr(0);
      setState(138);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == KoatParser::COMMA) {
        setState(134);
        match(KoatParser::COMMA);
        setState(135);
        expr(0);
        setState(140);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(143);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ToContext ------------------------------------------------------------------

KoatParser::ToContext::ToContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::ToContext::TO() {
  return getToken(KoatParser::TO, 0);
}

tree::TerminalNode* KoatParser::ToContext::MINUS() {
  return getToken(KoatParser::MINUS, 0);
}

tree::TerminalNode* KoatParser::ToContext::LCURL() {
  return getToken(KoatParser::LCURL, 0);
}

KoatParser::LbContext* KoatParser::ToContext::lb() {
  return getRuleContext<KoatParser::LbContext>(0);
}

tree::TerminalNode* KoatParser::ToContext::COMMA() {
  return getToken(KoatParser::COMMA, 0);
}

KoatParser::UbContext* KoatParser::ToContext::ub() {
  return getRuleContext<KoatParser::UbContext>(0);
}

tree::TerminalNode* KoatParser::ToContext::RCURL() {
  return getToken(KoatParser::RCURL, 0);
}

tree::TerminalNode* KoatParser::ToContext::GT() {
  return getToken(KoatParser::GT, 0);
}


size_t KoatParser::ToContext::getRuleIndex() const {
  return KoatParser::RuleTo;
}

void KoatParser::ToContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTo(this);
}

void KoatParser::ToContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTo(this);
}


std::any KoatParser::ToContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitTo(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::ToContext* KoatParser::to() {
  ToContext *_localctx = _tracker.createInstance<ToContext>(_ctx, getState());
  enterRule(_localctx, 24, KoatParser::RuleTo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(145);
      match(KoatParser::TO);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(146);
      match(KoatParser::MINUS);
      setState(147);
      match(KoatParser::LCURL);
      setState(148);
      lb();
      setState(149);
      match(KoatParser::COMMA);
      setState(150);
      ub();
      setState(151);
      match(KoatParser::RCURL);
      setState(152);
      match(KoatParser::GT);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(154);
      match(KoatParser::MINUS);
      setState(155);
      match(KoatParser::LCURL);
      setState(156);
      lb();
      setState(157);
      match(KoatParser::RCURL);
      setState(158);
      match(KoatParser::GT);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LbContext ------------------------------------------------------------------

KoatParser::LbContext::LbContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::ExprContext* KoatParser::LbContext::expr() {
  return getRuleContext<KoatParser::ExprContext>(0);
}


size_t KoatParser::LbContext::getRuleIndex() const {
  return KoatParser::RuleLb;
}

void KoatParser::LbContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLb(this);
}

void KoatParser::LbContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLb(this);
}


std::any KoatParser::LbContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitLb(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::LbContext* KoatParser::lb() {
  LbContext *_localctx = _tracker.createInstance<LbContext>(_ctx, getState());
  enterRule(_localctx, 26, KoatParser::RuleLb);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UbContext ------------------------------------------------------------------

KoatParser::UbContext::UbContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::ExprContext* KoatParser::UbContext::expr() {
  return getRuleContext<KoatParser::ExprContext>(0);
}


size_t KoatParser::UbContext::getRuleIndex() const {
  return KoatParser::RuleUb;
}

void KoatParser::UbContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUb(this);
}

void KoatParser::UbContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUb(this);
}


std::any KoatParser::UbContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitUb(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::UbContext* KoatParser::ub() {
  UbContext *_localctx = _tracker.createInstance<UbContext>(_ctx, getState());
  enterRule(_localctx, 28, KoatParser::RuleUb);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

KoatParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::CondContext::CONDSEP() {
  return getToken(KoatParser::CONDSEP, 0);
}

KoatParser::FormulaContext* KoatParser::CondContext::formula() {
  return getRuleContext<KoatParser::FormulaContext>(0);
}

tree::TerminalNode* KoatParser::CondContext::LBRACK() {
  return getToken(KoatParser::LBRACK, 0);
}

tree::TerminalNode* KoatParser::CondContext::RBRACK() {
  return getToken(KoatParser::RBRACK, 0);
}


size_t KoatParser::CondContext::getRuleIndex() const {
  return KoatParser::RuleCond;
}

void KoatParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void KoatParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}


std::any KoatParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::CondContext* KoatParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 30, KoatParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KoatParser::CONDSEP: {
        enterOuterAlt(_localctx, 1);
        setState(166);
        match(KoatParser::CONDSEP);
        setState(167);
        formula(0);
        break;
      }

      case KoatParser::LBRACK: {
        enterOuterAlt(_localctx, 2);
        setState(168);
        match(KoatParser::LBRACK);
        setState(169);
        formula(0);
        setState(170);
        match(KoatParser::RBRACK);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

KoatParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::ExprContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

std::vector<KoatParser::ExprContext *> KoatParser::ExprContext::expr() {
  return getRuleContexts<KoatParser::ExprContext>();
}

KoatParser::ExprContext* KoatParser::ExprContext::expr(size_t i) {
  return getRuleContext<KoatParser::ExprContext>(i);
}

tree::TerminalNode* KoatParser::ExprContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

tree::TerminalNode* KoatParser::ExprContext::MINUS() {
  return getToken(KoatParser::MINUS, 0);
}

KoatParser::VarContext* KoatParser::ExprContext::var() {
  return getRuleContext<KoatParser::VarContext>(0);
}

tree::TerminalNode* KoatParser::ExprContext::INT() {
  return getToken(KoatParser::INT, 0);
}

tree::TerminalNode* KoatParser::ExprContext::EXP() {
  return getToken(KoatParser::EXP, 0);
}

tree::TerminalNode* KoatParser::ExprContext::TIMES() {
  return getToken(KoatParser::TIMES, 0);
}

tree::TerminalNode* KoatParser::ExprContext::PLUS() {
  return getToken(KoatParser::PLUS, 0);
}


size_t KoatParser::ExprContext::getRuleIndex() const {
  return KoatParser::RuleExpr;
}

void KoatParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void KoatParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any KoatParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


KoatParser::ExprContext* KoatParser::expr() {
   return expr(0);
}

KoatParser::ExprContext* KoatParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  KoatParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  KoatParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, KoatParser::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(183);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KoatParser::LPAR: {
        setState(175);
        match(KoatParser::LPAR);
        setState(176);
        expr(0);
        setState(177);
        match(KoatParser::RPAR);
        break;
      }

      case KoatParser::MINUS: {
        setState(179);
        match(KoatParser::MINUS);
        setState(180);
        expr(7);
        break;
      }

      case KoatParser::ID: {
        setState(181);
        var();
        break;
      }

      case KoatParser::INT: {
        setState(182);
        match(KoatParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(199);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(197);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(185);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(186);
          match(KoatParser::EXP);
          setState(187);
          expr(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(188);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(189);
          match(KoatParser::TIMES);
          setState(190);
          expr(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(191);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(192);
          match(KoatParser::PLUS);
          setState(193);
          expr(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(194);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(195);
          match(KoatParser::MINUS);
          setState(196);
          expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(201);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FormulaContext ------------------------------------------------------------------

KoatParser::FormulaContext::FormulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::FormulaContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

std::vector<KoatParser::FormulaContext *> KoatParser::FormulaContext::formula() {
  return getRuleContexts<KoatParser::FormulaContext>();
}

KoatParser::FormulaContext* KoatParser::FormulaContext::formula(size_t i) {
  return getRuleContext<KoatParser::FormulaContext>(i);
}

tree::TerminalNode* KoatParser::FormulaContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

KoatParser::LitContext* KoatParser::FormulaContext::lit() {
  return getRuleContext<KoatParser::LitContext>(0);
}

tree::TerminalNode* KoatParser::FormulaContext::AND() {
  return getToken(KoatParser::AND, 0);
}

tree::TerminalNode* KoatParser::FormulaContext::OR() {
  return getToken(KoatParser::OR, 0);
}


size_t KoatParser::FormulaContext::getRuleIndex() const {
  return KoatParser::RuleFormula;
}

void KoatParser::FormulaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormula(this);
}

void KoatParser::FormulaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormula(this);
}


std::any KoatParser::FormulaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitFormula(this);
  else
    return visitor->visitChildren(this);
}


KoatParser::FormulaContext* KoatParser::formula() {
   return formula(0);
}

KoatParser::FormulaContext* KoatParser::formula(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  KoatParser::FormulaContext *_localctx = _tracker.createInstance<FormulaContext>(_ctx, parentState);
  KoatParser::FormulaContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, KoatParser::RuleFormula, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(208);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(203);
      match(KoatParser::LPAR);
      setState(204);
      formula(0);
      setState(205);
      match(KoatParser::RPAR);
      break;
    }

    case 2: {
      setState(207);
      lit();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(218);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(216);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<FormulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleFormula);
          setState(210);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(211);
          match(KoatParser::AND);
          setState(212);
          formula(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<FormulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleFormula);
          setState(213);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(214);
          match(KoatParser::OR);
          setState(215);
          formula(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(220);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LitContext ------------------------------------------------------------------

KoatParser::LitContext::LitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<KoatParser::ExprContext *> KoatParser::LitContext::expr() {
  return getRuleContexts<KoatParser::ExprContext>();
}

KoatParser::ExprContext* KoatParser::LitContext::expr(size_t i) {
  return getRuleContext<KoatParser::ExprContext>(i);
}

KoatParser::RelopContext* KoatParser::LitContext::relop() {
  return getRuleContext<KoatParser::RelopContext>(0);
}


size_t KoatParser::LitContext::getRuleIndex() const {
  return KoatParser::RuleLit;
}

void KoatParser::LitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLit(this);
}

void KoatParser::LitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLit(this);
}


std::any KoatParser::LitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitLit(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::LitContext* KoatParser::lit() {
  LitContext *_localctx = _tracker.createInstance<LitContext>(_ctx, getState());
  enterRule(_localctx, 36, KoatParser::RuleLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    expr(0);
    setState(222);
    relop();
    setState(223);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelopContext ------------------------------------------------------------------

KoatParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::RelopContext::LT() {
  return getToken(KoatParser::LT, 0);
}

tree::TerminalNode* KoatParser::RelopContext::LEQ() {
  return getToken(KoatParser::LEQ, 0);
}

tree::TerminalNode* KoatParser::RelopContext::EQ() {
  return getToken(KoatParser::EQ, 0);
}

tree::TerminalNode* KoatParser::RelopContext::GT() {
  return getToken(KoatParser::GT, 0);
}

tree::TerminalNode* KoatParser::RelopContext::GEQ() {
  return getToken(KoatParser::GEQ, 0);
}

tree::TerminalNode* KoatParser::RelopContext::NEQ() {
  return getToken(KoatParser::NEQ, 0);
}


size_t KoatParser::RelopContext::getRuleIndex() const {
  return KoatParser::RuleRelop;
}

void KoatParser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void KoatParser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}


std::any KoatParser::RelopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitRelop(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::RelopContext* KoatParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 38, KoatParser::RuleRelop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1056964608) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool KoatParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 16: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 17: return formulaSempred(antlrcpp::downCast<FormulaContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool KoatParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool KoatParser::formulaSempred(FormulaContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void KoatParser::initialize() {
  ::antlr4::internal::call_once(koatParserOnceFlag, koatParserInitialize);
}
