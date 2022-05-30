#ifndef CONVERSE_H
#define CONVERSE_H
#include<string>
#include <vector>
using namespace std;
class PreToInfix{
    public:
    int result;
    vector<string> string_vector;
    vector<int> int_vector;

    PreToInfix();
    PreToInfix(string);
    string convertPreToIn();
    void computation_infix(string);

};
#endif // !CONVERSE_H