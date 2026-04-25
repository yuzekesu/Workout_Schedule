#include "Schedule.h"
#include <Windows.h>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

static Schedule s("./schedule.txt");
BOOL WINAPI ConsoleHandler(DWORD signal);

int main() {
	SetConsoleCtrlHandler(ConsoleHandler, true);
	std::cout << s;
	for (size_t i = 1;; i++) {
		std::cout << "Plan " << i << " is: ";
		std::string input;
		std::cin >> input;
		try {
			size_t offset = std::stoull(input) - 1;
			s.Update(offset);
			std::cout << "\rSaved~ " << '"' << s.Query(offset) << '"' << '\n';
		}
		catch (std::exception e) {
			std::cout << "-- Invalid Input --\n";
			i--;
		}
	}
	return 0;
}

BOOL WINAPI ConsoleHandler(DWORD signal) {
	if (signal == CTRL_CLOSE_EVENT) {
		s.Save();
		return TRUE;
	}
	return FALSE;
}