#include "manager.h"
using namespace std;

//FILL in the blanks for Step #11 creating the manager copy constructor

//Step 11b - Add in the initialization list (uncomment the code)
manager::manager(const manager & old_manager) :

    salaried_employee(old_manager),
    group_name(old_manager.group_name), num_employees(old_manager.num_employees)

{

    //Step 11e - Fill in the blanks to create an array of employee pointers
    group = new employee*[num_employees];
    for (int i = 0; i < num_employees; ++i)
    {
        employee * temp = old_manager.group[i];

        //Step 11g - Fill in the blanks for using dynamic cast
        salaried_employee*  ptr = dynamic_cast<salaried_employee*> (temp);
        if (ptr)
            group[i] = new salaried_employee(*ptr);
        else 
        {
            full_time * ptr = dynamic_cast<full_time*> (temp);
            if (ptr) group[i] = new full_time(*ptr);
            else
            {
                hourly_employee * ptr = dynamic_cast<hourly_employee*> (temp);
                if (ptr) group[i] = new hourly_employee(*ptr);
                else group[i] = nullptr;
            }
        }
    }

}

