hippodrome.h

#pragma once

#include "observer.h"
#include "horse.h"
#include <list>
#include <iostream>

class hippodrome : public publisher {
public:
	void startRace();

	friend std::ostream& operator<<(std::ostream &ofs, const hippodrome &hp);

	friend std::ifstream& operator>>(std::ifstream &ifs, hippodrome &hp);
	friend std::ofstream& operator<<(std::ofstream &ofs, const hippodrome &hp);

	horse& operator[](size_t n);

	size_t size();

	const horse& get() override;

private:
	std::list<std::pair<size_t, horse>> hrs;
	std::list<std::pair<size_t, horse>>::iterator itWins;
};
