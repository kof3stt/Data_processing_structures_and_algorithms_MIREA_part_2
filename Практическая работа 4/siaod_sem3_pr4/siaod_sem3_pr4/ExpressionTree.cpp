#include "ExpressionTree.h"


ExpressionTree::ExpressionTree()
{
    root = nullptr;
}

void ExpressionTree::createTree(const std::string& str)
{
    std::stack<Node*> nodes; // стек для узлов дерева
    std::stack<char> operators; // стек для операторов

    for (char ch : str)
    {
        if (isdigit(ch)) // текущий символ - цифра
        {
            nodes.push(createNode(ch)); // создается новый узел и помещается в стек узлов дерева
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') // текущий символ - знак операции
        {
            while (!operators.empty() && hasHigherPrecedence(operators.top(), ch))
            {
                applyOperator(nodes, operators);
            }
            operators.push(ch);
        }
        else if (ch == '(')
        {
            operators.push(ch);
        }
        else if (ch == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                applyOperator(nodes, operators);
            }
            if (!operators.empty() && operators.top() == '(')
            {
                operators.pop();  // Удалить '('
            }
        }
    }

    while (!operators.empty())
    {
        applyOperator(nodes, operators);
    }

    if (!nodes.empty())
    {
        root = nodes.top();
    }
}

bool ExpressionTree::hasHigherPrecedence(char op1, char op2)
{
    return (op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'); // сравнивает приоритеты операций
}

void ExpressionTree::applyOperator(std::stack<Node*>& nodes, std::stack<char>& operators)
{
    char op = operators.top();
    operators.pop();
    if (nodes.size() < 2)
    {
        return;
    }
    Node* right = nodes.top();
    nodes.pop();
    Node* left = nodes.top();
    nodes.pop();
    Node* newNode = createNode(op);
    newNode->left = left;
    newNode->right = right;
    nodes.push(newNode);
}

void ExpressionTree::printTree()
{
    printTree(root, 0); // вывод дерева
}


std::string ExpressionTree::getPrefix()
{
    return prefix(root); // префиксная форма выражения
}

std::string ExpressionTree::prefix(Node* node)
{
    std::string result;
    if (node != nullptr)
    {
        result += node->data;
        if (node->left != nullptr || node->right != nullptr)
        {
            result += prefix(node->left);
            result += prefix(node->right);
        }
    }
    return result;
}

std::string ExpressionTree::getInfix()
{
    return getInfix(root);
}

std::string ExpressionTree::getInfix(Node* node)
{
    if (node != nullptr)
    {
        std::string infix = "";
        if (node->left != nullptr || node->right != nullptr)
        {
            infix += "(";
            infix += getInfix(node->left);
            infix += node->data;
            infix += getInfix(node->right);
            infix += ")";
        }
        else
        {
            infix += node->data;
        }
        return infix;
    }
    return "";
}

double ExpressionTree::evaluateExpression()
{
    return evaluate(root);
}

double ExpressionTree::evaluate(Node* node)
{
    if (node != nullptr)
    {
        if (isdigit(node->data))
        {
            return node->data - '0';
        }
        else
        {
            double leftVal = evaluate(node->left);
            double rightVal = evaluate(node->right);

            switch (node->data)
            {
            case '+':
                return leftVal + rightVal;
            case '-':
                return leftVal - rightVal;
            case '*':
                return leftVal * rightVal;
            case '/':
                return leftVal / rightVal;
            default:
                exit(0);
            }
        }
    }
    return INFINITY; // Error handling
}

double ExpressionTree::evaluatePrefixExpression(std::string prefix)
{
    std::stack<double> operands;

    for (int i = prefix.length()-1; i >= 0; i--)
    {
        if (isdigit(prefix[i]))
        {
            operands.push(prefix[i] - '0');
        }
        else if (prefix[i] == ' ' || prefix[i] == '\t')
        {
            continue;
        }
        else
        {
            double operand1 = operands.top();
            operands.pop();
            double operand2 = operands.top();
            operands.pop();

            switch (prefix[i])
            {
            case '+':
                operands.push(operand1 + operand2);
                break;
            case '-':
                operands.push(operand1 - operand2);
                break;
            case '*':
                operands.push(operand1 * operand2);
                break;
            case '/':
                operands.push(operand1 / operand2);
                break;
            default:
                return INFINITY; // Error handling
            }
        }
    }

    if (operands.size() == 1)
    {
        return operands.top();
    }
    else
    {
        return INFINITY; // Error handling
    }
}

inline ExpressionTree::Node::Node(char data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}
