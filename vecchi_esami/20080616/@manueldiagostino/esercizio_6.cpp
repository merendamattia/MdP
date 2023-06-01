/*
 *  Si presume che:
 *  1) release_mutex_for() non lanci eccezioni
 *  2) transmit() non possa causare l'arresto anomalo del programma in questione
 * */

// Soluzione RAII

#include "Mutex.hh"
#include <algorithm>

class MutexHandler {
private:
    Sched* schedule;
public:
    MutexHandler(const Sched& s) : schedule(&s) {
        get_mutex_for(*schedule);
    }

    MutexHandler(const MutexHandler& other) = delete; // disabilito copia
    MutexHandler(MutexHandler&& other) : schedule(other.schedule) {
        other.schedule = nullptr;
    }

    MutexHandler& operator=(const MutexHandler& other) = delete; // disabilito assegnamento per copia
    MutexHandler& operator=(MutexHandler&& other) {
        schedule = other.schedule;
        other.schedule = nullptr;
    }

    virtual ~MutexHandler() { 
        if (schedule != nullptr)
            release_mutex_for(*schedule); 
    } // non elimino il dato schedule
    
    void force_release() { release_mutex_for(*schedule); schedule = nullptr; }
    void force_reset(const Sched& s) {
        if (schedule != nullptr)
            force_release();
        schedule = &s;
        get_mutex_for(*schedule);
    }
};

void foo(Sched& v, Sched& w, unsigned n) {
    MutexHandler mh_1(v);
    MutexHandler mh_2(w);

    transmit(v,w,n);
}
