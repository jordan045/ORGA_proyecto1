#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int fromDecInteger(int, int);
int toDecInteger(int , int );
double FracionDecToDestino(double , int );
double FraccionOrigenToDec(double , int );
double convertToDec(double,int);
double convertFromDec(double,int);


//convert -n number [-s source] [-d destino]  [-v] [-h]
int main(int argc, char **argv)
{
    int seleccion;
    int num;
    int base;
    double numf;
    int basef;
    int source;
    int dest;
    int resultado;
    double resultadof;
    printf("QUE QUIERE HACER?\n1: Pasar entero a decimal\n2: Convertir decimal entero a otra base\n3: Pasar fraccionario a decimal\n4: Pasar frac. decimal a otra base\n5: Numero a decimal\n6: Decimal a otro\n7: Conversion en general\n");
    printf("Su respuesta...  ");
    scanf("%d", &seleccion);
    printf("\n\n");

    char letra= '3';
    char stringg[15]={"123456"};
    char *pc=&stringg;
    double cccc=atof(*pc);
    printf("%d __ %.5lf",letra,cccc);

    switch(seleccion){
    case 1:
        printf("Ingrese numero y en que base está\n");
        scanf("%d", &num);
        scanf("%d", &base);
        resultado= toDecInteger(num,base);
        printf("%d en base 10 es: %d\n\n",num,resultado);
        break;
    case 2:
        printf("Ingrese numero en decimal y a que base quiere pasarlo\n");
        scanf("%d", &num);
        scanf("%d", &base);
        resultado= fromDecInteger(num,base);
        printf("%d en base %d es: %d",num,base,resultado);
        break;
    case 3:
        printf("Ingrese numero y en que base está\n");
        scanf("%f", &numf);
        scanf("%d", &basef);
        resultadof= FraccionOrigenToDec(numf,basef);
        printf("%.5f en base 10 es: %.5f\n\n",numf,resultadof);
        break;
    case 4:
        printf("Ingrese numero en decimal y a que base quiere pasarlo\n");
        scanf("%f", &numf);
        scanf("%d", &basef);
        resultadof= FracionDecToDestino(numf,basef);
        printf("%.5f en base %d es: %.5f",numf,basef,resultadof);
        break;
    case 5:
        printf("Ingrese numero y en que base esta\n");
        scanf("%lf",&numf);
        scanf("%d",&basef);
        resultadof= convertToDec(numf,basef);
        printf("%.5lf en base 10 es: %.5lf\n\n",numf,resultadof);
        break;
    case 6:
        printf("Ingrese numero en decimal y a que base quiere pasarlo\n");
        scanf("%lf", &numf);
        scanf("%d", &basef);
        resultadof= convertFromDec(numf,basef);
        printf("%.5lf en base 10 es: %.5lf\n\n",numf,resultadof);
        break;
    case 7:
        printf("Ingrese numero y su base\n");
        scanf("%lf", &numf);
        scanf("%d", &source);
        printf("Ingrese base destino: ");
        scanf("%d",&dest);
        resultadof= convertFromDec(convertToDec(numf,source),dest);
        printf("(%.5lf)-%d es (%.5lf)-%d",numf,source,resultadof,dest);
        break;
    }
    return 0;
}

double convertToDec(double num, int base){
    double resultado;
    double numSinEntero=fmod(num,1);
    int numSoloEntero= num-numSinEntero;
    numSinEntero= FraccionOrigenToDec(numSinEntero,base);
    numSoloEntero= toDecInteger(numSoloEntero, base);
    resultado= numSinEntero+numSoloEntero;
    return resultado;
}

double convertFromDec(double num, int base){
    double resultado;
    double numSinEntero=fmod(num,1);
    int numSoloEntero= num-numSinEntero;
    numSinEntero= FracionDecToDestino(numSinEntero,base);
    numSoloEntero= fromDecInteger(numSoloEntero, base);
    resultado= numSinEntero+numSoloEntero;
    return resultado;
}

int toDecInteger(int value, int source){
    int res=0;
    int i=0;
    while(value != 0){
        res= res+(value % 10 * pow(source,i));
        value= value/10;
        i++;
    }
    return res;
}

int fromDecInteger(int value, int dest){
    int modulo=value % dest;
    int res= modulo;
    int i=1;
    value= value / dest;
    while(value != 0){
        modulo= value % dest;
        value= value / dest;
        res= res + modulo*(pow(10,i));
        i++;
    }
    return res;
}

double FracionDecToDestino(double numm, int basee){
    double numresultado=0;
    double numSinEntero=0;

    for(int i=1;i<=5;i++){
        numm=numm*basee;
        numSinEntero=fmod(numm,1);
        numresultado=numresultado+(numm-numSinEntero)/pow(10,i);
       // printf("la fraccion decimal"+num+"por la base= "+num+""+base=numbase);
        numm=fmod(numm,1);
       // printf("tomamos la parte entera de la multiplicacion que va a ser nuestro primer digito de la fraccion en destino= "+numSinEntero);
        //printf("tomamos la parte fracionaria de la multiplicacion que va a ser el numero que utilizaremos")
        //printf("para repetir el primer proceso de multiplicacion= "+num);
    }
    //printf(numresultado);
    return (numresultado);
}

double FraccionOrigenToDec(char numS[15], char base[2]){
    double *num;
    num=(double*)malloc(sizeof(double));
    *num=transformadorBaseM9(numS);
    double numresultado=0;
    double numSinEntero=0;
    for(int i=1;(i<=5) && (0.0<*num);i++){
        *num=*num*10;
        numSinEntero=fmod(*num,1);
        numresultado=numresultado+((*num-numSinEntero)/pow(base,i));
        *num=numSinEntero;
    }
    //printf(numresultado);
    free(num);
    return (numresultado);
}



//IMPORTANTE //itoa(valor, cadena, 10); pasar de int a cadena el 10 significa base 10 verificar q pasa si ponemos base 16 9 etc
float transformadorBaseM9 (char string[15]){
        char *ps;
        double numTransformado=0;
        for (int i=0;i<15;i++){
             if ((*ps=&string[i] >= 'a') && (*ps=&string[i] <= 'f')){
                *ps= *ps - 'a' + 'A'-55;
                numTransformado=numTransformado*10+(*ps);
            }else if((*ps=&string[i] >= 'A') && (*ps=&string[i] <= 'F')){
                 *ps= *ps-55;
                numTransformado=numTransformado*10+(*ps);
            }else if((*ps=&string[i]>'9') || (*ps=&string[i]<'0')){
                //ERROR SIN TERMINAR
                exit(2);
            }else{
                //double sumar=atof(*ps); en caso q no funcione le sumamos la variable
                numTransformado=numTransformado*10+ atof(*ps);
            }

        }
            return numTransformado;
    }



char[] FFracionDecToDestino(char[] num, char[] origen){
     char* resultado[5];
    resultado=(char*[])malloc(sizeof(char));
    *resultado="";
    //itoa(valor, cadena, 10); pasar de int a cadena el 10 significa base 10 verificar q pasa si ponemos base 16 9 etc
    free(resultado);
    return *resultado;
}




//  0      1   2      3     4     5     6       7    8
//convert -n number [-s source] [-d destino]  [-v] [-h]
//NO ES NECESARIO PONER LOS CORCHETES
void validacionDeIngresoDatos(){
     char* vHayBoolean;
    vHayBoolean=(int*)malloc(sizeof(int));
    int *vHayBoolean=0;
    int hHayBoolean=0;
    char numero[16] ="";
    char origen[2] ="";
    char destino[2] ="";
    int *i=0;
    for(*i=1;*i<argc;(*i)++){
        argv++;
        if(*argv=="-h"){
            if(*vHayBoolean==1)
                exit(2);
            *hHayBoolean=1;
        }else if(*argv=="-v"){
                if(*vHayBoolean==1)
                    exit(2);
                *vHayBoolean=1;
              }else if(*argv=="-n"){
                        if(numeroHabilitado(*argv+1)){ //ERROR NO ESTA HABILITADA
                            numero=*argv+1;
                            i++;
                        }else
                            exit(1);
                    }else if(*argv=="-s"){
                            if(baseHabilitada(*argv+1)){ //ERROR NO ESTA HABILITADA
                                origen=*argv+1
                                i++;
                            }else
                                exit(1);
                            }else if(*argv=="-d"){
                                     if(baseHabilitada(*argv+1)){ //ERROR NO ESTA HABILITADA
                                        destino=*argv+1;
                                        i++;
                                     }else
                                        exit(1); //ERROR NO ESTA HABILITADA
                            }else {
                                exit(2); // ERROR HAY ALGO Q NO ESTA BIEN ESCRITO
                            }
    }
    //se controla que no falte nada
    if((numero=="")||(origen=="")||(destino="")){
        exit(); //FALTAN DATOS PARA PROSEGUIR
    }else{
        //METODO PARA CONVERTIR
    }
    free(vHayBoolean);
}


