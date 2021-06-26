#include "Reportes.h"

int SumatoriamesFinal(int *vec)
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
    int vec[12]= {},pos=0,suma;
    Ventas reg;
    Fecha obj;
    while(reg.leerDeDisco(pos++))
    {
        if(reg.getFechaVenta().getAnio()==obj.getAnio())
        {
            vec[reg.getFechaVenta().getMes()-1]+=reg.getMontoTotal();
        }
    }
    for(int i=0; i<12; i++)
    {
        cout<<"MES:"<< i+1 <<" " << "RECAUDACION: "<< "$" <<vec[i]<<endl;
    }
    suma=SumatoriamesFinal(vec);
    if (suma>0)
    {
        cout<<endl;
        cout<< "RECAUDACION ANUAL TOTAL: "<<endl;
        cout<<"$"<<suma;
    }
    else
    {
        cout<< "NO HAY NINGUNA RECAUDACION"<<endl;
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
void CantMercaderiaDisponible()
{

}
