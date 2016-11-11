#include "student.h"
#include <iostream>
#include <vector>
#include <iomanip> 
#include <string>
#include <map>
#include <algorithm>

void input(std::map<std::string, Student> & students){  
    std::string name, course; int total, score;
    std::cin >> total;
    for(int i = 1; i <= total; i++){
        std::cin >> name >> course >> score;
        auto iter = students.find(name);
        if(iter == students.end()){
            students.emplace(name, Student(name));
            iter = students.find(name);
        }
        iter->second.add_score(course, score);
    }
}
void output(std::map<std::string, Student> & students){
    std::map<std::string,int> course_min, course_max, course_sum, course_cnt;
    for( auto & student : students){
        student.second.for_each([&](const std::string & course, int score){
            auto iter = course_min.find(course);
            if(iter == course_min.end()){
                course_min.emplace(course, 0x3f3f3f3f);
                course_max.emplace(course, -0x3f3f3f3f);
                course_sum.emplace(course, 0);
                course_cnt.emplace(course, 0);
            }
            course_min[course] = std::min(course_min[course], score);
            course_max[course] = std::max(course_max[course], score);
            course_sum[course] = course_sum[course] + score;
            course_cnt[course] = course_cnt[course] + 1;
        });
    }
    std::cout<<"============Course Summary============"<<std::endl;
    for(auto &x : course_min){
        std::cout<<x.first<<
        " max : "<<course_max[x.first]<<
        " min : "<<course_min[x.first]<<
        " average : "<<course_sum[x.first] * 1.0 / course_cnt[x.first]<<std::endl;
        
    }
    std::cout<<"============Student Summary============"<<std::endl;
    for( auto & student : students){
        student.second.print();
    }
}
int main(){
    std::map<std::string, Student> students;
    input(students);
    output(students);
    return 0;
}