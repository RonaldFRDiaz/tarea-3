#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

struct PedidosA{
    int frijolqueso;
    int revuelta;
    int queso;
    int loroco;
    int loca;
    string arroz;
    int coca;
    int cantidad;
    char sinococa;
    PedidosA *sig;
};

class pupuses
{
private:
    PedidosA *saltarin;
public:
    pupuses(){
        saltarin = NULL;
    }
    ~pupuses(){
        PedidosA *nax;
        while (nax->sig)
        {
            nax= saltarin;
            saltarin = saltarin->sig;
            delete nax;
        }
    };

void ingresarpedido(int frijolquesoX, int revueltaX, int quesoX, int lorocoX, int locaX ,string arrozX,int cantidadX, char cocitaX, int cocaX)
{  PedidosA *nuevaorden = new PedidosA;
   nuevaorden->frijolqueso=frijolquesoX;
   nuevaorden->revuelta=revueltaX;
   nuevaorden->queso=quesoX;
   nuevaorden->loroco=lorocoX;
   nuevaorden->loca=locaX;
   nuevaorden->arroz=arrozX;

   nuevaorden->cantidad=cantidadX;
   nuevaorden->sinococa=cocitaX;
   nuevaorden->coca=cocaX;

   nuevaorden->sig =NULL;

   if(saltarin == NULL){
     saltarin = nuevaorden;  }
    else{
      PedidosA *aux =nuevaorden;
          aux = saltarin;
            while(aux -> sig)
            {
                aux = aux->sig;
            }
            aux ->sig = nuevaorden;
        }
}

//void pedirpedido(int cantidadX, char cocitaX, int cocaX){
//   PedidosA *nuevaorden = new PedidosA;
//    nuevaorden->sig =NULL;
// if(saltarin == NULL){
//     saltarin = nuevaorden;  }  else{
//      PedidosA *aux =nuevaorden;
//          aux = saltarin;
//            while(aux -> sig)
//            {      aux = aux->sig;  }
//            aux ->sig = nuevaorden;  }
//}

void imprimirpedido(){
    PedidosA *mostrar = new PedidosA;
    mostrar = saltarin;

    
    while (mostrar != NULL)
    {   
        cout<<"\tla cantidad de pupusas que pidio: "<<mostrar->cantidad<<endl;
        cout<<"\tcantidad de pupusas de frijol con queso: "<<mostrar->frijolqueso<<endl;
        cout<<"\tcantidad de pupusas de revueltas: "<<mostrar->revuelta<<endl;
        cout<<"\tcantidad de pupusas de locoro con queso: "<<mostrar->loroco<<endl;
        cout<<"\tcantidad de pupusas de  queso: "<<mostrar->queso<<endl;
        cout<<"\tcantidad de pupusas locas : "<<mostrar->loca<<endl; 
        cout<<"\tde que tipo de pupusa pidio: "<<mostrar->arroz<<endl;
        cout<<"\tla cantidad de bebida que pidio: "<<mostrar->coca<<endl;
        mostrar = mostrar ->sig;
    }
}
};

int main(){
    pupuses paraverselindo;
    int opcion = 0;
    bool continuar = true;
    char cantidadcoca;
    int frijolqueso=0, coca=0,pupusa=0,revuelta=0,queso=0,loroco=0,loca=0,cantidad=0;
    string arroz;

    do{
        cout<<endl;
     cout<<"   **MENU**  "<<endl;
     cout<<"---------------\n"<<endl;
    cout<<"1. ingesar el pedido  \n"<<endl;
    cout<<"2. especialidad \n"<<endl;
    cout<<"3. mostrar el pedido \n"<<endl;
    cout<<"4. acabar el pedido  \n"<<endl;
    cout<<"elija su opcion: "<<endl;
    cin>>opcion;
    switch (opcion)
    {
      case 1:
     cout<<"ingrese la cantidad de pupusa que desea ordenar: ";
     cin>>cantidad;
     cout<<"quiere pedir coca con sus pupusas (S/N)?: ";
     cin>>cantidadcoca; 
     while((cantidadcoca=='S')||(cantidadcoca=='s')) 
     {cout<<"ingrese cuantas bebidas  quieren: ";
      cin>>coca; break;} 
    paraverselindo.ingresarpedido(frijolqueso,revuelta ,queso, loroco, loca , arroz, cantidad, cantidadcoca, coca);
    //paraverselindo.pedirpedido(cantidad, cantidadcoca, coca);
    break;
     case 2:
      cout<<" \t el menu de pupusas "<<endl;
      cout<<" --------------------------------------------------\n"<<endl;
        cout<<"ingrese cuantas pupusas de frijol con queso quieren : ";
        cin>>frijolqueso;
        cout<<"ingrese cuantas pupusas revueltas quieren: ";
        cin>>revuelta;
        cout<<"ingrese cuantas pupusas de queso quieren: ";
        cin>>queso;
        cout<<"ingrese cuantas pupusas de loroco con queso quieren: ";
        cin>>loroco;
        cout<<"ingrese cuantas pupusas locas quiere: ";
        cin>>loca;
       
        cout<<"elija si la quiere de arroz o maiz: ";
        cin>>arroz;
        cin.ignore();

        paraverselindo.ingresarpedido(frijolqueso,revuelta ,queso, loroco, loca , arroz, cantidad, cantidadcoca, coca);
       break;
    case 3:
      cout<<"este es el pedido que ordeno:\n "<<endl;
       paraverselindo.imprimirpedido();
       opcion=0;
       break;
       default: cout<<"\t******ADIOS, VUELVA PRONTO!!********\n"<<endl;
              break;

     } 
 }while(continuar);

}