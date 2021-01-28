#include "Manager.h"
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

Manager::Manager()
{
}

Manager::~Manager()
{
}

void Manager::run(const char* command)
{
    fin.open(command); //command.txt open
    flog.open("log.txt", ios::app); //log.txt open
    if (!fin)
    {
        flog << "File Open Error" << endl;
        return;
    }

    char cmd[32];

    queue<PatientNode*>* Patient_Queue = new queue<PatientNode*>;
    ds_queue = Patient_Queue;

    LocationBST* DS_BST = new LocationBST;
    ds_bst = DS_BST;
    LocationHeap* DS_Heap = new LocationHeap;
    ds_heap = DS_Heap;

    while (!fin.eof()) //last line end
    {
        fin.getline(cmd, 32);
        cout << cmd << endl;
        char* tmp;
        tmp = strtok(cmd, " "); //string truncation

        ////////////////LOAD////////////////////////////
        if (strcmp(tmp, "LOAD") == 0)
        {
            if (Patient_Queue->size() == 0) //when queue empty
            {
                if (LOAD(Patient_Queue))
                {
                    PrintSuccess("LOAD"); //success print
                }
                else
                    PrintErrorCode(100); //false print, load error
            }
            else
                PrintErrorCode(100); //false print load error
        }
        ///////////////////////ADD////////////////////////////
        else if (strcmp(tmp, "ADD") == 0)
        {
            char* name;
            float temperature = 0;
            char* cough;
            char* location;

            name = strtok(NULL, " ");
            temperature = atof(strtok(NULL, " "));
            cough = strtok(NULL, " ");
            location = strtok(NULL, " ");

            if (ADD(name, temperature, cough, location, ds_queue))
            {
                AddSuccess("ADD", name, temperature, cough, location); //success print
            }
            else
            {
                PrintErrorCode(200); //false print
            }
        }
        ///////////////////////QPOP////////////////////////////
        else if (strcmp(tmp, "QPOP") == 0)
        {
            int num;
            num = atoi(strtok(NULL, " "));
            if (QPOP(DS_BST, num))
            {
                PrintSuccess("QPOP"); //success print
            }
            else
            {
                PrintErrorCode(300); //false print
            }
        }
        ///////////////////////SEARCH////////////////////////////
        else if (strcmp(tmp, "SEARCH") == 0)
        {
            char* search_name;
            search_name = strtok(NULL, " ");
            if (SEARCH(DS_BST, search_name)== false)
            {
                PrintErrorCode(400); //false print
            }
        }
        ///////////////////////PRINT////////////////////////////
        else if (strcmp(tmp, "PRINT") == 0)
        {
            char* BH = NULL;
            char* traverse = NULL;
            BH = strtok(NULL, " ");
            if (strcmp(BH, "B") == 0)
                traverse = strtok(NULL, " ");
            if (PRINT(DS_BST, BH, traverse)==false)
            {
                PrintErrorCode(500); //false print
            }
        }
        ///////////////////////BPOP////////////////////////////
        else if (strcmp(tmp, "BPOP") == 0)
        {
            char* name;
            name = strtok(NULL, " ");

            if (BPOP(DS_BST, name))
            {
                PrintSuccess("BPOP"); //success print
            }
            else
            {
                PrintErrorCode(600); //false print
            }
        }
        ///////////////////////EXIT////////////////////////////
        else if (strcmp(tmp, "EXIT") == 0)
        {
            PrintSuccess("EXIT");
            break;
        }
        else
        {
            flog << "========== ERROR ==========" << endl;
            flog << "Command Error" << endl;
            flog << "===========================" << endl << endl;
        }
        
    }

    fin.close();
    flog.close();
}

//////////////////LOAD: read data.txt file////////////////////////////////////////////
bool Manager::LOAD(queue<PatientNode*>* Patient_Queue)
{
    ifstream Data_text("data.txt"); //read data.txt file input

    if (!Data_text.is_open())
        return false;

    char name[10];
    float temperature = 0;
    char cough;
    char location[10];

    char str[64];

    while (!Data_text.eof())
    {
        //Data_text.getline(str, 32);
        char* name = new char;
        char* location = new char;
        Data_text >> name;
        Data_text >> temperature;
        Data_text >> cough;
        Data_text >> location; 

        if (name == NULL || temperature == NULL || cough == NULL || location == NULL)
            return false;
        //input wrong

        PatientNode* newNode = new PatientNode; //PatientNode dynamic allocation
        newNode->SetName(name);
        newNode->SetTemp(temperature);
        newNode->SetCough(cough);
        newNode->SetLoc(location);
        
        Patient_Queue->push(newNode); //store PatientNode in ds_queue
        //delete newNode; // delete node
    }
    Data_text.close();
    
    return true;
}

///////////////////////ADD////////////////////////////
bool Manager::ADD(char* name, float temperature, char* cough, char* location, queue<PatientNode*>* ds_queue) //add directly
{
    if (name == NULL || temperature == NULL || cough == NULL || location == NULL)
        return false;
    //input wrong

    PatientNode* newNode = new PatientNode; //PatientNode dynamic allocation

    newNode->SetName(name);
    newNode->SetTemp(temperature);
    newNode->SetCough(cough[0]);
    newNode->SetLoc(location);
    ds_queue->push(newNode); //store PatientNode in ds_queue
    //delete newNode; // delete node
    
    return true;
}

///////////////////////QPOP: Move data to BST////////////////////////////
bool Manager::QPOP(LocationBST* DS_BST,int size)
{
    if (ds_queue->size() < size)
        return false; //enter a number larger than data

    if (DS_BST->GetRoot() == NULL)
    {
        char* location[7] = { (char*)"Gwangju" , (char*)"Daegu", (char*)"Seoul", (char*)"Busan", (char*)"Daejeon",(char*)"Incheon", (char*)"Ulsan" };
        //array location

        for (int i = 0; i < 7; i++)
        {
            LocationNode* newlocationNode = new LocationNode; //LocationNode dynamic allocation
            newlocationNode->SetLoc(location[i]);
            ds_bst->Insert_Location(newlocationNode);
            //delete newlocationNode;
        } // locationBST sucess
    }
    
    for (int i = 0; i < size; i++)
    {
        ds_bst->Insert_Patient(ds_queue->front());
        ds_queue->pop();
    }//patient info BST insert

    return true;
}

///////////////////////SEARCH: name search////////////////////////////
bool Manager::SEARCH(LocationBST* DS_BST, char* name)
{
    if (DS_BST->GetRoot() == NULL)
        return false;

    int a;
    a = DS_BST->Search(name);
    char diease;

    if (a == 2)
        return false;
    else if (a == 1)
        diease = '-';
    else
        diease = '+';
    //return 0: Y, return 1: N, return 2:false


    flog << "========== " << "SEARCH" << " ==========" << endl;
    flog << name << "/" << diease << endl;
    flog << "============================" << endl << endl;

    return true;
}

bool Manager::PRINT(LocationBST* DS_BST, char* BH, char* traverse)
{
    if (DS_BST->GetRoot() == NULL)
        return false;

    if (strcmp(BH,"B")== 0)
    {
        if (strcmp(traverse, "PRE") == 0) //preorder
            DS_BST->Print_PRE();

        else if (strcmp(traverse, "IN") == 0) //inorder
            DS_BST->Print_IN();

        else if (strcmp(traverse, "POST") == 0) //postorder
            DS_BST->Print_POST();

        else if (strcmp(traverse, "LEVEL") == 0) //level order
            DS_BST->Print_LEVEL();

        else //fail
            return false;
    }

    else //Heap print
    {
        if (ds_bst == NULL)
            return false;
        ds_heap->Print();

    }
    return true;
}

bool Manager::BPOP(LocationBST* DS_BST, char* name)
{
    if (DS_BST->GetRoot() == NULL)
        return false; 

    char* location;
    location = DS_BST->Delete(name);
    if (location == name) //not return location, name not find
        return false;

    ds_heap->Insert(location); //insert

    return true;
}

void Manager::PrintErrorCode(int num)
{
    flog << "========== ERROR ==========" << endl;
    flog << num << endl;
    flog << "===========================" << endl << endl;
}

void Manager::PrintSuccess(const char* act)
{
    flog << "========== " << act << " ==========" << endl;
    flog << "Success" << endl;
    flog << "============================" << endl << endl;
}

void Manager::AddSuccess(const char* act, char* name, float temperature, char* cough, char* location)
{
    flog << "========== " << act << " ==========" << endl;
    flog << name << "/" << temperature << "/" << cough << "/" << location << endl;
    flog << "============================" << endl << endl;
}


