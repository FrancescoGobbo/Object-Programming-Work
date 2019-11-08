#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
template <class T>
class Container{
private:
    unsigned int used;//dimUsata
    unsigned int size;//dimtot
    T* ptr;

    void  raddoppio();
public:
    /**
     * @brief Class Iteratore
     */
    class Iter{
        friend class Container<T>;
    private:
        T* ite;
        Iter(T*);
    public:
        bool operator == (const Iter&) const;
        bool operator != (const Iter&) const;

        T& operator * ();
        T* operator ->();

        Iter& operator ++();
        Iter operator ++(int);

        Iter &operator --();
        Iter operator --(int);
        Iter &operator +(unsigned int);
        Iter &operator -(unsigned int);
        Iter &operator +=(unsigned int);
        Iter &operator -=(unsigned int);
    };

    /**
        * @brief Classe Iteratore costante
    */
    class ConstIter{
        friend class Container<T>;
    private:
        const T* cite;
        ConstIter(T*);
    public:
        bool operator==(const ConstIter&) const;
        bool operator!= (const ConstIter&) const;
        const T& operator* ()const;
        const T* operator->()const;
        ConstIter& operator++();
        ConstIter operator++(int);
        ConstIter& operator --();
        ConstIter operator --(int);
        ConstIter &operator +(unsigned int);
        ConstIter &operator -(unsigned int);
        ConstIter &operator +=(unsigned int);
        ConstIter &operator -=(unsigned int);
    };


    Container(unsigned int =2);                    //Costruttore ad 1 parametro
    Container(const T&,unsigned int =2);           //Costruttore ad 2 parametri
    Container(const Container<T>&);                //Copia profonda
    ~Container();                                  //Distruzione profonda

    Container<T>& operator=(const Container<T>&);  //Assegnazione profonda

    T& operator[](unsigned int);                  //operator di dereferenziazione
    T& at(unsigned int);

    bool operator==(const Container<T>&) const;
    unsigned int capacity() const;                //Dimensione Container
    unsigned int containerUsed() const;           //Dimensione Container Usata
    bool empty() const;
    void clear();                                 //pulisce il vector

    void push_back(const T &);                    //inserimento elemento
    void pop(unsigned int);                       //eliminazione elemento
    void pop(T);                                  //elimina l'elemento T

    Iter begin()const;
    Iter end()const;
    ConstIter cbegin() const;
    ConstIter cend() const;
};

template <typename T>
Container<T>::Container(unsigned int s):used(0), size(s),ptr( new T[s]){}

template  <typename T>
Container<T>::Container(const T& t,unsigned int s):used(0), size(s), ptr(new T[s]){
    for(int i=0; i<size; i++)
        ptr[i]=t;
}

//Definizione costruttore di copia
template<typename T>
Container<T>::Container(const Container<T>& a):used(a.used),size(a.size),ptr(new T[a.used]){
    for(unsigned int i=0; i<used; i++)
        ptr[i]=a.ptr[i];
}

//Definizione Distruttore
template<typename T>
Container<T>::~Container<T>(){
    if(ptr) delete[] ptr;
}

//Definizione operatore di assegnazione
template <typename T>
Container<T>& Container<T>::operator=(const Container<T>& t){
    if(this!= &t){
        delete[] ptr;

        size=t.size;
        used=t.used;
        ptr= new T[size];

        for(unsigned int i=0; i<used; i++)
            ptr[i]=t.ptr[i];
    }

    return *this;
}

//Dimensione ToT
template<class T>
unsigned int Container<T>::capacity() const {
    return size;
}

//Dimensione Occupata
template<class T>
unsigned int Container<T>::containerUsed() const {
    return used;
}

//Vuoto?
template<class T>
bool Container<T>::empty() const{
    return !used;
}

//Assegnazione profonda

//Raddoppia la capità del container
template  <typename T>
void Container<T>::raddoppio(){

    unsigned int newCapacity= size*2;
    T* newptr= new T[newCapacity];

    for(unsigned int i=0; i<used; i++){
        newptr[i]= ptr[i];
    }

    size= newCapacity;
    delete [] ptr;
    ptr=newptr;
}

//Inserimento in coda
template<typename T>
void Container<T>::push_back(const T& t){
    if (!(used<size))
        raddoppio();
    ptr[used++]=t;
}

//Eliminazione elemento indice index
template <typename T>
void Container<T>::pop(unsigned int index){
    if(index>used-1) throw std::out_of_range("Attenzione, indice errato");
    for(unsigned int i=index; i<used-1; i++ ){
        ptr[i]= ptr[i+1];
    }
    used--;
}

//Eliminazione elemento k
template<class T>
void Container<T>::pop(T k){
    unsigned int i=0;
    while(i!=used){
        if(ptr[i]==k){
            pop(i);

        }
        else{
            i++;
        }
    }
}



//Pulisce container
template<class T>
void Container<T>::clear(){
    delete [] ptr;
    ptr= new T[0];
    used=0;
    size=0;
}

//Overloading operator[]
template<class T>
T& Container<T>::operator[](unsigned int index) {
    return ptr[index];
}

template <typename T>
T& Container<T>::at(unsigned int index){
    if(index<0 || index > used-1){
        throw std::out_of_range("The index is out of bound");
    }
    return ptr[index];
}


//Begin e End
template <typename T>
typename Container<T>::Iter Container<T>::begin()const{
    return Iter(ptr);
}

template <typename T>
typename Container<T>::Iter Container<T>::end()const{
    return Iter(ptr+(used));
}
template <typename T>
typename Container<T>::ConstIter Container<T>::cbegin()const{
    return ConstIter(ptr);
}
template <typename T>
typename Container<T>::ConstIter Container<T>::cend()const{
    return ConstIter(ptr+(used));
}

/**
 * ITERATORE
 */
template<class T>
Container<T>::Iter::Iter(T* t):ite(t){
}
template< typename T>
bool Container<T>::Iter::operator!=(const Iter& it) const {
    return ite!=it.ite;
}
template <typename T>
bool Container<T>::Iter::operator==(const Iter& it)const{
    return ite==it.ite;
}


template< typename T>
typename Container<T>::Iter& Container<T>::Iter::operator++() {
    if(ite) ite++;
    return *this;
}
template< typename T>
typename Container<T>::Iter Container<T>::Iter::operator++(int) {
    Iter aux=*this;
    if(ite) ite++;
    return aux;
}
template  <typename T>
T& Container<T>::Iter::operator*(){
    return *ite;
}

template  <typename T>
T* Container<T>::Iter::operator->(){
    return ite;
}

template <typename T>
typename Container<T>::Iter& Container<T>::Iter::operator --(){
    if(ite) ite--;
    return *this;
}

template <typename T>
typename Container<T>::Iter Container<T>::Iter::operator --(int){
    Iter aux(ite);
    if(ite) ite--;
    return aux;
}

template <typename T>
typename Container<T>::Iter& Container<T>::Iter::operator +(unsigned int i){
    if(ite) ite+=i;
    return *this;
}

template <typename T>
typename Container<T>::Iter& Container<T>::Iter::operator -(unsigned int i){
    if(ite) ite-=i;
    return *this;
}
template <typename T>
typename Container<T>::Iter& Container<T>::Iter::operator -=(unsigned int i){
    if(ite) ite-=i;
    return *this;
}

template <typename T>
typename Container<T>::Iter& Container<T>::Iter::operator +=(unsigned int i){
    if(ite) ite+=i;
    return *this;
}

/**
 * CONST_ITERATORE
 */

template<class T>
Container<T>::ConstIter::ConstIter(T * t):cite(t){
}
template< typename T>
bool Container<T>::ConstIter::operator!=(const ConstIter& it) const {
    return cite!=it.cite;
}
template <typename T>
bool Container<T>::ConstIter::operator==(const ConstIter& it)const{
    return cite==it.cite;
}

template< typename T>
typename Container<T>::ConstIter& Container<T>::ConstIter::operator++() {
    if(cite) cite++;
    return *this;
}
template< typename T>
typename Container<T>::ConstIter Container<T>::ConstIter::operator++(int) {
    ConstIter aux=*this;
    if(cite) cite++;
    return aux;
}
template  <typename T>
const T& Container<T>::ConstIter::operator*()const{
    return *cite;
}

template  <typename T>
const T* Container<T>::ConstIter::operator->()const{
    return cite;
}
template <typename T>

typename Container<T>::ConstIter& Container<T>::ConstIter::operator --(){
    if(cite) cite--;
    return *this;
}

template <typename T>
typename Container<T>::ConstIter Container<T>::ConstIter::operator --(int){
    ConstIter aux(cite);
    if(cite) cite--;
    return aux;
}

template <typename T>
typename Container<T>::ConstIter& Container<T>::ConstIter::operator +(unsigned int i){
    if(cite) cite+=i;
    return *this;
}

template <typename T>
typename Container<T>::ConstIter& Container<T>::ConstIter::operator -(unsigned int i){
    if(cite) cite-=i;
    return *this;
}
template <typename T>
typename Container<T>::ConstIter& Container<T>::ConstIter::operator -=(unsigned int i){
    if(cite) cite-=i;
    return *this;
}

template <typename T>
typename Container<T>::ConstIter& Container<T>::ConstIter::operator +=(unsigned int i){
    if(cite) cite+=i;
    return *this;
}

#endif // CONTAINER_H
