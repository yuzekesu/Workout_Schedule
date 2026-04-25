#include "Exercise.h"

const long long Exercise::m_today = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()).time_since_epoch().count();

Exercise::Exercise(std::string& execise, std::string& lastDay) {
	m_name = execise;
	m_lastDay = std::stoll(lastDay);
}

const std::string& Exercise::Name() const {
	return m_name;
}

std::string Exercise::LastDay() const {
	std::string lastDay = std::to_string(m_lastDay);
	return lastDay;
}

long long Exercise::Delta() const {
	long long delta = m_today - m_lastDay;
	if (m_today - m_lastDay > 7) {
		delta = 0;
	}
	return delta;
}

void Exercise::Update() {
	m_lastDay = m_today;
}
