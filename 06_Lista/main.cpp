#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{

    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
        deletarTudo(head);
    }

    void deletarTudo(Node * node){
        if(head == nullptr){
               return;
        }

        while(node->next != nullptr){
            delete node;
        }
    }


    //procura o valor, remove desse no em diante
    Node *cortarRabo(Node * node, int value){
          if(head == nullptr){
              return nullptr;
          }


    while(node->next != nullptr){

         if(node->value == value){
              while(node->next != nullptr){
                 delete node;
               }
          }
      }
    }

    void push_front(int value){
        //this->head = new Node(value, this->head);
        Node * node = new Node(value);
        Node* head;
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

    void push_back(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }

    Node * _push_back(Node * node, int value){
        //todo
        if(head == nullptr){
              head = new Node(value);
              return nullptr;
        }

        node = head;

          while(node->next != nullptr){
              node = node->next;
              node->next = new Node(value);
          }
    }

    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
    }

    void rpop_back(){
        this->head = _rpop_back(head);
    }

    void ishow(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
private:
    void _rshow(Node * node){
        if(node == nullptr)
            return;
        cout << node->value << " ";
        _rshow(node->next);
    }
public:
    void rshow(){
        _rshow(head);
        cout << endl;
    }

    Node * _remove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
    }

    void rremove(int value){
        head = _remove(head, value);
    }

    void iremove(int value){
        while(head->value != value){
           if(head->value == value){
               delete head;
                 return;
           }
        }

     return;
    }


    void inserir_ordenado(int value){
        auto node = head;
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return;
        }
        while(node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value, node->next);
    }

    Node * _rinserir_ordenado(Node * node, int value){
        //todo
        if(head == nullptr || head->value > value){
             this->head = new Node(value, head);
             return nullptr;
         }
         if(node->next != nullptr){
             return nullptr;
         }
         _rinserir_ordenado(node->next,value);

         node->next = new Node(value, node->next);

        return nullptr;
    }

    void rinserir_ordenado(int value){
        Node *node;
        if(head == nullptr || head->value > value){
              this->head = new Node(value, head);
              return;
         }

        if(node->next != nullptr){
              return;
        }

       _rinserir_ordenado(node->next, value);

       node->next = new Node(value, node->next);

       return;
    }

    //todo
    int size(){
        int size = 0;
        Node *node;

       if(this->head == nullptr){
            return 0;
       }

       while(node->next != nullptr){
             node = node->next;
             size += 1;
       }

       return size;
    }



    int rsomar(Node * node){
        int soma = 0;

        if(head == nullptr){
            return 0;
        }

        if(node->next == nullptr){
           soma = node->value;
           return soma;
        }

        while(node->next != nullptr){
            soma = soma + node->value;
        }

        return soma;
    }

    int rmin(Node * node){
        if(node->next == nullptr)
            return node->value;
        return std::min(node->value, rmin(node->next));
    }

};

int main(){
    SList lista;
    lista.push_back(5);
    lista.push_back(6);
    lista.push_back(7);
    lista.push_back(10);

    return 0;
}


//int main()
//{
//    SList lista;
//    lista._rshow(lista.head);
//    return 0;
//}

////int mainc(){
////    char produto[] = "nescau 200 ml 10.00 5 laticineos";
////    char str[50];
////    float valor = 4.50;
////    int qtd = 10;
////    char setor[] = "hortifruti";
////    sprintf(str, "uva %f %d %s", valor, qtd, setor);
////    char nome[50];
////    sscanf(produto, "%s %f %d %s", nome, &valor, &qtd, setor);
////    return 0;
////}

////#include <fstream>

////int maincpp(){
////    int x;
////    ofstream asaida("../lista/saida.txt");
////    ifstream ainput("../lista/entrada.txt");
////    string linha;
////    getline(ainput, linha, ';');
////    asaida << "digite um inteiro" << endl;
////    ainput >> x;
////    asaida << "digite um nome bonito" << endl;
////    string s;
////    ainput >> s;
////    asaida << "x = " << x << ", s = " << s << endl;

////    return 0;
////}

////#include <sstream>
////int main(){
////    stringstream ss;
////    ss << "hoje " << 24 << "abril de 2014, temp=" << 27.73 << endl;
////    cout << ss.str();

////    string str("44 38");
////    stringstream ss2(str);
////    int lixo;
////    int i;
////    ss2 >> lixo >> i;
////    return 0;
////}


