/*
 * ssim_parser.cpp
 *
 *  Created on: May 25, 2011
 *      Author: xmwu
 */

#include "ssm_parser.h"
#include <iostream>

namespace ttl {

namespace ssim {

ssm_parser::ssm_parser() {
	// TODO Auto-generated constructor stub

}

ssm_parser::~ssm_parser() {
	// TODO Auto-generated destructor stub
}

int ssm_parser::init() {
	// TODO Auto-generated destructor stub
	flt_info_pattern_ = bos >> (s1 = repeat<2,2>( alnum )) >> (s2 = repeat<1,4> (digit) )>>(s3 = repeat<0,1>(upper))>> *_s >>*(digit) >>*((alnum)|'/');
	return 0;
}

boost::shared_ptr<ssm> ssm_parser::parse(const string & msg)
		throw (format_exception, std::bad_alloc) {

	std::string s_tmp = msg;
	s_tmp.erase(std::remove(s_tmp.begin(), s_tmp.end(), '\r'), s_tmp.end());
	std::istringstream ss(s_tmp);

	boost::shared_ptr<ssm> ssm_ptr(new ssm);

	smatch what;
	std::string s_line;

	std::getline(ss, s_line);
	if (s_line != "SSM")
		THROW_EXCEPTION(format_exception,"Not A SSM Message!");

	std::getline(ss, s_line);
	if (s_line == "LT")
		ssm_ptr->set_time_mode(LT);
	else if (s_line == "UTC")
		ssm_ptr->set_time_mode(UTC);
	else
		THROW_EXCEPTION(format_exception,"Wrong Time Mode!");

	std::getline(ss, s_line); //skip Message Reference

	std::getline(ss, s_line);
    parse_sub_msg_type(s_line,ssm_ptr);



	std::getline(ss, s_line);
	if(regex_match(s_line,what,flt_info_pattern_))
	{
        ssm_ptr->set_airline(what[1]);
        ssm_ptr->set_flight_number(what[2]);
        if( ! what[3].str().empty())
        {
        	ssm_ptr->set_suffix(what[3].str().at(0));
        }

	}
	else
	{
		THROW_EXCEPTION(format_exception,"Wrong Flight Info!");
	}






	return ssm_ptr;
}








void ssm_parser::parse_sub_msg_type(std::string s_line,boost::shared_ptr<ssm> ssm_ptr){
	if (s_line == "RPL")
		ssm_ptr->set_sub_msg_type(RPL);
	else if (s_line == "NEW")
		ssm_ptr->set_sub_msg_type(NEW);
	else if (s_line == "SKD")
		ssm_ptr->set_sub_msg_type(SKD);
	else if (s_line == "CNL")
		ssm_ptr->set_sub_msg_type(CNL);
	else if (s_line == "REV")
		ssm_ptr->set_sub_msg_type(REV);
	else if (s_line == "FLT")
		ssm_ptr->set_sub_msg_type(FLT);
	else if (s_line == "EQT")
		ssm_ptr->set_sub_msg_type(EQT);
	else if (s_line == "TIM")
		ssm_ptr->set_sub_msg_type(TIM);
	else if (s_line == "CON")
		ssm_ptr->set_sub_msg_type(CON);
	else if (s_line == "ADM")
		ssm_ptr->set_sub_msg_type(ADM);
	else if (s_line == "RSD")
		ssm_ptr->set_sub_msg_type(RSD);
	else if (s_line == "ACK")
		ssm_ptr->set_sub_msg_type(ACK);
	else if (s_line == "NAC")
		ssm_ptr->set_sub_msg_type(NAC);
	else
		THROW_EXCEPTION(format_exception,"Unknown Sub Msg Type!");
}

}//namespace ssim

}//namespace ttl
