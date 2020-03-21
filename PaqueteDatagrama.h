//
// Created by Javier Fuentes Mora on 21/03/20.
//


class PaqueteDatagrama {
public:

/*
    PaqueteDatagrama(unsigned int);
*/

    PaqueteDatagrama(unsigned int _longitud);

    PaqueteDatagrama(char *_datos, unsigned int _longitud, char *_ip, int _puerto);

    ~PaqueteDatagrama();

    char *obtieneDireccion();

    unsigned int obtieneLongitud();

    int obtienePuerto();

    char *obtieneDatos();

    void inicializaPuerto(int);

    void inicializaIp(char *);

    void inicializaDatos(char *);

private:
    char *datos;
    char ip[16]{};
    unsigned int longitud;
    int puerto;
};
