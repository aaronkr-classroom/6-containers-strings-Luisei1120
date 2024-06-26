#pragma once

#ifndef GUARD_grade_h
#define GUARD_grade_h


#include<list>
#include <vector>
#include "Student_info.h"

bool fgrade(const Student_info&);
double grade(double , double, double);
double grade(double, double, vector<double>&);
double grade(const Student_info&);
list<Student_info> extract_fails(vector<Student_info>&);

#endif
