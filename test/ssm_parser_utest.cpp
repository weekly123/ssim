/*
 * ssmparserutest.cpp
 *
 *  Created on: 2011-8-27
 *      Author: wxm
 */

#include "ssm_parser_utest.h"

#include <boost/tr1/memory.hpp>
using std::string;

TEST_F(ssm_parser_utest,test1)
{
	ASSERT_TRUE(false);
	string msg = "SSM\r\n"
		"LT\r\n"
		"17APR00001E002/029660-CZ6306/16APR\r\n"
		"RPL\r\n"
		"CZ6306\r\n"
		"16APR11 16APR11 6\r\n"
		"S 73G FAPCDIJWZYTKHMGSLQUEVBXNRO.F8C0W23Y88\r\n"
		"HFE2050 XIY2220 7//C\r\n"
		"XIY0400/1 URC0710/1 7//C\r\n"
		"HFEXIY 8/R/A/D/Z/T/K/H/M/G/S/L/Q/E/V/B/X/N/R\r\n"
		"HFEXIY 850/ACDIJ\r\n"
		"HFEURC 8/R/A/D/Z/T/K/H/M/G/S/L/Q/E/V/B/X/N/R\r\n"
		"HFEURC 850/ACDIJ\r\n"
		"XIYURC 8/R/A/D/Z/T/K/H/M/G/S/L/Q/E/V/B/X/N/R\r\n"
		"XIYURC 850/ACDIJ\r\n"
		"QQQQQQ 505/ET\r\n"
		"QQQXIY 98/T1\r\n"
		"XIYQQQ 99/T1\r\n"
		"QQQURC 98/T3\r\n"
		"QQQQQQ 851//\r\n";

	boost::shared_ptr<ttl::ssim::ssm> p_ssm;

	ASSERT_NO_THROW( p_ssm = ssm_parser_.parse(msg) );
	//CPPUNIT_ASSERT_THROW( p_ssm = ssm_parser_.parse(msg) , ttl::ssim::format_exception );
	ASSERT_EQ(ttl::ssim::RPL,p_ssm->get_sub_msg_type());
	ASSERT_EQ(ttl::ssim::LT,p_ssm->get_time_mode());
	ASSERT_EQ(string("CZ"),p_ssm->get_airline());
	ASSERT_EQ(string("6306"),p_ssm->get_flight_number());
	ASSERT_EQ('^',p_ssm->get_suffix());
	ASSERT_EQ(0,1);
}
TEST_F(ssm_parser_utest,test2)
{
	string msg = "SSM\r\n"
		"UTC\r\n"
		"17APR00001E002/029660-CZ6306/16APR\r\n"
		"NEW\r\n"
		"CZ921A 8/A/B\r\n"
		"16APR11 16APR11 6\r\n"
		"S 73G FAPCDIJWZYTKHMGSLQUEVBXNRO.F8C0W23Y88\r\n"
		"HFE2050 XIY2220 7//C\r\n"
		"XIY0400/1 URC0710/1 7//C\r\n"
		"HFEXIY 8/R/A/D/Z/T/K/H/M/G/S/L/Q/E/V/B/X/N/R\r\n"
		"HFEXIY 850/ACDIJ\r\n"
		"HFEURC 8/R/A/D/Z/T/K/H/M/G/S/L/Q/E/V/B/X/N/R\r\n"
		"HFEURC 850/ACDIJ\r\n"
		"XIYURC 8/R/A/D/Z/T/K/H/M/G/S/L/Q/E/V/B/X/N/R\r\n"
		"XIYURC 850/ACDIJ\r\n"
		"QQQQQQ 505/ET\r\n"
		"QQQXIY 98/T1\r\n"
		"XIYQQQ 99/T1\r\n"
		"QQQURC 98/T3\r\n"
		"QQQQQQ 851//\r\n";

	boost::shared_ptr<ttl::ssim::ssm> p_ssm;

	ASSERT_NO_THROW( p_ssm = ssm_parser_.parse(msg) );
	//CPPUNIT_ASSERT_THROW( p_ssm = ssm_parser_.parse(msg) , ttl::ssim::format_exception );
	ASSERT_EQ(ttl::ssim::NEW,p_ssm->get_sub_msg_type());
	ASSERT_EQ(ttl::ssim::UTC,p_ssm->get_time_mode());
	ASSERT_EQ(string("CZ"),p_ssm->get_airline());
	ASSERT_EQ(string("921"),p_ssm->get_flight_number());
	ASSERT_EQ('A',p_ssm->get_suffix());
}
