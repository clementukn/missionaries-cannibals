#ifndef SOLVE_H
#define SOLVE_H

#include "SearchProblem.h"
#include "SearchNode.h"
#include <deque>
#include <memory>
#include <string>

using SearchNodesList = std::deque<std::shared_ptr<SearchNode>>;

std::string displaySate(const State& s);
std::string pathTo(const SearchNode* node);
std::string treeSearch(const SearchProblem& problem);
std::shared_ptr<SearchNode> selectFrom(SearchNodesList& fringe);
SearchNodesList expand(const SearchProblem& problem, const SearchNode* currNode);

#endif