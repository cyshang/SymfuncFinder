#include "FuncGroup.h"
#include "FuncInfo.h"

FuncGroup::FuncGroup(const int & _element) :elem(_element), nFunc(0) {}

FuncGroup::~FuncGroup() {}

void FuncGroup::Construct(istream & fin, const int & _nFunc)
{
	nFunc = _nFunc;

	string line;
	funcinfo.clear();
	for (int iFunc = 0; iFunc < nFunc; ++iFunc) {
		std::getline(fin, line);
		funcinfo.push_back(line);
	}

#ifdef DEBUG_FUNCGROUP

	OutputInfo(debug);

#endif // DEBUG_FUNCGROUP

}

void FuncGroup::OutputInfo(ostream & fout)
{
	fout << parameter.num_to_elem[elem] << " " << nFunc << endl;

	for (int iFunc = 0; iFunc < nFunc; ++iFunc) {
		fout << funcinfo[iFunc].PrintFuncInfo() << endl;
	}
}
