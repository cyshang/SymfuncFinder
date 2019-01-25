#ifndef MOLECULE_H_
#define MOLECULE_H_

#include "global.h"
#include <Eigen/Core>

#ifdef DEBUG_MODE
//#define DEBUG_MOLECULE
#endif // DEBUG_MODE


struct Molecule {

	double energy;
	Eigen::MatrixXd X;
	Eigen::MatrixXd R;
	Eigen::MatrixXd fc;
	std::vector<Eigen::MatrixXd> cos0;
	std::vector<Eigen::MatrixXd> g3_sum;
	std::vector<Eigen::MatrixXd> g4_sum;

	Molecule();
	~Molecule();

	void CalMidValue();
	void OutputAtom(std::ostream & out);
};

istream & operator >> (istream &, const Molecule &);

#endif // !MOLECULE_H_