#include "MenuDeMesas.h"


void dibujarMenudeMesas()
{
    cout << "        MENU MESAS         " << endl;
    cout << " ------------------------- " << endl;
    cout << " 1 -    NUEVA MESA         " << endl;
    cout << " 2 -    BUSCAR MESA        " << endl;
    cout << " 3 -    HACER RESERVA      " << endl;
    cout << " 4 -    LISTADO MESAS      " << endl;
    cout << " 5 -                       " << endl;   /// MODIFICACION DE MESA
    cout << " 6 -                       " << endl;   /// BAJA LOGICA DE MESA
    cout << " 0 - VOLVER AL MENU PRINCIPAL " << endl;
    cout << " ---------------------------- " << endl;
    cout << endl;
}

void MenuMesas()
{
    setlocale(LC_CTYPE, "Spanish");

    bool salir=false;
    int opcion;

    while(!salir)
    {
        system("cls");
        dibujarMenudeMesas();
        cout << "INGRESAR OPCION: ";
        cin >> opcion;
        cin.ignore();
        system("cls");

        switch(opcion)
        {
        case 1:
        {
            NuevaMesa();
        }
        break;
        case 2:
        {
            Buscar_Mesa();
        }
        break;
        case 3:
        {
            HacerReserva();
        }
        break;

        case 4:
        {
            ListadoMesas();
        }
        break;
        case 5:
        {

        } break;
        case 0:
        {
            salir=true;
            cout << "VOLVIENDO AL MENU PRINCIPAL..";
        }
        break;
        default:
        {
            cout << "OPCION INCORRECTA";
        }
        break;
        }
        cin.get();
    }
}
