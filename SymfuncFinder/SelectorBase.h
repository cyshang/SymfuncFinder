#ifndef SELECTORBASE_H_
#define SELECTORBASE_H_

#include "global.h"
#include "ParameterUnit.h"

struct SelectorBase
{
	vector<ParameterUnit> param_pool;
	vector<size_t> select_set;

	virtual void ConstrPool() = 0;
};

#endif