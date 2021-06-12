#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new(void);
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

int ObtenerMayorId(LinkedList* listaEmpleados);
int employee_findID(LinkedList* listaEmpleados, int id);

int employee_printOneEmployee(Employee* this);
int employee_printList(LinkedList* listaEmpleados);

int employee_add(LinkedList* listaEmpleados);
int employee_remove(LinkedList* listaEmpleados);
int employee_modify(LinkedList* listaEmpleados);
int employee_setVerify(Employee* this, char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
int employee_getVerify(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo);

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);
int employee_compareById(void* empleado1, void* empleado2);

int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);
int employee_modifyNombre(LinkedList* listaEmpleados, int index, char* auxNombre);
int employee_compareByNombre(void* empleado1, void* empleado2);

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);
int employee_modifyHorasTrabajadas(LinkedList* listaEmpleados, int index, int auxHoras);
int employee_compareByHorasTrabajadas(void* empleado1, void* empleado2);

int employee_setSueldo(Employee* this, int sueldo);
int employee_getSueldo(Employee* this, int* sueldo);
int employee_modifySueldo(LinkedList* listaEmpleados, int index, int auxSueldo);
int employee_compareBySueldo(void* empleado1, void* empleado2);

#endif // employee_H_INCLUDED
