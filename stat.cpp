#include "stat.h"
std::vector<Stat*> Stat::statStack = {};

int Stat::nameCounter=0;


std::vector<ASTNode*> ASTNode::astStack={};

std::vector<std::string> Stat::endList={};

int StatBreak::loopCounter = 0;
