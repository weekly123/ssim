/*
 * ssim_parser.h
 *
 *  Created on: May 25, 2011
 *      Author: xmwu
 */

#ifndef SSM_PARSER_H_
#define SSM_PARSER_H_

#include <boost/xpressive/xpressive.hpp>
#include "exception_def.h"
#include "ssm.h"

using boost::xpressive::sregex ;
using boost::xpressive::as_xpr;
using boost::xpressive::regex_match;

using namespace boost::xpressive;


namespace ttl {

namespace ssim {

class ssm_parser {
public:
	ssm_parser();
	virtual ~ssm_parser();
	int init();
	boost::shared_ptr<ssm> parse(const string & msg) throw (format_exception,std::bad_alloc);
private:
	sregex flt_info_pattern_;

private:
	void parse_sub_msg_type(std::string s_line,boost::shared_ptr<ssm> ssm_ptr);
};

}

}

#endif /* SSIM_PARSER_H_ */
