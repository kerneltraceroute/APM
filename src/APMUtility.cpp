#include "APMutility.h"


namespace APMutility {
	std::string getLogCommand(const std::string& filename) {
		std::ifstream ifs(filename);
		if (std::string LoggingScript( (std::istreambuf_iterator<char>(ifs) ), (std::istreambuf_iterator<char>()) ); !LoggingScript.empty() )
			return LoggingScript;
		else {
			std::cerr << "Error: " << std::strerror(errno) << '\n';
			std::cerr << "File Name : "<<__FILE__ << " Line Number: "<<__LINE__ << "\n";
			throw("getLogCommand function error\n");
		}

	}

	void runCommand(const std::string& cmd, std::chrono::seconds interval) {
		int status; 
		while(true) {
			std::cout<< cmd << std::endl;
			if (status = std::system(cmd.c_str()); status < 0) {
				std::cerr << "Error: " << std::strerror(errno) << '\n';
				std::cerr << "File Name : "<<__FILE__ << " Line Number: "<<__LINE__ << "\n";
				throw("getLogCommand function error\n");
			}
			else {
			    if (WIFEXITED(status) && !WEXITSTATUS(status)) {
			        std::this_thread::sleep_for(interval);
			        continue;
			    }
			    else
			        std::cerr << "runCommand func. exited abnormaly\n";
			}

		}
	}
}