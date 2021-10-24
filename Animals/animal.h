#ifndef __animal__
#define __animal__

#include "utils.h"
#include <string>
#include "constants.h"
#include <iostream>

class animal {
protected:
    int weight;
    Utils::string *name;
public:
    virtual void out(FILE *out) = 0;

    virtual double someParameter();

    static animal *read(FILE *in);

    static animal *readRnd();
    virtual ~animal();
};
#endif