#ifndef FOO_H
#define FOO_H
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "lesson.h"


bool isFileExist(string& filename);
void readFile(const string& filename, vector<string>& strarray);
void getInfoFromFile(const string& filename, vector<Lesson>& lessonlist);
void addNewElementFromString(const string& str, vector<Lesson>& lessonlist);
void writeFile(const string& filename, vector<Lesson>& lessonlist);

#endif // FOO_H
