#ifndef LESSON_H
#define LESSON_H

#include <string>

using namespace std;

enum class EMPLOYMENT{
    TYPE_NOTHING,
    TYPE_LECTION,
    TYPE_PRACTICE,
    TYPE_LAB,
    TYPE_EXAM
};

class Lesson
{
private:
    int id;
    string title;
    EMPLOYMENT type;
    int classroom;
public:
    Lesson(int id, string title, size_t type, int classroom);
    int getId();
    string getTitle();
    EMPLOYMENT getType();
    int getClassroom();
    void setId(int id);
};

#endif // LESSON_H
