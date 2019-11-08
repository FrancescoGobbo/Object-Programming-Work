#ifndef Deepptr_H
#define Deepptr_H

#include<typeinfo>

#include <iostream>

template<class T>
class Deepptr{
private:
    T* p;
public:
    //Costruttore
    Deepptr(T* =nullptr);
    //Costruzione di copia, graie alla clonazione polimorfa in T
    Deepptr(const Deepptr&);
    //Distruttore polimorfa , grazie alla distruzione virtuale presente in T
    ~Deepptr();

    Deepptr &operator=(const Deepptr&);

    bool operator ==(const Deepptr<T>&) const;
    bool operator !=(const Deepptr<T>&) const;

    T& operator*() const;
    T* operator->() const;
};
template<class T>
Deepptr<T>::Deepptr(T* d):p(d!=nullptr ? d->clone():nullptr){}

template<class T>
Deepptr<T>::Deepptr(const Deepptr& d): p(d.p!=nullptr ? d.p->clone(): nullptr){}

template<class T>
Deepptr<T>::~Deepptr(){
    if(p)
        delete p;
}

template<class T>
class Deepptr<T>::Deepptr& Deepptr<T>::operator=(const Deepptr& d){
    if(this != &d)
    {
        if(p) delete p;
        p = (d.p!=nullptr ? (d.p)->clone(): nullptr);
    }
    return *this;
}

template<class T>
bool Deepptr<T>::operator==(const Deepptr<T>& d) const
{
    bool rit=0;
    if( *p == *d ){
        rit=1;
    }

    return rit;
}

template<class T>
bool Deepptr<T>::operator!=(const Deepptr<T>& d) const
{
    return !(*p == d) && typeid(*p) != typeid (d);
}

template<class T>
T& Deepptr<T>::operator*() const
{
    return *p;
}

template<class T>
T* Deepptr<T>::operator->() const{
    return p;
}

#endif // Deepptr_H
