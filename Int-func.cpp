

class Expression;

struct varexp {			//structure for the var-exp
	char var;
	bool boo = false;
};

struct constexp {
	int num;
	bool boo = false;
};

struct diffexp {
	Expression* exp1;
	Expression* exp2;
	bool boo = false;
};

struct zeroexp {
	Expression* exp1;
	bool boo = false;
};

struct ifexp {
	Expression* exp1;
	Expression* exp2;
	Expression* exp3;
	bool boo = false;
};

struct letexp {
	char var;
	Expression* exp1;
	Expression* body;
	bool boo = false;
};

struct procexp {
	char var;
	Expression* body;
	bool boo = false;
};

struct callexp {
	Expression* rator;
	Expression* rand;
	bool boo = false;
};

struct letrecexp {
	char pname;
	char bvar;
	Expression* pbody;
	Expression* letrecbody;
	bool boo = false;
};

class Expression {

	constexp Const;
	varexp Var;
	diffexp Diff;
	zeroexp Zero;
	ifexp If;
	letexp Let;
	procexp Proc;
	callexp Call;
	letrecexp Letrec;

	Expression(int num);
	Expression(char var);
	Expression(Expression* exp1);
	Expression(Expression* exp1, Expression* exp2, Expression* exp3);
	Expression(char var, Expression* exp1, Expression* exp2);
	Expression(char var, Expression* exp1);
	Expression(char name, char var, Expression* body, Expression* letbody);
	Expression(Expression* exp1, Expression* exp2, char type);
	Expression(Expression* exp1, Expression* exp2, bool call);
};

	Expression::Expression(int num){
		Const.num = num;
		Const.boo = true;
	}

	Expression::Expression(char var){
		Var.var = var;
		Var.boo = true;
	}

	Expression::Expression(Expression* exp1){
		Zero.exp1 = exp1;
		Zero.boo = true;
	}
	
	Expression::Expression(Expression* exp1, Expression* exp2, Expression* exp3){
		If.exp1 = exp1;
		If.exp2 = exp2;
		If.exp3 = exp3;
		If.boo = true;
	}
	
	Expression::Expression(char var, Expression* exp1, Expression* exp2){
		Let.var = var;
		Let.exp1 = exp1;
		Let.body = exp2;
		Let.boo = true;
	}
	
	Expression::Expression(char var, Expression* exp1){
		Proc.var = var;
		Proc.body = exp1;
		Proc.boo = true;
	}
	
	Expression::Expression(char name, char var, Expression* body, Expression* letbody){
		Letrec.pname = name;
		Letrec.bvar = var;
		Letrec.pbody = body;
		Letrec.letrecbody = letbody;
		Letrec.boo = true;
	}
	
	Expression::Expression(Expression* exp1, Expression* exp2, bool call){
		if(call){
			Call.rator = exp1;
			Call.rand = exp2;
			Call.boo = true;
		}
		else{
			Diff.exp1 = exp1;
			Diff.exp2 = exp2;
			Diff.boo = true;
		}
	}

int main(){
	return 0;
}
