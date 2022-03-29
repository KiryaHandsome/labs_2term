#include "rpn.h"
#include <algorithm>



int RPN::priority(char alpha)
{
    if (alpha == '+' || alpha == '-')
        return 1;
    if (alpha == '*' || alpha == '/')
        return 2;
    return 0;
}

std::string RPN::RPNconvert(std::string str)
{
        std::string srpn;

        size_t ind = str.find(' ');
        while (ind >= 0 && ind < str.size()) // удаление пробелов из входной строки
        {
            str.erase(ind, 1);
            ind = str.find(' ');
        }

//        for (int i = 0; i < str.size(); ++i) // учёт отрицательных чисел
//        {
//            if ((str[i] == '+' || str[i] == '-') && (0 == i || (!isalnum(str[i - 1]) && str[i - 1] != '.' && str[i - 1] != ')')))
//            {
//                auto it = std::find_if(str.begin() + i + 1, str.end(), [](char const c) {return !isalnum(c); });
//                str.insert(it, ')');
//                str.insert(i, "(0");
//            }
//        }

        Stack<char> stack;
        for (auto c : str) // формировка результирующей строки в ОПЗ
        {
            if (!isalnum(c) && ('.' != c))
            {
                //srpn += ' ';
                if (')' == c) {
                    while (stack.top() != '(')
                    {
                        srpn += stack.top();
                        stack.pop();
                        srpn += ' ';
                    }
                    stack.pop();
                }
                else if ('(' == c) {
                    stack.push(c);
                }
                else if (stack.isEmpty() || (priority(stack.top()) < priority(c))) {
                    stack.push(c);
                }
                else {
                    do {
                        srpn += stack.top();
                        srpn += ' ';
                        stack.pop();
                    } while (!(stack.isEmpty() || (priority(stack.top()) < priority(c))));
                    stack.push(c);
                }
            } else {
                srpn += c;
            }
        }
        while (!stack.isEmpty())  // остаток из стека добавляется в результ. строку
        {
            srpn += stack.top();
            //srpn += ' ';
            stack.pop();
        }
        std::cout << srpn << std::endl; // результирующая строка в ОПЗ

        return srpn;
}

std::string RPN::calculateRPN(std::string str, vector<std::string> nums)
{
    int i = 0;

    int length = str.size();

    auto isOp = [](char ch){ return (ch == '*' || ch == '-' || ch == '+' || ch == '/'); };
    auto isABCDE = [](char ch){ return (ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e'); };

    Stack<std::string> stack;
    while (i < length)
    {
        if (str.at(i) == '\n')
        {
            break;
        }

        if (str.at(i) >= 97 && str.at(i) <= 101 || str.at(i) == '0')
        {
            switch (str.at(i))
            {
            case 'a':
            {
                std::string a = nums[0];
                if(a != "" ) stack.push(a);
                if(a == "empty") {
                    return "ERROR";
                }
                break;
            }
            case 'b':
            {
                std::string b = nums[1];
                if(b != "") stack.push(b);
                if(b == "empty") {
                    return "ERROR";
                }
                break;
            }
            case 'c':
            {
                std::string c = nums[2];
                if(c != "" ) stack.push(c);
                if(c == "empty") {
                    return "ERROR";
                }
                break;
            }
            case 'd':
            {
                std::string d = nums[3];
                if(d != "") stack.push(d);
                if(d == "empty") {
                    return "ERROR";
                }
                break;
            }
            case 'e':
            {
                std::string e = nums[4];
                if(e != "") stack.push(e);
                if(e == "empty") {
                    return "ERROR";
                }
                break;
            }
            case '0':
            {
                //stack.push("0");
                return "ERROR";
                break;
            }
            }
        }

        switch (str.at(i))
        {
        case '+':
        {
            double d11, d12;
            try{
                d11 = std::stod(stack.top());
                stack.pop();
                d12 = std::stod(stack.top());
                stack.pop();
            } catch(...){
                return "ERROR";
            }
            std::string num1 = std::to_string(add(d12, d11));
            stack.push(num1);
            break;
        }
        case '-':
        {
            double d11, d12;
            try{
                d11 = std::stod(stack.top());
                stack.pop();
                d12 = std::stod(stack.top());
                stack.pop();
            } catch(...){
                return "ERROR";
            }
            std::string num2 = std::to_string(sub(d12, d11));
            stack.push(num2);
            break;
        }
        case '*':
        {
            double d11, d12;
            try{
                d11 = std::stod(stack.top());
                stack.pop();
                d12 = std::stod(stack.top());
                stack.pop();
            } catch(...){
                return "ERROR";
            }
            std::string num3 = std::to_string(mul(d12, d11));
            stack.push(num3);
            break;
        }
        case '/':
        {
            double d11, d12;
            try{
                d11 = std::stod(stack.top());
                stack.pop();
                d12 = std::stod(stack.top());
                stack.pop();
            } catch(...){
                return "ERROR";
            }
            if(d12 == 0) return "ERROR";
            std::string num4 = std::to_string(divide(d12, d11));
            stack.push(num4);
            break;
        }
        default:
        {
            if(!isOp(str.at(i)) && !isABCDE(str.at(i)) && str.at(i) != ' ') return "ERROR";
        }
        }
        i++;
    }
    std::string tmp = stack.top();
    stack.pop();
    return tmp;
}

double RPN::add(double x, double y)
{
  return x + y;
}

double RPN::sub(double x, double y)
{
  return x - y;
}

double RPN::mul(double x, double y)
{
  return x * y;
}

double RPN::divide(double x, double y)
{
  return x / y;
}

bool RPN::isCorrectExpression(const std::string& a)
{
    auto isOp = [](char ch){ return (ch == '*' || ch == '-' || ch == '+' || ch == '/'); };
    auto isABCDE = [](char ch){ return (ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e'); };

    // проверка первого символа
    if (a[0] == '+'||a[0] == '*'||a[0] == '/'){
        return false;
    }
    else if (isOp(a[a.size() - 1])){
        return false;
    }
    // если всё верно (в начале и в конце стоят не знаки), то выполняется цикл,
    else { // который прогоняет строку на предмет двух символов подряд.
        for (int i = 1; i < a.length(); i++) {
            if (isOp(a[i]) && isOp(a[i - 1])){
                return false;
            }
            if(!isOp(a[i]) && !isABCDE(a[i]) && a[i] != ' ' && a[i] != '(' && a[i] != ')'){
                return false;
            }
            if((isABCDE(a[i - 1]) && a[i] == '(') || (isABCDE(a[i]) && a[i - 1] == ')')){
                return false;
            }
            if(isABCDE(a[i - 1]) && isABCDE(a[i])){
                return false;
            }
        }
    }
    return true;
}

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
