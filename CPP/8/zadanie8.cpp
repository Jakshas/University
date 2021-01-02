//Jakub Szajner zadanie 8 podpunkt 1

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Lista{
    private:
    class Node{
        public:
        T wartosc;
        Node *next;
        Node(T wartosc){
            this->wartosc=wartosc;
            this->next=nullptr;
        }
        Node(T wartosc,Node next){
            this->wartosc=wartosc;
            this->next=next;
        }
        Node(){
            this->wartosc=NULL;
            this->next=nullptr;
        }
    };
    public:
    Node *first;
    Lista(){
        this->first=nullptr;
    }
    void listadd(T wartosc, int poz1){
        int poz=poz1;
        if(this->first==nullptr){
            if(poz == 0){
            this->first=new Node(wartosc);
            }else
            {
                cerr<<"Błąd"<<endl;
            }
            return;
        }else{
            Node *pom=this->first;
            if(poz == 0){
                Node *p=new Node(wartosc);
                p->next=this->first;
                this->first=p;
                return;
            }

            while(pom->next!=nullptr && poz!=1){
                pom=pom->next;
                poz=poz-1;;
            }
            if(poz==1){
                Node *p=new Node(wartosc);
                p->next=pom->next;
                pom->next=p;
                return;
            }else
            {
                cerr<<"Błąd1"<<endl;
            }
        }
        
    }
    int listcount(){
        Node *pom=first;
        int i=0;
            while(pom!= nullptr){
                pom=pom->next;
                i++;
            }
        return i;
    }
    void listdelete(T wartosc){
        if(this->first->wartosc.equals(wartosc)){
            this->first=this->first->next;
        }else
        {
        Node *pom=first->next;
        Node *pomp=first;
            while(!pom->wartosc.equals(wartosc)&&pom->next!=nullptr){
                pomp=pom;
                pom=pom->next;
            }
            if(pom->wartosc.equals(wartosc)&&pom->next==nullptr){
                pomp->next=nullptr;
            }
            if(pom->wartosc.equals(wartosc)&&pom->next!=nullptr){
                pomp->next=pom->next;
            }
        }
        
    }
        int listsearch(T wartosc){
        Node *pom=first;
        int i=0;
            while(pom!= nullptr&&!pom->wartosc.equals(wartosc)){
                pom=pom->next;
                i++;
            }
            if(pom->wartosc.equals(wartosc)){
                return i;
            }
        return 0;
    }
    Lista(const Lista &l){
            Node *pom = l->first;
            Node *temp= new Node(pom->wartosc);;
            Node *temp2;
            while (pom != nullptr)
            {
                temp2= new Node(pom->next->wartosc);
                temp->next=temp2;
                temp=temp2;
                pom=pom->next;
            }
    }
    Lista<T> operator=(const Lista &l){
            Node *pom = l->first;
            Node *temp= new Node(pom->wartosc);;
            Node *temp2;
            while (pom != nullptr)
            {
                temp2= new Node(pom->next->wartosc);
                temp->next=temp2;
                temp=temp2;
                pom=pom->next;
            }
            return *this;
    }
    Lista(Lista &&l){
        this->first=l->first;
        l->first=nullptr;
    }
    Lista<T> operator=(const Lista &&l){
        this->first=l->first;
        l->first=nullptr;
        return *this;
    }
    Lista(initializer_list<T> lista){
        if (lista.size() <= 0){
            cerr<<"Błąd"<<endl;
        }
        int i = 0;
        for (const T &it : lista)
        {
            listadd(it, i);
            i++;
        }
    }
};

int main(int argc, char const *argv[])
{
    Lista<int> *li=new Lista<int>();
    li->listadd(1,0);
    li->listadd(2,1);
    cout<<li->listcount();
}
