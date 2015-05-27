/*
	xie maolin 2015-4-25
	Record log.
*/

#ifndef _LOG_H
#define _LOG_H

#include <iostream>

using namespace std;

// log format
//#define LOG_FORMAT basename(__FILE__)<<":"<<__LINE__
#define LOG_FORMAT __FILE__<<":"<<__LINE__

#ifndef NDEBUG
# define LOG_DEBUG(msg) \
	do{\
		cout << LOG_FORMAT << "[DEBUG] " << msg << endl;\
	}while(0)
#else
# define LOG_DEBUG(msg)
#endif

#define LOG_INFO(msg) \
	do{\
		cout << LOG_FORMAT << "[INFO] " << msg << endl;\
	}while(0)

#define LOG_WARN(msg) \
	do{\
		cout << LOG_FORMAT << "[WARN] " << msg << endl;\
	}while(0)

#define LOG_ERROR(msg) \
	do{\
		cout << LOG_FORMAT << "[ERROR] " << msg << endl;\
	}while(0)

#define LOG_FATAL(msg) \
	do{\
		cout << LOG_FORMAT << "[FATAL] " << msg << endl;\
	}while(0)


#endif // _LOG_H
