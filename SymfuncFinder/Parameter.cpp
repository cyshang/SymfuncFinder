#include <iostream>
#include <sstream>
#include "Parameter.h"

using std::string;
using std::istringstream;
using std::getline;
using std::cout;
using std::endl;

Parameter::Parameter() :IfLoadSample(false)
{
	function_table.insert(Str_to_Func::value_type("run_mode", &Parameter::get_run_mode));
	function_table.insert(Str_to_Func::value_type("select_mode", &Parameter::get_select_mode));
	function_table.insert(Str_to_Func::value_type("random_seed", &Parameter::get_random_seed));
	function_table.insert(Str_to_Func::value_type("nSample", &Parameter::get_nSample));
	function_table.insert(Str_to_Func::value_type("nElement", &Parameter::get_nElement));
	function_table.insert(Str_to_Func::value_type("totAtom", &Parameter::get_totAtom));
	function_table.insert(Str_to_Func::value_type("nAtom", &Parameter::get_nAtom));
	function_table.insert(Str_to_Func::value_type("nFind", &Parameter::get_nFind));
	function_table.insert(Str_to_Func::value_type("element_list", &Parameter::get_element_list));
	function_table.insert(Str_to_Func::value_type("atom_list", &Parameter::get_atom_list));
	function_table.insert(Str_to_Func::value_type("filter_threshold", &Parameter::get_filter_threshold));
	function_table.insert(Str_to_Func::value_type("coef_threshold", &Parameter::get_coef_threshold));
	function_table.insert(Str_to_Func::value_type("range_threshold", &Parameter::get_range_threshold));
	//--------------------
	function_table.insert(Str_to_Func::value_type("fFunctionSave", &Parameter::getFunctionSave));
	function_table.insert(Str_to_Func::value_type("fFuncPrototype", &Parameter::getFuncPrototype));
	function_table.insert(Str_to_Func::value_type("fMoleculeData", &Parameter::getMoleculeData));
	//

	function_table.insert(Str_to_Func::value_type("/input_folder/", &Parameter::get_input_folder));
	function_table.insert(Str_to_Func::value_type("/output_folder/", &Parameter::get_output_folder));

}

void Parameter::GetParameter(std::istream & in)
{
	string line, var;
	istringstream getVar;
	while (getline(in, line)) {

		if (line.empty() || line[0] == '#' || line[0] == ' ' || line[0] == '\r')
			continue;
		getVar.clear();
		getVar.str(line);
		getVar >> var;
		if (function_table.find(var) == function_table.end()) {
			cout << "Counld not recognize key word: " << var << endl;
		}
		else {
			(this->*function_table[var])(getVar);
		}
	}
}

void Parameter::OutputDebug(std::ostream & out)
{
	out << "run_mode: " << run_mode << endl;
	out << "select_mode: " << select_mode << endl;
	out << "nSample: " << nSample << endl;
	out << "nElement: " << nElement << endl;
	out << "totAtom: " << totAtom << endl;
	out << "nAtom:" << endl;
	for (int i = 0; i < nElement; ++i) {
		out << "Element" << i << ", " << "nAtom = " << nAtom[i] << endl;
	}
	out << "nFind: " << nFind << endl;
	out << "element list:" << endl;
	for (int i = 0; i < nElement; ++i) {
		out << num_to_elem[i] << "<->" << elem_to_num[num_to_elem[i]] << endl;
	}
	out << "atom list:" << endl;
	for (int i = 0; i < totAtom; ++i) {
		out << atom_list[i] << " ";
	}
	out << endl;
	out << "filter_threshold: " << filter_threshold << endl;
	out << "coef_threshold: " << coef_threshold << endl;

	out << "fFunctionSave: " << fFunctionSave << endl;
	out << "fFuncPrototype: " << fFuncPrototype << endl;
	out << "fMoleculeData: " << fMoleculeData << endl;

	out << "input_folder: " << input_folder << endl;
	out << "output_folder: " << output_folder << endl;
}