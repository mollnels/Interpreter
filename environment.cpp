#include "expression.cpp"

template <class VALUE1, class VALUE2, class VALUE3> 
class Environment{
public:
	VALUE1* values1[100];
	char* variables1[100];
	VALUE2* values2[100];
	char* variables2[100];
	VALUE3* values3[100];
	char* variables3[100];

	Environment();

	Environment* extendenv(char var, VALUE1 val, Environment<VALUE1, VALUE2, VALUE3>* env);
	Environment* extendenv(char var, VALUE2 val, Environment<VALUE1, VALUE2, VALUE3>* env);
	Environment* extendenv(char var, VALUE3 val, Environment<VALUE1, VALUE2, VALUE3>* env);

	//Environment* extendenvrec(char var1, char var2, Expression* exp, Environment* env);
	bool i;
	bool b;
	bool p;
	VALUE1 applyenvi(char var, Environment<VALUE1, VALUE2, VALUE3>* env);
	VALUE2 applyenvb(char var, Environment<VALUE1, VALUE2, VALUE3>* env);
	VALUE3 applyenvp(char var, Environment<VALUE1, VALUE2, VALUE3>* env);

	bool varin(char var, Environment<VALUE1, VALUE2, VALUE3>* env);

	VALUE1 findvari(char var, Environment<VALUE1, VALUE2, VALUE3>* env);
	VALUE2 findvarb(char var, Environment<VALUE1, VALUE2, VALUE3>* env);	
	VALUE3 findvarp(char var, Environment<VALUE1, VALUE2, VALUE3>* env);	

	int findlength(char* vars);
};




template <class VALUE1, class VALUE2, class VALUE3> 
Environment<VALUE1, VALUE2, VALUE3>::Environment(){
	for (int i = 0; i < 100; ++i)
	{
		values1[i] = '\0';
		variables1[i] = '\0';
		values2[i] = '\0';
		variables2[i] = '\0';
		values3[i] = '\0';
		variables3[i] = '\0';
	}
}




template <class VALUE1, class VALUE2, class VALUE3> 
int Environment<VALUE1, VALUE2, VALUE3>::findlength(char* vars){
	int len = 0;
	while(vars[i] != '\0'){
		len++;
	}
	return len;
}




template <class VALUE1, class VALUE2, class VALUE3> 
Environment<VALUE1, VALUE2, VALUE3>* Environment<VALUE1, VALUE2, VALUE3>::extendenv(char var, VALUE1 val, Environment* env){
	int len = findlength(env->values1);
	env->values1[len] = val;
	env->variables1[len] = var;
	return env;
}

template <class VALUE1, class VALUE2, class VALUE3> 
Environment<VALUE1, VALUE2, VALUE3>* Environment<VALUE1, VALUE2, VALUE3>::extendenv(char var, VALUE2 val, Environment* env){
	int len = findlength(env->values2);
	env->values2[len] = val;
	env->variables2[len] = var;
	return env;
}
template <class VALUE1, class VALUE2, class VALUE3> 
Environment<VALUE1, VALUE2, VALUE3>* Environment<VALUE1, VALUE2, VALUE3>::extendenv(char var, VALUE3 val, Environment* env){
	int len = findlength(env->values3);
	env->values3[len] = val;
	env->variables3[len] = var;
	return env;
}

// Environment* Environment::extendenvrec(char var1, char var2, Expression* exp, Environment* env){

// 	return env;
// }



template <class VALUE1, class VALUE2, class VALUE3> 
bool Environment<VALUE1, VALUE2, VALUE3>::varin(char var, Environment<VALUE1, VALUE2, VALUE3>* env){
	for (int i = 0; i < 100; ++i) {
		if(env->variables1[i] == var) return true;
		if(env->variables2[i] == var) return true;
		if(env->variables3[i] == var) return true;
	}

	return false;
}





template <class VALUE1, class VALUE2, class VALUE3> 
VALUE1 Environment<VALUE1, VALUE2, VALUE3>::findvari(char var, Environment<VALUE1, VALUE2, VALUE3>* env){
	for (int i = 0; i < 100; ++i) {
		if(env->variables1[i] == var){
			return env->values1[i];
		}
	}	
}

template <class VALUE1, class VALUE2, class VALUE3> 
VALUE2 Environment<VALUE1, VALUE2, VALUE3>::findvarb(char var, Environment<VALUE1, VALUE2, VALUE3>* env){
	for (int i = 0; i < 100; ++i) {
		if(env->variables2[i] == var){
			return env->values2[i];
		}
	}	
}

template <class VALUE1, class VALUE2, class VALUE3> 
VALUE3 Environment<VALUE1, VALUE2, VALUE3>::findvarp(char var, Environment<VALUE1, VALUE2, VALUE3>* env){
	for (int i = 0; i < 100; ++i) {
		if(env->variables3[i] == var){
			return env->values3[i];
		}
	}	
}






template <class VALUE1, class VALUE2, class VALUE3> 
VALUE1 Environment<VALUE1, VALUE2, VALUE3>::applyenvi(char var, Environment<VALUE1, VALUE2, VALUE3>* env){
	if(varin(var, env)){
		VALUE1 val = findvari(var, env);
		i = true;
		b = false;
		p = false;
		return val;
	}
	else{
		cout << "ERROR. No binding for " << var << endl;
	}
	
}

template <class VALUE1, class VALUE2, class VALUE3> 
VALUE2 Environment<VALUE1, VALUE2, VALUE3>::applyenvb(char var, Environment<VALUE1, VALUE2, VALUE3>* env){
	if(varin(var, env)){
		VALUE2 val = findvarb(var, env);
		b = true;
		i = false;
		p = false;
		return val;
	}
	else{
		cout << "ERROR. No binding for " << var << endl;
	}
	
}

template <class VALUE1, class VALUE2, class VALUE3> 
VALUE3 Environment<VALUE1, VALUE2, VALUE3>::applyenvp(char var, Environment<VALUE1, VALUE2, VALUE3>* env){
	if(varin(var, env)){
		VALUE3 val = findvarp(var, env);
		p = true;
		i = false;
		b = false;
		return val;
	}
	else{
		cout << "ERROR. No binding for " << var << endl;
	}
	
}




//findlength function
//varin function - returns true if variable is in environment
//findvar fundtion - returns value of variable


