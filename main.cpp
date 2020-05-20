#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;


class DateGresite : public std::exception {
public:
  DateGresite () noexcept {}
  DateGresite (const DateGresite&) noexcept = default;
  DateGresite& operator= (const DateGresite&) noexcept = default;
  virtual ~DateGresite() noexcept = default;
  virtual const char* what() const noexcept {
    return "Nu pot fi 0 (sau numar negativ) masini expuse.";
  }
};


int n;

 class masina {
  protected:
    string nume;
    string culoare;
    int capacitate_cilindrica; /// cm cubi
    int cai_putere;
public:
    masina(){};
    masina(const masina &aux)
    {
        this -> nume = aux.nume;
        this -> culoare = aux.culoare;
        this -> capacitate_cilindrica = aux.capacitate_cilindrica;
        this -> cai_putere = aux.cai_putere;
    }
    virtual ~masina(){};
     friend istream &operator>>(istream &f,masina& aux);
     friend ostream &operator<<(ostream &f, masina& aux);
     virtual void afisare(){ cout <<"\nNume "<< this->nume;
                             cout<<"\nCuloare "<<this->culoare;
                             cout<<"\nCapacitate cilindrica "<<this ->capacitate_cilindrica;
                             cout<<"\n Cai putere "<<this->cai_putere;
                             }
    };


istream &operator>>(istream &f,masina& aux){
    cout<<"\nIntroduceti nume: ";
f>>aux.nume;
    cout<<"\n Introduceti culoarea: ";
f>>aux.culoare;
    cout<<"\nIntroduceti capacitatea cilindrica: ";
f>>aux.capacitate_cilindrica;
    cout<<"\nIntroduceti caii putere: ";
f>>aux.cai_putere;
return f;
}

ostream &operator<<(ostream &f, masina& aux){
cout<<"\n Nume: ";
f<<aux.nume;
cout<<"\n Culoare: ";
f<<aux.culoare;
cout<<"\n Capacitate cilindrica: ";
f<<aux.capacitate_cilindrica;
cout<<"\n Cai putere: ";
f<<aux.cai_putere;
return f;
}

class coupe: public masina {
    int numar_portiere;
public:
    coupe(){};
    ~coupe(){};
    friend istream &operator>>(istream &f,coupe& aux);
    friend ostream &operator<<(ostream &f, coupe& aux);
     coupe operator=(const coupe& aux)
      {
      this->nume = aux.nume;
      this->culoare = aux.culoare;
      this->capacitate_cilindrica = aux.capacitate_cilindrica;
      this->cai_putere = aux.cai_putere;
      this->numar_portiere = aux.numar_portiere;
      return *this;
      }
      void afisare(){ cout <<"\nNume "<< this->nume;
                             cout<<"\nCuloare "<<this->culoare;
                             cout<<"\nCapacitate cilindrica "<<this ->capacitate_cilindrica;
                             cout<<"\n Cai putere "<<this->cai_putere;
                             cout<<"\n Numar portiere" <<this->numar_portiere;
                             }

};

class hot_hatch : public masina {
    string spoiler;
public:
    friend istream &operator>>(istream &f,hot_hatch& aux);
    friend ostream &operator<<(ostream &f, hot_hatch& aux);
    hot_hatch(){};
    ~hot_hatch(){};
     hot_hatch operator=(const hot_hatch& aux)
      {
      this->nume = aux.nume;
      this->culoare = aux.culoare;
      this->capacitate_cilindrica = aux.capacitate_cilindrica;
      this->cai_putere = aux.cai_putere;
      this->spoiler = aux.spoiler;
      return *this;
      }
      void afisare(){ cout <<"\nNume "<< this->nume;
                             cout<<"\nCuloare "<<this->culoare;
                             cout<<"\nCapacitate cilindrica "<<this ->capacitate_cilindrica;
                             cout<<"\n Cai putere "<<this->cai_putere;
                             cout<<"\nSpoiler "<<this->spoiler;
                             }
};

class cabrio: public masina {
    string material_acoperis; /// e.g textil , metal.
public:
    friend istream &operator>>(istream &f,cabrio& aux);
     friend ostream &operator<<(ostream &f, cabrio& aux);
    cabrio(){};
    ~cabrio(){};
     cabrio operator=(const cabrio& aux)
      {
      this->nume = aux.nume;
      this->culoare = aux.culoare;
      this->capacitate_cilindrica = aux.capacitate_cilindrica;
      this->cai_putere = aux.cai_putere;
      this->material_acoperis = aux.material_acoperis;
      return *this;
      }
      void afisare(){ cout <<"\nNume "<< this->nume;
                             cout<<"\nCuloare "<<this->culoare;
                             cout<<"\nCapacitate cilindrica "<<this ->capacitate_cilindrica;
                             cout<<"\n Cai putere "<<this->cai_putere;
                             cout<<"\n Material acoperis "<<this->material_acoperis;
                             }
};

class supersport: public masina {
    string fibra_carbon;
public:
    friend istream &operator>>(istream &f,supersport& aux);
    friend ostream &operator<<(ostream &f, supersport& aux);
    supersport(){};
    ~supersport(){};
     supersport operator=(const supersport& aux)
      {
      this->nume = aux.nume;
      this->culoare = aux.culoare;
      this->capacitate_cilindrica = aux.capacitate_cilindrica;
      this->cai_putere = aux.cai_putere;
      this->fibra_carbon = aux.fibra_carbon;
      return *this;
      }
      void afisare(){ cout <<"\nNume "<< this->nume;
                             cout<<"\nCuloare "<<this->culoare;
                             cout<<"\nCapacitate cilindrica "<<this ->capacitate_cilindrica;
                             cout<<"\n Cai putere "<<this->cai_putere;
                             cout<<"\nFibra carbon "<<this->fibra_carbon;
                             }
};

ostream &operator<<(ostream &f, coupe& aux){
    f << static_cast<masina&>(aux);
    cout<<"\nNumarul de portiere: ";
    f<<aux.numar_portiere;
    return f;
};
istream &operator>>(istream &f,coupe& aux){
   f>> static_cast<masina&>(aux);
   cout<<"\nIntroduceti numarul de portiere: ";
   f>> aux.numar_portiere;
   return f;
}
ostream &operator<<(ostream &f, hot_hatch& aux){
    f << static_cast<masina&>(aux);
    cout<<"\nSpoiler: ";
    f<<aux.spoiler;
    return f;
};
istream &operator>>(istream &f,hot_hatch& aux){
   f>> static_cast<masina&>(aux);
   cout<<"\nIntroduceti spoiler: ";
   f>> aux.spoiler;
   return f;
}
ostream &operator<<(ostream &f, cabrio& aux){
    f << static_cast<masina&>(aux);
    cout<<"\nMaterial acoperis: ";
    f<<aux.material_acoperis;
    return f;
};
istream &operator>>(istream &f,cabrio& aux){
   f>> static_cast<masina&>(aux);
   cout<<"\nIntroduceti materialul acoperisului: ";
   f>> aux.material_acoperis;
   return f;
}
ostream &operator<<(ostream &f, supersport& aux){
    f << static_cast<masina&>(aux);
    cout<<"\nFibra carbon: ";
    f<<aux.fibra_carbon;
    return f;
};
istream &operator>>(istream &f,supersport& aux){
   f>> static_cast<masina&>(aux);
   cout<<"\nIntroduceti fibra de carbon: ";
   f>> aux.fibra_carbon;
   return f;
}
template < typename T >
class Expozitie
{
    int numar_masini_expuse;
    T *masini = new T[n];
public:
     Expozitie(){this->numar_masini_expuse = 0;};
    ~Expozitie(){ delete[]masini;};
     void set_masini(T*p)
     {
        numar_masini_expuse++;
        masini[numar_masini_expuse] = *p;
     }
};

template <>
class Expozitie <supersport>
{
    int nr_masini_supersport_expuse;
    int nr_masini_vandute;
    supersport *masini_vandute = new supersport[nr_masini_vandute];
    supersport *stoc = new supersport[nr_masini_supersport_expuse];
public:
    Expozitie (){};
    ~Expozitie ( ){ delete[]masini_vandute; delete[]stoc;}
    Expozitie operator -= (int i){
        Expozitie s;
        this->masini_vandute[++nr_masini_vandute] = this->stoc[i];
        for(int j = i; j < nr_masini_supersport_expuse; j++) stoc[j] = stoc[j+1];
        nr_masini_supersport_expuse --;
        return s;
    }
    void add(supersport s)
    {
        stoc[++nr_masini_supersport_expuse] = s;
    }
};
Expozitie <supersport> eS;
Expozitie <cabrio> eCabrio;
Expozitie <hot_hatch> eH;
Expozitie <coupe> eCoupe;

int main ()
{
vector <pair<int,int>> Vanzari;
cout<<"Cate masini sunt ?"; cin>> n; if(n <= 0) throw(DateGresite());
cout<<"\nCiteste masinile ";
for(int i = 1 ; i <= n; i++)
{
    cout<<"\nDe care tip este?";
    string raspuns;
    cin>>raspuns;
    if( raspuns == "cabrio")
    {
        cabrio Cabrio ;
        cin>>Cabrio;
        eCabrio.set_masini(&Cabrio);
    }
     if( raspuns == "coupe")
    {
        coupe Coupe;
        cin>>Coupe;
        eCoupe.set_masini(&Coupe);
    }
     if( raspuns == "hot_hatch")
    {
        hot_hatch H;
        cin>> H;
        eH.set_masini(&H);
    }
     if( raspuns == "supersport")
    {
        supersport S;
        cin>>S;
        eS.add(S);
    }
}

cout<<"\n\n";
string interactiv;
cout<<"Vrei sa vinzi o masina? ";
cin >> interactiv;
if(interactiv == "nu") return 0;
else {
    while(interactiv =="da")
    {
        cout<<"Introdu numarul masinii pe care vrei s-o vinzi, si pretul de vanzare";
        int pretul, i;
        cin>>pretul>>i;
        Vanzari.push_back({i , pretul});
        eS-=i; ///operatorul -=
    }
}
return 0;
}
