#ifndef MYPHYOBJECT_H
#define MYPHYOBJECT_H

class myphyobject{
    public:
        double Eta;
        double Phi;
        double Energy;
        int ID;
        myphyobject() = default;
        myphyobject(double x, double y ,double z):Eta(x),Phi(y),Energy(z){}; 
        ~myphyobject(){};
        virtual inline void setId(int I){
            ID = I;
        }
        virtual inline void seteta(double e){
            Eta = e;
        }
        virtual inline void setphi(double p){
            Phi = p;}
        virtual inline void setenergy(double e){
            Energy = e;
        }
        virtual inline double E(){
            return Energy;
        }
        virtual inline double phi(){
            return Phi;
        }
        virtual inline double eta(){
            return Eta;
        }
        virtual inline int Id(){
            return ID;
        }

};

#endif
