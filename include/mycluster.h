#ifndef MYCLUSTER_H
#define MYCLUSTER_H
#include "/wk_cms2/zhenggangchen/env/workspace/CMSSW_10_2_26/src/include/myphyobject.h"
class mycluster : public myphyobject {
    public:
        void setmask_HAD(double mask){
            mask_had = mask;
        }
        void setmask_EM(double mask){
            mask_em = mask;
        }
        void setmask_Trk(double mask){
            mask_trk= mask;
        }
        void setLayer(int Layer)
        {
            layer = Layer;
        }
        void setsensor_type(int type)
        {
            Sensor_type = type;
        }

        double mask_EM();
        double mask_Trk();
        double mask_HAD();
        int Layer(){
            return layer;
        }
        double sensor_type()
        {
            return Sensor_type;
        }
    private:
        double mask_em;
        double mask_trk;
        double mask_had;
        int Sensor_type;
        double layer;
};

#endif
