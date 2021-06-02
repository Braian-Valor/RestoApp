#include "FuncionesMesas.h"

void NuevaMesa()
{
    Mesas obj;
    int numMesa,cantmesa;
    cout<< "Ingrese el numero de mesa: "<<endl;
    cin>>numMesa;
    while(numMesa<0)
    {
        cout<< "Dato de mesa Erroneo Ingrese Nuevo numero de mesa: "<<endl;
        cin>>numMesa;
    }
    cout<< "Ingrese la ocupacion de la mesa: "<<endl;
    cin>>cantmesa;
    while(numMesa<0)
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
    for(int i=0;i<cr;i++)
    {
        vec[i].Mostrar();
    }
    fclose(p);
    delete vec;
}

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
    return false;
}

void Buscar_Mesa()
{
    Mesas obj;
    int nroMesa,pos;
    cout<< "Ingrese el Numero de Mesa el cual desea buscar: "<<endl;
    cin>>nroMesa;
    pos=buscarNroMesa(nroMesa);
    while (pos==false)
    {
        cout<< "Mesa no encontrada ingresar un nuevo valor: "<<endl;
        cin>>nroMesa;
        pos=buscarNroMesa(nroMesa);
    }
    system("cls");
    obj.leerDeDisco(pos);
    obj.Mostrar();
    cin.get();
}

void HacerReserva()
{
    Mesas obj;
    Fecha aux;
    int numMesa;
    bool estado=true;
    obj.setEstado(estado);
    cout<< "Ingrese la Fecha a Reservar: "<<endl;
    aux.Cargar();                                                /// Falta Validaciones de Fechas y Num de mesa no Ocupado/reservado
    obj.setFecha(aux);
    cout<< "Ingrese el numero de Mesa a Reservar"<<endl;        ///Ver tema de Fecha del sistema
    cin>>numMesa;
    obj.setNroMesa(numMesa);
    if(obj.escribirEnDisco())
    {
        cout<< "Reserva Añadida con excito"<<endl;
    }
    else
    {
        cout << "No se ha podido añadir la reserva"<<endl;
    }
}
