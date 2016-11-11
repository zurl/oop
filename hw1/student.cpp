#include <iostream>
#include <string>
#include <iomanip> 
#include "student.h"

Student::Student(int no, std::string &name, int score[3])
    : no(no), name(name){
    for (int i = 0; i < 3; i++){
        this->score[i] = score[i];
    }
}

void Student::print(){
    double sum = 0.0;
    std::cout << std::setw(10) << no << std::setw(10) << name;
    for (int i = 0; i < 3; i++){
        std::cout << std::setw(10) << score[i];
        sum += score[i];
    }
    std::cout << std::setw(10) << sum / 3 << std::endl;
}
int Student::get_score(int i){
    return score[i];
}