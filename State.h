#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>
#include <sstream>

struct State {
	State(int ml, int cl, int mr, int cr, int b);
	~State() { }

	bool operator==(const State& s1);
	std::string toString() const;

	// boat position (0:left, 1:right)
	int b_;
	// missionaries left side
	int ml_;
	// cannibals left sides
	int cl_;
	// missionaries right side
	int mr_;
	// cannibals right sides
	int cr_;
};

typedef std::vector<State> StateSet;


#endif // STATE_H