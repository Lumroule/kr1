function.cpp

#include "function.h"

bool match(const char *str, const char *pat) {
	for (;; ++str, ++pat) {
		switch (*pat) {
		case '\0':
			return (*str == '\0');
		case '*':
			for (int i = 0; ; ++i) {
				if (match(str + i, pat + 1)) return true;
				if (!str[i]) return false;
			}
		case '?':
			if (!*str) return false;
			break;
		default:
			if (*str != *pat) return false;
		}
	}
}
void print_exp(const std::exception &e) {
	std::cout << "Ошибка: " << e.what() << std::endl;
}
int get_dec(std::string &&str) {
	int tmp;
	std::cout << str;
	std::cin >> tmp;
	std::cin.get();
	return tmp;
}
