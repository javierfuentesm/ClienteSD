//
// Created by Javier Fuentes Mora on 21/03/20.
//

#include "SocketDatagrama.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>


using namespace std;

SocketDatagrama::SocketDatagrama(int _puerto) {
    s = socket(AF_INET, SOCK_DGRAM, 0);

    bzero((char *) &direccionForanea, sizeof(direccionForanea));
    bzero((char *) &direccionLocal, sizeof(direccionLocal));

    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;

    if (_puerto == 0)
        direccionLocal.sin_port = htons (_puerto);
    else
        direccionLocal.sin_port = _puerto;
}

SocketDatagrama::~SocketDatagrama() {
    close(s);//cerrar socket
}

//Recibe un paquete tipo datagrama proveniente de este socket int recibe(PaqueteDatagrama & p);
//Envía un paquete tipo datagrama desde este socket
int SocketDatagrama::recibe(PaqueteDatagrama &p) {


    return recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0,
                    (struct sockaddr *) &direccionForanea, reinterpret_cast<socklen_t *>(sizeof(direccionForanea)));
}

int SocketDatagrama::envia(PaqueteDatagrama &p) {
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(reinterpret_cast<const char *>(p.obtienePuerto()));
    direccionForanea.sin_port = htons(p.obtienePuerto());
    return sendto(s, (char *) p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0,
                  (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));

}
