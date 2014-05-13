<<<<<<< HEAD:Int-func.cpp

#include <string>
=======
>>>>>>> 7e0182abe17a5b2f0cb1067b09b2cd7982822954:Expression.cpp
#include <iostream>
using namespace std;

class Expression;

<<<<<<< HEAD:Int-func.cpp
=======
struct procval{
	char var;
	Expression* body;
};
>>>>>>> 7e0182abe17a5b2f0cb1067b09b2cd7982822954:Expression.cpp

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

// struct letrecexp {
// 	char pname;
// 	char bvar;
// 	Expression* pbody;
// 	Expression* letrecbody;
// 	bool boo = false;
// };

class Expression {
public:
	constexp Const;
	varexp Var;
	diffexp Diff;
	zeroexp Zero;
	ifexp If;
	letexp Let;
	procexp Proc;
	callexp Call;
<<<<<<< HEAD:Int-func.cpp
	letrecexp Letrec;
public:
=======
	// letrecexp Letrec;

>>>>>>> 7e0182abe17a5b2f0cb1067b09b2cd7982822954:Expression.cpp
	Expression(int num);
	Expression(char var);
	Expression(Expression* exp1);
	Expression(Expression* exp1, Expression* exp2, Expression* exp3);
	Expression(char var, Expression* exp1, Expression* exp2);
	Expression(char var, Expression* exp1);
	// Expression(char name, char var, Expression* body, Expression* letbody);
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
	
	// Expression::Expression(char name, char var, Expression* body, Expression* letbody){
	// 	Letrec.pname = name;
	// 	Letrec.bvar = var;
	// 	Letrec.pbody = body;
	// 	Letrec.letrecbody = letbody;
	// 	Letrec.boo = true;
	// }
	
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

<<<<<<< HEAD:Int-func.cpp
Expression * translate(string str) {
	string v="(varexp ";
	string c ("(constexp ");
	string z ("(zeroexp ");
	string d ("(diffexp ");
	string i ("(ifexp ");
	string p=("(procexp ");
	string l=("(letexp ");
	string ca=("(callexp ");
	//for varexp
	if (str.compare(0,8,v)==0) {
		char c=str[8];
		Expression e (c);
		return &e;
	}
	//for constexp
	if (str.compare(0,10,c)==0){
		char c1=str[10];
		int n=c1-'0';
		Expression e (n);
		return &e;
	}
	//for zeroexp
	if (str.compare(0,9,z)==0){
		string z1=str.substr(9,str.length());
		Expression e (translate(str.substr(9,str.length()-10)));
		return &e;
}
	//for diffexp
	if (str.compare(0,9,d)==0){
		string d1=str.substr(9,str.length()-10);
		int parenum=0;
		int i;
		string l="(";
		string r=")";
		for (i=0; i<d1.length(); i++) {
			if (l.compare(d1.substr(i,1))==0)
				parenum++;
			if (r.compare(d1.substr(i,1))==0)
				parenum--;
			if (parenum==0)
				break;
		}
		Expression e (translate(d1.substr(0,i+1)),translate(d1.substr(i+1)),false);
		return &e;

	}
	//for ifexp
	if (str.compare(0,7,i)==0){
		string q=str.substr(7,str.length()-8);
		int parenum=0;
		int i;
		int j;
		bool onedown=false;
		string l="(";
		string r=")";
		string i1,i2,i3;
		for (i=0; i<q.length(); i++) {
			if (l.compare(q.substr(i,1))==0)
				parenum++;
			if (r.compare(q.substr(i,1))==0)
				parenum--;
			if ((parenum==0)&&(onedown==true)) {
				i2=q.substr(j,i-j+1);
				break;
			}
			if (parenum==0){
				onedown=true;
				i1=q.substr(0,i+1);
				j=i+1;
			}
			

		}
		i3=q.substr(i+1);
		Expression e (translate(i1),translate(i2),translate(i3));
		return &e;

	}
	//for procexp
	if (str.compare(0,9,p)==0){
	  string p1=str.substr(9,str.length()-10);
	  char c=p1[8];
    	  int parenum=0;
		int i;
		string l="(";
		string r=")";
		for (i=0; i<p1.length(); i++) {
			if (l.compare(p1.substr(i,1))==0)
				parenum++;
			if (r.compare(p1.substr(i,1))==0)
				parenum--;
			if (parenum==0)
			  break;
		}
		Expression e (c,translate(p1.substr(i+1)));
		return &e;
	}
	//for letexp
	if (str.compare(0,8,l)==0) {
	  string l1=str.substr(8,str.length()-9);
	  int parenum=0;
		int i;
		int j;
		bool onedown=false;
		string l="(";
		string r=")";
		string i1,i2,i3;
		for (i=0; i<l1.length(); i++) {
			if (l.compare(l1.substr(i,1))==0)
				parenum++;
			if (r.compare(l1.substr(i,1))==0)
				parenum--;
			if ((parenum==0)&&(onedown==true)) {
				i2=l1.substr(j,i-j+1);
				break;
			}
			if (parenum==0){
				onedown=true;
				i1=l1.substr(0,i+1);
				j=i+1;
			}
			

		}
		i3=l1.substr(i+1);
		char c=l1[8];
		Expression e (c,translate(i2),translate(i3));
       
	}
	//for callexp
	if (str.compare(0,9,ca)==0){
		string c1=str.substr(9,str.length()-10);
		int parenum=0;
		int i;
		string l="(";
		string r=")";
		for (i=0; i<c1.length(); i++) {
			if (l.compare(c1.substr(i,1))==0)
				parenum++;
			if (r.compare(c1.substr(i,1))==0)
				parenum--;
			if (parenum==0)
				break;
		}
		Expression e (translate(c1.substr(0,i+1)),translate(c1.substr(i+1)),true);
		return &e;

	}
};
		


int main() {
	Expression * expr=translate("(diffexp (zeroexp (constexp 2))(ifexp (varexp x)(varexp y)(varexp z)))");
	cout<< (*(*(*expr).Diff.exp1).Zero.exp1).Const.num<<'\n';
	return 0; 
}
=======
>>>>>>> 7e0182abe17a5b2f0cb1067b09b2cd7982822954:Expression.cpp
