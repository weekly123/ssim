/*
 * exception_def.h
 *
 *  Created on: May 25, 2011
 *      Author: xmwu
 */

#ifndef EXCEPTION_DEF_H_
#define EXCEPTION_DEF_H_

#include <string>
#include <sstream>
#include <exception>

using std::string;

#define THROW_EXCEPTION(excep_t,msg) \
	do{\
		excep_t e( basename((char *)__FILE__),__LINE__,msg);\
        throw e;\
    }while(0)

namespace ttl {
namespace ssim {

class ssim_exception: public std::exception {
public:
	explicit ssim_exception(const char * file, int line,
			const std::string & msg) throw () {
		file_ = string(file);
		line_ = line;
		msg_ = msg;

		show_msg_ = "throw "  + get_name() +" at " +get_file()+":";
		std::stringstream ss(show_msg_);
		ss << line_;
		ss << " ." << msg_ << std::endl;
		show_msg_ = ss.str();
	}

	~ssim_exception() throw () {
	}

	virtual const char * what() const throw () {
		return show_msg_.c_str();
	}

	std::string get_file() {
		return file_;
	}
	;
	int get_line() {
		return line_;
	}
	std::string get_msg() {
		return msg_;
	}

protected:
	virtual string get_name() {
		return "ssim_exception";
	}
	;
protected:
	std::string file_;
	int line_;
	std::string msg_;
	std::string show_msg_;
};

class format_exception: public ssim_exception {
public:
	explicit format_exception(const char * file, int line,
			const std::string & msg) :
		ssim_exception(file, line, msg) {

	}

};//class format_exception

}//namespace ttl
}//namespace ssim
#endif /* EXCEPTION_DEF_H_ */
