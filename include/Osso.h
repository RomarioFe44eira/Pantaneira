#ifndef OSSO_H
#define OSSO_H

class Osso{
    public:
        Osso(float a, float l): largura(l), altura(a), conexcao(0) {}
        void desenha();

        void setConexcao(Osso *osso, float ang) {conexcao = osso, angulo = ang;}

        void setAngulo(float ang){angulo = ang;}
        float getAngulo(){return angulo;}

    protected:
        float largura;
        float altura;

        float angulo;
        Osso *conexcao;
};

#endif // OSSO_H
