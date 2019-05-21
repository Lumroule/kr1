#include "hippodrome.h"

#define _NUMBER_OF_GAMES_ 5

#define PATH "../"


int main() {
	setlocale(LC_ALL, "Russian");

	std::ifstream in(PATH"kr1.txt");

	std::ofstream out;

	if (!in.is_open()) {
		std::cout << "Файл не был открыт!" << std::endl;
		return 0;
	}

	hippodrome hp;
	vladik vl;


	hp.subscribe(vl);


	int numFile = 1;

	int prevHorse = -1;

	while (numFile) {

		in >> hp;

		std::cout << hp;

		if (!hp.size())
			return 0;


		int numHorse = get_dec("Выберете коня: ") - 1;
		std::cout << std::endl;

		try {
			vl.setHorse(hp[numHorse]);
		}
		catch (const std::exception &e) {
			print_exp(e);
		}

		for (int j = 0; j < _NUMBER_OF_GAMES_; ++j) {
			hp.startRace();
		}

		std::cout << std::endl;

		std::cout << "Вы выиграли " << vl.getCountWins() << " из " << _NUMBER_OF_GAMES_ << " игр." << std::endl;
		
		if (prevHorse != numHorse) {
			prevHorse = numHorse;
			out.close();
			out.open(
				std::string(PATH"game") + 
				std::string(std::to_string(numFile++)) +
				std::string(".txt"), 
				std::ios::app
			);
		}
		out << "------------------------------------------------------" << std::endl;
		out << "Вы выиграли " << vl.getCountWins() << " из " << _NUMBER_OF_GAMES_ << " игр." << std::endl;
		out << "Характеристики коней: " << std::endl;
		out << hp;
		out << "------------------------------------------------------" << std::endl;

		if (!get_dec("Сделать ставки ещё раз? ")) break;
		std::cout << std::endl;

	}

	out.close();

	return 0;
}

