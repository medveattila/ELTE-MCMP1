#include<cmath>
#include<iostream>

template<typename T>

struct Vector2d {

    T x, y;

    //Definiálunk osztályon belüli műveleteket
    
    Vector2d<T>& operator+=(Vector2d<T> const& u) {
    
        x += u.x;
        y += u.y;
        
        return *this;
        
    }

    Vector2d<T>& operator-=(Vector2d<T> const& u) {
    
        x -= u.x;
        y -= u.y;
        
        return *this;
        
    }

    Vector2d<T>& operator*=(T const& u) {
    
        x *= u;
        y *= u;
        
        return *this;
        
    }

    Vector2d<T>& operator/=(T const& u) {
    
        x /= u;
        y /= u;
        
        return *this;
        
    }
    
};

//Definiálunk osztályon kívüli műveleteket

template<typename T>

    Vector2d<T> operator+(Vector2d<T> const& u, Vector2d<T> const& v) {

    return Vector2d<T>{u.x+v.x, u.y+v.y};
    
    }


template<typename T>
    
    Vector2d<T> operator-(Vector2d<T> const& u, Vector2d<T> const& v) {

    return Vector2d<T>{u.x-v.x, u.y-v.y};
        
    }

template<typename T>
    
    Vector2d<T> operator*(Vector2d<T> const& u, T c) { //A skalárral való szorzást mindkét
                                            //oldalról bevezetjük
    return Vector2d<T>{c*u.x, c*u.y};
        
    }

template<typename T>
    
    Vector2d<T> operator*(T c, Vector2d<T> const& v) {
        
    return Vector2d<T>{c*v.x, c*v.y};
        
    }

template<typename T>
    
    Vector2d<T> operator/(Vector2d<T> u, T c) {

    return Vector2d<T>{u.x/c, u.y/c};
        
    }

template<typename T>
    
    T dot(Vector2d<T> const& u, Vector2d<T> const& v) { //Skaláris szorzás

    return u.x*v.x+u.y*v.y;
        
    }

template<typename T>
        
    T length(Vector2d<T> const& u) {
        
    T l;
    l = std::sqrt(dot(u,u));
        
    return l;
            
    }
    
template<typename T>
    
    T sqlength(Vector2d<T> const& u) {

    T sl;
    sl = dot(u,u);
        
    return sl;
        
    }

template<typename T>
    
    Vector2d<T> normalize(Vector2d<T> const& u) {

    return u/length(u);
        
    }

template<typename T>
    
    std::ostream& operator<<(std::ostream& o, Vector2d<T> const& u) {
    
    o << u.x << " " << u.y;
        
    return o;
        
    }

template<typename T>
    
    std::istream& operator>>(std::istream& i, Vector2d<T>& u) {

    i >> u.x;
    i >> u.y;

    return i;

    }
