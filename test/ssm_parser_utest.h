/*
 * ssmparserutest.h
 *
 *  Created on: 2011-8-27
 *      Author: wxm
 */

#ifndef SSMPARSERUTEST_H_
#define SSMPARSERUTEST_H_

#include "gtest/gtest.h"
#include "ssm_parser.h"

class ssm_parser_utest : public ::testing::Test {
public:
	virtual void SetUp(){ssm_parser_.init();}
	//virtual void TearDown(){}

	ttl::ssim::ssm_parser  ssm_parser_;
};

#endif /* SSMPARSERUTEST_H_ */
