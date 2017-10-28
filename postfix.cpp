#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <fstream>

std::string in2postfix(std::vector<std::string> values);             // convert infix to postfix
int HasHigherPrecedence(std::string operator1, std::string operator2);    // check precedence
bool IsOperator(std::string C);                                    // check if operator symbol
bool IsOperand(std::string C);                                     // check if alphanumeric or not

int main() {
    int numOperators = 0;
    int numOperands = 0;
    std::string infix;
    std::string postfix;
    std::vector<std::string> infixValues;
    std::vector<std::string> postfixValues;
    
    std::cout << "Please enter the infix expression: ";
    std::getline(std::cin,infix);
    std::cout << std::endl;
    
    std::stringstream iss(infix);
    std::string data;
    
    // read in infix to a vector
    while ( iss >> data ) {
        infixValues.push_back(data);
        if (IsOperand(data)) {
            numOperands++;
        }
        if (IsOperator(data)) {
            numOperators++;
        }
    }

    postfix = in2postfix(infixValues);
    std::stringstream ixx(postfix);
    while ( ixx >> data ) {
        postfixValues.push_back(data);
    }
    
    int parenthesesMismatch = 0;
    int braceMismatch = 0;

    for (int i = 0; i < postfixValues.size(); i++) {
        if (postfixValues[i] == "(")
            parenthesesMismatch++;
        if (postfixValues[i] == ")")
            parenthesesMismatch--;
        if (postfixValues[i] == "{")
            braceMismatch++;
        if (postfixValues[i] == "}")
            braceMismatch--;
    }
    
    std::string postfixString = "";
    if (parenthesesMismatch == 0 && braceMismatch == 0) {
        postfixString += "True ";
    } else {
        postfixString += "False ";
    }
    
    postfixString += postfix;
    
    std::cout << postfixString << std::endl << std::endl;
    return 0;
}

// Function to evaluate Postfix expression and return output
std::string in2postfix(std::vector<std::string> e)
{
    std::stack<std::string> s;
    std::string postfix = "";
    
    for(int i = 0;i< e.size();i++) {
        // operator, pop two and perform operation
        if(IsOperator(e[i]))
        {
            while(!s.empty() && s.top() != "(" && HasHigherPrecedence(s.top(),e[i]))
            {
                postfix+= s.top();
                postfix += " ";
                s.pop();
            }
            s.push(e[i]);
        }
        // operand
        else if(IsOperand(e[i]))
        {
            postfix +=e[i];
            postfix += " ";
        }
        
        else if (e[i] == "(")
        {
            s.push(e[i]);
        }
        
        else if(e[i] == ")")
        {
            while(!s.empty() && s.top() !=  "(") {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.pop();
        }
    }
    
    while(!s.empty()) {
        postfix += s.top();
        postfix += " ";
        s.pop();
    }
    return postfix;
}

// check whether a string is an alphanumeric
bool IsOperand(std::string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if(c >= '0' && c <= '9')
            return true;
        if (c >= 'A' && c <= 'Z')
            return true;
        if (c >= 'a' && c <= 'z')
            return true;
    }
    return false;
}

// check whether a string is an operator
bool IsOperator(std::string o)
{
    if(o == "+" || o == "-" || o == "*" || o == "/")
        return true;
    return false;
}

// checks whether a string is a parenthesis
bool IsParenthesis(std::string o)
{
    if(o == "(" || o == ")")
        return true;
    return false;
}

// check the weight of an operator and assign precedence
int GetOperatorWeight(std::string o)
{
    int weight = -1;
    
    if (o == "+" || o == "-") {
        weight = 1;
    }
    
    if (o == "*" || o == "/") {
        weight = 2;
    }
    
    return weight;
}

// check precendence
int HasHigherPrecedence(std::string a, std::string b)
{
    int aWeight = GetOperatorWeight(a);
    int bWeight = GetOperatorWeight(b);
    
    if (aWeight > bWeight) {
        return true;
    } else {
        return false;
    }
}

