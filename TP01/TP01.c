/*
 * TP01.c
 *
 *  Created on: 28 mar. 2021
 *      Author: FeDuS
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "TP01.h"

//menu de ocpiones
void menu(void)
{

    char opcion;
    int flagResultado;
    int flagCalculo;
    int flagA;
    int flagB;
    int flagON;
    int div0;
    float num1;
    float num2;
    float resultadoS;
    float resultadoR;
    float resultadoP;
    float resultadoD;
    long long int resultadoFA;
    long long int resultadoFB;


    //asignacion de valores iniciales
    flagResultado = 0;
    flagCalculo = 0;
    flagA = 0;
    flagB = 0;
    flagON = 1;

    //Iteracion de Menu
    while (flagON == 1)
    {
        system("cls");
        printf("\n +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ ");
        printf("\n +=                      CALCULADORA                        =+ ");
        printf("\n +=                    MENU DE OPCIONES                     =+ ");
        printf("\n +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
        printf("\n 1. Ingresar 1er operando: A");
               if(flagA==1)
                {
                    printf("=%g", num1);
                }
        printf("\n 2. Ingresar 2do operando: B");
                if(flagB==1)
                {
                    printf("=%g", num2);
                }
        printf("\n 3. Calcular todas las operaciones: ");
            if( flagCalculo == 1)
            {
                printf("   <CALCULOS REALIZADOS>  ");
            }
        printf("\n      a) Suma de Operadores (A+B)");
        printf("\n      b) Resta de Operadores (A-B)");
        printf("\n      c) Division de Operadores (A*B)");
        printf("\n      d) Multiplicacion de Operadores (A/B)");
        printf("\n      e) Factorial de Operadores (A! B!)");
        printf("\n 4. Informar resultados");
        printf("\n 5. Salir");
        printf("\n +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
        printf("\n Solo se tomara el primer caracter ingresado \n");
        printf("\n Ingrese su Opcion: "); //pido valor de opcion
        scanf("%c", &opcion);

        //determinacion del tipo de opcion elegida
        switch(opcion)
        {
        case '1'://asignacion del primer operador
            //validar num1

            printf("\n Ingrese el valor para el 1er operador: ");
            scanf("%f", &num1);
            flagA = 1;
            fflush(stdin);
            break;

        case '2'://asignacion del segundo operador
            //validar num2
            printf("\n Ingrese el valor para el 2do operador: ");
            scanf("%f", &num2);
            flagB = 1;
            fflush(stdin);
            break;

        case '3': //invoco funciones de calculo

            if (flagA != 1 && flagB != 1) //verifico que estén ambos operadores cargados
            {
                printf("\n Por Favor Ingrese todos los Operadores\n");
                system("pause");
            }
            else
            {

                flagResultado = 1; //cambio la bandera para emitir resultados
                    flagCalculo = 1;
                    resultadoS = suma(num1, num2);
                    resultadoR = resta(num1, num2);
                    if(num2!=0) //verifico division por 0
		            {
		            	resultadoD = division(num1, num2);
                    }
		            else
		            {
		            	printf("\n Divison por 0 no admitida");
		            	div0 = 1;

		            }
                    resultadoP = producto(num1, num2);
                    resultadoFA = factorial(num1);
                    resultadoFB = factorial(num2);

                }
                printf("\n Calculando...\n");
                system("pause");
            fflush(stdin);
            break;

        case '4'://emito resultados en pantalla
            if (flagResultado == 0)
            {
                printf("\n Por Favor ejecute primero las operaciones\n");
                system("pause");
            }
            else
            {
                printf("\n El resultado de la suma de A= %g y de B= %g es : %g \n", num1, num2, resultadoS);
                printf("\n El resultado de la resta de A= %g y de B= %g es : %g \n", num1, num2, resultadoR);
                if(div0 != 1)
                {
                    printf("\n El resultado de la division de A= %g y de B= %g es : %g \n", num1, num2, resultadoD);
                }
                else
                {
                    printf("\n El resultado de la division de A= %g y de B= %g es : 'error, division por cero' \n", num1, num2);
                }

                printf("\n El resultado del producto de A= %g y de B= %g es : %g \n", num1, num2, resultadoP);

                printf("\n El resultado del factorial de A= %g es : %I64u \n", num1, resultadoFA);
                printf("\n El resultado del factorial de B= %g es : %I64u \n", num2, resultadoFB);

                flagResultado = 0;
                flagCalculo = 0;
                flagA = 0;
                flagB = 0;
                div0 = 0;
                system("pause");
            }
            fflush(stdin);
            break;

        case '5'://cambio la bandera de ingreso a la iteracion para cortar el ciclo
            flagON = 0;
            printf("\n Cerrando Programa\n");
            fflush(stdin);
            break;

        default : //pido opcion nuevamente en caso que el input sea distinto de las opciones disponibles
            printf("\n Opcion Invalida \n Reingrese opcion: ");
            printf("\n Solo se tomara el primer caracter ingresado \n");
            scanf("%c", &opcion);
            fflush(stdin);
            break;
        }
        fflush(stdin);
    }

}

//funcion de suma
float suma(float num1, float num2)
{
    float resultadoS;

	resultadoS = num1 + num2;

	return resultadoS;

}

//funcion de resta
float resta(float num1, float num2)
{
    float resultadoR;

    resultadoR = num1 - num2;

	return resultadoR;

}

//funcion de producto
float producto(float num1, float num2)
{
    float resultadoP;

	resultadoP = num1 * num2;

	return resultadoP;

}

//funcion de division
float division(float num1, float num2)
{
    float resultadoD;

    resultadoD = num1 / num2;

    return resultadoD;

}

//funcion factorial
unsigned long long int factorial(float num)
{
    unsigned long long int resultado;

    //validar menores a 11
    if (num < 0 )
    {
        printf("\n No se puede realizar el factorial de un numero menor a 0");
        resultado = 0;
    }
    else if (num >11)
    {
         printf("\n Este programa no puede realizar el factorial de un numero superior a 11");
         resultado = 0;
    }
    else
    {
        if(num == 0 || num == 1)
        {
            resultado = 1;
        }
        else
        {
            resultado = num * factorial(num-1);
        }
    }

    return resultado;
}
