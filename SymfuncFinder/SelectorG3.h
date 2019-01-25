#ifndef SELECTORG3
#define SELECTORG3

#include "SelectorBase.h"

struct SelectorG3 :public SelectorBase
{
	int central_elem;
	array<int, 2> adj_elem;
	vector<vector<array<int, 3>>> trav_list;

	SelectorG3(const int & central, const int & adj);
	virtual void ConstrPool();
};

#endif