#include "student.h"
#include <iostream>
#include <vector>
#include <iomanip> 
#include <string>

void input(std::vector<Student> & students){  
    std::string name;
    int temp_score[3];
    for(int i = 1; i <= 10; i++){
        std::cin>>name;
        for(int j = 0; j < 3; j++){
            std::cin>>temp_score[j];
        }
        students.emplace_back(i, name, temp_score);
    }
}
void output(std::vector<Student> & students){
    int max_score[3], min_score[3], sum_score[3];
    for(int i = 0; i < 3; i++){
        max_score[i] = sum_score[i] = 0;
        min_score[i] = 0xFFFFFF;
    }
    for( auto & student : students){
        for(int i = 0; i < 3; i++){
            if(max_score[i] < student.get_score(i))max_score[i] = student.get_score(i);
            if(min_score[i] > student.get_score(i))min_score[i] = student.get_score(i);
            sum_score[i] += student.get_score(i);
        }
    }
    std::cout<< std::setw(10)<<"no"<< std::setw(10)<<"name";
    for(int i = 1; i < 4 ; i++){
        std::cout<< std::setw(9)<<"score"<<i;
    }
    std::cout<< std::setw(10)<<"average"<<std::endl;
    for( auto & student : students){
        student.print();
    }
    std::cout<< std::setw(10)<<" "<<std::setw(10)<<"average";
    for(int i = 0; i < 3; i++){
       std::cout<< std::setw(10) << sum_score[i] * 1.0 / students.size(); 
    }
    std::cout<<std::endl;
    std::cout<< std::setw(10)<<" "<<std::setw(10)<<"min";
    for(int i = 0; i < 3; i++){
       std::cout<< std::setw(10) << min_score[i];
    }
    std::cout<<std::endl;
    std::cout<< std::setw(10)<<" "<<std::setw(10)<<"max";
    for(int i = 0; i < 3; i++){
       std::cout<< std::setw(10) << max_score[i];
    }
    std::cout<<std::endl;
}
int main(){
    std::vector<Student> students;
    input(students);
    output(students);
    return 0;
}