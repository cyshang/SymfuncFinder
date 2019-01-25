#ifndef PARAMETER_H_
#define PARAMETER_H_

#include <map>
#include <vector>
#include <string>

//--------Typedef--------
typedef std::map<std::string, int> Str_to_Int;
typedef std::map<int, std::string> Int_to_Str;

struct Parameter
{
	typedef void(Parameter::*pFunc)(std::istream & in);
	typedef std::map<std::string, pFunc> Str_to_Func;

	Str_to_Func function_table;

	//========== Run mode ==========
	std::string run_mode;
	void get_run_mode(std::istream & in) { in >> run_mode; }

	//========== Select mode ==========
	std::string select_mode;
	void get_select_mode(std::istream & in) { in >> select_mode; }

	//========== nSample ==========
	long nSample; //Number of Samples in Data

	//========== nElement ==========
	int nElement;	//	The number of elements in this system

	//========== Element list ==========
	Str_to_Int elem_to_num;	//	A map convert an element's name into it's number
	Int_to_Str num_to_elem;	//	A map convert an element's number into it's name

	//========== totAtom ==========
	int totAtom;				// The total number of atoms

	//========== nAtom ==========
	std::vector<int> nAtom;		// The number of atoms for each element

	//========== Atom list ==========
	std::vector<int> atom_list;

	double cutoff;
	bool IfG1;
	bool IfG2;
	bool IfG3;
	bool IfG4;
	size_t pool_size;

	//========== nFind ==========
	int nFind;
	void get_nFind(std::istream & in) { in >> nFind; }

	//========== Filter threshold ==========
	double filter_threshold;
	void get_filter_threshold(std::istream & in) {
		in >> filter_threshold;
	}

	//========== Corrcoef threshold ==========
	double coef_threshold;
	void get_coef_threshold(std::istream & in) {
		in >> coef_threshold;
	}

	//========== File Name ==========

	std::string fFunctionSave;
	void getFunctionSave(std::istream & in) { in >> fFunctionSave; }

	std::string fFuncPrototype;
	void getFuncPrototype(std::istream & in) { in >> fFuncPrototype; }

	std::string fMoleculeData; // The original data in cartesian coordinates
	void getMoleculeData(std::istream & in) { in >> fMoleculeData; }

	//--------Folder Address--------

	std::string input_folder;
	void get_input_folder(std::istream & in) {
		in >> input_folder;
		if (input_folder == "NULL")
			input_folder = "";
	}

	std::string output_folder;
	void get_output_folder(std::istream & in) {
		in >> output_folder;
		if (output_folder == "NULL")
			output_folder = "";
	}

	Parameter();
	~Parameter() {}
	void GetParameter(std::istream & in);
	void OutputDebug(std::ostream & out);
};

#endif // !PARAMETER_H_