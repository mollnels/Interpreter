#include "environment.cpp"

template <class VALUE> 
VALUE applyprocedure(procval proc, VALUE arg, Environment<VALUE>* env){
	valueof(proc.body, extendenv(proc.var, arg, env));
}

template <class VALUE> 
VALUE valueof(Expression* exp, Environment<VALUE>* env){

	if(exp->Var.boo == true){
		exp->Var.boo = false;
		VALUE val = applyenv(exp->Var.var, env);
		return val;
	}

	else if(exp->Const.boo == true){
		exp->Const.boo = false;
		return exp->Const.num;
	}

	else if(exp->If.boo == true){
		exp->If.boo = false;
		VALUE val1 = valeueof(exp->If.exp1, env);
		if(val1){
			valueof(exp->If.exp2, env);
		}
		else{
			valueof(exp->If.exp3, env);
		}
	}

	else if(exp->Let.boo == true){
		exp->Let.boo = false;
		VALUE val1 = valueof(exp->Let.exp1, env);
		valueof(exp->Let.body, extendenv(exp->Let.var, val1, env));
	}

	else if(exp->Diff.boo == true){
		exp->Diff.boo = false;
		VALUE val1 = valueof(exp->Diff.exp1, env);
		VALUE val2 = valueof(exp->Diff.exp2, env);
		return val1-val2;
	}

	else if(exp->Call.boo == true){
		exp->Call.boo = false;
		VALUE proc = valueof(exp->Call.rator, env);
		VALUE arg = valueof(exp->Call.rand, env);
		applyprocedure(proc, arg, env);
	}

	else if(exp->Proc.boo == true){
		exp->Proc.boo = false;
		procval pv;
		pv.var = exp->Proc.var;
		pv.body = exp->Proc.body;
		return pv;
	}

	else if(exp->Zero.boo == true){
		exp->Zero.boo = false;
		VALUE val1 = valueof(exp->Zero.exp1, env);
		if(val1){
			return true;
		}
		else{
			return false;
		}
	}

	// elif(Letrec.boo == true){
	// 	Letrec.boo = false;
	// 	valueof(Letrec.pbody, extendenvrec(Letrec.pname, Letrec.bvar, Letrec.pbody, env));
	// }

	else{
		cout << "ERROR. Expression not defined." << endl;
	}
}

int main(){
	cout << "hello" << endl;
}

