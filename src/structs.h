#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_STAFF 100
#define MAX_PATIENTS 1000
#define MAX_CONDITIONS 10
#define MAX_CONDITIONS_LENGTH 100
#define MAX_MEDICATIONS 10
#define MAX_MEDICATIONS_LENGTH 100
#define MAX_SPECIALTY_LENGTH 50
#define MAX_STAFF_PER_DEPARTMENT 25
#define MAX_DEPARTMENTS_NUMBER 10

typedef enum
{
    DOCTOR,
    NURSE,
    ADMINISTRATIVE,
    OTHER
} Role;

typedef struct
{
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int age;
    Role role;
    char specialty[MAX_SPECIALTY_LENGTH];
} Staff;

typedef struct
{
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int age;
    char conditions[MAX_CONDITIONS][MAX_CONDITIONS_LENGTH];
    char medication[MAX_MEDICATIONS][MAX_MEDICATIONS_LENGTH];
} Patient;

typedef struct
{
    int id;
    char name[MAX_NAME_LENGTH];
    Staff head;
    int staff_count;
    Staff staff[MAX_STAFF_PER_DEPARTMENT];
} Department;

typedef struct
{
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int max_staff_count;
    Department departments[MAX_DEPARTMENTS_NUMBER];
    int department_count;
    Patient patients[MAX_PATIENTS];
    int patient_count;
} Hospital;

Staff create_staff(int id, char *name, char *address, int age, Role role, char *specialty);

int add_staff_to_department(Department *department, Staff staff);

Staff* find_staff(Department *department, int id);

Patient create_patient(int id, char *name, char *address, int age, char conditions[][MAX_CONDITIONS_LENGTH], char medication[][MAX_MEDICATIONS_LENGTH]);

int add_patient_to_hospital(Hospital *hospital, Patient patient);

Patient* find_patient(Hospital *hospital, int id);

Department create_department(int id, char *name, Staff head, int staff_count, Staff *staff);

int add_department_to_hospital(Hospital *hospital, Department department);

Department* find_department(Hospital *hospital, int id);

Hospital create_hospital(int id, char *name, char *address, int max_staff_count, Department departments[], int department_count, Patient patients[], int patient_count);

void list_all_patients(Hospital *hospital);

#endif