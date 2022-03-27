#include "Balanced.h"



Position checkBrackets(const std::string& input)
{
    Stack<char> stack;
    Stack<Position> pos;
    pos.push(Position(0,0));
    int colCount = 0, rowCount = 1;
    char now;
    for (const auto& it : input) {

        if (it == '\n') {
            colCount = 0;
            ++rowCount;
        }
        else {
            ++colCount;
        }

        now = '0';
        if (it == '{' || it == '[' || it == '(') {
            stack.push(it);
            pos.push(Position(rowCount, colCount));
        }
        if (it == '}' || it == ']' || it == ')') {
            pos.push(Position(rowCount, colCount));
        }

        if(stack.size()) now = stack.top();

        if ((it == '}'  && now != '{') || (it == ']' && now != '[') || (it == ')' && now != '(')) {
            return pos.top();
        }

        if((it == '}' && now == '{') || (it == ']' && now == '[') || (it == ')' && now == '(')) {
            stack.pop();
            pos.pop();
            pos.pop();
        }
    }


    return pos.top();
}
