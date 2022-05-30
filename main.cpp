#include <iostream>
#include<string>
#include <vector>
#include "converse.h"
using namespace std;


int main(){
     string input;
     getline(cin, input);
     PreToInfix *abc = new PreToInfix(input);
     cout<<abc->convertPreToIn() << " = " << abc->int_vector.at(0)<<endl;
    return 0;
}

// / + * - 5 6 7 10 3