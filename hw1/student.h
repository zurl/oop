#include <string>

class Student{
    int score[3];
    int no;
    std::string name;
public:
    Student(int no, std::string & name, int score[3]);
    int get_score(int i);
    void print();
};