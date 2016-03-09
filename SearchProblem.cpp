#include "SearchProblem.h"

const State SearchProblem::intialState = State(3, 3, 0, 0, 0); 	//"L:3m,3c,b-R:0m,0c"
const State SearchProblem::goalState = State(0, 0, 3, 3, 1); 	//"L:0m,0c-R:3m,3c,b"


SearchProblem::SearchProblem() {
}

/* -- */
SearchProblem::SuccessorList SearchProblem::GetSuccessorList(State actualState) const {
	SuccessorList newStates;
	std::vector<Action> actions = {"2m", "1m1c", "2c", "1m", "1c"};
	int *ms, *me, *cs, *ce, *b;
	// starting/ending edge
	for (int i = 0; i < 5; ++i) {
		State tmpState = actualState;
		b = &tmpState.b_;
		if (tmpState.b_) { // right
			ms = &tmpState.mr_;
			cs = &tmpState.cr_;
			me = &tmpState.ml_;
			ce = &tmpState.cl_;
		}
		else {
			me = &tmpState.mr_;
			ce = &tmpState.cr_;
			ms = &tmpState.ml_;
			cs = &tmpState.cl_;
		}
		switch (i) {
			// 2 missionaries
			case 0: {
				*ms -= 2;
				*me += 2;
				break;
			}
			// 1 missionary, 1 cannibal
			case 1: {
				*ms -= 1;
				*me += 1;
				*cs -= 1;
				*ce += 1;
				break;
			}
			// 2 cannibals
			case 2: {
				*cs -= 2;
				*ce += 2;
				break;
			}
			// 1 missionary
			case 3: {
				*ms -= 1;
				*me += 1;
				break;
			}
			// 1 cannibal
			case 4: {
				*cs -= 1;
				*ce += 1;
				break;
			}
		}

		*b = (*b == 0 ? 1 : 0);
		State newState(	tmpState.ml_, tmpState.cl_, 
						tmpState.mr_, tmpState.cr_, 
						tmpState.b_);
		if (RulesCheck(newState))
			newStates.push_back(make_pair(actions[i], newState));
	}
	return newStates;
}

/* -- */
bool SearchProblem::RulesCheck(const State& state) const {
	return !((state.ml_ < state.cl_ && 0 < state.ml_) 
			|| (state.mr_ < state.cr_ && 0 < state.mr_))
			&& (state.ml_ >=0 && state.mr_ >=0 && state.cl_ >=0 && state.cr_ >= 0);

}


bool SearchProblem::TestGoal(State actualState) const {
	return actualState == goalState;
}


State SearchProblem::GetInitialState() const {
	return intialState;
}


