#include "Reportes.h"


int buscadoranio(int *vec)
{
    int suma=0;
    for(int i=0; i<12; i++)
    {
        suma+=vec[i];
    }
    return suma;
}




void RecaudacionAnual()
{
    int suma,anio,vec[12]={},pos=0;
    Ventas reg;
    Fecha obj;
    cout<< "Ingrese el anio el cual desea buscar: "<<endl;
    cin>>anio;
    while (anio<0)
    {
        cout<< "Valor ingresado negativo, favor de ingresar un anio valido: "<<endl;
        cin>>anio;
    }
    while(reg.leerDeDisco(pos++))
    {
        if(reg.getFechaVenta().getAnio()==anio)
        {
            vec[reg.getFechaVenta().getMes()-1]+=reg.getMontoTotal();
        }
    }
    suma=buscadoranio(vec);
    if(suma>0)
    {
        for(int i=0; i<12; i++)
        {
            cout<<"MES: "<< i+1 <<" " << "RECAUDACION: "<< "$" <<vec[i]<<endl;
        }
        cout<< "La suma vendida anio es de: "<<endl;
        cout<< suma;
        cin.get();
    }
    else
    {
        system("cls");
        cout<< "El anio elegido no tiene ninguna recaudacion "<<endl;
        cin.get();
    }


}

int buscadormes(int mes, int anio)
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


void RecaudacionMensual()
{
    int suma,mes,anio;
    Ventas reg;
    cout<< "Ingrese el anio el cual desea saber: "<<endl;
    cin>>anio;
    while (anio<0)
    {
        cout<< "Valor ingresado negativo, favor de ingresar un anio valido: "<<endl;
        cin>>anio;
    }
    cout<< "Ingrese el mes el cual desea buscar: "<<endl;
    cin>>mes;
    while (mes<0)
    {
        cout<< "Valor ingresado negativo, favor de ingresar un mes valido: "<<endl;
        cin>>mes;
    }
    suma=buscadormes(mes, anio);
    if (suma>0)
    {
        cout<< "La suma vendida en el mes es de: "<<endl;
        cout<< suma;
        cin.get();
    }
    else
    {
        system("cls");
        cout<< "El anio/mes que selecciono no posee ninguna recaudacion "<<endl;
        cin.get();
    }

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
