#include "State.h"


State::State(int ml, int cl, int mr, int cr, int b) 
		: ml_(ml)
		, cl_(cl)
		, mr_(mr)
		, cr_(cr)
		, b_(b) { }


bool State::operator==(const State& s1) {
	return 	b_ == s1.b_
			&& ml_ == s1.ml_ && cl_ == s1.cl_
			&& mr_ == s1.mr_ && cr_ == s1.cr_;
}


std::string State::toString() const {
	std::ostringstream ss;
	ss 	<< "L:" << ml_ << "m," << cl_ << "c";
	if (b_ == 0) ss << ",b";
	ss << "-R:" << mr_ << "m," << cr_ << "c";
	if (b_ == 1) ss << ",b";
	return ss.str();
}


