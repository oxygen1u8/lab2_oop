#include "lesson.h"

Lesson::Lesson(int id, string title, size_t type, int classroom)
{
    this->id = id;
    this->title = title;
    switch(type)
    {
    case 0:
        this->type = EMPLOYMENT::TYPE_NOTHING;
        break;
    case 1:
        this->type = EMPLOYMENT::TYPE_LECTION;
        break;
    case 2:
        this->type = EMPLOYMENT::TYPE_PRACTICE;
        break;
    case 3:
        this->type = EMPLOYMENT::TYPE_LAB;
        break;
    case 4:
        this->type = EMPLOYMENT::TYPE_EXAM;
        break;
    }
    this->classroom = classroom;
}

int Lesson::getId()
{
    return this->id;
}

int Lesson::getClassroom()
{
    return this->classroom;
}

EMPLOYMENT Lesson::getType()
{
    return this->type;
}

string Lesson::getTitle()
{
    return this->title;
}

void Lesson::setId(int id)
{
    if(id >= 0) this->id = id;
}
