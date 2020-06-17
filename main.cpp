#include <iostream>


class Expression {
public:
	virtual double calculate() = 0;
	
};

class BinaryExpression : public Expression {
	private:
		Expression* left;
		Expression* right;

	public:
		BinaryExpression(Expression* l, Expression* r) {
			left = l;
			right = r;
		}
		Expression* getLeft() { return left; }
		Expression* getRight() { return right; }
		void setLeft(Expression* l) { left = l; }
		void setRight(Expression* r) { right = r; }
};

class Number : public Expression {
	private:
		double value;
public:
	Number(double val) { value = val; }
	double calculate() { return value; }
};

class Plus : public BinaryExpression {
	public:
		Plus(Expression* e1, Expression* e2) : BinaryExpression (e1,e2) {}
		double calculate() {
			return getLeft()->calculate() + getRight()->calculate();
		}
};

class Minus : public BinaryExpression {
public:
	Minus(Expression* e1, Expression* e2) : BinaryExpression(e1, e2) {}
	double calculate() {
		return getLeft()->calculate() - getRight()->calculate();
	}
};

class Div : public BinaryExpression {
public:
	Div(Expression* e1, Expression* e2) : BinaryExpression(e1, e2) {}
	double calculate() {
		return getLeft()->calculate() / getRight()->calculate();
	}
};

class Mul : public BinaryExpression {
public:
	Mul(Expression* e1, Expression* e2) : BinaryExpression(e1, e2) {}
	double calculate() {
		return getLeft()->calculate() * getRight()->calculate();
	}
};


int main()
{
	Number num1(8);
	Number num2(7);
	Number num3(4);

	Expression* Pnum1 = &num1;
	Expression* Pnum2 = &num2;
	Expression* Pnum3 = &num3; 

	Plus P1(Pnum1, Pnum2);
	Number num5(P1.calculate());
	Expression* Pnum5 = &num5;


	Mul M1(Pnum5, Pnum3);
	std::cout << "(" << num1.calculate() << "+" << num2.calculate() << ")" << "*" << num3.calculate() << "=" << M1.calculate();



	







}