//
// Created by Javier Fuentes Mora on 21/03/20.
//


#include <netinet/in.h>
#include "PaqueteDatagrama.h"

class SocketDatagrama {
public:
    SocketDatagrama(int);

    ~SocketDatagrama();

//Recibe un paquete tipo datagrama proveniente de este socket
    int recibe(PaqueteDatagrama &p);

//Envía un paquete tipo datagrama desde este socket
    int envia(PaqueteDatagrama &p);

private:
    struct sockaddr_in direccionLocal{};
    struct sockaddr_in direccionForanea{};
    int s; //ID socket
};
