#include "SelectorG2.h"

SelectorG2::SelectorG2(const int & central, const int & adj)
	:central_elem{central}, adj_elem{adj}
{
	trav_list.resize(parameter.nAtom[central_elem]);
	
	for (int i = 0; i < parameter.totAtom; ++i) {
		if (parameter.atom_list[i] == central_elem) {
			for (int j = 0; j < parameter.totAtom; ++j) {
				if (parameter.atom_list[j] == adj_elem && i != j) {
					
				}
			}
		}
	}

}