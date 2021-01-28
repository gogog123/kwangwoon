#include "LocationBST.h"

LocationBST::LocationBST()
{
    Root = NULL;
}

LocationBST::~LocationBST()
{
    Root = NULL;
}

LocationNode* LocationBST::GetRoot()
{
    return Root;
}

void LocationBST::Insert_Location(LocationNode* node)
{
    //Build once in Constructor
    if (Root == NULL) { //NULL BST
        Root = node;
    }
    else {
        LocationNode* tempNode = new LocationNode;
        tempNode = Root;
        while (1)
        {
            if (strcmp(tempNode->GetLoc(),node->GetLoc())>0)
            {
                if (tempNode->GetLeft() == NULL){
                    tempNode->SetLeft(node); //store left node 
                    break;
                }
                tempNode = tempNode->GetLeft();
            }
            else {
                if (tempNode->GetRight() == NULL){
                    tempNode->SetRight(node); //store right node 
                    break;
                }
                tempNode = tempNode->GetRight();
            }
        } // Location BST insert
    }

}

bool LocationBST::Insert_Patient(PatientNode* node)
{
    LocationNode* tempNode = new LocationNode;
    tempNode = Root;
    while (1)
    {
        if (strcmp(tempNode->GetLoc(), node->GetLoc()) > 0)
            tempNode = tempNode->GetLeft();
        else if (strcmp(tempNode->GetLoc(), node->GetLoc()) < 0)
            tempNode = tempNode->GetRight();
        else
            break;
    }

    char disease;
    PatientBSTNode* newPatientBSTNode = new PatientBSTNode; //patientBSTNode dynamic alloc
    newPatientBSTNode->SetName(node->GetName());
    if ((node->GetTemp() >= 37.5) && node->GetCough() == 'Y')
    {
        disease = '+'; // have a disease
    }
    else
    {
        disease = '-'; // have not a disease
    }
    newPatientBSTNode->SetDisease(disease);

    if (tempNode->GetBST() == NULL) //Patient_BST empty
    {
        PatientBST* newPatientBST = new PatientBST;
        tempNode->SetBST(newPatientBST);
    }
    tempNode->GetBST()->Insert(newPatientBSTNode);

    return true;
    //QPOP
}

int LocationBST::Search(char* name)
{
    //return 0: Y, return 1: N, return 2:false
    LocationNode* temp = new LocationNode;
    temp = Root;

    int exist = 0;

    if (temp->GetBST() != NULL) //Gwangju 
    {

        exist = temp->GetBST()->Search(name);
        if (exist == 0)
            return 0; //diease Y
        else if (exist == 1)
            return 1; //diease N
    }
    if (temp->GetLeft()->GetBST() != NULL) //Daegu
    {
        exist = temp->GetLeft()->GetBST()->Search(name);
        if (exist == 0)
            return 0; //diease Y
        else if (exist == 1)
            return 1; //diease N
    }

    if (temp->GetLeft()->GetLeft()->GetBST() != NULL) //Busan
    {
        exist = temp->GetLeft()->GetLeft()->GetBST()->Search(name);
        if (exist == 0)
            return 0; //diease Y
        else if (exist == 1)
            return 1; //diease N
    }
    if (temp->GetLeft()->GetRight()->GetBST() != NULL) //Daejeon
    {
        exist = temp->GetLeft()->GetRight()->GetBST()->Search(name);
        if (exist == 0)
            return 0; //diease Y
        else if (exist == 1)
            return 1; //diease N
    }
    if (temp->GetRight()->GetBST() != NULL) //Seoul
    {
        exist = temp->GetRight()->GetBST()->Search(name);
        if (exist == 0)
            return 0; //diease Y
        else if (exist == 1)
            return 1; //diease N
    }
    if (temp->GetRight()->GetLeft()->GetBST() != NULL) //Incheon
    {
        exist = temp->GetRight()->GetLeft()->GetBST()->Search(name);
        if (exist == 0)
            return 0; //diease Y
        else if (exist == 1)
            return 1; //diease N
    }
    if (temp->GetRight()->GetRight()->GetRight() != NULL) //Ulsan
    {
        exist = temp->GetRight()->GetRight()->GetBST()->Search(name);
        if (exist == 0)
            return 0; //diease Y
        else if (exist == 1)
            return 1; //diease N
    }

    return 2; //false
    
    //SEARCH
}

char* LocationBST::Delete(char* name)
{
    LocationNode* temp = new LocationNode;
    PatientBSTNode* temp_p = new PatientBSTNode;
    int exist = 0;

    temp = Root;
    if (temp->GetBST() != NULL) //Gwangju 
    {
        if (temp->GetBST()->Delete(name) == true) //name exist
            return temp->GetLoc();
    }

    temp = Root->GetLeft();
    if (temp->GetBST() != NULL) //Daegu
    {
        if (temp->GetBST()->Delete(name) == true) //name exist
            return temp->GetLoc();
    }

    temp = Root->GetLeft()->GetLeft(); //Busan
    if (temp->GetBST() != NULL)
    {
        if (temp->GetBST()->Delete(name) == true) //name exist
            return temp->GetLoc();
    }

    temp = Root->GetLeft()->GetRight(); //Daejeon
    if (temp->GetBST() != NULL)
    {
        if (temp->GetBST()->Delete(name) == true) //name exist
            return temp->GetLoc();
    }

    temp = Root->GetRight(); //Seoul
    if (temp->GetBST() != NULL)
    {
        if (temp->GetBST()->Delete(name) == true) //name exist
            return temp->GetLoc();
    }

    temp = Root->GetRight()->GetLeft(); //Incheon
    if (temp->GetBST() != NULL)
    {
        if (temp->GetBST()->Delete(name) == true) //name exist
            return temp->GetLoc();
    }

    temp = Root->GetRight()->GetRight(); //ulsan
    if (temp->GetBST() != NULL)
    {
        if (temp->GetBST()->Delete(name) == true) //name exist
            return temp->GetLoc();
    }

    return name;
    //BPOP
}

void LocationBST::Print_PRE()
{
    LocationNode* temp = new LocationNode;
    PatientBSTNode* temp_p = new PatientBSTNode;

    flog.open("log.txt", ios::app); //log.txt open
    flog << "========== " << "PRINT" << " ==========" << endl;


    temp = Root;
    if (temp->GetBST() != NULL) //Gwangju 
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_PRE(temp_p); //preorder PatientBST
    }

    temp = Root->GetLeft();
    if (temp->GetBST() != NULL) //Daegu
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_PRE(temp_p); //preorder PatientBST
    }

    temp = Root->GetLeft()->GetLeft(); //Busan
    if (temp->GetBST() != NULL) 
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_PRE(temp_p); //preorder PatientBST
    }

    temp = Root->GetLeft()->GetRight(); //Daejeon
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_PRE(temp_p); //preorder PatientBST
    }

    temp = Root->GetRight(); //Seoul
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_PRE(temp_p); //preorder PatientBST
    }

    temp = Root->GetRight()->GetLeft(); //Incheon
    if (temp->GetBST() != NULL) 
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_PRE(temp_p); //preorder PatientBST
    }

    temp = Root->GetRight()->GetRight(); //ulsan
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_PRE(temp_p); //preorder PatientBST
    }
    //Gwangju, Daegu, Busan, Daejeon, seoul, Incheon, Ulsan
    flog << "============================" << endl << endl;
    flog.close();
    //PRINT B PRE
}

void LocationBST::Print_IN()
{
    LocationNode* temp = new LocationNode;
    PatientBSTNode* temp_p = new PatientBSTNode;

    flog.open("log.txt", ios::app); //log.txt open
    flog << "========== " << "PRINT" << " ==========" << endl;

    temp = Root->GetLeft()->GetLeft(); //Busan
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_IN(temp_p); //inorder PatientBST
    }

    temp = Root->GetLeft();
    if (temp->GetBST() != NULL) //Daegu
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_IN(temp_p); //inorder PatientBST
    }

    temp = Root->GetLeft()->GetRight(); //Daejeon
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_IN(temp_p); //inorder PatientBST
    }

    temp = Root;
    if (temp->GetBST() != NULL) //Gwangju 
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_IN(temp_p); //inorder PatientBST
    }

    temp = Root->GetRight()->GetLeft(); //Incheon
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_IN(temp_p); //inorder PatientBST
    }

    temp = Root->GetRight(); //Seoul
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_IN(temp_p); //inorder PatientBST
    }

    temp = Root->GetRight()->GetRight(); //ulsan
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_IN(temp_p); //inorder PatientBST
    }

    //PRINT B IN
    flog << "============================" << endl << endl;
    flog.close();
    // Busan, Daegu, Daejeon, Incheon, seoul, Ulsan
}

void LocationBST::Print_POST()
{
    LocationNode* temp = new LocationNode;
    PatientBSTNode* temp_p = new PatientBSTNode;

    flog.open("log.txt", ios::app); //log.txt open
    flog << "========== " << "PRINT" << " ==========" << endl;

    temp = Root->GetLeft()->GetLeft(); //Busan
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_POST(temp_p); //postorder PatientBST
    }

    temp = Root->GetLeft()->GetRight(); //Daejeon
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_POST(temp_p); //postorder PatientBST
    }

    temp = Root->GetLeft();
    if (temp->GetBST() != NULL) //Daegu
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_POST(temp_p); //postorder PatientBST
    }

    temp = Root->GetRight()->GetLeft(); //Incheon
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_POST(temp_p); //postorder PatientBST
    }

    temp = Root->GetRight()->GetRight(); //ulsan
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_POST(temp_p); //postorder PatientBST
    }

    temp = Root->GetRight(); //Seoul
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_POST(temp_p); //postorder PatientBST
    }

    temp = Root;
    if (temp->GetBST() != NULL) //Gwangju 
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_POST(temp_p); //postorder PatientBST
    }

    //PRINT B POST
    flog << "============================" << endl << endl;
    flog.close();
    // Busan, Daejeon, Daegu, Incheon, Ulsan, Seoul, Gwangju 

}

void LocationBST::Print_LEVEL()
{
    LocationNode* temp = new LocationNode;
    PatientBSTNode* temp_p = new PatientBSTNode;

    flog.open("log.txt", ios::app); //log.txt open
    flog << "========== " << "PRINT" << " ==========" << endl;

    temp = Root;
    if (temp->GetBST() != NULL) //Gwangju 
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_LEVEL(temp_p); //level PatientBST
    }

    temp = Root->GetLeft();
    if (temp->GetBST() != NULL) //Daegu
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_LEVEL(temp_p); //level PatientBST
    }

    temp = Root->GetRight(); //Seoul
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_LEVEL(temp_p); //level PatientBST
    }

    temp = Root->GetLeft()->GetLeft(); //Busan
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_LEVEL(temp_p); //level PatientBST
    }

    temp = Root->GetLeft()->GetRight(); //Daejeon
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_LEVEL(temp_p); //level PatientBST
    }

    temp = Root->GetRight()->GetLeft(); //Incheon
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_LEVEL(temp_p); //level PatientBST
    }

    temp = Root->GetRight()->GetRight(); //ulsan
    if (temp->GetBST() != NULL)
    {
        temp_p = temp->GetBST()->GetRoot();
        temp->GetBST()->Print_LEVEL(temp_p); //level PatientBST
    }
    //PRINT B LEVEL
    flog << "============================" << endl << endl;
    flog.close();
    //Gwangju, Daegu, Seoul, Busan, Daejeon, Incheon, Ulsan

}
