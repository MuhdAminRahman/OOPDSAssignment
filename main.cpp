#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <cstdlib>

using namespace std;

vector<string> program {
                        "Var int x", 
                        "Var int y", 
                        "= x 2",
                        "+ x 1",
                        "= y 9", 
                        "+ y x", 
                        "- y 4",
                        "+ y 20",
                        "- y x",
                        "* y 3",
                        "print y"
};

struct Value{
    string type;
    string value;
};


int main(){
    map<string, Value> prg;

// read the program line by line
for (auto command : program){
    string first;
    string type, name;
    string value;

    stringstream ss(command);
    ss >> first;
    for_each(first.begin(), first.end(), [](char &ch){ch = tolower(ch);});
    
    if (first == "var"){
        ss >> type;
        ss >> name;

        Value v = {type, value};
       
        if (type == "int")
          value = "0";
        else
            if (value == "string")
                value = "";

        prg[name].type = type;
        prg[name].value = value;
    }
    else
    if (first == "="){
        string name, value;
        ss >> name;
        ss >> value;
        prg[name].value = value;
    }
    else
    if (first == "+"){
        string name;
        string value;
        ss >> name;
        ss >> value;

        if (isdigit(value[0])){
            int old = stoi(prg[name].value); 
            old += stoi(value);
            prg[name].value = to_string(old);
        }
        else
        { 
            // + y x
            string valueoffirst = prg[name].value;
            string valueofsecond = prg[value].value;

            int old1 = stoi(valueoffirst); 
            int old2 = stoi(valueofsecond);
            old1 += old2;
            prg[name].value = to_string(old1);
        }
    }
    else
    if (first == "print"){
        string var;
        ss >> var;
        cout << prg[var].value << endl;
    }
    else
    if (first == "-"){
        string name;
        string value;
        ss >> name;
        ss >> value;

        if (isdigit(value[0])){
            int old = stoi(prg[name].value); 
            old -= stoi(value);
            prg[name].value = to_string(old);
        }
        else
        { 
            // + y x
            string valueoffirst = prg[name].value;
            string valueofsecond = prg[value].value;

            int old1 = stoi(valueoffirst); 
            int old2 = stoi(valueofsecond);
            old1 -= old2;
            prg[name].value = to_string(old1);
        }
    }
    else
    if (first == "*"){
        string name;
        string value;
        ss >> name;
        ss >> value;

        if (isdigit(value[0])){
            int old = stoi(prg[name].value); 
            old *= stoi(value);
            prg[name].value = to_string(old);
        }
        else
        { 
            // + y x
            string valueoffirst = prg[name].value;
            string valueofsecond = prg[value].value;

            int old1 = stoi(valueoffirst); 
            int old2 = stoi(valueofsecond);
            old1 *= old2;
            prg[name].value = to_string(old1);
        }
    }
    
    
}
