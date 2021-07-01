#include "MenuReportes.h"

void dibujarMenudeReportes()
{
    cout << "        MENU REPORTES        " << endl;
    cout << "  ------------------------- " << endl;
    cout << " 1 - RECAUDACION ANUAL         " << endl;
    cout << " 2 - RECAUDACION MENSUAL       " <<endl;
    cout << " 3 - RECAUDACION DIARIA        " << endl;
    cout << " 4 - RECAUDACION POR PLATO     " << endl;
    cout << " 0 - VOLVER AL MENU PRINCIPAL " << endl;
    cout << " ---------------------------- " << endl;
    cout << endl;
}

void MenuReportes()
{
    setlocale(LC_CTYPE, "Spanish");

    bool salir=false;
    int opcion;

    while(!salir)
    {
        system("cls");
        dibujarMenudeReportes();
        cout << "INGRESAR OPCION: ";
        cin >> opcion;
        cin.ignore();
        system("cls");

        switch(opcion)
        {
        case 1:
        {
            RecaudacionAnual();
        }
        break;
        case 2:
        {
            RecaudacionMensual();
        }
        break;
        case 3:
        {
            RecaudacionDiaria();
        }
        break;
        case 4:
        {
            RecaudacionPorPlato();
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
