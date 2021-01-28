#include "PatientBST.h"
#include <iostream>
#include <queue>
using namespace std;

PatientBST::PatientBST()
{
    Root = NULL;
    count = 0;
}

PatientBST::~PatientBST()
{
    Root = NULL;
    count = 0;
}

PatientBSTNode* PatientBST::GetRoot()
{
    return Root;
}

bool PatientBST::Insert(PatientBSTNode* node)
{
    if (Root == NULL)
    {
        Root = node;
    }
    else
    {
        PatientBSTNode* tempNode = new PatientBSTNode;
        tempNode = Root;
        while (1)
        {
            if (strcmp(tempNode->GetName(), node->GetName()) > 0)
            {
                if (tempNode->GetLeft() == NULL) {
                    tempNode->SetLeft(node); //store left node 
                    break;
                }
                tempNode = tempNode->GetLeft();
            }
            else {
                if (tempNode->GetRight() == NULL) {
                    tempNode->SetRight(node); //store right node 
                    break;
                }
                tempNode = tempNode->GetRight();
            }
        } // Pateint BST insert
    }
    return true;
    //QPOP
}

int PatientBST::Search(char* name)
{
    //return 0: Y, return 1: N, return 2:false

    PatientBSTNode* tempNode = new PatientBSTNode;
    tempNode = Root;

    while (1)
    {
        if (strcmp(tempNode->GetName(), name) > 0)
        {
            if (tempNode->GetLeft() != NULL)
                tempNode = tempNode->GetLeft();
            else
                return 2; //false, no exist
        }
        if (strcmp(tempNode->GetName(), name) < 0)
        {
            if (tempNode->GetRight() != NULL)
                tempNode = tempNode->GetRight();
            else
                return 2; //false, no exist
        }
        else
        {
            if (tempNode->GetDisease() == '+')
                return 0;
            else if (tempNode->GetDisease() == '-')
                return 1;
            break;
        }
    }

    return false;
    //SEARCH
}

bool PatientBST::Delete(char* name)
{
    PatientBSTNode* tempNode = new PatientBSTNode; // delete node
    PatientBSTNode* tempNode_root = new PatientBSTNode; //delte node parent
    tempNode = Root;
    tempNode_root = Root;

    while (1)
    {
        if (tempNode->GetName() == NULL)
            return false;
        if (strcmp(tempNode->GetName(), name) > 0)
        {
            if (tempNode->GetLeft() == NULL)
                return false;
            if (tempNode->GetLeft() != NULL)
            {
                tempNode_root = tempNode;
                tempNode = tempNode->GetLeft();
            }
        }
        else if (strcmp(tempNode->GetName(), name) < 0)
        {
            if (tempNode->GetLeft() == NULL)
                return false;
            if (tempNode->GetLeft() != NULL)
            {
                tempNode_root = tempNode;
                tempNode = tempNode->GetLeft();
            }
        }
        else // find delete node
        {
            if (tempNode->GetLeft() == NULL && tempNode->GetRight() == 0) //leaf node
            {
            }
            else if (tempNode->GetLeft() == NULL) // only exist right node
            {
                if (tempNode = tempNode_root)
                    Root = tempNode->GetRight();
                else
                    tempNode_root->SetRight(tempNode->GetRight());
            }
            else if (tempNode->GetRight() == NULL) // only exist left node
            {
                if (tempNode = tempNode_root)
                    Root = tempNode->GetLeft();
                else
                    tempNode_root->SetLeft(tempNode->GetLeft());
            }
            else
            {
                PatientBSTNode* largeNode = new PatientBSTNode;
                PatientBSTNode* largeNode_root = new PatientBSTNode;
                largeNode = tempNode->GetLeft();
                largeNode_root = tempNode;
                while (1)
                {
                    if (largeNode->GetRight() == NULL && largeNode->GetLeft() == NULL)
                    {
                        largeNode->SetRight(tempNode->GetRight());
                        largeNode->SetLeft(tempNode->GetLeft()); //set Right, Left
                        break; // leaf node
                    }
                    else if (largeNode->GetRight() != NULL)
                    {
                        largeNode_root = largeNode; // large parent
                        largeNode = largeNode->GetRight();
                    }
                    else if (largeNode->GetRight() == NULL)
                    {
                        if (strcmp(largeNode_root->GetRight()->GetName(), largeNode->GetName()) == 0) 
                        {
                            largeNode_root->SetRight(largeNode->GetLeft());
                        }
                        else
                        {
                            largeNode_root->SetLeft(largeNode->GetLeft());
                        }//child node link
                        largeNode->SetRight(tempNode->GetRight());
                        largeNode->SetLeft(tempNode->GetLeft()); //set Right, Left
                        break;
                    }
                }
                
            }
            tempNode->SetName(NULL);
            tempNode->SetDisease(NULL);
            tempNode->SetLeft(NULL);
            tempNode->SetRight(NULL);
            return true;
        }
    }
    return true;
    //BPOP
}

void PatientBST::Print_PRE(PatientBSTNode* node)
{
    if (node != NULL)
    {
        flog.open("log.txt", ios::app); //log.txt open
        //cout << node->GetName() << "/" << node->GetDisease() << endl; //check
        flog << node->GetName() << "/" << node->GetDisease() << endl; //print
        flog.close();
        Print_PRE(node->GetLeft());
        Print_PRE(node->GetRight());
    }
    //PRINT B PRE
}

void PatientBST::Print_IN(PatientBSTNode* node)
{

    if (node != NULL)
    {
        Print_IN(node->GetLeft());
        flog.open("log.txt", ios::app); //log.txt open
        cout << node->GetName() << "/" << node->GetDisease() << endl; //print
        flog << node->GetName() << "/" << node->GetDisease() << endl; //print
        flog.close();
        Print_IN(node->GetRight());
    }

    //PRINT B IN
}

void PatientBST::Print_POST(PatientBSTNode* node)
{
    if (node != NULL)
    {
        Print_POST(node->GetLeft());
        Print_POST(node->GetRight());
        flog.open("log.txt", ios::app); //log.txt open
        flog << node->GetName() << "/" << node->GetDisease() << endl; //print
        flog.close();
    
    }
    //PRINT B POST
}

void PatientBST::Print_LEVEL(PatientBSTNode* node)
{
    queue <PatientBSTNode*>* q;
    queue<PatientBSTNode*>* qu = new queue<PatientBSTNode*>;
    q = qu;

    PatientBSTNode* tempNode = new PatientBSTNode;

    tempNode = Root;
    while (tempNode)
    {
        flog.open("log.txt", ios::app); //log.txt open
        cout << tempNode->GetName() << "/" << tempNode->GetDisease() << endl; //print
        flog << tempNode->GetName() << "/" << tempNode->GetDisease() << endl; //print
        flog.close();
        if (tempNode->GetLeft()) {
            qu->push(tempNode->GetLeft()); //queue in
        }
        if (tempNode->GetRight()) {
            qu->push(tempNode->GetRight()); //queue in
        }
        if (qu->empty()) return;
        tempNode = qu->front();
        qu->pop();
    }
    //PRINT B LEVEL
}
