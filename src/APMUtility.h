#ifndef APMUTILITY_H
#define APMUTILITY_H

#include <string>
#include <chrono>
#include <fstream>

#include <cstdlib>
#include <cerrno>
#include <cstring>


namespace APMutility {
	std::string getLogCommand(const std::string& filename);
	void runCommand(const std::string& cmd, std::chrono::seconds interval);
}

#endif // APMUTILITY_H


