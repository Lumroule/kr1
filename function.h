function.h

#pragma once

#include <exception>
#include <iostream>
#include <string>

int get_dec(std::string &&str);
bool match(const char *str, const char *pat);
void print_exp(const std::exception &e);
