#include "SimpleOperations.hh"

#include <iostream>
using std::cout;
using std::endl;
using std::overflow_error;

const char* DELIMITER = "---";
const char* WELCOME = "Hello, world!";

void SimpleOperations::SimpleOperation::printDel() 
    { cout << DELIMITER << endl; }

void SimpleOperations::SimpleOperation::printWelcome() 
    { cout << WELCOME << endl; }

void SimpleOperations::SimpleOperation::printMex(const char* someMessage) 
    { cout << someMessage << endl; }