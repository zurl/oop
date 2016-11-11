#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <functional>
#include <map>

class Student{
    std::map<std::string, int> score;
    std::string name;
public:
    Student(std::string & name) ;
    void add_score(std::string & course, int score);
    void print() const ;
    void for_each(std::function<void(const std::string&, int)> fn) const ;
    int reduce(std::function<int(int,const std::string&, int)> fn, int initial_value) const ;
};
#endif