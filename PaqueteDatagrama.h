//
// Created by Javier Fuentes Mora on 21/03/20.
//


class PaqueteDatagrama {
public:
    PaqueteDatagrama(char *, unsigned int, char *, int);

    explicit PaqueteDatagrama(unsigned int);

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
    char ip[16];
    unsigned int longitud;
    int puerto;
};
