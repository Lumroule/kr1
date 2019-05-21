horse.cpp

#include "horse.h"

horse::horse() : year(0), numWins(0) {}
horse::horse(const horse &hrs) {
	name = hrs.name;
	breed = hrs.breed;
	year = hrs.year;
	numWins = hrs.numWins;
}

horse& horse::operator=(const horse &hrs) {
	if (this != &hrs) {
		name = hrs.name;
		breed = hrs.breed;
		year = hrs.year;
		numWins = hrs.numWins;
	}

	return *this;
}


const std::string& horse::getBreed() const {
	return breed;
}
const std::string& horse::getName() const {
	return name;
}
size_t horse::getYear() const {
	return year;
}
size_t horse::getNumWins() const {
	return numWins;
}

void horse::setNumWins(size_t numWins) {
	this->numWins = numWins;
}

std::ifstream& operator>>(std::ifstream &ifs, horse &hrs) {
	std::string str;
	
	size_t flag = 0;

	do {
		str.clear();

		std::getline(ifs, str, '\n');

		if (!str.length()) {
			break;
		}
		else if (match(str.c_str(), "Breed: ?*")) {
			hrs.breed = std::string(str.c_str() + 7);
			++flag;
		}
		else if (match(str.c_str(), "Name: ?*")) {
			hrs.name = std::string(str.c_str() + 6);
			++flag;
		}
		else if (match(str.c_str(), "Year of birth: ?*")) {
			hrs.year = static_cast<size_t>(atoi(str.c_str() + 15));
			++flag;
		}
		else if (match(str.c_str(), "Number of wins: ?*")) {
			hrs.numWins = static_cast<size_t>(atoi(str.c_str() + 16));
			++flag;
		}
		if (str[0] == '-' || flag == 4) {
			break;
		}
	} while (1);

	if (flag != 4) {
		throw std::exception("Введено недостаточно параметров!");
	}

	return ifs;
}

bool operator==(const horse &hrs1, const horse &hrs2) {
	return (hrs1.name == hrs2.name);
}
