#ifndef __bird__
#define __bird__

#include "animal.h"

class bird : public animal {
    bool isMigration;
public:
    bird(char *name, int weight, bool isMigration);

    void out(FILE *out) override;

    ~bird() override;
};

#endif
