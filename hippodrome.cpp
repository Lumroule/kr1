#include "hippodrome.h"

std::ostream& operator<<(std::ostream &os, const hippodrome &hp) {

	int size = hp.hrs.size();

	if (!size) {
		os << "Список коней пуст!" << std::endl;
		return os;
	}

	int width_one = 20;
	int width_two = 3;

	os.width(width_two);
	os << "№";
	os.width(width_one);
	os << "Имя";
	os.width(width_one);
	os << "Порода";
	os.width(width_one);
	os << "Кол-во побед";
	os.width(width_one);
	os << "Год рождения";

	os << std::endl;

	int i = 1;
	for (auto it = hp.hrs.begin(); it != hp.hrs.end(); ++it, ++i) {

		os.width(width_two);
		os << i;
		os.width(width_one);
		os << (it->second).getName();
		os.width(width_one);
		os << (it->second).getBreed();
		os.width(width_one);
		os << (it->second).getNumWins();
		os.width(width_one);
		os << (it->second).getYear();

		os << std::endl;
	}

	return os;

}

void hippodrome::startRace() {
	
	itWins = hrs.begin();

	for (auto it = hrs.begin(); it != hrs.end(); ++it) {
		it->first = static_cast<size_t>(rand() % 100);
		if (it->first > itWins->first)
			itWins = it;
	}

	itWins->second.setNumWins(itWins->second.getNumWins() + 1);

	notify();
}

size_t hippodrome::size() {
	return hrs.size();
}

std::ofstream& operator<<(std::ofstream &ofs, const hippodrome &hp) {
	int size = hp.hrs.size();

	if (!size) {
		ofs << "Список коней пуст!" << std::endl;
		return ofs;
	}

	int width_one = 20;
	int width_two = 3;

	ofs.width(width_two);
	ofs << "№";
	ofs.width(width_one);
	ofs << "Имя";
	ofs.width(width_one);
	ofs << "Порода";
	ofs.width(width_one);
	ofs << "Кол-во побед";
	ofs.width(width_one);
	ofs << "Год рождения";

	ofs << std::endl;

	int i = 1;
	for (auto it = hp.hrs.begin(); it != hp.hrs.end(); ++it, ++i) {

		ofs.width(width_two);
		ofs << i;
		ofs.width(width_one);
		ofs << (it->second).getName();
		ofs.width(width_one);
		ofs << (it->second).getBreed();
		ofs.width(width_one);
		ofs << (it->second).getNumWins();
		ofs.width(width_one);
		ofs << (it->second).getYear();

		ofs << std::endl;
	}

	return ofs;
}
std::ifstream& operator>>(std::ifstream &ifs, hippodrome &hp) {
	horse tmpHorse;
	try {
		while (true) {
			if (ifs.get() == EOF) {
				break;
			}
			ifs.unget();
			ifs >> tmpHorse;
			hp.hrs.push_back(std::pair<size_t, horse>({ 0, tmpHorse }));
		}
	}
	catch (const std::exception &e) {
		print_exp(e);
	}
	return ifs;
}
horse& hippodrome::operator[] (size_t n) {
	
	if (n < 0) {
		throw std::exception("Выход за пределы контейнера!");
	}
	
	int i = 0;
	
	for (auto it = hrs.begin(); it != hrs.end(); ++it, ++i) {
		if (i == n)
			return it->second;
	}

	throw std::exception("Выход за пределы контейнера!");
}
const horse& hippodrome::get() {
	return itWins->second;
}
