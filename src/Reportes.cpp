#include "Reportes.h"

#include "Reportes.h"

int buscador(int anio,int mes)
{
    Ventas obj;
    int pos=0,suma=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getFechaVenta().getAnio()==anio && obj.getFechaVenta().getMes()==mes)
        {
            suma+=obj.getMontoTotal();
        }
    }
    return suma;
}




void RecaudacionAnual()
{
    int suma,anio,mes;
    Ventas reg;
    cout<< "Ingrese el anio el cual desea buscar: "<<endl;
    cin>>anio;
    while (anio<0)
    {
        cout<< "Valor ingresado negativo, favor de ingresar un anio valido: "<<endl;
        cin>>anio;
    }
    cout<< "Ingrese el mes el cual desea buscar: "<<endl;
    cin>>mes;
    while(mes<0)
    {
        cout<< "Valor ingresado negativo, favor de ingresar un mes valido: "<<endl;
        cin>>mes;
    }
    suma=buscador(anio,mes);
    cout<< "La suma vendida de ese mes y anio son: "<<endl;
    cout<< suma;
    cin.get();

}

int SumatoriadiaFinal(int *vec)
{
    int suma=0;
    for(int i=0; i<31; i++)
    {
        suma+=vec[i];
    }
    return suma;
}

void RecaudacionDiaria()
{
    int vec[31]= {},pos=0,suma;
    Ventas reg;
    Fecha obj;
    while(reg.leerDeDisco(pos++))
    {
        if(reg.getFechaVenta().getMes()==obj.getMes())
        {
            vec[reg.getFechaVenta().getDia()-1]+=reg.getMontoTotal();
        }
    }
    for(int i=0; i<31; i++)
    {
        cout<<"DIA:"<< i+1 <<" " << "RECAUDACION: "<< "$" <<vec[i]<<endl;
    }
    suma=SumatoriadiaFinal(vec);
    if (suma>0)
    {
        cout<<endl;
        cout<< "RECAUDACION DEL MES TOTAL: "<<endl;
        cout<<"$"<<suma;
    }
    else
    {
        cout<< "NO HAY NINGUNA RECAUDACION"<<endl;
    }
}


int buscarplato(int numplato)
{
    Ventas obj;
    int pos=0,recaudacion=0;

    while (obj.leerDeDisco(pos++))
    {
        if(obj.getIDplato()==numplato)
        {
            recaudacion+=obj.getMontoTotal();
        }
    }
    return recaudacion;
}

void RecaudacionPorPlato()
{
    Ventas obj;
    Carta reg;
    int pos=0,numplato,recaudacion;

    cout<< "PLATOS DISPONIBLES: "<<endl;
    cout<<endl;
    while(reg.leerDeDisco(pos++))
    {
        reg.MostrarsinPrecio();
    }
    cout<<endl;
    cout<< "INGRESE EL NUMERO DE PLATO EL CUAL DESEA SABER SU RECAUDACION: "<<endl;
    cin>>numplato;

    recaudacion=buscarplato(numplato);
    while(numplato<0 || recaudacion==0)
    {
        cout<< "NUMERO DE PLATO NEGATIVO O INEXISTENTE FAVOR DE INGRESAR UNO NUEVO: "<<endl;
        cin>>numplato;
        recaudacion=buscarplato(numplato);
    }
    cout<< "La recaudacion total del plato es: "<<endl;
    cout<<"$"<<recaudacion;
    cin.get();
}


void CantMercaderiaDisponible()
{

}
