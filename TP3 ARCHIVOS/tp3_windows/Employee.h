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
Employee* AuxiliarEmpleado(LinkedList* listaEmpleados, int* id, int* index);//no me sirve
int employee_findID(LinkedList* listaEmpleados, int id);

int Menu(void);
int employee_menuModify(void);
int employee_menuOrden(void);

int employee_printEmployee(Employee* this);
int employee_printOne(LinkedList* listaEmpleados, int index);
int employee_printList(LinkedList* listaEmpleados);

int employee_add(LinkedList* listaEmpleados);
int employee_remove(LinkedList* listaEmpleados);
int employee_modify(LinkedList* listaEmpleados);

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
