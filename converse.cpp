#include <iostream>
#include<string>
#include <vector>
#include <stack>
#include <sstream>
#include "converse.h"
using namespace std;


PreToInfix:: PreToInfix(){}
PreToInfix:: PreToInfix(string str){
   
   stringstream s(str);
   string temp;

   while(getline(s, temp, ' ')){
       string_vector.push_back(temp);
   }

}
string PreToInfix:: convertPreToIn(){

    stack<string> my_string;
    for (int i = string_vector.size() -1; i >= 0 ; i--)
    {
        if(string_vector[i] == "+" ||string_vector[i] == "-" ||string_vector[i] == "*" ||string_vector[i] == "/" )
        {   
            if(my_string.size() < 2){
                cout<<"Error"<<endl;
                exit(1);
            }
            string first = my_string.top();
            my_string.pop();
            string second = my_string.top();
            my_string.pop();
            string tempInfix = "";
             if(string_vector[i] == "+" ||string_vector[i] == "-" )
             {
                 tempInfix = "(" + first + " " + string_vector[i] + " " + second + ")";
             }else{
                 tempInfix = first + " " + string_vector[i] + " " + second;
             }
            
            my_string.push(tempInfix);

            int valueA = int_vector.at(int_vector.size() - 1);
            int valueB = int_vector.at(int_vector.size() - 2);
            int_vector.pop_back(); int_vector.pop_back();
            int result;
            if(string_vector[i] == "+"){
                result = valueA + valueB;
            }else if(string_vector[i] == "-"){
                result = valueA - valueB;
            }else if(string_vector[i] == "*"){
                result = valueA * valueB;
            }else if(string_vector[i] == "/"){
                result = valueA / valueB;
            }else result = 0;

            int_vector.push_back(result);

        }else{
             my_string.push(string_vector[i]);
             int_vector.push_back(stoi(string_vector[i]));
        }    
       
    }
 
    if(my_string.size() !=1){
        cout<<"Error"<<endl;
        exit(1);
    }



    return my_string.top();
}




