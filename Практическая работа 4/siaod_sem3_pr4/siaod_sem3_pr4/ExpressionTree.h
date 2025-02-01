#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
#include <string>
#include <iomanip>

class ExpressionTree
{
private:
    struct Node // структура узла
    {
        char data; // данные
        Node* left; // указатель на левое поддерево
        Node* right; // указатель на правое поддерево

        explicit Node(char data);
    };

    Node* root; // указатель на корень дерева
    
    void printTree(Node* node, int level = 0) // метод вывода дерева
    {
        if (node != nullptr)
        {
            level += 10;
            printTree(node->right, level);
            std::cout << std::endl;
            for (int i = 0; i < level; i++)
                std::cout << " ";
            std::cout << node->data << "\n";
            printTree(node->left, level);

        }
    }

public:
    ExpressionTree(); // конструктор

    Node* createNode(char data) // создание нового узла
    {
        return new Node(data);

    }

    void createTree(const std::string& str); // метод построения дерева

    bool hasHigherPrecedence(char op1, char op2); // сравнение приоритетов операций

    void applyOperator(std::stack<Node*>& nodes, std::stack<char>& operators); // применяет оператор к двум верхним узлам из стека узлов.Создается новый узел, в котором оператор становится данными, а два верхних узла становятся его потомками.Новый узел помещается в стек узлов.

    std::string getPrefix();

    std::string prefix(Node* node);

    std::string getInfix();

    std::string getInfix(Node* node);

    double evaluateExpression();

    double evaluate(Node* node);

    void printTree();

    double evaluatePrefixExpression(std::string prefix);
};
