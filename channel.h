#include <systemc>
using namespace std;

class DoorEventIf: public sc_interface{
public:
    virtual bool nb_read(int& dest) = 0;
    virtual void nb_write(int msg) = 0;
};

class DoorChannel: public DoorEventIf, public sc_prim_channel {
private:
    sc_fifo<int> queue;

public:
    explicit DoorChannel(sc_module_name name) : sc_prim_channel(name), queue(10) {}

    bool nb_read(int& dest) override {
        return queue.nb_read(dest);
    }

    void nb_write(int msg) override {
        queue.nb_write(msg);
    }
};
