//uses int-func and environment

value valueof(Expression* exp, Environment* env){
	if(Var.boo == true){
		Var.boo = false;
		value val = applyenv(Var.var, env);
		return val;
	}

	elif(Const.boo == true){
		Const.boo = false;
		return Const.num;
	}

	elif(If.boo == true){
		If.boo = false;
		val1 = valeueof(If.exp1, env);
		if(val1){
			valueof(If.exp2, env);
		}
		else{
			valueof(If.exp3, env);
		}
	}

	elif(Let.boo == true){
		Let.boo = false;
		val1 = valueof(Let.exp1, env);
		valueof(Let.body, extendenv(Let.var, val1, env));
	}

	elif(Diff.boo == true){
		Diff.boo = false;
		val1 = valueof(Diff.exp1, env);
		val2 = valueof(Diff.exp2, env);
		return val1-val2;
	}

	elif(Call.boo == true){
		Call.boo = false;
		proc = valueof(Call.rator, env);
		arg = valueof(Call.rand, env);
		applyprocedure(proc, arg);
	}

	elif(Proc.boo == true){
		Proc.boo = false;
		//make procval struct?
		return proc;
	}

	elif(Zero.boo == true){
		Zero.boo = false;
		val1 = valueof(Zero.exp1, env);
		if(val1){
			return true;
		}
		else{
			return false;
		}
	}

	elif(Letrec.boo == true){
		Letrec.boo = false;
		valueof(Letrec.pbody, extendenvrec(Letrec.pname, Letrec.bvar, Letrec.pbody, env));
	}

	else{
		cout << "ERROR. Expression not defined." << endl;
	}
}



/*things we need to make:
	Environment class
	applyenv function - method?
	extendenv(CHAR, VAL, ENVIRONMENT) - method?
	extendenvrec(CHAR, CHAR, EXPRESSION, ENVIRONMENT)
	applyprocedure(PROCVAL, VAL)
	procedure(CHAR, EXPRESSION, ENVIRONMENT)
	procval?

