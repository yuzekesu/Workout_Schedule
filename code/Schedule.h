#pragma once
#include "Exercise.h"
#include <ostream>
#include <vector>



class Schedule {
	std::string m_filePath;
	std::vector<Exercise> m_vector;
public:
	Schedule() = delete;
	Schedule(const char* filePath);
	friend std::ostream& operator<<(std::ostream& o, const Schedule& s);
	const std::string& Query(size_t offset) const;
	void Save();
	void Sort();
	void Update(size_t offset);
};

