/*
 * HTE.h
 *
 *  Created on: Oct 8, 2022
 *      Author: dancar
 */

#ifndef HTE_H_
#define HTE_H_

#include "EmployeeData.h"
#include "LL.h"

struct HTE {

	EmployeeData employee;
	LL<EmployeeData> collisions;


};


#endif /* HTE_H_ */
