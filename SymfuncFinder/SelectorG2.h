#ifndef SELECTORG2
#define SELECTORG2

#include "SelectorBase.h"

struct SelectorG2 :public SelectorBase
{
	int central_elem;
	int adj_elem;
	vector<vector<array<int, 2>>> trav_list;
	
	SelectorG2(const int & central, const int & adj);
	virtual void ConstrPool();
};

#endif