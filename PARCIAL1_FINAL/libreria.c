#include "libreria.h"
#include "input.h"
#include <stdio.h>
#include <string.h>

void cargaUsuarioProductos(eProducto* producto, eUsuario* usuario)
{
    int i;
    int idu[] = {1,2,3,4,5};
    char user[][20]= {"samantha","jorge","aldana","anabella","daniela"};
    char pass[][15]= {"sam","jor","aldi","ana","dani"};
    int idp[] = {100,101,102,103,104};
    char prod[][20]= {"arroz","lentejas","atun","caballa","choclo"};
    float precio[]= {1.12,5.5,8.9,10,18.5};
    int stock[]= {5,8,6,3,10};
    int id_uspr[] = {1,5,4,3,2};
    int calif[] = {0,0,0,0,0};

    for(i=0; i<5; i++)
    {
        (usuario+i)->id = idu[i];
        strcpy((usuario+i)->nombre,user[i]);
        strcpy((usuario+i)->pass,pass[i]);
        (usuario+i)->calificacion = calif[i];
        (usuario+i)->flag = 1;
    }
    for(i=0; i<5; i++)
    {
        (producto+i)->id = idp[i];
        strcpy((producto+i)->nombre,prod[i]);
        (producto+i)->precio = precio[i];
        (producto+i)->stock = stock[i];
        (producto+i)->id_usuario = id_uspr[i];
    }
}

int altaUsuario(eUsuario* usuario, int sizeUser)
{
    int i;
    int flag2=0;

    for(i=0; i<sizeUser; i++)
    {
        if((usuario+i)->flag==0)
        {
            (usuario+i)->id = i+1;
            getString((usuario+i)->nombre,"Ingrese nombre de usuario nuevo","Debe ser mayor a 2 y menor a 15 caracteres",2,15);
            getString((usuario+i)->pass,"Ingrese password del nuevo usuario","Debe ser mayor a 2 y menor a 15 caracteres",2,15);
            (usuario+i)->flag = 1;
            (usuario+i)->calificacion = 0;
            flag2 = 1;
            break;
        }
    }
    if(flag2==0)
    {
        return -1;
    }
    mostrarUsuarios(usuario, sizeUser);
    return 0;
}

void mostrarUsuarios(eUsuario* usuario, int sizeUser)
{
    int i;

    printf("ID\t NOMBRE \t PASS \t CALIFICACION\n\n");
    for(i=0; i<sizeUser; i++)
    {
        if((usuario+i)->flag==1)
        {
            printf("%d\t%s\t\t%s\t%d\n",(usuario+i)->id,(usuario+i)->nombre,(usuario+i)->pass,(usuario+i)->calificacion);
        }
    }
    printf("\n");
    system("pause");
}

int publicarProducto(eUsuario* usuario,eProducto* producto, int sizeUser, int sizeProd)
{
    int i;
    int id;
    int flag = 0;
    char pass[15];

    mostrarUsuarios(usuario, sizeUser);
    printf("\nIngrese la id del usuario que quiere publicar el producto:\n");
    fflush(stdin);
    scanf("%d",&id);

    for(i=0; i<sizeUser; i++) //verifico que exista el usuario
    {
        if((usuario+i)->id == id)
            flag = 1;
    }
    if(flag==0)
    {
        return -1;
    }
    flag=0;
    getString(pass,"Ingrese contraseña de usuario:","Tiene que tener por lo menos 3 caracteres",3,15);
    for(i=0; i<sizeUser; i++) //verifico contraseña
    {
        if((usuario+i)->flag!=0)
        {
            if((usuario+i)->id==id && strcmp((usuario+i)->pass,pass)==0)
                flag=1;
        }
    }
    if(flag==0)
    {
        return -1;
    }

    for(i=0; i<sizeProd; i++)
    {
        if((producto+i)->id == 0)
        {
            (producto+i)->id = i+100;
            (producto+i)->id_usuario = id;
            getString((producto+i)->nombre,"Ingrese el nombre del producto:","Debe tener entre 3 y 20 caracteres",3,20);
            //getFloat(producto[i].precio,"Ingrese el precio:","Debe ser un numero y ser mayor a 0",1,10);
            printf("Ingrese el precio:\n");
            fflush(stdin);
            scanf("%f",&(producto+i)->precio);
            printf("Ingrese la cantidad de stock disponible del producto:\n");
            fflush(stdin);
            scanf("%d",&(producto+i)->stock);
            break;
        }
    }
    mostrarProductos(producto,usuario,sizeProd,sizeUser);
    return 0;
}

void mostrarProductos(eProducto* producto,eUsuario* usuario, int sizeProd, int sizeUser)
{
    int i, j;
    char user[20];

    printf("ID\t NOMBRE \t PRECIO \t STOCK \t USUARIO\t CANT.VENDIDA\n\n");
    for(i=0; i<sizeProd; i++)
    {
        if((producto+i)->id!=0)
        {
            for(j=0; j<sizeUser; j++)
            {
                if((producto+i)->id_usuario == (usuario+j)->id)
                {
                    strcpy(user,(usuario+j)->nombre);
                    break;
                }
            }
            printf("%d\t%s\t\t%.2f\t\t  %d\t  %s\t %d\n",(producto+i)->id,(producto+i)->nombre,(producto+i)->precio,(producto+i)->stock,user,(producto+i)->vendido);
        }
    }
    printf("\n");
    system("pause");
}

int bajaUsuario(eUsuario* usuario,eProducto* producto, int sizeUser, int sizeProd)
{
    int i;
    int id;
    int flag = 0;
    int retorno;
    int* idP;
    idP = &id;

    /*mostrarUsuarios(usuario, sizeUser);
    printf("\n");
    printf("Ingrese el id del usuario a dar de baja:\n");
    fflush(stdin);
    scanf("%d",&id);*/
    retorno = verificarUsuario(usuario,sizeUser,idP);
    if(retorno!=0)
        return retorno;

    for(i=0; i<sizeUser; i++)
    {
        if((usuario+i)->id == id)
        {
            (usuario+i)->id = 0;
            (usuario+i)->flag = 0;
            (usuario+i)->calificacion = 0;
            flag = 1;
            break;
        }
    }
    for(i=0; i<sizeProd; i++)
    {
        if(id == (producto+i)->id_usuario)
        {
            (producto+i)->id = 0;
            (producto+i)->id_usuario = 0;
            (producto+i)->stock = 0;
        }
    }
    if(flag == 0)
        return -1;

    printf("\nUsuario dado de baja!\n");
    return 0;
}

int compraProducto(eProducto* producto, eUsuario* usuario, int sizeProd, int sizeUser)
{
    int i;
    int j;
    int idu;
    int idp;
    int calif;
    int flag = 0;
    char pass[15];
    int retorno;
    char user[20];
    int cant;
    int* iduP;
    int iduenio;

    iduP = &idu;

    retorno = verificarUsuario(usuario,sizeUser,iduP);
    if(retorno != 0)
        return retorno;

    printf("ID\t NOMBRE \t PRECIO \t STOCK \t USUARIO\t CANT.VENDIDA\n\n");
    for(i=0; i<sizeProd; i++)
    {
        if((producto+i)->id!=0)
        {
            for(j=0; j<sizeUser; j++)
            {
                if((producto+i)->id_usuario == (usuario+j)->id)
                {
                    strcpy(user,(usuario+j)->nombre);
                    iduenio = j; //guardo la posicion del dueño del producto para luego utilizarlo
                    break;
                }
            }
            if((producto+i)->stock > 0) //solo muestra los productos cuyo stock sea mayor a cero
                printf("%d\t%s\t\t%.2f\t\t  %d\t  %s\t %d\n",(producto+i)->id,(producto+i)->nombre,(producto+i)->precio,(producto+i)->stock,user,(producto+i)->vendido);
        }
    }

    printf("\n");

    printf("Ingrese el id del producto que quiere comprar:\n");
    fflush(stdin);
    scanf("%d",&idp);

    printf("\n");
    for(i=0; i<sizeProd; i++) //compruebo stock
    {
        if((producto+i)->id==idp && (producto+i)->id_usuario==idu)
        {
            printf("Este producto ya es del usuario actual... \n");
            break;
        }
        else if((producto+i)->id==idp && (producto+i)->stock!=0)
        {
            printf("Ingrese la cantidad que desea comprar:\n");
            fflush(stdin);
            scanf("%d",&cant);
            if((producto+i)->stock < cant) //verifica que haya stock para poder comprar
            {
                printf("No hay stock!\n");
                break;
            }
            (producto+i)->stock = (producto+i)->stock - cant;
            (producto+i)->vendido = (producto+i)->vendido + cant;
            printf("Compro %d %s.\n\n",cant,(producto+i)->nombre);
            //system("pause");
            //system("cls");
            printf("\nIngrese calificacion al vendedor(1 a 10):\n");
            fflush(stdin);
            scanf("%d",&calif);
            for(i=0; i<sizeUser; i++)
            {
                if((producto+i)->id_usuario == (usuario+i)->id)
                {
                    if((usuario+iduenio)->calificacion == 0)
                    {
                        (usuario+iduenio)->calificacion = calif;
                        return 0;
                    }
                    else
                    {
                        (usuario+iduenio)->calificacion = ((usuario+iduenio)->calificacion + calif)/2;
                        return 0;
                    }
                }
            }
        }
    }
    return -1;

}

int modificarUsuario(eUsuario* usuario,int sizeUser)
{
    int i;
    int id;
    char resp;
    int flag = 0;

    mostrarUsuarios(usuario, sizeUser);
    //getInt(id,"Ingrese el id del usuario que desea modificar:","Debe ser un numero de id existente",0,5);
    printf("\nIngrese el id del usuario que desea modificar:\n");
    fflush(stdin);
    scanf("%d",&id);

    for(i=0; i<sizeUser; i++)
    {
        if((usuario+i)->id==id && (usuario+i)->flag==1)
        {
            printf("Desea modificar el nombre de usuario? S/N:\n");
            fflush(stdin);
            scanf("%c",&resp);
            resp = toupper(resp);
            while(resp != 'S' && resp != 'N')
            {
                printf("Desea modificar el nombre de usuario? S/N:\n");
                fflush(stdin);
                scanf("%c",&resp);
                resp = toupper(resp);
            }
            if(resp=='S')
            {
                printf("Ingrese nuevo nombre de usuario:\n");
                fflush(stdin);
                scanf("%s",(usuario+i)->nombre);
            }
            getchar();
            printf("Desea modificar la contraseña? S/N:\n");
            fflush(stdin);
            scanf("%c",&resp);
            resp = toupper(resp);
            while(resp != 'S' && resp != 'N')
            {
                printf("Desea modificar la contraseña? S/N:\n");
                fflush(stdin);
                scanf("%c",&resp);
                resp = toupper(resp);
            }
            if(resp=='S')
            {
                printf("Ingrese nueva contraseña:\n");
                fflush(stdin);
                scanf("%s",(usuario+i)->pass);
            }
            flag = 1;
        }
    }

    if(flag == 0)
    {
        return -1;
    }
    printf("\n");
    mostrarUsuarios(usuario, sizeUser);

    return 0;
}

int modificarPublicacion(eUsuario* usuario, eProducto* producto,int sizeUser, int sizeProd)
{
    int i;
    int idp;
    int flag=0;
    char resp;
    int idUsuario;
    int* id;
    id = &idUsuario;
    int ver;

    ver=verificarUsuario(usuario,sizeUser,id);
    if(ver != 0)
        return ver;

    for(i=0; i<sizeProd; i++)
    {
        if((producto+i)->id_usuario == *id)
        {
            if((producto+i)->id != 0)
                printf("ID: %d -- NOMBRE: %s -- PRECIO: %.2f -- STOCK: %d\n",(producto+i)->id,(producto+i)->nombre, (producto+i)->precio, (producto+i)->stock);
        }
    }
    printf("\nIngrese la id del producto que desea modificar:\n");
    fflush(stdin);
    scanf("%d",&idp);
    flag=0;
    for(i=0; i<sizeProd; i++) //verifico que existe id
    {
        if((producto+i)->id == idp && (producto+i)->id_usuario == *id)
        {
            flag = 1;
            break;
        }
    }

    if(flag==0)//no existe el id
        return -3;

    printf("Desea modificar el precio del producto? S/N: ");
    fflush(stdin);
    scanf("%c",&resp);
    resp = toupper(resp);
    while(resp != 'S' && resp != 'N')
    {
        printf("Error. Desea modificar el precio del producto? S/N: ");
        fflush(stdin);
        scanf("%c",&resp);
        resp = toupper(resp);
    }
    if(resp=='S')
    {
        printf("Ingrese nuevo precio:\n");
        fflush(stdin);
        scanf("%f",&(producto+i)->precio);
    }
    getchar();
    printf("Desea modificar el stock? S/N: ");
    fflush(stdin);
    scanf("%c",&resp);
    resp = toupper(resp);
    while(resp != 'S' && resp != 'N')
    {
        printf("Error. Desea modificar el stock? S/N: ");
        fflush(stdin);
        scanf("%c",&resp);
        resp = toupper(resp);
    }
    if(resp=='S')
    {
        printf("Ingrese nuevo stock:\n");
        fflush(stdin);
        scanf("%d",&(producto+i)->stock);
    }
    system("pause");
    return 0;
}


int cancelarPublicacion(eUsuario* usuario, eProducto* producto,int sizeUser, int sizeProd)
{
    int i;
    int idUsuario;
    int* id;
    id = &idUsuario;
    int ver;
    int idp;
    int flag = 0;

    ver = verificarUsuario(usuario,sizeUser,id);
    if(ver != 0)
        return ver;
    printf("\n");
    ver = mostrarPublicacionesUsuario(producto,sizeProd,idUsuario);
    if(ver != 0)
        return ver;

    printf("\nIngrese el id de la publicacion que quiere cancelar:\n");
    fflush(stdin);
    scanf("%d",&idp);

    for(i=0; i<sizeProd; i++) //verifico que existe id
    {
        if((producto+i)->id == idp && (producto+i)->id_usuario == idUsuario)
        {
            flag = 1;
            break;
        }
    }
    if(flag==0)//no existe el id
        return -4;

    (producto+i)->id = 0;

    printf("\nPublicacion cancelada!\n");
    system("pause");
    return 0;
}


int verificarUsuario(eUsuario* usuario,int sizeUser,int* idu)
{
    int i;
    int flag=0;
    char pass[15];

    mostrarUsuarios(usuario,sizeUser);
    printf("\nIngrese el id del usuario que quiere realizar una accion:\n");
    fflush(stdin);
    scanf("%d",idu);
    if(*idu == 0)
    {
        printf("\nError. Ingrese el id del usuario que quiere realizar una accion:\n");
        fflush(stdin);
        scanf("%d",idu);
    }
    for(i=0; i<sizeUser; i++) //verifico que existe id
    {
        if((usuario+i)->id == *idu)
        {
            flag = 1;
            break;
        }
    }
    if(flag==0)// si no existe usuario
    {
        return -1;
    }

    flag=0;
    getString(pass,"Ingrese contraseña de usuario:","Tiene que tener por lo menos 3 caracteres",2,10);
    for(i=0; i<sizeUser; i++) //verifico contraseña
    {
        if((usuario+i)->flag!=0)
        {
            if((usuario+i)->id==*idu && strcmp((usuario+i)->pass,pass)==0)
                flag=1;
        }
    }
    if(flag==0)//contraseña incorrecta
    {
        return -2;
    }
    return 0;
}

int mostrarPublicacionesUsuario(eProducto* producto,int sizeProd,int id)
{
    int i;
    int flag = 0;

    for(i=0; i<sizeProd; i++) //verifico que el usuario exista
    {
        if((producto+i)->id_usuario == id && (producto+i)->id!=0)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        return -1;
    }

    printf("  ID\tNOMBRE\t\tPRECIO\tSTOCK\tVENDIDO\n");
    for(i=0; i<sizeProd; i++)
    {
        if((producto+i)->id_usuario == id && (producto+i)->id!=0)
        {
            printf("# %d\t%s\t\t%.2f\t%d\t%d\n",(producto+i)->id,(producto+i)->nombre,(producto+i)->precio,(producto+i)->stock,(producto+i)->vendido);
        }
    }
    return 0;
}
