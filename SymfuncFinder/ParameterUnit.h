#ifndef PARAMETERUNIT_H_
#define PARAMETERUNIT_H_

#include "global.h"
#include <Eigen/Core>

struct ParameterUnit
{
	std::array<double, 2> param;
	Eigen::MatrixXd data;

	ParameterUnit(const size_t & _nSample, const int & _nAtom) :param{ 0,0 }, data(_nSample, _nAtom){}
	inline void GetParam(const std::array<double, 2> & p) { param = p; }
	inline double norm() { return (data.colwise().norm()).sum() / data.cols(); }
	void normalize()
	{	
		Eigen::RowVectorXd mean = data.colwise().mean();
		data = (data.array().rowwise() - mean.array()) / data.colwise().norm().array();
	}

	inline double corrcoef(const ParameterUnit & p) { return (data.array()*p.data.array()).colwise().sum().mean(); }
};

#endif