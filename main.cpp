#include <sys/types.h>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include "SocketDatagrama.h"

using namespace std;

int main() {
    char num[2];
    SocketDatagrama cliente = SocketDatagrama(7200);
    PaqueteDatagrama paquete = PaqueteDatagrama(num, 2, "127.0.0.1", 7200);
    PaqueteDatagrama paqueteRecibido = PaqueteDatagrama(2);

    num[0] = 2;
    num[1] = 5; /*rellena el mensaje */

    cliente.envia(paquete);
    cliente.recibe(paqueteRecibido);
    /* se bloquea esperando respuesta */

    printf("2 + 5 = %s\n", paqueteRecibido.obtieneDatos());
}

