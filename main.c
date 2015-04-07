
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//altura
int altura = 0;
//variables para el tiempo
struct timeval inicio, fin;
//metodo para el tiempo
double tiempo(struct timeval *a, struct timeval *b){
return
(double)(a->tv_sec + (double)a->tv_usec/1000000) - (double)(b->tv_sec + (double)b->tv_usec/1000000);
}


typedef struct Otronum{
    int Num;
    struct Otronum *Siguiente;
}Otronum;
typedef struct Otronum2{
    int Num;
    struct Otronum2 *Siguiente;
}Otronum2;
//metodo burbuja
typedef struct ListaB{
//struct ListaB *Buble_Sort;
struct Otronum *Primero;
}ListaB;

typedef struct ListaQu{
struct Otronum2 *Primero;
}ListaQu;

void InsertarBuble_Sort(ListaB *Coso, int num){
   //referencia del nodo
   Otronum *Nuevo;
    Nuevo = malloc(sizeof(Otronum));
    Nuevo->Siguiente = NULL;
    Nuevo->Num = num;
//lista vacia
    if(Coso->Primero==NULL){
        Coso->Primero = Nuevo;
    }else{
        Otronum *NodoAux;
        NodoAux = Coso->Primero;

        while(NodoAux->Siguiente!=NULL){
            NodoAux = NodoAux->Siguiente;
        }
        NodoAux->Siguiente = Nuevo;
        NodoAux = Nuevo;
    }
}//mostrar quick
void InsertarQuick_Sort(ListaQu *Coso, int num){
   //referencia del nodo
   Otronum2 *Nuevo;
    Nuevo = malloc(sizeof(Otronum2));
    Nuevo->Siguiente = NULL;
    Nuevo->Num = num;
//lista vacia
    if(Coso->Primero==NULL){
        Coso->Primero = Nuevo;
    }else{
        Otronum2 *NodoAux;
        NodoAux = Coso->Primero;

        while(NodoAux->Siguiente!=NULL){
            NodoAux = NodoAux->Siguiente;
        }
        NodoAux->Siguiente = Nuevo;
        NodoAux = Nuevo;
    }
}
//mostrar burbuja

void MostrarBuble_Sort(ListaB *OtroCoso){

    Otronum *NodoAux;
    NodoAux= OtroCoso->Primero;

    while(NodoAux!=NULL){
        printf("%d ",NodoAux->Num);
        NodoAux = NodoAux->Siguiente;
    }


}
//mostrar quick

void MostrarQuick_Sort(ListaQu *OtroCoso){

    Otronum2 *NodoAux;
    NodoAux= OtroCoso->Primero;

    while(NodoAux!=NULL){
        printf("%d ",NodoAux->Num);
        NodoAux = NodoAux->Siguiente;
    }
}
//Ordenamiento burbuja

int Tam_Archivo=0;

void OrdenamientoBuble_Sort (ListaB *ListaBuble){

int i,j;
int Temporal;
Otronum *NodoBuble;
NodoBuble=ListaBuble->Primero;
//recorriendo
    for (i=1;i<Tam_Archivo;i++){
    NodoBuble=ListaBuble->Primero;
    for(j=0;j<Tam_Archivo-i;j++){
//si su siguiente es mayor entonces cambian
    if(NodoBuble->Num > NodoBuble->Siguiente->Num)
    {

    Temporal=NodoBuble->Num;
    NodoBuble->Num=NodoBuble->Siguiente->Num;
    NodoBuble->Siguiente->Num=Temporal;
            }
    NodoBuble=NodoBuble->Siguiente;

        }
    }
}

//quick

Otronum2 *Buscar(ListaQu *LQ,int num){
    int indice = 0;
    Otronum2 *auxiliar = LQ->Primero;
    Otronum2 *retorno_nodo;
    while(auxiliar!=NULL){
        if(indice==num){
            retorno_nodo = auxiliar;
            auxiliar = NULL;
        }else{
            ++indice;
            auxiliar = auxiliar->Siguiente;
        }
    }
    return retorno_nodo;
}

int Cambios(ListaQu *LQ, int inicio, int fin) {
    int lim_izq;
    int lim_der;
    int pivote;
    int temp;
    Otronum2 *aux_izq;
    Otronum2 *aux_der;
    Otronum2 *comienzo_nodo = Buscar(LQ,inicio);
    pivote = Buscar(LQ,inicio)->Num;
    lim_izq = inicio;
    lim_der = fin;

    while (lim_izq < lim_der) {
        while (Buscar(LQ,lim_der)->Num > pivote) {
            lim_der--;
        }
        aux_der = Buscar(LQ,lim_der);
        while ((lim_izq < lim_der) && (Buscar(LQ,lim_izq)->Num <= pivote)) {
            lim_izq++;
        }
        aux_izq = Buscar(LQ,lim_izq);
        if (lim_izq < lim_der) {
            temp = aux_izq->Num;
            aux_izq->Num = aux_der->Num;
            aux_der->Num = temp;
        }
    }

    temp = aux_der->Num;
    aux_der->Num = comienzo_nodo->Num;
    comienzo_nodo->Num = temp;

    return lim_der;
}

void qs(ListaQu *LQ, int inicio, int fin){ // Ordenando los datos de la lista
    int pivote;
    if (inicio < fin) {
        pivote = Cambios(LQ, inicio, fin);
        qs(LQ, inicio, pivote - 1); // menor
        qs(LQ, pivote + 1, fin);// mayor
    }
}





//Nodo avl
typedef struct NodoNumero{
    int num;
    int FE;
    struct NodoNumero *Izquierda;
    struct NodoNumero *Derecha;
}NodoNumero;
//Estructura avl
typedef struct Arbol {
    struct NodoNumero *Raiz;
}Arbol;

ListaB *Buble_Sort;
ListaQu *Quick_Sort;
Arbol *AVL;



//Rotaciones
//RII
NodoNumero *RII(NodoNumero *Num, NodoNumero *Num1){
    Num->Izquierda = Num1->Derecha;
    Num1->Derecha = Num;
    if(Num1->FE==-1){
        Num->FE=0;
        Num1->FE= 0;
    }
    else{
        Num->FE= -1;
        Num1->FE= 1;
    }
    return Num1;
}
//RDD
NodoNumero *RDD(NodoNumero *Num, NodoNumero *Num1){
    Num->Derecha = Num1->Izquierda;
    Num1->Izquierda = Num;
    if(Num1->FE==1){
        Num->FE=0;
        Num1->FE= 0;
    }
    else{
        Num->FE= 1;
        Num1->FE= -1;
    }
    return Num1;
}
//RID
NodoNumero *RID(NodoNumero *Num, NodoNumero *Num1){
    NodoNumero *Num2;
    Num2 = Num1->Derecha;
    Num1->Derecha= Num2->Izquierda;
    Num2->Izquierda = Num1;
    Num->Izquierda = Num2->Derecha;
    Num2->Derecha = Num;
    if(Num2->FE==1){
        Num1->FE = -1;
    }
    else{
        Num1->FE=0;
    }
    if(Num2->FE==-1){
        Num->FE= 1;
    }
    else{
        Num->FE=0;
    }
    Num2->FE=0;
    return Num2;
}
//RDI
NodoNumero *RDI(NodoNumero *Num, NodoNumero *Num1){
    NodoNumero *Num2;
    Num2 = Num1->Izquierda;
    Num1->Izquierda = Num2->Derecha;
    Num2->Derecha = Num1;
    Num->Derecha = Num2->Izquierda;
    Num2->Izquierda = Num;
    if(Num2->FE==1){
        Num->FE= -1;
    }
    else{
        Num->FE=0;
    }
    if(Num2->FE==-1){
        Num1->FE = 1;
    }
    else{
        Num1->FE=0;
    }
    Num2->FE=0;
    return Num2;
}

NodoNumero *Insertar(NodoNumero *Nodo, int num){
    NodoNumero *Nodoaux;
    if(Nodo==NULL){
        NodoNumero *Nuevo;
        Nuevo = (NodoNumero *)malloc(sizeof(NodoNumero));
        Nodo = Nuevo;
        Nodo->num = num;
        Nodo->Derecha = NULL;
        Nodo->Izquierda = NULL;
        Nodo->FE=0;
        altura = 1;
    }

    else{
        if(Nodo->num > num){
            Nodo->Izquierda = Insertar(Nodo->Izquierda,num);
            if(altura!=0){
                switch(Nodo->FE){
                    case 1:
                        Nodo->FE = 0;
                        altura=0;
                        break;
                    case 0:
                        Nodo->FE = -1;
                        break;
                    case -1:
                        Nodoaux = Nodo->Izquierda;
                        if(Nodoaux->FE==-1){
                            Nodo = RII(Nodo,Nodoaux);
                        }
                        else{
                            Nodo = RID(Nodo,Nodoaux);
                        }
                        altura=0;
                        break;
                }
            }
        }
        else if(Nodo->num < num){
            Nodo->Derecha = Insertar(Nodo->Derecha,num);
            if(altura!=0){
                switch(Nodo->FE){
                    case 1:
                        Nodoaux = Nodo->Derecha;
                        if(Nodoaux->FE==1){
                            Nodo = RDD(Nodo,Nodoaux);
                        }
                        else{
                            Nodo = RDI(Nodo,Nodoaux);
                        }
                        altura=0;
                        break;
                    case 0:
                        Nodo->FE = 1;
                        break;
                    case -1:
                        Nodo->FE = 0;
                        altura=0;
                        break;
                }
            }
        }
    }
    return Nodo;
}
//mostrar avl
void Mostrar(NodoNumero *Nodo){
    if(Nodo==NULL){
        return;
    }
    int Otroaux = Nodo->num;
    printf("%d",Otroaux);
    Mostrar(Nodo->Izquierda);
    Mostrar(Nodo->Derecha);
}

void InOrden(NodoNumero *Nodo){
    if(Nodo==NULL){
        return;
    }
    InOrden(Nodo->Izquierda);

    int Otroaux = Nodo->num;
    printf("%d ",Otroaux);
    InOrden(Nodo->Derecha);
}

float Lectura(char* Nombre){

    FILE* Archivo=NULL;
    char ReadLine[100];
    int endFile=0;
    Archivo = fopen(Nombre,"r");
    if(Archivo==NULL) return -1;
    endFile = fscanf(Archivo," %[^\n]",&ReadLine);
    int n = atoi(ReadLine);
     gettimeofday(&inicio, NULL);
    AVL->Raiz = Insertar(AVL->Raiz,n);
    //InsertarBuble_Sort(Buble_Sort, n);
  //  InsertarBuble_Sort(Quick_Sort, n);
    Tam_Archivo+=1;
    while(endFile!=EOF){

        endFile = fscanf(Archivo," %[^\n]",&ReadLine);
        if(endFile!=EOF){
        int n = atoi(ReadLine);
        AVL->Raiz = Insertar(AVL->Raiz,n);
        //InsertarBuble_Sort(Buble_Sort, n);
       // InsertarBuble_Sort(Quick_Sort, n);
        Tam_Archivo+=1;
        }
    }
    gettimeofday(&fin, NULL);
    float time_recorrido = tiempo(&fin, &inicio);
    printf("\nRecorrido: %lf segundos\n", time_recorrido);
    printf("\nEl archivo a sido cargado con éxito!\n");
    fclose(Archivo);
    return time_recorrido;
}

int Lectura2(char* Nombre){

    //Tam_Archivo=0
    FILE* Archivo=NULL;
    char ReadLine[100];
    int endFile=0;
    Archivo = fopen(Nombre,"r");
    if(Archivo==NULL) return -1;
    endFile = fscanf(Archivo," %[^\n]",&ReadLine);
    int n = atoi(ReadLine);
     //gettimeofday(&inicio, NULL);
    //AVL->Raiz = Insertar(AVL->Raiz,n);
    InsertarBuble_Sort(Buble_Sort, n);
    InsertarQuick_Sort(Quick_Sort, n);
    Tam_Archivo=1;
    while(endFile!=EOF){

        endFile = fscanf(Archivo," %[^\n]",&ReadLine);
        if(endFile!=EOF){
        int n = atoi(ReadLine);
        //AVL->Raiz = Insertar(AVL->Raiz,n);
        InsertarBuble_Sort(Buble_Sort, n);
        InsertarQuick_Sort(Quick_Sort, n);
        Tam_Archivo+=1;
        }
    }
    //gettimeofday(&fin, NULL);
    //float time_recorrido = tiempo(&fin, &inicio);
    //printf("\nRecorrido: %lf segundos\n", time_recorrido);
    //printf("\nEl archivo a sido cargado con éxito!\n");
    fclose(Archivo);
    return Tam_Archivo;
}

void Menu(){
    int salir=0;
    int op=0;
    char NombreArchivo[250];
    while(salir==0){
        printf("\n****************************************************************\n");
        printf("Opciones de la aplicacion:\n");
        printf("1. Datos\n");
        printf("2. Recorrido(Inorden)\n");
        printf("3. Ordenamiento (Burbuja)\n");
        printf("4. Ordenamiento (Quiksort)\n");
        printf("5. Tiempo AVL\n");
        printf("6. Tiempo BUBBLE\n");
        printf("7. Tiempo QUICKSORT\n");
        printf("8. Graficar\n");
        printf("9. Salir del Programa\n");
        printf("\n****************************************************************\n");
        printf("Eliga una opción a ejecutar: ");
        scanf("%d",&op);
        char a_Plotear[80];
        char pendiente_avl[15];
        char cant_datos[15];

        switch(op){
            case 1:
                printf("Archivo:\n");
                fflush(stdin);
                scanf("%s",&NombreArchivo);
                float time_recorrido=Lectura(NombreArchivo);
                int n = Lectura2(NombreArchivo);
                break;
            case 2:
                printf("\nRecorrido del arbol\n");
                InOrden(AVL->Raiz);
                break;
            case 3:
                printf("\nOrdenamiento de burbuja\n");
                OrdenamientoBuble_Sort(Buble_Sort);
                MostrarBuble_Sort(Buble_Sort);
                break;
            case 4:
            //pendiente
                printf("\nOrdenamiento de quick\n");
                qs(Quick_Sort,0,Tam_Archivo);
                printf("\nSi ordena\n");
                MostrarQuick_Sort(Quick_Sort);


                break;
            case 5:
            //avl
                printf("\nAVL\n");
                gettimeofday(&inicio, NULL);
                InOrden(AVL->Raiz);
                gettimeofday(&fin, NULL);
              float time_arbol = tiempo(&fin, &inicio);
                printf("\nRecorrido del arbol: %lf segundos\n", time_arbol);
                break;
            case 6:
              //Buble_sort
                printf("\nBubble_Sort\n");
                gettimeofday(&inicio, NULL);
                OrdenamientoBuble_Sort(Buble_Sort);
                MostrarBuble_Sort(Buble_Sort);
                gettimeofday(&fin, NULL);
              float time_buble = tiempo(&fin, &inicio);
                printf("\nRecorrido del bubble: %lf segundos\n", time_buble);
                break;
            case 7:
              //quick
                printf("\nQuick_Sort\n");
                gettimeofday(&inicio, NULL);

                qs(Quick_Sort,0,cant_datos);
                MostrarQuick_Sort(Quick_Sort);

                gettimeofday(&fin, NULL);
                float time_quick = tiempo(&fin, &inicio);
                printf("\nRecorrido del quick: %lf segundos\n", time_quick);
                break;


            case 8:
 // Conversion a char las variables
   sprintf(pendiente_avl, "%f", time_recorrido);
   sprintf(cant_datos, "%i", n);
// comando para "Plotear"
strcpy(a_Plotear, "gnuplot -p -e \"plot [0:");
strcat(a_Plotear, pendiente_avl);
strcat(a_Plotear, "][0:");
strcat(a_Plotear, cant_datos);
strcat(a_Plotear, "] ");
strcat(a_Plotear, cant_datos);
strcat(a_Plotear, "*x/");
strcat(a_Plotear, pendiente_avl);
strcat(a_Plotear, " title 'Grafica de inserccion AVL'\"");
system(a_Plotear);
//printf( "\nGráfica de la inserción del AVL:\n");
getchar();

//InOrden
char a_Plotear2[80];
char pendiente_inorden[15];
sprintf(pendiente_inorden, "%f", time_arbol);
strcpy(a_Plotear2, "gnuplot -p -e \"plot [0:");
strcat(a_Plotear2, pendiente_inorden);
strcat(a_Plotear2, "][0:");
strcat(a_Plotear2, cant_datos);
strcat(a_Plotear2, "] ");
strcat(a_Plotear2, cant_datos);
strcat(a_Plotear2, "*x/");
strcat(a_Plotear2, pendiente_inorden);
strcat(a_Plotear2, " title 'Grafica de InOrden'\"");
system(a_Plotear2);
//burbuja
char a_Plotear3[80];
char pendiente_bubble[15];
sprintf(pendiente_bubble, "%f", time_buble);
strcpy(a_Plotear3, "gnuplot -p -e \"plot [0:");
strcat(a_Plotear3, pendiente_bubble);
strcat(a_Plotear3, "][0:");
strcat(a_Plotear3, cant_datos);
strcat(a_Plotear3, "] ");
strcat(a_Plotear3, cant_datos);
strcat(a_Plotear3, "*x/");
strcat(a_Plotear3, pendiente_bubble);
strcat(a_Plotear3, " title 'Grafica de Bubble'\"");
system(a_Plotear3);
//quick
char a_Plotear4[80];
char pendiente_quick[15];
sprintf(pendiente_quick, "%f", time_quick);
strcpy(a_Plotear4, "gnuplot -p -e \"plot [0:");
strcat(a_Plotear4, pendiente_quick);
strcat(a_Plotear4, "][0:");
strcat(a_Plotear4, cant_datos);
strcat(a_Plotear4, "] ");
strcat(a_Plotear4, cant_datos);
strcat(a_Plotear4, "*x/");
strcat(a_Plotear4, pendiente_quick);
strcat(a_Plotear4, " title 'Grafica de Quick'\"");
system(a_Plotear4);
                break;

            case 9:
                salir = 4;
                break;

            default:
                printf("\nPorfavor ingrese una opcion correcta");
                break;
        }
    }

}

int main()
{
    AVL =malloc(sizeof(Arbol));
    Buble_Sort = malloc(sizeof(ListaB));
    Quick_Sort= malloc(sizeof(ListaQu));

    Menu();


    return 0;
}
