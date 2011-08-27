/*
 * type_def.h
 *
 *  Created on: May 25, 2011
 *      Author: xmwu
 */

#ifndef TYPE_DEF_H_
#define TYPE_DEF_H_

#include <string>

using std::string;

namespace ttl {
namespace ssim {


typedef enum {
		UNKNOWN = 0,
		SKD,
		NEW,
		CNL,
		RPL,
		REV,
		FLT,
		EQT,
		TIM,
		CON,
		ADM,
		RSD,
		ACK,
		NAC
	} sub_msg_type_t;
	typedef enum {
		UTC = 1, LT
	} time_mode_t;
	typedef struct {
		char service_type_;
		string aircraft_type; //EQT   e.g.  "737"  "747"
		string prbd; //Passenger Reservations Booking Designator
		string acv; //Aircraft Configuration/Version
	} eqt_info_t;

	typedef std::pair<int, string> dei_info_t;

	typedef struct {
		string dep_station;
		string dep_time;
		string dep_date_var;
		string arr_station;
		string arr_time;
		string arr_date_var;
		std::vector<dei_info_t> dei_infos;
	} leg_info_t;

	typedef struct {
		string dep_station;
		string arr_station;
		std::vector<dei_info_t> dei_infos;
	} seg_info_t;


}//	namespace ttl
}//	namespace ssim


#endif /* TYPE_DEF_H_ */
