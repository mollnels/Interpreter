#include "expression.cpp"

template <class VALUE> 
class Environment{
	VALUE* values[100];
	char* variables[100];

	Environment(VALUE* vals, char* vars);

	Environment* extendenv(char var, VALUE val, Environment<VALUE>* env);
	//Environment* extendenvrec(char var1, char var2, Expression* exp, Environment* env);
	VALUE applyenv(char var, Environment* env);
	bool varin(char var, Environment* env);
	VALUE findvar(char var, Environment* env);	
};

template <class VALUE> 
Environment<VALUE>::Environment(VALUE* vals, char* vars){
	values = vals;
	variables = vars;
}
template <class VALUE> 
Environment<VALUE>* Environment<VALUE>::extendenv(char var, VALUE val, Environment* env){
	int len = length(env->values);
	env->values[len] = val;
	env->variables[len] = var;
	return env;
}

// Environment* Environment::extendenvrec(char var1, char var2, Expression* exp, Environment* env){

// 	return env;
// }

template <class VALUE> 
bool Environment<VALUE>::varin(char var, Environment* env){
	for (int i = 0; i <= length(env->variables); ++i) {
		if(env->variables[i] == var) return true;
	}

	return false;
}

template <class VALUE> 
VALUE Environment<VALUE>::findvar(char var, Environment* env){
	for (int i = 0; i <= length(env->variables); ++i) {
		if(env->variables[i] == var){
			return env->values[i];
		}
	}	
}

template <class VALUE> 
VALUE Environment<VALUE>::applyenv(char var, Environment* env){
	if(varin(var, env)){
		VALUE val = findvar(var, env);
		return val;
	}
	else{
		cout << "ERROR. No binding for " << var << endl;
	}
	
}



//findlength function
//varin function - returns true if variable is in environment
//findvar fundtion - returns value of variable


