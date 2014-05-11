//uses int-func


struct procval{
	char var;
	Expression* body;
};

template <class value>   //need to figure out how templates work

class Environment{
	values = value*[100];
	variables = char*[100];

	Environment(value vals, char* vars);

	Environmnet* extendenv(char var, value val, Environment* env);
	Environment* extendenvrec(char var1, char var2, Expression* exp, Environment* env);
	value applyenv(char var, Environment* env);	
};

Environment::Environment(value vals, char* vars){
	values = vals;
	variables = vars;
}

Environment* Environment::extendenv(char var, value val, Environment* env){
	len = findlength(env.values);
	env.values[len] = val;
	env.variables[len] = var;
	return env;
}

Environment* Environment::extendenvrec(char var1, char var2, Expression* exp, Environment* env){

	return env;
}

value Environment::applyenv(char var, Environment* env){
	if(varin(var, env)){
		value val = findvar(var, env)
		return val;
	}
	else{
		cout << "ERROR. No binding for " << var << endl;
	}
	
}

//findlength function
//varin function - returns true if variable is in environment
//findvar fundtion - returns value of variable


