#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#include "State.h"
#include "Action.h"

struct SearchNode {
	SearchNode(const State& s)	
		: state_(s)
		, parentNode_(nullptr)
		, action_("")
		, pathCost_(0)
		, depth_(0) { }

	SearchNode(const State& s, Action a, const SearchNode* p) 	
		: state_(s)
		, parentNode_(p)
		, action_(a)
		, pathCost_(1)
		, depth_(0) { }

	State state_;
	const SearchNode* parentNode_;
	Action action_;
	int pathCost_;
	int depth_;
};

#endif // NODE_H