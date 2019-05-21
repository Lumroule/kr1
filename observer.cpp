#pragma once

#include <list>
#include <exception>
#include "horse.h"

class publisher;

class subscriber {
public:
	virtual void update(publisher &pb) = 0;
private:
};


class publisher {
public:
	void subscribe(subscriber &sbr) {
		subscribers.push_back(&sbr);
	}
	void unsubscribe(subscriber &sbr) {
		subscribers.remove(&sbr);
	}
	void notify() {
		for (auto it = subscribers.begin(); it != subscribers.end(); ++it) {
			(*it)->update(*this);
		}
	}
	virtual const horse& get() = 0;
private:
	std::list<subscriber*> subscribers;
};


class vladik : public subscriber {
public:
	void update(publisher &pb) override {
		if (hrs == pb.get()) {
			++countWins;
			std::cout << "Выбраннаый конь победил!" << std::endl;
		}
		else {
			std::cout << "Выбраннаый конь не победил." << std::endl;
		}
	}
	size_t getCountWins() {
		return countWins;
	}
	void setHorse(const horse& hrs) {
		this->hrs = hrs;
		countWins = 0;
	}
private:
	horse hrs;
	size_t countWins{};
};

