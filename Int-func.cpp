

class Expression;

struct varexp {			//structure for the var-exp
	char var;
};

struct constexp {
	int num;
};

struct diffexp {
	Expression* exp1;
	Expression* exp2;
};

struct zeroexp {
	Expression* exp1;
};

struct ifexp {
	Expression* exp1;
	Expression* exp2;
	Expression* exp3;
};

struct letexp {
	char var;
	Expression* exp1;
	Expression* body;
};

struct procexp {
	char var;
	Expression* body;
};

struct callexp {
	Expression* rator;
	Expression* rand;
};

struct letrecexp {
	char p-name;
	char b-var;
	Expression* p-body;
	Expression* letrec-body;
};

class Expression {

	constexp Const;
	diffexp Diff;
	zeroexp Zero;
	ifexp If;
	letexp Let;
	procexp Proc;
	callexp Call;
	lertrecexp Letrec;

	Expression(int num);
	Expression(char var);
	Expression(Expression* exp1);
	Expression(Expression* exp1, Expression* exp2, Expression* exp3);
	Expression(char var, Expression* exp1, Expression* exp2);
	Expression(char var, Expression* exp1);
	Expression(char name, char var, Expression* body, Expression* letbody);
	Expression(Expression* exp1, Expression* exp2, char type);
};

