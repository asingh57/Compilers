#include "BlockAllocator.h"

std::map<std::string, int> Block::blockNameToNumberMap = {};

int Block::blockCounter = 0;

std::vector<Block*> Block::blockList = {};

std::map<std::string, std::vector<int>> Block::functionReturnCallNameToNumberMap;