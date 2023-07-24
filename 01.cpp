#include <iostream>

class bad_length : public std::exception
{
public:
	bad_length();
	~bad_length();
	const char* what() const override;
private:

};

const char* bad_length::what() const
{
	return "Вы ввели слово запретной длины! До свидания";
}

bad_length::bad_length()
{
}

bad_length::~bad_length()
{
}

int function(const std::string& str, const int& forbidden_length);

int main(int argc, char** argv)
{
	std::system("chcp 1251");

	int forbidden_length;
	std::string str;

	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;

	while (true)
	{
		std::cout << "Введите слово: " << std::endl;
		std::cin >> str;
		try
		{
			std::cout << "Длина слова " << str << " равна " << function(str, forbidden_length) << std::endl;
		}
		catch(const bad_length& ex)
		{
			std::cout << ex.what() << std::endl;
			break;
		}
		catch (...)
		{
			std::cout << "Неизвестная ошибка" << std::endl;
		}
	}

	std::system("pause");
	return 0;
}

int function(const std::string& str, const int& forbidden_length)
{
	if (str.length() == forbidden_length)
	{
		throw bad_length();
	}
	return str.length();
}