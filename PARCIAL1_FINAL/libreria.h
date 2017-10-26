typedef struct{
    int id;
    char nombre[20];
    char pass[15];
    int flag;
    int calificacion;
} eUsuario;

typedef struct{
    int id;
    char nombre[20];
    float precio;
    int stock;
    int id_usuario;
    int vendido;
} eProducto;

/** \brief Crea un usuario nuevo
 * \param Estructura de datos de usuario
 * \param Tamaño de la estructura de datos pasada por parametro
 * \return Retorna 0 si se pudo realizar la carga con exito sino retorna -1
 */
int altaUsuario(eUsuario*, int);


/** \brief Muestra los usuarios con su id, nombre, contraseña
 * \param Estructura de datos de usuario
 * \param Tamaño de la estructura de datos pasada por parametro
 */
void mostrarUsuarios(eUsuario*, int);


/** \brief Crea un nuevo producto
 * \param Estructura de datos de usuarios
 * \param Estructura de datos de producto
 * \param Tamaño de la estructura de datos usuarios pasada por parametro
 * \param Tamaño de la estructura de datos productos pasada por parametro
 * \return Retorna 0 si se pudo realizar la carga con exito sino retorna -1
 */
int publicarProducto(eUsuario*,eProducto*, int, int);


/** \brief Muestra los productos con su id, nombre, precio, stock, usuario
 * \param Estructura de datos de producto
 * \param Estructura de datos de usuarios
 * \param Tamaño de la estructura de datos productos pasada por parametro
 * \param Tamaño de la estructura de datos usuarios pasada por parametro
 */
void mostrarProductos(eProducto*, eUsuario*, int, int);


/** \brief Precarga usuarios y productos
 * \param Estructura de datos de producto
 * \param Estructura de datos de usuario
 */
void cargaUsuarioProductos(eProducto*, eUsuario*);


/** \brief Da de baja a un usuario
 * \param Estructura de datos de usuarios
 * \param Estructura de datos de producto
 * \param Tamaño de la estructura de datos usuarios pasada por parametro
 * \param Tamaño de la estructura de datos productos pasada por parametro
 * \return Retorna 0 si se pudo realizar la carga con exito sino retorna -1
 */
int bajaUsuario(eUsuario*,eProducto*,int , int);


/** \brief Comprar productos
 * \param Estructura de datos de producto
 * \param Estructura de datos de usuarios
 * \param Tamaño de la estructura de datos productos pasada por parametro
 * \param Tamaño de la estructura de datos usuarios pasada por parametro
 * \return Retorna 0 si se pudo realizar la carga con exito sino retorna -1
 */
int compraProducto(eProducto*, eUsuario*, int, int);

/** \brief Modifica un usuario
 * \param Estructura de datos de usuario
 * \param Tamaño de la estructura pasada por parametro
 * \return Retorna 0 si todo salio bien sino -1
 */
int modificarUsuario(eUsuario*,int);


/** \brief Modifica una publicacion
 * \param Estructura de datos de usuario
 * \param Estructura de datos de producto
 * \param Tamaño de la primera estructura pasada por parametro
 * \param Tamaño de la segunda estructura pasada por parametro
 * \return Retorna -1 si no existe el usuario, -2 si es incorrecta la contraseña y -3 si no existe el id del producto
 */
int modificarPublicacion(eUsuario*, eProducto*,int, int);


/** \brief Elimina un producto en venta
 * \param Estructura de datos de usuario
 * \param Estructura de datos de producto
 * \param Tamaño de la primera estructura pasada por parametro
 * \param Tamaño de la segunda estructura pasada por parametro
 * \return Retorna 0 si se puedo eliminar correctamente si no retorna -1 si no existe el usuario y -2 si la contraseña es incorrecta y -3 si no existe la id de la publicacion
 */
int cancelarPublicacion(eUsuario*, eProducto*,int, int);


/** \brief Pide usuario y verifica que existe, pide la contraseña de ese usuario y verifica que sea correcta
 * \param Estructura de datos de usuario
 * \param Tamaño de la estructura pasada por parametro
 * \param Variable donde se va a guardar el id ingresado y verificado
 * \return Retorna 0 si se puedo verificar correctamente si no retorna -1 si no existe el usuario y -2 si la contraseña es incorrecta
 */
int verificarUsuario(eUsuario*,int,int*);


/** \brief Muestra los productos publicados de un usuario pasado por parametro
 * \param Estructura de datos de producto
 * \param Tamaño de la estructura pasada por parametro
 * \param Id del usuario que publico los productos
 * \return Devuelve -1 si no encuentra el usuario
 */
int mostrarPublicacionesUsuario(eProducto*,int,int);

