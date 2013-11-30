/*
 * Exception.cpp
 *
 *  Created on: Nov 13, 2013
 *      Author: robin
 */

#include "Exception.h"

Exception::Exception()
	: text_("An exception without any info has been thrown."),
	  exit_(0)
{}

Exception::Exception(std::string s, bool exit)
	: text_(s),
	  exit_(exit)
{}

std::string Exception::what() {
	return text_;
}
Exception::~Exception() throw() {
	if (exit_) {
		exit(1);
	}
}
