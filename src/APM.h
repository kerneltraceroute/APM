#ifndef APM_H
#define APM_H


#include <iostream>
#include <fstream>
#include <chrono>  
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
	
#include <atomic>
#include <mutex>
#include <thread>

#include <cstdlib>
#include <cerrno>
#include <cstring>

//class RWSyncContainer;
//class RWSyncFile;

class APM {

std::chrono::seconds _time_interval;
std::string _log_file_name;
std::string _export_file_name;
std::string _script_file_name;
std::atomic<bool> status = false;
std::ostream& _os;

public:
	APM(const std::string& log_file_name,const std::string& export_file_name,const std::chrono::seconds time_interval,const std::string& script_file_name,std::ostream& os = std::cout) : 
		_log_file_name{log_file_name},
		_export_file_name{export_file_name},
		_time_interval{time_interval},
		_script_file_name{script_file_name},
		_os{os}	{ }

	bool start();
	bool pause();
	bool resume();
	bool stop();
	bool restart(const std::string& log_file_name,
				 const std::string& export_file_name,
				 const std::chrono::seconds time_interval,
				 const std::string& script_file_name);

};



#endif // APM_H