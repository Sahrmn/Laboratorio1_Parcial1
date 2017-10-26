#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include "input.h"
#define US 10
#define PR 10

int main()
{
    char seguir='s';
    int opcion=0;
    int i;
    eUsuario user[US];
    eUsuario* usuario;
    eProducto prod[PR];
    eProducto* producto;
    int comprobacion;
    int idUser;

    usuario = user;
    producto = prod;

    for(i=0;i<US;i++) // inicializo los usuarios para, mas tarde, saber cual contiene un usuario cargado
    {
        (usuario+i)->flag = 0;
        (usuario+i)->calificacion = 0;
    }
    for(i=0;i<PR;i++) //inicializo productos en 0
    {
        (producto+i)->id = 0;
        (producto+i)->vendido = 0;
    }
    cargaUsuarioProductos(producto,usuario);

    while(seguir=='s')
    {
        system("cls");
        printf("==========================\n");
        printf("|         MENU           |\n");
        printf("==========================\n\n");
        printf("1- ALTA DE USUARIO\n");
        printf("2- MODIFICAR USUARIO\n");
        printf("3- BAJA DE USUARIO\n");
        printf("4- PUBLICAR PRODUCTO\n");
        printf("5- MODIFICAR PUBLICACION\n");
        printf("6- CANCELAR PUBLICACION\n");
        printf("7- COMPRAR PRODUCTO\n");
        printf("8- LISTAR PUBLICACIONES DE USUARIO\n");
        printf("9- LISTAR PUBLICACIONES\n");
        printf("10- LISTAR USUARIOS\n");
        printf("11- SALIR\n\n");

        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1: //Alta de usuario
                system("cls");
                printf("***********************\n");
                printf("*   ALTA DE USUARIO   *\n");
                printf("***********************\n\n");
                comprobacion = altaUsuario(usuario, US);
                if(comprobacion == -1)
                {
                    printf("No se pudo crear el usuario.\n");
                    system("pause");
                }
                break;
            case 2: //Modificar usuario
                system("cls");
                printf("******************************\n");
                printf("*   MODIFICACION DE USUARIO   *\n");
                printf("******************************\n\n");
                comprobacion = modificarUsuario(usuario, US);
                if(comprobacion == -1)
                {
                    printf("Hubo un problema. Intentelo de nuevo.\n");
                    system("pause");
                }
                break;
            case 3: //Baja del usuario
                system("cls");
                printf("***********************\n");
                printf("*   BAJA DE USUARIO   *\n");
                printf("***********************\n\n");
                comprobacion = bajaUsuario(usuario,producto,US,PR);
                if(comprobacion == -1)
                {
                    printf("No se pudo dar de baja el usuario o no existe.\n");
                    system("pause");
                }
                else if(comprobacion == -2)
                {
                    printf("\nContraseña incorrecta.\n");
                }
                system("pause");
                break;
            case 4: //Publicar producto
                system("cls");
                printf("*******************************\n");
                printf("*   PUBLICACION DE PRODUCTO   *\n");
                printf("*******************************\n\n");
                comprobacion = publicarProducto(usuario,producto,US,PR);
                if(comprobacion == -1)
                {
                    printf("No existe el usuario o la contraseña es incorrecta. Intente de nuevo.\n");
                    system("pause");
                }
                printf("\n");
                break;
            case 5: //Modificar publicacion
                system("cls");
                printf("***********************************\n");
                printf("*   MODIFICACION DE PUBLICACION   *\n");
                printf("***********************************\n\n");
                comprobacion = modificarPublicacion(usuario,producto,US,PR);
                if(comprobacion == -1)
                {
                    printf("\nNo existe el usuario.\n");
                    system("pause");
                }
                else if(comprobacion == -2)
                {
                    printf("\nContraseña incorrecta.\n");
                    system("pause");
                }
                else if(comprobacion == -3)
                {
                    printf("\nNo existe el id de producto.\n");
                    system("pause");
                }
                printf("\n");
                break;
            case 6: //Cancelacion de publicaciones de usuario
                system("cls");
                printf("**********************************\n");
                printf("*   CANCELACION DE PUBLICACION   *\n");
                printf("**********************************\n\n");
                comprobacion = cancelarPublicacion(usuario,producto,US,PR);
                if(comprobacion == -1)
                {
                    printf("\nEl usuario no tiene publicaciones activas o no existe.\n");
                    system("pause");
                }
                else if(comprobacion == -2)
                {
                    printf("\nContraseña incorrecta. Intente de nuevo.\n");
                    system("pause");
                }
                else if(comprobacion == -3)
                {
                    printf("\nEl usuario no tiene publicaciones activas.\n");
                    system("pause");
                }
                else if(comprobacion == -4)
                {
                    printf("\nNo existe la publicacion.\n");
                    system("pause");
                }
                printf("\n");
                break;
            case 7: //Comprar producto
                system("cls");
                printf("**************************\n");
                printf("*   COMPRA DE PRODUCTO   *\n");
                printf("**************************\n\n");
                comprobacion = compraProducto(producto,usuario,PR,US);
                if(comprobacion == -1)
                {
                    printf("\nNo se pudo comprar el producto.\n");
                    system("pause");
                }
                else
                {
                    printf("\nHecho!\n");
                    system("pause");
                }
                printf("\n");
                break;
            case 8: //Listar publicaciones de usuario
                system("cls");
                printf("********************************\n");
                printf("*   PUBLICACIONES DE USUARIO   *\n");
                printf("********************************\n\n");
                mostrarUsuarios(usuario,US);
                printf("Ingrese el id del usuario:\n");
                scanf("%d",&idUser);
                comprobacion = mostrarPublicacionesUsuario(producto,PR,idUser);
                if(comprobacion == -1)
                {
                    printf("\nEl usuario no existe o no tiene publicaciones activas.\n");
                }
                printf("\n");
                system("pause");
                break;
            case 9: //Listar publicaciones
                system("cls");
                printf("**************************\n");
                printf("*   LISTA DE PRODUCTOS   *\n");
                printf("**************************\n\n");
                mostrarProductos(producto,usuario,PR,US);
                printf("\n");
                break;
            case 10: //Listar usuarios
                system("cls");
                printf("*************************\n");
                printf("*   LISTA DE USUARIOS   *\n");
                printf("*************************\n\n");
                mostrarUsuarios(usuario,US);

                printf("\n");
                break;
            case 11:
                seguir = 'n';
                break;
            default:
                seguir = 's';
                break;
        }
    }
    return 0;
}
