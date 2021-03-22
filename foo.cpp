#include "foo.h"
#include "lesson.h"

bool isFileExist(string& filename)
{
    ifstream fin;
    std::string tmpstr;
    if(filename[filename.size()-1] == '\n')
    {
        filename = filename.substr(0, filename.size()-1);
        fin.open(filename);
    }
    else fin.open(filename);
    if(!fin.is_open())
        return false;
    else return true;
}

void getInfoFromFile(const string& filename, vector<Lesson>& lessonlist)
{
    ifstream fin(filename);
    string buff;
    while (!fin.eof())
    {
        getline(fin, buff);
        addNewElementFromString(buff, lessonlist);
    }
    fin.close();
}

void addNewElementFromString(const string& str, vector<Lesson>& lessonlist)
{
    string tmpstr;
    vector<string> tmparr;
    size_t pointindex = -1, prevpindex = 0, numstep = 0;
    if(str != "")
    {
        for (size_t i = 0; i < str.size(); i++)
        {
            if(str[i] == ';' || i == str.size() - 1)
            {
                prevpindex = pointindex + 1;
                pointindex = i;
                if (i == str.size() - 1) ++pointindex;
                tmparr.push_back(str.substr(prevpindex, pointindex-prevpindex));
                numstep++;
            }
            if(numstep == 4) break;
        }
        if(atoi(tmparr[0].c_str()) != 0 || (atoi(tmparr[0].c_str()) == 0 && tmparr[0][0] == '0'))
        {
            if(atoi(tmparr[3].c_str()) != 0 || (atoi(tmparr[3].c_str()) == 0 && tmparr[0][0] == '0'))
            {
                Lesson lesson(atoi(tmparr[0].c_str()), tmparr[1], atoi(tmparr[2].c_str()), atoi(tmparr[3].c_str()));
                lessonlist.push_back(lesson);
            }
        }
    }
}

void writeFile(const string& filename, vector<Lesson>& lessonlist)
{
    ofstream fout(filename);
    for(size_t i = 0; i < lessonlist.size(); i++)
        lessonlist[i].setId(i+1);
    for (size_t i = 0; i < lessonlist.size(); i++)
        fout << lessonlist[i].getId() << ";" << lessonlist[i].getTitle() << ";" <<
                (int)lessonlist[i].getType() << ";" << lessonlist[i].getClassroom() << endl;
    fout.close();
}

