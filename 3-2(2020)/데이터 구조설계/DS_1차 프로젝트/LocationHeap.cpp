#include "LocationHeap.h"
#include <iostream>
using namespace std;
LocationHeap::LocationHeap()
{
    Heap= NULL;
    size = 0;
}

LocationHeap::~LocationHeap()
{
    Heap = NULL;
    size = 0;
}

bool LocationHeap::Insert(char* location)
{
    int check = 0;
    //Heap = new LocationHeapNode * [location_max + 1];

    //Heap[0] = *Heap;
    if (size == 0)
    {
        Heap = new LocationHeapNode * [location_max + 1];
        LocationHeapNode* newheapNode = new LocationHeapNode; //not pointer newheapNode
        newheapNode->SetLoc(location);
        newheapNode->SetCount(1);
        //LocationHeapNode** newheap = new LocationHeapNode*; //pointer newheap
        //(*newheap)->SetLoc(location);
        //(*newheap)->SetCount(1);
        Heap[1] = newheapNode; //array Heap[0] = NULL
        size++;
    }
    else
    {
        for (int i = 1; i < size+1; i++)
        {
            if (strcmp(Heap[i]->GetLoc(), location) == 0) //location node already exist
            {
                int conunt_p = Heap[i]->GetCount() + 1;
                Heap[i]->SetCount(conunt_p);
                check = 1;
                for (int j = i - 1; j > 0; j--)
                {
                    if (Heap[i]->GetCount() > Heap[j]->GetCount()) // re arrange
                    {
                        LocationHeapNode* temp = new LocationHeapNode;
                        temp = Heap[i];
                        Heap[i] = Heap[j];
                        Heap[j] = temp;
                        //change
                        i--;
                    }
                    else
                        break;
                }
                //re array
            }
        }
        if (check == 0)
        {
            LocationHeapNode* newNode = new LocationHeapNode;
            newNode->SetCount(1);
            newNode->SetLoc(location);
            Heap[size + 1] = newNode;// newheapNode add;
            size++;
        }

    }

    return true;
    //BPOP
}

void LocationHeap::Print()
{
    flog.open("log.txt", ios::app); //log.txt open
    flog << "========== PRINT ==========" << endl;
    flog << "Heap" << endl;
    for (int i = 1; i < size + 1; i++)
    {
       // cout << Heap[i]->GetCount() << endl;
        flog << Heap[i]->GetCount() << "/" << Heap[i]->GetLoc() << endl;
    }
    flog << "===========================" << endl << endl;
    flog.close();
    //PRINT H
}
