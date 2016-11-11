#include <iostream>
#include <string>
#include <iomanip> 
#include "student.h"
#include <map>
#include <algorithm>

const int INF = 0x3f3f3f3f;

void Student::add_score(std::string & course, int score){
    this->score[course] = score;
}

int Student::reduce(std::function<int(int, const std::string&, int)> fn, int initial_value) const {
    int result = initial_value;
    for(auto & x : score){
        result = fn(result, x.first, x.second);
    }
    return result;
}    

Student::Student(std::string &name)
    :name(name){}

void Student::for_each(std::function<void(const std::string&, int)> fn) const {
    for(auto x : score){
        fn(x.first, x.second);
    }
}

void Student::print() const{
    std::cout << name << " : ";
    for(auto x : score){
        std::cout << x.first << " : " << x.second << " , ";
    }
    std::cout<<" max : "<<this->reduce([](int prev, const std::string & course, int score){
         return std::max(prev, score);
    },-INF)<<" min : "<<this->reduce([](int prev,const std::string & course, int score){
         return std::min(prev, score);
    },INF)<<" average : "<<this->reduce([](int prev, const std::string & course, int score){
         return prev + score;
    },0) * 1.0 / this->score.size()<<std::endl;
}