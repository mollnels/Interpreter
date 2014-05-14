#include "environment.cpp"
// #include <type_info>


letlang applyprocedure(procval proc, letlang arg, Environment<int, bool, procval>* env){
	return valueof(proc.body, env->extendenv(proc.var, arg, env));
}
 
letlang valueof(Expression* exp, Environment<int, bool, procval>* env){

	if(exp->Var.boo == true){
		exp->Var.boo = false;
		letlang VAL;
		if(env->i){
			VAL = (NUMVAL) VAL;
			VAL.val = env->applyenvi(exp->Var.var, env);
		}
		else if(env->b){
			VAL = (BOOLVAL) VAL;
			VAL.val = env->applyenvb(exp->Var.var, env);
		}
		else
			VAL = (PROCVAL) VAL;
			VAL.val = env->applyenvp(exp->Var.var, env);
		return VAL;
	}

	else if(exp->Const.boo == true){
		exp->Const.boo = false;
		NUM.val = exp->Const.num;
		return NUM;
	}

	else if(exp->If.boo == true){
		exp->If.boo = false;
		bool val1 = (valueof(exp->If.exp1, env)).val;
		if(val1){
			return valueof(exp->If.exp2, env);
		}
		else{
			return valueof(exp->If.exp3, env);
		}
	}

	else if(exp->Let.boo == true){
		exp->Let.boo = false;
		return valueof(exp->Let.body, env->extendenv(exp->Let.var, (valueof(exp->Let.exp1, env)).val, env));
	}

	else if(exp->Diff.boo == true){
		exp->Diff.boo = false;
		int val1 = (valueof(exp->Diff.exp1, env)).val;
		int val2 = (valueof(exp->Diff.exp2, env)).val;
		NUM.val = val1-val2;
		return NUM;
	}

	else if(exp->Call.boo == true){
		exp->Call.boo = false;
		procval proc = ((PROCVAL) valueof(exp->Call.rator, env)).val;
		letlang arg = (valueof(exp->Call.rand, env)).val;
		return applyprocedure(proc, arg, env);
	}

	else if(exp->Proc.boo == true){
		exp->Proc.boo = false;
		procval pv;
		pv.var = exp->Proc.var;
		pv.body = exp->Proc.body;
		PROC.val = pv
		return PROC;
	}

	else if(exp->Zero.boo == true){
		exp->Zero.boo = false;
		int val1 = ((NUMVAL) valueof(&exp->Zero.exp1, env)).val;
		if(val1){
			BOOL.val = true;
			return BOOL;
		}
		else{
			BOOLVAL.val = false;
			return BOOL;
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
	Environment<int, bool, procval> env = Environment<int, bool, procval>();
	Expression expr = Expression(5);
	cout << (valueof(&expr, &env)).val << endl;
}

