#pragma once

#include <string>
#include <fstream>
#include "function.h"

class horse {
public:
	horse();
	horse(const horse &hrs);

	horse& operator=(const horse &hrs);
	
	const std::string& getBreed() const;
	const std::string& getName() const;
	size_t getYear() const;
	size_t getNumWins() const;

	void setNumWins(size_t numWins);

	friend std::ifstream& operator>>(std::ifstream &ifs, horse &hrs);
	friend bool operator==(const horse &hrs1, const horse &hrs2);

private:
	std::string breed;
	std::string name;
	size_t year;
	size_t numWins;
};
