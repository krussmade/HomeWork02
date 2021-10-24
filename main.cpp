#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "Animals/container.h"

void errMessage1() {
    std::cout << "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

int main(int argc, char *argv[]) {
    int capacity;
    container *cont;

    FILE *in = fopen("C:\\Users\\tagir\\Desktop\\a.txt", "r");
    fscanf(in, "%d\n", &capacity);
    cont = new container(capacity);
    cont->fill(in);
    fclose(in);

    FILE *out1 = fopen("C:\\Users\\tagir\\Desktop\\b.txt", "w");
    FILE *out2 = fopen("C:\\Users\\tagir\\Desktop\\c.txt", "w");

    fprintf(out1, "Filled container:\n");
    cont->out(out1);

    cont->heapSort();

    fprintf(out2, "Sorted container complete:\n");
    cont->out(out2);

    delete cont;
    printf("Stop\n");

    fclose(out1);
    fclose(out2);
    return 0;


//======================================================================================================================
//    if (argc != 5) {
//        errMessage1();
//        return 1;
//    }
//    std::cout << "Start\n";
//
//    int capacity;
//    container *cont;
//
//    if (!strcmp(argv[1], "-f")) {
//        FILE *in = fopen(argv[2], "r");
//        fscanf(in, "%d\n", &capacity);
//        cont = new container(capacity);
//        cont->fill(in);
//        fclose(in);
//    } else {
//        if (!strcmp(argv[1], "-n")) {
//            capacity = atoi(argv[2]);
//            if ((capacity < 1) || (capacity > 10000)) {
//                std::cout << "incorrect numer of figures = "
//                          << capacity
//                          << ". Set 0 < number <= 10000\n";
//                return 3;
//            }
//            srand(static_cast<unsigned int>(time(0)));
//            cont = new container(capacity);
//            cont->fill();
//        } else {
//            errMessage2();
//            return 2;
//        }
//    }
//
//    FILE *out1 = fopen(argv[3], "w");
//    FILE *out2 = fopen(argv[4], "w");
//
//    fprintf(out1, "Filled container:\n");
//    cont->out(out1);
//
//    cont->heapSort();
//
//    fprintf(out2, "Sorted container complete:\n");
//    cont->out(out2);
//
//    delete cont;
//    printf("Stop\n");
//
//    fclose(out1);
//    fclose(out2);
//    return 0;
}