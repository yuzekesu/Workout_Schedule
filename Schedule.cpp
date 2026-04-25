#include "Schedule.h"
#include <ctype.h>
#include <fstream>
#include <stdexcept>

Schedule::Schedule(const char* filePath) {
	m_filePath = filePath;
	std::ifstream stream(m_filePath, std::ios_base::in);
	std::string line;
	while (std::getline(stream, line)) {
		// skip blank lines 
		std::string noSpace = line;
		auto newEnd = std::remove(noSpace.begin(), noSpace.end(), ' ');
		newEnd = std::remove(noSpace.begin(), newEnd, '\t');
		noSpace.erase(newEnd, noSpace.end());
		if (noSpace.empty()) continue;
		// process inputs from the .txt
		size_t offset_TheFirstDigit = 0;
		size_t offset_TheCharBeforeTheLastSpace = 0;
		for (size_t i = 1; i < line.length(); i++) {
			const char c = line[i];
			if (isdigit(c)) {
				offset_TheFirstDigit = i;
				break;
			}
			else if (c != ' ' && c != '\t') {
				offset_TheCharBeforeTheLastSpace = i;
			}
		}
		// insert Execise to the vector
		std::string execiseLastDay;
		if (offset_TheFirstDigit == 0) {
			execiseLastDay = "0";
		}
		else {
			execiseLastDay = line.substr(offset_TheFirstDigit);
		}
		std::string execiseName = line.substr(0, offset_TheCharBeforeTheLastSpace + 1);
		Exercise e(execiseName, execiseLastDay);
		m_vector.push_back(e);
		// sort the Execise 
		Sort();
	}
	stream.close();
}

const std::string& Schedule::Query(size_t offset) const {
	if (offset >= m_vector.size()) {
		throw std::runtime_error("out of scope");
	}
	return m_vector[offset].Name();
}

void Schedule::Save() {
	std::ofstream stream(m_filePath, std::ios_base::out);
	for (auto e : m_vector) {
		stream << e.Name() << std::string(5, ' ') << e.LastDay() << '\n';
	}
	stream.close();
}

void Schedule::Sort() {
	for (size_t i = 0; i < m_vector.size(); i++) {
		bool noSwapDone = true;
		for (size_t u = 0; u < m_vector.size() - i - 1; u++) {
			if (m_vector[u].Delta() > m_vector[u + 1].Delta()) {
				std::swap(m_vector[u], m_vector[u + 1]);
				noSwapDone = false;
			}
		}
		if (noSwapDone = true) break;
	}
}

void Schedule::Update(size_t offset) {
	if (offset < m_vector.size()) {
		m_vector[offset].Update();
	}
	else {
		throw std::runtime_error("out of scope");
	}
}

std::ostream& operator<<(std::ostream& o, const Schedule& s) {
	size_t maxLength = 0;
	const std::vector<Exercise>& vector = s.m_vector;
	for (Exercise e : s.m_vector) {
		if (e.Name().length() > maxLength) {
			maxLength = e.Name().length();
		}
	}
	std::string frameX(maxLength + 20, '-');
	o << frameX;
	o << "\n";
	o << "|" << "i";
	o << "|" << std::left << std::setw(maxLength + 2) << "Exercise" << "|" << std::setw(13) << "Last Time" << "|";
	o << "\n";
	o << frameX;
	o << "\n";
	size_t row = 5 < vector.size() ? 5 : vector.size();
	for (size_t i = 0; i < row; i++) {
		o << "|" << i + 1;
		o << "|" << std::setw(maxLength + 2) << vector[i].Name() << "|" << vector[i].Delta() << std::setw(12) << " days ago" << "|";
		o << "\n";
	}
	o << frameX;
	o << "\n";
	return o;
}
