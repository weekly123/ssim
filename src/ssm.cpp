/*
 * SSM.cpp
 *
 *  Created on: May 21, 2011
 *      Author: xmwu
 */

#include "ssm.h"

namespace ttl {
namespace ssim {

ssm::ssm() {
	// TODO Auto-generated constructor stub
	sub_msg_type_ = UNKNOWN;
	time_mode_ = LT;
	suffix_='^';

}

ssm::~ssm() {
	// TODO Auto-generated destructor stub
}

    string ssm::get_airline() const
    {
        return airline_;
    }

    string ssm::get_days_of_operation() const
    {
        return days_of_operation_;
    }

    string ssm::get_end_date() const
    {
        return end_date_;
    }

    const std::vector<eqt_info_t> & ssm::get_eqt_infos() const
    {
        return eqt_infos_;
    }

    string ssm::get_flight_number() const
    {
        return flight_number_;
    }

    int ssm::get_frequency_rate() const
    {
        return frequency_rate_;
    }

    const std::vector<leg_info_t> & ssm::get_leg_infos() const
    {
        return leg_infos_;
    }

    const std::vector<seg_info_t> & ssm::get_seg_infos() const
    {
        return seg_infos_;
    }

    string ssm::get_start_date() const
    {
        return start_date_;
    }

    char ssm::get_suffix() const
    {
        return suffix_;
    }

    time_mode_t ssm::get_time_mode() const
    {
        return time_mode_;
    }

    bool ssm::is_xasm() const
    {
        return xasm_;
    }

    sub_msg_type_t ssm::get_sub_msg_type()
    {
    	return sub_msg_type_;
    }

    void ssm::set_airline(const string & airline)
    {
        airline_ = airline;
    }

    void ssm::set_days_of_operation(const string & days_of_operation)
    {
        days_of_operation_ = days_of_operation;
    }

    void ssm::set_end_date(const string & end_date)
    {
        end_date_ = end_date;
    }

    void ssm::set_eqt_infos(const std::vector<eqt_info_t> & eqt_infos)
    {
        eqt_infos_ = eqt_infos;
    }

    void ssm::set_flight_number(const string & flight_number)
    {
        flight_number_ = flight_number;
    }

    void ssm::set_frequency_rate(int frequency_rate)
    {
        frequency_rate_ = frequency_rate;
    }

    void ssm::set_leg_infos(const std::vector<leg_info_t> & leg_infos)
    {
        leg_infos_ = leg_infos_;
    }

    void ssm::set_seg_infos(const std::vector<seg_info_t> & seg_infos)
    {
        seg_infos_ = seg_infos;
    }

    void ssm::set_start_date(const string & start_date)
    {
        start_date_ = start_date;
    }


    void ssm::set_suffix(char suffix)
    {
        suffix_ = suffix;
    }

    void ssm::set_time_mode(time_mode_t time_mode)
    {
        time_mode_ = time_mode;
    }


    void ssm::set_xasm(bool XASM)
    {
        xasm_ = XASM;
    }

    void ssm::set_sub_msg_type(sub_msg_type_t sub_msg_type)
    {
    	sub_msg_type_ = sub_msg_type;
    }

}//namespace ssim
}//namespace TTL
