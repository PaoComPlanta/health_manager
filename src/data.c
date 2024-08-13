#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

typedef char* string;

int main(void)
{
    printf("Testiiiiiiiiiiiiiiiiiiiing\n");
}

Staff create_staff(int id, string name, string address, int age, Role role, string specialty)
{
    Staff staff;
    staff.id = id;
    strcpy(staff.name, name);
    strcpy(staff.address, address);
    staff.age = age;
    staff.role = role;
    strcpy(staff.specialty, specialty);

    return staff;
}

int add_staff_to_department(Department *department, Staff staff)
{
    int counter = department->staff_count;

    if (counter == MAX_STAFF_PER_DEPARTMENT) 
    {
        return 1;
    }

    department->staff[counter] = staff;
    department->staff_count++;

    return 0;
}

Staff* find_staff(Department *department, int id)
{
    for (int i = 0; i < department->staff_count; i++)
    {
        if (department->staff[i].id == id)
        {
            return &(department->staff[i]);
        }
    }

    return NULL;
}

Patient create_patient(int id, string name, string adress, int age, char conditions[][MAX_CONDITIONS_LENGTH], char medication[][MAX_MEDICATIONS_LENGTH])
{
    Patient patient;
    patient.id = id;
    strcpy(patient.name, name);
    strcpy(patient.address, adress);
    patient.age = age;

    for (int i = 0; i < MAX_CONDITIONS; i++)
    {
        strcpy(patient.conditions[i], conditions[i]);
    }

    for (int k = 0; k < MAX_MEDICATIONS; k++)
    {
        strcpy(patient.medication[k], medication[k]);
    }

    return patient;
}

int add_patient_to_hospital(Hospital *hospital, Patient patient)
{
    int counter = hospital->patient_count;

    if (counter ==MAX_PATIENTS)
    {
        return 1;
    }

    hospital->patients[counter] = patient;
    hospital->patient_count++;

    return 0;
}

Patient* find_patient(Hospital *hospital, int id)
{
    for (int i = 0; i < hospital->patient_count; i++)
    {
        if (hospital->patients[i].id == id)
        {
            return &(hospital->patients[i]);
        }
    }

    return NULL;
}

Department create_department(int id, string name, Staff head, int staff_count, Staff *staff)
{
    Department department;
    department.id = id;
    strcpy(department.name, name);
    department.head = head;
    department.staff_count = staff_count;

    for (int i = 0; i < staff_count; i++)
    {
        department.staff[i] = staff[i];
    }

    return department;
}

int add_department_to_hospital(Hospital *hospital, Department department)
{
    int counter = hospital->department_count;

    if (counter == MAX_DEPARTMENTS_NUMBER)
    {
        return 1;
    }

    hospital->departments[counter] = department;
    hospital->department_count++;

    return 0;
}

Department* find_department(Hospital *hospital, int id)
{
    for (int i = 0; i < hospital->department_count; i++)
    {
        if (hospital->departments[i].id == id)
        {
            return &(hospital->departments[i]);
        }
    }

    return NULL;
}

Hospital create_hospital(int id, string name, string address, int max_staff_count, Department departments[], int department_count, Patient patients[], int patient_count)
{
    Hospital hospital;
    hospital.id = id;
    strcpy(hospital.name, name);
    strcpy(hospital.address, address);
    hospital.max_staff_count = max_staff_count;
    
    for (int i = 0; i < department_count; i++)
    {
        hospital.departments[i] = departments[i];
    }

    hospital.department_count = department_count;
    
    for (int k = 0; k < patient_count; k++)
    {
        hospital.patients[k] = patients[k];
    }

    hospital.patient_count = patient_count;

    return hospital;
}