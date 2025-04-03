

#ifndef DTFECHA_H
#define DTFECHA_H

class DtFecha {

private:
    int dia;
    int mes;
    int ano;


public:
    DtFecha(int d, int m, int a);
    ~DtFecha();

    int getDia() ;
    int getMes() ;
    int getAno() ;

/*Solo le agregaría la de comparar:

bool operator<(DtFecha& otra)

Nico Palleiro*/

//    void setDia(int d);
//    void setMes(int m);
//    void setAno(int a);

};

#endif /* DTFECHA_H */

