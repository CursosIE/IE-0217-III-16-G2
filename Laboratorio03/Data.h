#ifndef DATA_H
#define DATA_H

template <typename D>
class Data {
public:
   D data;

    Data() {
    }

    Data(D d) {
     data = d;
    }
    
    virtual ~Data() {
    }
};

#endif /* DATA_H */
