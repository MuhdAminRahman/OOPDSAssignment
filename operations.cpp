#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <algorithm>

using namespace std;


// struct DeclObject
// {
//     string varCommand;
//     string dsType;
//     string itemType;
//     string dsName;
//     string value;
// };

struct Value
{
    string type;
    string value;
};

class Program
{
    vector<string> program;
    map<string, Value> prg;
    //map<string, DeclObject> runningProgram;

public:
    Program()
    {
        string comm;
        getline(cin, comm);
        while (comm.compare("#") != 0)
        {
            program.push_back(comm);
            operations();
            program.clear();
            getline(cin, comm); 
        }
    }


    int operations()
    {
        for (auto command : program)
        {
            string first;
            string type, name;
            string value;

            stringstream ss(command);
            ss >> first;
            for_each(first.begin(), first.end(), [](char &ch)
                     { ch = tolower(ch); });

            if (first == "var")
            {
                ss >> type;
                ss >> name;

                Value v = {type, value};

                if (type == "int")
                    value = "0";
                else if (value == "string")
                    value = "";

                prg[name].type = type;
                prg[name].value = value;
            }
            else if (first == "=")
            {
                string name, value;
                ss >> name;
                ss >> value;
                prg[name].value = value;
            }
            else if (first == "+")
            {
                string name;
                string value;
                ss >> name;
                ss >> value;

                if (isdigit(value[0]))
                {
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
            
            else if (first == "-")
            {
                string name;
                string value;
                ss >> name;
                ss >> value;

                if (isdigit(value[0]))
                {
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
            else if (first == "*")
            {
                string name;
                string value;
                ss >> name;
                ss >> value;

                if (isdigit(value[0]))
                {
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
            else if (first == "/")
            {
                string name;
                string value;
                ss >> name;
                ss >> value;

                if (isdigit(value[0]))
                {
                    int old = stoi(prg[name].value);
                    old /= stoi(value);
                    prg[name].value = to_string(old);
                }
                else
                {
                    // + y x
                    string valueoffirst = prg[name].value;
                    string valueofsecond = prg[value].value;

                    int old1 = stoi(valueoffirst);
                    int old2 = stoi(valueofsecond);
                    old1 /= old2;
                    prg[name].value = to_string(old1);
                }
            }
            else if (first == "%")
            {
                string name;
                string value;
                ss >> name;
                ss >> value;

                if (isdigit(value[0]))
                {
                    int old = stoi(prg[name].value);
                    old %= stoi(value);
                    prg[name].value = to_string(old);
                }
                else
                {
                    // + y x
                    string valueoffirst = prg[name].value;
                    string valueofsecond = prg[value].value;

                    int old1 = stoi(valueoffirst);
                    int old2 = stoi(valueofsecond);
                    old1 %= old2;
                    prg[name].value = to_string(old1);
                }
            }
            else if (first == "print")
            {
                string var;
                ss >> var;
                cout << prg[var].value << endl;
                  
            }
        }
        return 0;
    }
};

int main()
{
    Program p;
}