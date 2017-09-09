#pragma once


#include "Function.h"
#include "FunctionContext.h"
#include "Config.h"
#include <iostream>

typedef std::map<std::string, CFunction> dataFunctions;


class CCalculator : public IFunctionContext
{
public:
	CCalculator() = default;
	bool PrintVariables();
	bool PrintFunctions();
	bool Print(std::string const &name);
	bool AddVariable(std::string const & var, double val = NAN);
	bool AddFunction(Vector const &inst);
	bool AssignValToVar(std::string const & var1, std::string const & var2);
	bool AssignValToVar(std::string const & var1, double val);
	double GetValue(std::string const &var);
	double Calculate(std::string const &variable) override;
	bool GetValueVariable(std::string const &var, double &number);
	
private:
	DataVariables m_variables;
	dataFunctions m_functions;
};