#ifndef FUNCTYPE_H_
#define FUNCTYPE_H_

#include "global.h"
#ifdef DEBUG_MODE
//#define DEBUG_FUNCINFO
#endif // DEBUG_MODE

constexpr int func_parameter = 4;

struct FuncInfo 
{
	double funcParam[func_parameter];
	double copyParam[func_parameter];
	//	G1 : {Rc}
	//	G2 : {Rc, Rs, eta}
	//	G3 : {Rc, lambda, eta, xi}
	//	G4 : {Rc, lambda, eta, xi}
	int symfunc;
	int adj_elem[2];

	FuncInfo(const std::string & str);
	void GetFuncInfo(const std::string & str);
	void Backup();
	void Restore();
	std::string PrintFuncInfo() const;
	std::string OutputPES();
};

#endif // !FUNCTYPE_H