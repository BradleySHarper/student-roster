#pragma once
#include <string>
using namespace std;

//Enumerated data type DegreeProgram
enum DegreeProgram {SECURITY, NETWORK, SOFTWARE};

//Parallel array for converting each degree to string
static const string degreeTypes[] = { "SECURITY", "NETWORK ", "SOFTWARE" };