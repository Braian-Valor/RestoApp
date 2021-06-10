#include "FuncionesMesas.h"

int buscarNroMesa(int nro)
{
    Mesas reg;
    int pos=0;
    while(reg.leerDeDisco(pos))
    {
        if(reg.getNroMesa()==nro)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

void NuevaMesa()
{
    Mesas obj;
    int numMesa,cantmesa,repeticion;
    cout<< "Ingrese el numero de mesa: "<<endl;
    cin>>numMesa;
    repeticion=buscarNroMesa(numMesa);
    while(numMesa<0 || repeticion>=0)
    {
        cout<< "Numero de mesa negativo o ya ingresado en el sistema "<<endl;
        cout<< "Ingrese Nuevo numero de mesa: "<<endl;
        cin>>numMesa;
        repeticion=buscarNroMesa(numMesa);
    }
    cout<< "Ingrese la ocupacion de la mesa: "<<endl;
    cin>>cantmesa;
    while(cantmesa<0)
    {
        cout<< "Ocupacion de mesa Erroneo Ingrese Nuevo numero de mesa: "<<endl;
        cin>>cantmesa;
    }
    bool Estado=true;
    obj.setNroMesa(numMesa);
    obj.setCapacidad(cantmesa);
    obj.setEstado(Estado);
    if(obj.escribirEnDisco())
    {
        cout<< "Mesa añadida con excito"<<endl;
    }
    else
    {
        cout<< "No se ha podido agregar la Mesa"<<endl;
    }
}

void leermesas(Mesas *vec,int tam)
{
    FILE *p;
    p=fopen("datos/mesas.dat","rb");
    fread(vec,sizeof(Mesas),tam,p);
    fclose(p);
}

void ListadoMesas()
{
    Mesas obj;
    int cr,t;
    FILE *p;
    p=fopen("datos/mesas.dat","rb");
    if(p==NULL)
    {
        cout<< "ERROR DE ARCHIVO"<<endl;
        return;
    }
    fseek(p,0,SEEK_END);
    t=ftell(p);
    cr=t/sizeof(Mesas);
    Mesas *vec=NULL;
    vec= new Mesas [cr];
    if(vec==NULL)
    {
        cout<< "No hay memoria"<<endl;
        delete vec;
        return;
    }
    leermesas(vec,cr);
    int posmax;
    for(int i=0; i<cr-1; i++)
    {
        posmax=i;
        for(int j=i+1; j<cr; j++)
        {
            if(vec[j].getEstado()==true && vec[posmax].getEstado()==false)
            {
                posmax=j;
            }
        }
        Mesas aux=vec[i];
        vec[i]=vec[posmax];
        vec[posmax]=aux;
    }
    for(int i=0; i<cr; i++)
    {
        vec[i].Mostrar();
    }
    fclose(p);
    delete vec;
}


void Buscar_Mesa()
{
    Mesas obj;
    int nroMesa,pos;
    cout<< "Ingrese el Numero de Mesa el cual desea buscar: "<<endl;
    cin>>nroMesa;
    pos=buscarNroMesa(nroMesa);
    while (pos==-1 || nroMesa<0)
    {
        cout<< "Mesa inexistente o valor ingresado negativo ingresar un nuevo numero de Mesa: "<<endl;
        cin>>nroMesa;
        pos=buscarNroMesa(nroMesa);
    }
    system("cls");
    obj.leerDeDisco(pos);
    obj.Mostrar();
    cin.get();
}

/*bool BuscarOcupacionMesa(int nro)
{
    Mesas reg;
    int pos=0;
    while(reg.leerDeDisco(pos++))
    {
        if(reg.getNroMesa()==nro && reg.getEstado()==false)
        {
            return false;
        }
        if(reg.getNroMesa()==nro && reg.getEstado()==true)
        {
            return true;
        }

    }
    return false;
}*/

void BajaMesa()
{
    Mesas obj;
    int repeticion, NumMesa;
    cout<< "Ingrese el Numero de Mesa para dar de baja: "<<endl;
    cin>>NumMesa;
    repeticion=buscarNroMesa(NumMesa);
    while(NumMesa<0 || repeticion==-1)
    {
        system("cls");
        int pos=0;
        cout<< "Numero de mesa negativo o inexistente "<<endl;
        cout<< "Mesas Libres para dar de baja: "<<endl;
        while(obj.leerDeDisco(pos++))
        {
            if(obj.getEstado()==true)
            {
                obj.Mostrar();
            }
        }
        cout<< "Ingrese Nuevo numero de mesa: "<<endl;
        cin>>NumMesa;
        repeticion=buscarNroMesa(NumMesa);
    }
    obj.leerDeDisco(repeticion);
    obj.setEstado(false);
    if(obj.ModificarValorMesa(repeticion))
    {
        cout<< "La baja ha sido asignada con exito"<<endl;
    }
    else
    {
        cout<< "No se ha podido realizar la baja"<<endl;
    }
    cin.get();
}

void ModificacionMesa()
{
    Mesas obj;
    int repeticion, NumMesa;
    cout<< "Ingrese el Numero de Mesa a Modificar: "<<endl;
    cin>>NumMesa;
    repeticion=buscarNroMesa(NumMesa);
    while(NumMesa<0 || repeticion==-1)
    {
        system("cls");
        int pos=0;
        cout<< "Numero de mesa negativo o inexistente "<<endl;
        cout<< "Mesas Libres para Modificar: "<<endl;
        while(obj.leerDeDisco(pos++))
        {
            if(obj.getEstado()==true)
            {
                obj.Mostrar();
            }
        }
        cout<< "Ingrese nuevamente numero de mesa: "<<endl;
        cin>>NumMesa;
        repeticion=buscarNroMesa(NumMesa);
    }
    int opc;
    bool salir=false;
    Mesas reg;
    FILE *p;
    p=fopen("datos/Mesas.dat", "rb+");
    if(p==NULL)
    {
        cout << "ERROR, NO SE PUDO ABRIR EL ARCHIVO";
        return;
    }
    while(fread(&reg, sizeof(Mesas), 1, p)==1)
    {
        while(!salir)
        {
            system("cls");
            cout << "REGISTRO A MODIFICAR" << endl;
            cout << "--------------------" << endl;
            reg.Mostrar();
            cout << endl;
            cout << " SELECCIONAR CAMPO A MODIFICAR " << endl;
            cout << " ----------------------------- " << endl;
            cout << " 1 - NUMERO DE MESA " << endl;
            cout << " 2 - CAPACIDAD   " << endl;
            //cout << " 3 - ESTADO    " << endl;   /// Estado?
            cout << " 0 - SALIR    " << endl;
            cout << endl;
            cout << "OPCION: ";
            cin >> opc;
            system("cls");
            switch (opc)
            {
            case 1:
            {
                int NuevoNum;
                cout<< "Ingrese Nuevo Numero de Mesa: "<<endl;
                cin>>NuevoNum;
                while(NuevoNum<0 || buscarNroMesa(NuevoNum)>=0)
                {
                    int pos=0;
                    system("cls");
                    cout<< "Valor Ingresado Negativo o Numero de mesa Existentes en el archivo"<<endl;
                    cout<< "Mesas Existentes: "<<endl;
                    while(obj.leerDeDisco(pos++))
                    {
                        if(obj.getEstado()==true)
                        {
                            obj.Mostrar();
                        }
                    }
                    cout<< "Favor de ingresar un valor valido: "<<endl;
                    cin>>NuevoNum;
                    buscarNroMesa(NuevoNum);
                }
                reg.setNroMesa(NuevoNum);
                reg.ModificarValorMesa(repeticion);
            }
            break;
            case 2:
            {
                int NuevaCapacidad;
                cout<< "Ingrese Nueva Capacidad: "<<endl;
                cin>>NuevaCapacidad;
                while(NuevaCapacidad<0)
                {
                    cout<< "Valor Ingresado Negativo favor de ingresar un valor positivo valido: "<<endl;
                    cin>>NuevaCapacidad;
                }
                reg.setCapacidad(NuevaCapacidad);
                reg.ModificarValorMesa(repeticion);
            }
            break;
            /*case 3:
            {

            }
            break;*/
            case 0:
            {
                fclose(p);
                salir=true;
                cout << "VOLVIENDO AL MENU DE MESAS..";
            }
            break;
            default:
            {
                cout<< "Valor Ingresado Incorrecto"<<endl;
            }
            }
            cin.get();
        }
    }
    fclose(p);
}
/*void HacerReserva()
{
    Mesas obj,reg;
    Fecha aux;
    int numMesa,pos=0,valor2;
    bool estado=false,valor;
    obj.setEstado(estado);
    cout<< "Ingrese la Fecha a Reservar: "<<endl;
    aux.Cargar();                                                /// Falta Validaciones de Fechas y Num de mesa no Ocupado/reservado
    obj.setFecha(aux);
    cout<< "Ingrese el numero de Mesa a Reservar"<<endl;        ///Ver tema de Fecha del sistema
    cin>>numMesa;
    valor=BuscarOcupacionMesa(numMesa);
    while(valor==false)
    {
        system ("cls");
        cout<< "Numero de mesa ingresado inexistente o ocupado reingrese numero de mesa: "<<endl;
        cout<< "Mesas Libres: "<<endl;
        while(reg.leerDeDisco(pos++))
        {
            if(reg.getEstado()==true)
            {
                reg.Mostrar();
            }
        }
        cin>>numMesa;
        valor=BuscarOcupacionMesa(numMesa);
    }
    valor2=buscarNroMesa(numMesa);
    obj.leerDeDisco(valor2);
    obj.setEstado(false);
    if(obj.ModificarValorMesa(valor2))
    {
        cout<< "Reserva Añadida con excito"<<endl;
    }
    else
    {
        cout << "No se ha podido añadir la reserva"<<endl;
    }
    cin.get();
}*/
