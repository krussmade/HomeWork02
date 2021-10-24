#include "../beast.h"


beast::beast(char *name, int weight, beast::Diet diet) {
    this->name = new Utils::string(name);
    this->weight = weight;
    this->diet = diet;
}

void beast::out(FILE *out) {
    fprintf(out, "[Beast]\n"
                 "-name: %s\n"
                 "-weight: %d\n"
                 "-diet %d\n"
                 "-function result: %lf\n\n", name->toCharArray(), weight, (int) diet, someParameter());
}

beast::~beast() = default;
