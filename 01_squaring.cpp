#include <iostream>
#include <vector>
#include <variant>
#include <any>


void printHeader();

template <class T>
void squaring(T & var)
{
	var *= var;
}

template <>
void squaring(std::vector<int> & vect)
{
	for (auto& data : vect) data *= data;
}

// перегружаю оператор << для cout (чтобы выводить std::vector<int>)
std::ostream& operator<< (std::ostream& out, const std::vector<int>& vect)
{
	for (const auto& val : vect) out << val << " ";
	return out;
}

template <class Type>
void prinToConsole(const std::string& str, const Type& data)
{
	std::cout << "[" << str << "]: " << data << std::endl;
}

int main()
{
	printHeader();

	int intData(4);
	prinToConsole("IN", intData);
	squaring(intData);
	prinToConsole("OUT", intData);

	std::vector<int> vectorIntData{ -1, 4, 8 };
	prinToConsole("IN", vectorIntData);
	squaring(vectorIntData);
	prinToConsole("OUT", vectorIntData);

	return 0;
}


// функции
// заголовок 
void printHeader()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");   // задаём русский текст
	system("chcp 1251");            // настраиваем кодировку консоли
	std::system("cls");
	cout << "Задача 1. Возведение в квадрат\n"
		 << "------------------------------\n" << endl;
}
