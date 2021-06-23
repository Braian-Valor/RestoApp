#include "MenuDeMesas.h"


void dibujarMenudeMesas()
{
    cout << "        MENU MESAS         " << endl;
    cout << " ------------------------- " << endl;
    cout << " 1 - NUEVA MESA         " << endl;
    cout << " 2 - BUSCAR MESA        " << endl;
    cout << " 3 - LISTADO MESAS      " << endl;
    cout << " 4 - MODIFICACION MESA  " << endl;
    cout << " 5 - BAJA DE MESA       " << endl;
    cout<<  " 6 - ALTA DE MESA DADA DE BAJA"<<endl;
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
            ListadoMesas();
        }
        break;

        case 4:
        {
            ModificacionMesa();
        }
        break;
        case 5:
        {
            BajaMesa();
        }
        break;
        case 6:
        {
            AltadeMesadadaDebaja();
        }
        break;
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
