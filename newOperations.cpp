#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <memory>

#include "DoublyLinkedList.cpp"
#include "Queue.cpp"
#include "Stack.cpp"
#include "BinarySearch.cpp"

using namespace std;

enum DataType
{
    INT,
    STRING,
    FLOAT,
    DOUBLE,
    BOOL,
    NULLDT
};

struct Value
{
    string type;
    string value;
    bool isTrue;
};

class Program
{
    vector<string> program;
    map<string, Value> prg;

    map<string, DataStructure<int> *> DSint;
    map<string, DataStructure<string> *> DSstring;
    map<string, DataStructure<double> *> DSdouble;
    map<string, DataStructure<float> *> DSfloat;

    map<string, DataStructureSandQ<int> *> DSSQint;
    map<string, DataStructureSandQ<string> *> DSSQstring;
    map<string, DataStructureSandQ<double> *> DSSQdouble;
    map<string, DataStructureSandQ<float> *> DSSQfloat;

    map<string, DataStructureBST<int> *> DSBSTint;

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

    void handleVariableDeclaration(stringstream &ss)
    {
        string type, dstype, name, value;
        ss >> type;
        if (type == "dll" || type == "sll" || type == "stack" || type == "queue" || type == "bst")
        {
            if (type == "bst")
            {
                ss >> name;
                DataType dataType = INT;
                createDataStructure(type, dataType, name);
                return;
            }
            ss >> dstype;
            ss >> name;
            DataType dataType = parseDataType(dstype);
            createDataStructure(type, dataType, name);
        }
        else
        {
            ss >> name;
            string checkname = name;
            if (checkNameVar(checkname) == 1)
            {
                cout << "Variable name is taken: " << checkname << "\nPlease insert a new one.\n";
                return;
            }
            Value v = {type, value};
            if (type == "int")
            {
                value = "0";
            }
            else if (type == "string")
            {
                value = "";
            }
            else if (type == "float")
            {
                value = "0.000";
            }
            else if (type == "double")
            {
                value = "0.00";
            }
            else if (type == "pointer")
            {
                value = "";
            }
            else if (type == "bool")
            {
                value = "true";
            }
            prg[name].type = type;
            prg[name].value = value;
        }
    }

    bool checkNameVar(string const &name)
    {
        if (prg.count(name) == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void printFunction(stringstream &ss)
    {
        string name;
        ss >> name;
        string checkname = name;
        if (checkNameDS(checkname) == 0 && checkNameVar(checkname) == 0)
        {
            cout << "The name of the Data Structure or Variable does not exist" << endl;
            return;
        };
        if (prg.find(name) != prg.end())
        {
            cout << prg[name].value << endl;
        }
        else if (DSint.find(name) != DSint.end())
        {
            DSint[name]->print();
        }
        else if (DSstring.find(name) != DSstring.end())
        {
            DSstring[name]->print();
        }
        else if (DSfloat.find(name) != DSfloat.end())
        {
            DSfloat[name]->print();
        }
        else if (DSdouble.find(name) != DSdouble.end())
        {
            DSdouble[name]->print();
        }
        else if (DSSQint.find(name) != DSSQint.end())
        {
            DSSQint[name]->print();
        }
        else if (DSSQstring.find(name) != DSSQstring.end())
        {
            DSSQstring[name]->print();
        }
        else if (DSSQfloat.find(name) != DSSQfloat.end())
        {
            DSSQfloat[name]->print();
        }
        else if (DSSQdouble.find(name) != DSSQdouble.end())
        {
            DSSQdouble[name]->print();
        }
        else if (DSBSTint.find(name) != DSBSTint.end())
        {
            cout << "There's no default print function for the BST data structure, please use the inorder/postorder/preorder command to print out the tree.\n";
            return;
        }
    }

    void variableOperations(stringstream &ss, const string &first)
    {
        string name, value;
        ss >> name;
        if (first == "if")
        {
            string boolname;
            ss >> boolname;
            if (prg[name].value == "False")
            {
                cout << "not yet.\n";
            }
            else
            {
                return;
            }
        }
        ss >> value;
        if (first == "=")
        {
            prg[name].value = value;
        }
        else if (first == "+")
        {
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
    }

    void stackAndQueueFunctions(stringstream &ss, const string &first)
    {
        string name, value, boolname;
        ss >> name;
        if (first == "push")
        {
            ss >> value;
            int addvalue = stoi(value);
            DSSQint[name]->push(addvalue);
        }
        else if (first == "pop")
        {
            DSSQint[name]->pop();
        }
        else if (first == "isfull")
        {
            ss >> boolname;
            bool boolvar = DSSQint[name]->isFull();
            if (boolvar == true)
            {
                prg[boolname].value = "True";
                cout << "The DS is full.\n";
            }
            else
            {
                prg[boolname].value = "False";
                cout << "False, DS is not full.\n";
            }
        }
        else if (first == "isempty")
        {
            ss >> boolname;
            bool boolvar = DSSQint[name]->isEmpty();
            if (boolvar == true)
            {
                prg[boolname].value = "True";
                cout << "The DS is empty.\n";
            }
             else
            {
                prg[boolname].value = "False";
                cout << "False, DS is not empty.\n";
            }
        }
        else if (first == "top" || first == "front")
        {
            string intname;
            ss >> intname;
            auto s = to_string(DSSQint[name]->first());
            prg[intname].value = s;
            cout << "x = " << prg[intname].value << endl;
        }
        else if (first == "bottom" || first == "back")
        {
            string intname;
            ss >> intname;
            auto s = to_string(DSSQint[name]->last());
            prg[intname].value = s;
            cout << "x = " << prg[intname].value << endl;
        }
    }

    void llFunctions(stringstream &ss, const string &first)
    {
        string name, value, ptrname;
        ss >> name;

        if (first == "addf")
        {
            ss >> value;
            int addvalue = stoi(value);
            if (DSint.find(name) != DSint.end())
                DSint[name]->AddF(addvalue);
            else
                cout << "Key not found" << endl;
        }
        else if (first == "adde")
        {
            ss >> value;
            int addvalue = stoi(value);
            if (DSint.find(name) != DSint.end())
                DSint[name]->AddE(addvalue);
            else
                cout << "Key not found" << endl;
        }
        else if (first == "adda")
        {
            ss >> value;
            string newvalue;
            ss >> newvalue;
            int addnewvalue = stoi(newvalue);
            int nodevalue = stoi(value);
            if (DSint.find(name) != DSint.end())
                DSint[name]->AddA(nodevalue, addnewvalue);
            else
                cout << "Key not found" << endl;
        }
        else if (first == "delf")
        {
            if (DSint.find(name) != DSint.end())
                DSint[name]->DelF();
            else
                cout << "Key not found" << endl;
        }
        else if (first == "dele")
        {
            if (DSint.find(name) != DSint.end())
                DSint[name]->DelE();
            else
                cout << "Key not found" << endl;
        }
        else if (first == "ptrstart")
        {
            ss >> ptrname;
            int ptr;
            string ptrstr;
            if (DSint.find(name) != DSint.end())
            {
                DSint[name]->PtrStart();
                ptr = DSint[name]->getNode();
                ptrstr = to_string(ptr);
                prg[ptrname].value = ptrstr;
            }
            else
            {
                cout << "Key not found" << endl;
            }
        }
        else if (first == "ptrend")
        {
            ss >> ptrname;
            int ptr;
            string ptrstr;
            if (DSint.find(name) != DSint.end())
            {
                DSint[name]->PtrEnd();
                ptr = DSint[name]->getNode();
                ptrstr = to_string(ptr);
                prg[ptrname].value = ptrstr;
            }
            else
            {
                cout << "Key not found" << endl;
            }
        }
        else if (first == "getnode")
        {
            string ptrname;
            ss >> ptrname;
            
            if(prg.find(name) != prg.end())
            {
                prg[name].value = prg[ptrname].value;
            }
            else
            {
                cout << "Key not found.\n";
            }
        }
        else if (first == "nextnode")
        {
            string ptrname;
            ss >> ptrname;
            int ptr;
            string ptrstr;
            if (DSint.find(name) != DSint.end())
            {
                DSint[name]->nextNode();
                ptr = DSint[name]->getNode();
                ptrstr = to_string(ptr);
                prg[ptrname].value = ptrstr;
            }
            else
            {
                cout << "Key not found" << endl;
            }
        }
        else if (first == "prevnode")
        {
            string ptrname;
            ss >> ptrname;
            int ptr;
            string ptrstr;
            if (DSint.find(name) != DSint.end())
            {
                DSint[name]->prevNode();
                ptr = DSint[name]->getNode();
                ptrstr = to_string(ptr);
                prg[ptrname].value = ptrstr;
            }
            else
            {
                cout << "Key not found" << endl;
            }
        }
        else if (first == "ishead")
        {
            string ptrname, boolname;
            ss >> ptrname;
            ss >> boolname;

            if (DSint.find(name) != DSint.end())
            {
                bool isHeadVar = DSint[name]->isHead();
                if (isHeadVar == true)
                {
                    prg[boolname].value = "True";
                    cout << "At head.\n";
                }
                else
                {
                    prg[boolname].value = "False";
                    cout << "False,not at head.\n";
                }
            }
            else
            {
                cout << "Key not found" << endl;
            }
        }
        else if (first == "isend")
        {
            string ptrname, boolname;
            ss >> ptrname;
            ss >> boolname;

            if (DSint.find(name) != DSint.end())
            {
                bool isEndVar = DSint[name]->isEnd();
                if (isEndVar == true)
                {
                    prg[boolname].value = "True";
                    cout << "At tail.\n";
                }
                else
                {
                    prg[boolname].value = "False";
                    cout << "False,not at tail.\n";
                }
            }
            else
            {
                cout << "Key not found" << endl;
            }
        }
    }

    void bstFunctions(stringstream &ss, const string &first)
    {
        string name;
        ss >> name;

        if (first == "insert")
        {
            string value;
            ss >> value;
            int addvalue = stoi(value);
            DSBSTint[name]->insert(addvalue);
        }
        else if (first == "delete")
        {
            string value;
            ss >> value;
            int addvalue = stoi(value);
            DSBSTint[name]->Delete(addvalue);
        }
        else if (first == "root")
        {
            string varname;
            ss >> varname;
            int rootvalue = stoi(prg[varname].value);
            DSBSTint[name]->Root(rootvalue);
        }
        else if (first == "inorder")
        {
            DSBSTint[name]->inorder();
        }
        else if (first == "postorder")
        {
            DSBSTint[name]->postorder();
        }
        else if (first == "preorder")
        {
            DSBSTint[name]->preorder();
        }
    }

    void handleGeneralFunctions(stringstream &ss, const string &first)
    {

        if (first == "print")
        {
            printFunction(ss);
        }
        else if (first == "delete")
        {
            string name;
            ss >> name;
            deleteDS(name);
        }
        else if (first == "search")
        {
            bool isTrue = searchDataStructure(ss);
            if (isTrue == true)
            {
                cout << "True.\n";
            }
            else
            {
                cout << "False.\n";
            }
        }
        else if (first == "sort")
        {
            string name;
            ss >> name;
            sortDataStructure(name);
        }
        else if (first == "clone")
        {
            string name;
            ss >> name;
            cloneDataStructure(ss, name);
        }

        else if (first == "addf" || first == "delf" || first == "adde" || first == "dele" || first == "adda" || first == "ptrstart" || first == "ptrend" || first == "getnode" || first == "nextnode" || first == "prevnode" || first == "ishead" || first == "isend")
        {
            llFunctions(ss, first);
        }
        else if (first == "push" || first == "pop" || first == "isfull" || first == "isempty" || first == "top" || first == "bottom" || first == "front" || first == "back")
        {
            stackAndQueueFunctions(ss, first);
        }
        else if (first == "insert" || first == "delete" || first == "root" || first == "inorder" || first == "postorder" || first == "preorder")
        {
            bstFunctions(ss, first);
        }
        else
        {
            variableOperations(ss, first);
        }
        // ... other function handlers
    }

    bool checkNameDS(string const &name)
    {
        if (DSint.count(name) == 1 || DSSQint.count(name) == 1 || DSstring.count(name) == 1 || DSSQstring.count(name) == 1 || DSfloat.count(name) == 1 || DSSQfloat.count(name) == 1 || DSdouble.count(name) == 1 || DSSQdouble.count(name) == 1 || DSBSTint.count(name) == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void createDataStructure(const string &type, DataType dataType, const string &name)
    {
        string checkname = name;
        if (checkNameDS(checkname) == 1)
        {
            cout << "The name of the Data Structure is already taken please use a new name for your new DS" << endl;
            return;
        };

        switch (dataType)
        {
        case INT:
            if (type == "dll")
            {
                DSint[name] = new DoublyLinkedList<int>();
            }
            else if (type == "sll")
            {
                DSint[name] = new SinglyLinkedList<int>();
            }
            else if (type == "stack")
            {
                DSSQint[name] = new Stack<int>();
            }
            else if (type == "queue")
            {
                DSSQint[name] = new Queue<int>(30);
            }
            else if (type == "bst")
            {
                DSBSTint[name] = new BinarySearchTree<int>();
            }
            break;
        case STRING:
            if (type == "dll")
            {
                DSstring[name] = new DoublyLinkedList<string>();
            }
            else if (type == "sll")
            {
                DSstring[name] = new SinglyLinkedList<string>();
            }
            else if (type == "stack")
            {
                DSSQstring[name] = new Stack<string>();
            }
            else if (type == "queue")
            {
                DSSQstring[name] = new Queue<string>(30);
            }
            break;
        case FLOAT:
            if (type == "dll")
            {
                DSfloat[name] = new DoublyLinkedList<float>();
            }
            else if (type == "sll")
            {
                DSfloat[name] = new SinglyLinkedList<float>();
            }
            else if (type == "stack")
            {
                DSSQfloat[name] = new Stack<float>();
            }
            else if (type == "queue")
            {
                DSSQfloat[name] = new Queue<float>(30);
            }
            break;
        case DOUBLE:
            if (type == "dll")
            {
                DSdouble[name] = new DoublyLinkedList<double>();
            }
            else if (type == "sll")
            {
                DSdouble[name] = new SinglyLinkedList<double>();
            }
            else if (type == "stack")
            {
                DSSQdouble[name] = new Stack<double>();
            }
            else if (type == "queue")
            {
                DSSQdouble[name] = new Queue<double>(30);
            }
            break;
        case NULLDT:
            cout << "Invalid Data Type for Data Structure" << endl;
            break;
        }
    }

    DataType parseDataType(const string &type)
    {
        if (type == "int")
        {
            return INT;
        }
        else if (type == "string")
        {
            return STRING;
        }
        else if (type == "float")
        {
            return FLOAT;
        }
        else if (type == "double")
        {
            return DOUBLE;
        }
        else if (type == "bool")
        {
            return BOOL;
        }
        // error
        else
        {
            cout << "Invalid datatype: " << type << endl;
            return NULLDT;
        }
    }

    void deleteDS(const string &name)
    {
        string checkname = name;
        if (checkNameDS(checkname) == 0)
        {
            cout << "The name of the Data Structure does not exist" << endl;
            return;
        };
        if (DSint.count(name) == 1)
        {
            DSint[name]->Delete();
            DSint.erase(name);
        }
        else if (DSstring.count(name) == 1)
        {
            DSstring[name]->Delete();
            DSstring.erase(name);
        }
        else if (DSfloat.count(name) == 1)
        {
            DSfloat[name]->Delete();
            DSfloat.erase(name);
        }
        else if (DSdouble.count(name) == 1)
        {
            DSdouble[name]->Delete();
            DSdouble.erase(name);
        }
        else if (DSSQint.count(name) == 1)
        {
            DSSQint.erase(name);
        }
        else if (DSSQstring.count(name) == 1)
        {
            DSSQstring.erase(name);
        }
        else if (DSSQfloat.count(name) == 1)
        {
            DSSQfloat.erase(name);
        }
        else if (DSSQdouble.count(name) == 1)
        {
            DSSQdouble.erase(name);
        }
    }

    bool searchDataStructure(stringstream &ss)
    {
        string dsname;
        string varname;
        bool boolvar;
        ss >> dsname;
        ss >> varname;

        DataType dataType = parseDataType(prg[varname].type);
        bool isVarInDS = searchDSFunctions(dsname, dataType, varname);

        return isVarInDS;
    }

    bool searchDSFunctions(const string &dsname, DataType dataType, const string &varname)
    {
        int varint;
        string varstr;
        float varflt;
        double vardoub;
        switch (dataType)
        {
        case INT:
            varint = stoi(prg[varname].value);
            if (DSint.find(dsname) != DSint.end())
            {
                return DSint[dsname]->search(varint);
            }
            else if (DSSQint.find(dsname) != DSSQint.end())
            {
                return DSSQint[dsname]->search(varint);
            }
            break;
        case STRING:
            varstr = prg[varname].value;
            if (DSstring.find(dsname) != DSstring.end())
            {
                return DSstring[dsname]->search(varstr);
            }
            else if (DSSQstring.find(dsname) != DSSQstring.end())
            {
                return DSSQstring[dsname]->search(varstr);
            }
            break;
        case FLOAT:
            varflt = stof(prg[varname].value);
            if (DSfloat.find(dsname) != DSfloat.end())
            {
                return DSfloat[dsname]->search(varflt);
            }
            else if (DSSQfloat.find(dsname) != DSSQfloat.end())
            {
                return DSSQfloat[dsname]->search(varflt);
            }
            break;
        case DOUBLE:
            vardoub = stod(prg[varname].value);
            if (DSdouble.find(dsname) != DSdouble.end())
            {
                return DSdouble[dsname]->search(vardoub);
            }
            else if (DSSQdouble.find(dsname) != DSSQdouble.end())
            {
                return DSSQdouble[dsname]->search(vardoub);
            }
            break;
        case BOOL:
        {
            cout << "There's no bool type DataStructure" << endl;
            break;
        }
        case NULLDT:
            cout << "Invalid Data Type for Data Structure" << endl;
            break;
        }
        return false;
    }

    void sortDataStructure(const string &dsname)
    {
        if (DSint.find(dsname) != DSint.end())
        {
            DSint[dsname]->sort();
        }
        else if (DSstring.find(dsname) != DSstring.end())
        {
            DSstring[dsname]->sort();
        }
        else if (DSfloat.find(dsname) != DSfloat.end())
        {
            DSfloat[dsname]->sort();
        }
        else if (DSdouble.find(dsname) != DSdouble.end())
        {
            DSdouble[dsname]->sort();
        }
        else if (DSSQint.find(dsname) != DSSQint.end())
        {
            DSSQint[dsname]->sort();
        }
        else if (DSSQstring.find(dsname) != DSSQstring.end())
        {
            DSSQstring[dsname]->sort();
        }
        else if (DSSQfloat.find(dsname) != DSSQfloat.end())
        {
            DSSQfloat[dsname]->sort();
        }
        else if (DSSQdouble.find(dsname) != DSSQdouble.end())
        {
            DSSQdouble[dsname]->sort();
        }
    }

    void cloneDataStructure(stringstream &ss, const string &dsname)
    {
        string newname;
        ss >> newname;
        if (DSint.find(dsname) != DSint.end())
        {
            DSint[newname] = DSint[dsname];
        }
        else if (DSstring.find(dsname) != DSstring.end())
        {
            DSstring[newname] = DSstring[dsname];
        }
        else if (DSfloat.find(dsname) != DSfloat.end())
        {
            DSfloat[newname] = DSfloat[dsname];
        }
        else if (DSdouble.find(dsname) != DSdouble.end())
        {
            DSdouble[newname] = DSdouble[dsname];
        }
        else if (DSSQint.find(dsname) != DSSQint.end())
        {
            DSSQint[newname] = DSSQint[dsname];
        }
        else if (DSSQstring.find(dsname) != DSSQstring.end())
        {
            DSSQstring[newname] = DSSQstring[dsname];
        }
        else if (DSSQfloat.find(dsname) != DSSQfloat.end())
        {
            DSSQfloat[newname] = DSSQfloat[dsname];
        }
        else if (DSSQdouble.find(dsname) != DSSQdouble.end())
        {
            DSSQdouble[newname] = DSSQdouble[dsname];
        }
    }

    int operations()
    {
        for (const auto &command : program)
        {
            stringstream ss(command);
            string first;
            ss >> first;
            transform(first.begin(), first.end(), first.begin(), ::tolower);
            if (first == "var")
            {
                handleVariableDeclaration(ss);
            }
            else
            {
                handleGeneralFunctions(ss, first);
            }
        }
        return 0;
    }
};

int main()
{
    Program p;
}