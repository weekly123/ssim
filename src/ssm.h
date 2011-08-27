/*
 * SSM.h
 *
 *  Created on: May 21, 2011
 *      Author: xmwu
 */

#ifndef SSM_H_
#define SSM_H_

#include <vector>
#include <string>
#include "type_def.h"

using std::string;

namespace ttl {
namespace ssim {


class ssm {
public:


	ssm();
	virtual ~ssm();
	string get_airline() const;
	string get_days_of_operation() const;
	string get_end_date() const;
	const std::vector<ttl::ssim::eqt_info_t> & get_eqt_infos() const;
	string get_flight_number() const;
	int get_frequency_rate() const;
	const std::vector<leg_info_t> & get_leg_infos() const;
	const std::vector<seg_info_t> & get_seg_infos() const;
	string get_start_date() const;
	char get_suffix() const;
	time_mode_t get_time_mode() const;
	bool is_xasm() const;
	sub_msg_type_t get_sub_msg_type();

	void set_airline(const string & airline_);
	void set_days_of_operation(const string & days_of_operation_);
	void set_end_date(const string & end_date_);
	void set_eqt_infos(const std::vector<eqt_info_t>& eqt_infos_);
	void set_flight_number(const string &flight_number_);
	void set_frequency_rate(int frequency_rate);
	void set_leg_infos(const std::vector<leg_info_t> & leg_infos_);
	void set_seg_infos(const std::vector<seg_info_t> & seg_infos_);
	void set_start_date(const string & start_date_);
	void set_suffix(char suffix_);
	void set_time_mode(time_mode_t time_mode_);
	void set_xasm(bool xasm);
	void set_sub_msg_type(sub_msg_type_t sub_msg_type);

private:

	//Message Heading
	time_mode_t time_mode_;

	//Message Reference

	//Action Information
	sub_msg_type_t sub_msg_type_;
	bool xasm_;
	string airline_;

	//Flight Information
	string flight_number_;
	char suffix_;

	//Period/Frequency Information
	string start_date_;
	string end_date_;
	string days_of_operation_; //e.g. 123   1234567
	int frequency_rate_;

	//Equipment Informations
	std::vector<eqt_info_t> eqt_infos_;

	//Routing or Leg Information
	std::vector<leg_info_t> leg_infos_;

	//Segment Information
	std::vector<seg_info_t> seg_infos_;
};

}//namespace ssim
}//namespace ttl

#endif /* SSM_H_ */
