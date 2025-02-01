#include "ExpressionTree.h"

int main()
{
	system("chcp 1251");
	std::string expression;
	std::string prefix;
	std::string infix;
	double res;
	ExpressionTree tree;
	int num;
	while (true)
	{
		std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << " Меню\n";
		std::cout << " 1. Создать дерево выражений в соответствии с вводимым выражением\n";
		std::cout << " 2. Отобразить дерево на экране\n";
		std::cout << " 3. Образовать префиксную форму выражения, содержащегося в дереве\n";
		std::cout << " 4. Вычислить значение выражения по дереву\n";
		std::cout << " 5. Вычислить значение выражение по префиксной форме\n";
		std::cout << " 6. Образовать инфиксную форму выражения, содержащегося в дереве\n";
		std::cout << " 7. Завершить выполнение программы\n";
		std::cin >> num;
		switch (num)
		{
		case 1:
		{
			std::cout << " Введите выражение: ";
			std::cin >> expression;
			tree.createTree(expression);
			break;
		}
		case 2:
		{
			std::cout << "Printed Tree:\n";
			tree.printTree();
			break;
		}
		case 3:
		{
			prefix = tree.getPrefix();
			if (prefix.size() == 0)
				std::cout << " Дерево выражения не создано" << std::endl;
			else
				std::cout << prefix << std::endl;
			break;
		}
		case 4:
		{
			res = tree.evaluateExpression();
			if (res == INFINITY)
				std::cout << " Дерево выражения не создано или было вызвано исключение division by zero" << std::endl;
			else
				std::cout << res << std::endl;
			break;
		}
		case 5:
		{
			prefix = tree.getPrefix();
			if (prefix.size() == 0)
				std::cout << " Дерево выражения не создано" << std::endl;
			else
				std::cout << tree.evaluatePrefixExpression(prefix) << std::endl;
			break;
		}
		case 6:
		{
			infix = tree.getInfix();
			if (infix.size() == 0)
				std::cout << " Дерево выражения не создано" << std::endl;
			else
				std::cout << infix << std::endl;
			break;
		}
		case 7:
			return 0;
		default:
		{
			std::cout << " Нет такого пункта\n";
		}
		}
	}
}
