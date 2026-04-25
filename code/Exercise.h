#pragma once
#include <chrono>
#include <string>

class Exercise {
	long long m_lastDay;
	std::string m_name;
	static const long long m_today;
public:
	Exercise() = delete;
	Exercise(std::string& execise, std::string& lastDay);
	const std::string& Name() const;
	std::string LastDay() const;
	long long Delta() const;
	void Update();
};

