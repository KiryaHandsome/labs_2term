#include <iostream>

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {};
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}
    double evaluate() const { return value; }
    ~Number() {}
private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const* left, char op, Expression const* right)
        : left(left), op(op), right(right)
    {
        switch (op) {
        case '+':
            result = left->evaluate() + right->evaluate();
            break;
        case '-':
            result = left->evaluate() - right->evaluate();
            break;
        case '*':
            result = left->evaluate() * right->evaluate();
            break;
        case '/':
            result = left->evaluate() / right->evaluate();
            break;
        }
    }
    double evaluate() const { return result; }
    ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    double result;
    Expression const* left;
    Expression const* right;
    char op;
};

int main()
{
    Expression* sube1 = new BinaryOperation(new Number(2), '*', new Number(5));

    Expression* sube2 = new BinaryOperation(new Number(3), '+', new Number(4));

    Expression* expr = new BinaryOperation(sube1, '+', sube2);

    std::cout << expr->evaluate() << std::endl;

    delete expr;
}