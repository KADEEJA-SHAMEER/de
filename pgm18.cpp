// (not corrected)write a program to convert infix expression to postfix
#include <iostream>
#include <string>
using namespace std;

class Stack
{
    char data[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char c)
    {
        data[++top] = c;
    }

    char pop()
    {
        if (!isEmpty())
        {
            return data[top--];
        }
        return '\0';
    }

    char peek()
    {
        if (!isEmpty())
        {
            return data[top];
        }
        return '\0';
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class InfixToPostfix
{
    string infix;
    string postfix;

    int getPrecedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return 0;
    }

public:
    void readInfix()
    {
        cout << "Enter an infix expression: ";
        getline(cin, infix);

        check();
    }

    void displayInfix()
    {
        cout << "Infix expression: " << infix << endl;
    }

    string convert()
    {
        Stack operatorStack;

        for (int i = 0; i < infix.length(); i++)
        {
            char c = infix[i];

            if (isalnum(c))
            {
                string operand;
                while (isalnum(infix[i]))
                {
                    operand += infix[i];
                    i++;
                }
                i--;
                postfix += operand + ' ';
            }
            else if (c == '(')
            {
                operatorStack.push(c);
            }
            else if (c == ')')
            {
                while (!operatorStack.isEmpty() && operatorStack.peek() != '(')
                {
                    postfix += operatorStack.pop();
                    postfix += ' ';
                }
                if (!operatorStack.isEmpty() && operatorStack.peek() == '(')
                {
                    operatorStack.pop();
                }
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
            {
                while (!operatorStack.isEmpty() && getPrecedence(c) <= getPrecedence(operatorStack.peek()))
                {
                    postfix += operatorStack.pop();
                    postfix += ' ';
                }
                operatorStack.push(c);
            }
        }

        while (!operatorStack.isEmpty())
        {
            postfix += operatorStack.pop();
            postfix += ' ';
        }

        return postfix;
    }

    bool isOperator(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    void check()
    {
        char ch;
       /* int operand = 0, operatorr = 0;
         char ch;
        for (int i=0;i<infix.length();i++)
        {
            char c=infix[i];
            if (isalnum(c))
            { 
                operand++;
            }
            else if (isOperator(c))
            {
                operatorr++;
            }
        }*/
       
         for(int i=0;i<infix.length()-1;)
       {
         for(int j=i+1;j<infix.length();j++)
           {   
               while(infix[j]==' ')
                 {
                     ++j;
                 }
               if((isalnum(infix[i]))&&(isalnum(infix[j])))
                 {
                    cout<<"\n invalid expression re enter"<<endl;
                   
                    readInfix();
                 }
                else if((isOperator(infix[i]))&&(isOperator(infix[j])))
                 {
                    cout<<"\n invalid expresiion re enter"<<endl;
                    
                  readInfix();
                 
                 }
                 i++;
                 while(infix[i]==' ')
                 {
                     i++;
                     j++;
                 }
           }
       }
       
      if(infix[0]=='(')
           ch=infix[1];
        else
         ch=infix[0];
        if (/*operatorr != operand - 1 || */isOperator(infix[infix.length() - 1])|| isOperator(ch) )
        {
           
            cout << endl
                 << endl
                 << "Invalid expression!..Re-Enter..!" << endl
                 << endl;
            readInfix();
        }
    }
};

int main()
{
    InfixToPostfix converter;
    converter.readInfix();
    converter.displayInfix();
    string postfixExpression = converter.convert();

    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}