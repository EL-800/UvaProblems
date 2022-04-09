#include "pila.h"

/*********************************************************
Definir las funciones que se utilizan para el control
  de las pilas.
Por: Juan Jes�s Guti�rrez Garc�a
Para: Ejemplos de programaci�n
Fecha: Nov-2020
**********************************************************/

/* Funci�n interna que hace crecer el arreglo
   dentro de la pila
RECIBE: Apuntador a la pila que ya est� llena
REGRESA: La misma pila con espacio adicional
     o c�digo de error en caso que ya no haya memoria
NOTAS: El arreglo crece en TAMCRE espacios de memoria
*/
int crece(pila* p){
  /*Apuntador a arreglo m�s grande*/
  DATO* nuevo;
  int i;

  nuevo = (DATO*)malloc(sizeof(DATO)*(p->tam+TAMCRE));
  if(!AP_VAL(nuevo))
    return OVERFLOW;
  /*Copiar datos al arreglo nuevo*/
  for(i=0;i<p->tam;i++)
    nuevo[i] = p->dato[i];

  if (AP_VAL(p->dato))
    free(p->dato);

  p->dato = nuevo;
  p->tam+=TAMCRE;
  return OK;
}

/**********************************************************
                C O N S T R U C T O R E S
/*********************************************************/
/* Inicializar la pila.
Objetivo: Dar valores iniciales. Se debe invocar despu�s
   de declarar una variable tipo pila.
RECIBE:
   Apuntador a pila a ser inicializada
REGRESA:
   C�digo de error.
REQUIERE:
   Que el apuntador que recibie no sea NULL
*/
int inic_pil(pila* p){
  if(!AP_VAL(p))
    return AP_INV;

  p->dato = NULL;
  p->tope = 0;
  p->tam  = 0;
  return OK;
}

/* Asignar memoria din�mica.
Objetivo: Dar valores iniciales. Y solicitar memoria para
   El arreglo que almacenar� los datos. Crea una pila vac�a.
RECIBE:
   Apuntador a pila a ser creada
REGRESA:
   C�digo de error.
REQUIERE:
   Que el apuntador que recibie no sea NULL y que
   se invoque a la funci�n eliminar cuando ya no se use
   la pila.
*/
int crea_pil(pila* p){
  if(!AP_VAL(p))
    return AP_INV;

  if(AP_VAL(p->dato))
    elim_pil(p);
  p->dato = (DATO*)malloc(sizeof(DATO)*TAMMAX);
  if(!AP_VAL(p->dato))
    return OVERFLOW;

  p->tope = 0;
  p->tam = TAMMAX;
  return OK;
}

/* Regresa la memoria din�mica.
Objetivo: Destruir la pila y regresar la memoria din�mica.
RECIBE:
   Apuntador a pila a ser creada
REGRESA:
   C�digo de error.
REQUIERE:
   Que la pila haya sido creada. Y pasa la pila al estado de
   Cav�a sin memoria.
*/
int elim_pil(pila* p){
  if(!AP_VAL(p))
    return AP_INV;

  if(p->dato)
    free(p->dato);
  inic_pil(p);
  return OK;
}

/**********************************************************
                M O D I F I C A D O R E S
/*********************************************************/

/* Inserta un dato en la pila.
Objetivo: Insertar un dato en la pila. En caso de que la
  pila est� llena busca hacer crecer el arreglo. Si no hay
  memoria regresar� OVERFLOW
RECIBE:
   Apuntador a pila a ser creada
   Dato a ser insertado en la pila
REGRESA:
   C�digo de error.
REQUIERE:
   Que la pila haya sido creada y un apuntador no NULL
*/
int push_pil(pila* p,DATO d){
  int err;
  if(!AP_VAL(p))
    return AP_INV;
  if(!TIE_ESP(p))
	  if((err = crece(p)))
      return err;

  p->dato[p->tope++]= d;
  return OK;
}

/* Eliminar un dato en la pila.
Objetivo: Eliminar un dato de la pila. En caso de que
   la pila est� vac�a regresa UNDERFLOW.
RECIBE:
   Apuntador a pila de que se sacar� el dato
REGRESA:
   C�digo de error.
REQUIERE:
   Que haya datos en la pila, apuntador no NULL
*/
int pop_pil(pila* p){
  if(!AP_VAL(p))
    return AP_INV;
  if(!TIE_DAT(p))
    return UNDERFLOW;

  p->tope--;
  return OK;
}

/**********************************************************
                O B S E R V A D O R A S
/*********************************************************/
/* Tope de la pila
Objetivo: Regresa dato en el tope de la pila.
RECIBE:
   Apuntador a pila de que se sacar� el dato
   Apuntador a dato en que se regresar� el valor
      que est� en el tope de la pila
REGRESA:
   C�digo de error.
REQUIERE:
   Que haya datos en la pila, apuntadores no NULL
*/
int tope_pil(DATO* d, const pila* p){
  if(!(AP_VAL(p) && AP_VAL(d)) )
    return AP_INV;
  if(!TIE_DAT(p))
    return UNDERFLOW;

  *d = p->dato[p->tope-1];
  return OK;
}

/* A cadena
Objetivo: Generar una representaci�n de la pila
   Como cadena. Usa la constante FORMATO para
   convertir cada dato de la pila a cadena.
   Debe garantizar la cadena de salida tiene espacio
     para almcenar la representaci�n completa.
RECIBE:
   Apuntador a cadena que tendr� la representaci�n
   Apuntador pila que ser� convertida a cadena.
REGRESA:
   El mismo apuntador que regresa. En caso de erro
   Agrega a la cadena el valor "NULL"
REQUIERE:
   Apuntadores no NULL
*/
char* tostr_pil(char* s, const pila* p){
  char dato[TAMDAT];
  int i;
  if(!(AP_VAL(s)&&AP_VAL(p)))
    return s;

  strcpy(s,"[");
  for(i=0;i<p->tope;i++){
    sprintf(dato,FORMATO,p->dato[i]);
	  strcat(s,dato);
  }
  strcat(s,"]\n");
  return s;
}
