#ifndef RPN_H
#define RPN_H

#include "Stack.h"
#include "mainwindow.h"


class RPN {
private:
    RPN();
public:

    static int priority(char alpha);

    static std::string RPNconvert(std::string str);

    static std::string calculateRPN(std::string str, vector<std::string> nums);

    static double add(double x, double y);
    static double sub(double x, double y);
    static double mul(double x, double y);
    static double divide(double x, double y);

    static bool isCorrectExpression(const std::string& str);


};

struct Position {
    Position(int r = 0, int c = 0) : row(r), column(c){}
    int row;
    int column;
};

Position checkBrackets(const std::string& input);

#endif // RPN_H
