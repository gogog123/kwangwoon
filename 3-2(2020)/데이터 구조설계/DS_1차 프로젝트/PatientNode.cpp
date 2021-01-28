#include "PatientNode.h"

PatientNode::PatientNode()
{
}

PatientNode::~PatientNode()
{
}

char* PatientNode::GetName()
{
	return Name;
}

float PatientNode::GetTemp()
{
	return Temperature;
}

char PatientNode::GetCough()
{
	return Cough;
}

char* PatientNode::GetLoc()
{
	return Location;
}

void PatientNode::SetName(char* name)
{
	Name = name;
}

void PatientNode::SetTemp(float temp)
{
	Temperature = temp;
}

void PatientNode::SetCough(char cough)
{
	Cough = cough;
}

void PatientNode::SetLoc(char* location)
{
	Location = location;
}