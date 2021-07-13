#ifndef MY_PARTICLE_H
#define MY_PARTICLE_H
//#include "myLibConstants.h"
#include "myphyobject.h"
/*
const int pion = particleId::pion;
const int pion_plus = particleId::charged_pion;
const int photon = particleId::photon;
const int electron = particleId::electron;
const int kaon_S = particleId::kaon_S;
const int kaon_L = particleId::kaon_L;
const int gluon = particleId::gluon ;
const int d = particleId::d ;
const int u = particleId::u ;
const int s = particleId::s;
*/
class myparticle : public myphyobject{
    public:
        double Pt;
        double Px,Py,Pz;
        double Charge;
        double P;
        
        virtual void setpt(double p){
            Pt = p;}
        virtual void setp(double x ,double y ,double z){
            Px = x;
            Py = y;
            Pz = z;
            P = TMath::Sqrt(x*x + y*y + z*z);
        }
        virtual void setcharge(int c){
            Charge = c;}
        
        virtual double pt(){
            return Pt;}
        virtual double p(){
            return P;}
        virtual double px(){
            return Px;}
        virtual double py(){
            return Py;}
        virtual double pz(){
            return Pz;}
        virtual double charge(){
            return Charge;}
};

#endif //QG_SEPARATION_MY_GENPARTICLE_H
