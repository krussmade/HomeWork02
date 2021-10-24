#include "../animal.h"
#include "../fish.h"
#include "../bird.h"
#include "../beast.h"


animal::~animal() {
    delete name;
}

animal *animal::readRnd() {
    int type = std::rand() % 3;
    int weight = std::rand() % 1000;
    char name[NAME_SIZE];
    Utils::RandomName(name, NAME_SIZE);
    switch (type) {
        case 0: {
            int habitat = std::rand() % 5;
            return new fish(name, weight, (fish::Habitat) habitat);
        }
        case 1: {
            int diet = std::rand() % 3;
            return new beast(name, weight, (beast::Diet) diet);
        }
        case 2: {
            bool isMigration = std::rand() % 2;
            return new bird(name, weight, isMigration);
        }
    }
}

animal *animal::read(FILE *in) {
    char type[NAME_SIZE];
    char name[NAME_SIZE];
    int weight;
    fscanf(in, "%s\n", type);

    if (!strcmp(type, "fish")) {
        int habitat;
        fscanf(in, "%s %d %d\n", name, &weight, &habitat);
        return new fish(name, weight, (fish::Habitat) habitat);
    } else if (!strcmp(type, "beast")) {
        int diet;
        fscanf(in, "%s %d %d\n", name, &weight, &diet);
        return new beast(name, weight, (beast::Diet) diet);
    } else if (!strcmp(type, "bird")) {
        int isMigration;
        fscanf(in, "%s %d %d\n", name, &weight, &isMigration);
        return new bird(name, weight, (bool) isMigration);
    } else {
        printf("ERROR: Wrong movie type %s\n", type);
        exit(1);
    }
}

double animal::someParameter() {
    int sum = 0;

    for (int i = 0; i < name->lenght(); ++i) {
        sum += (int) (*name)[i];
    }
    return sum / (double) weight;
}
