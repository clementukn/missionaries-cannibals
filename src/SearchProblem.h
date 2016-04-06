#ifndef SEARCHPROBLEM_H
#define SEARCHPROBLEM_H

#include <string>
#include <map>
#include <set>
#include "State.h"
#include "Action.h"

class SearchProblem {
public:
	using Successor = std::pair<Action, State>;
	using SuccessorList = std::vector<Successor>;

	SearchProblem();
	~SearchProblem() { }
	
	SuccessorList GetSuccessorList(State actualState) const;
	State GetInitialState() const;
	bool TestGoal(State actualState) const;
	bool RulesCheck(const State& state) const;

private:
	static const State intialState;
	static const State goalState;
};

#endif // SEARCHPROBLEM_H