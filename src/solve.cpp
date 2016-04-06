#include <ctime>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include "solve.h"
#include "SearchProblem.h"
#include "SearchNode.h"


using namespace std;
unordered_map<string, shared_ptr<SearchNode>>  nodesHistory;


// get the list of states/action that get to the current state
string pathTo(const SearchNode* node) {
	string result = "";
	int count = 0;
	while (node->parentNode_ != nullptr) {
		result = "\n" + node->action_ + "->" + node->state_.toString() + result;
		node = node->parentNode_;
		++count;
	}
	return node->state_.toString() + result;
}


// A* Greedy
// find a solution and print the list of states to get to it
string treeSearch(const SearchProblem& problem) {
	SearchNodesList fringe;
	auto initialNode = make_shared<SearchNode>(problem.GetInitialState());
	nodesHistory.insert(make_pair(initialNode->state_.toString(), initialNode));
	fringe.push_back(initialNode);

	while (!fringe.empty()) {
		auto currNode = selectFrom(fringe);
		if (problem.TestGoal(currNode->state_))
			return pathTo(currNode.get());
		SearchNodesList newNodes = expand(problem, currNode.get());
		for (auto& node : newNodes) {
			nodesHistory.insert(make_pair(node->state_.toString(), node));
			fringe.push_back(node);
		}
	}
	return "No solution!";
}


// Return the new possible states it can get to from the current state
SearchNodesList expand(const SearchProblem& problem, const SearchNode* currNode) {	
	SearchNodesList newNodes;
	auto mySuccessors = problem.GetSuccessorList(currNode->state_);
	for (auto& successor : mySuccessors) {
		if (nodesHistory.find(successor.second.toString()) == nodesHistory.end()) {
			newNodes.push_back(make_shared<SearchNode>(successor.second, successor.first, currNode));
		}
	}
	return newNodes;
}


// Has to keep track of selected nodes for deterministic solution
shared_ptr<SearchNode> selectFrom(SearchNodesList& fringe) {
	auto node = fringe.front();
	fringe.pop_front();	
	return node;
}


int main() {
	clock_t start = clock();
	SearchProblem canMisPb;
	cout << treeSearch(canMisPb) << endl;
	clock_t end = clock();
	cout << "Program solved in : " << double(end) - start  << '\n';
	return 0;
}



