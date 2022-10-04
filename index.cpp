#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


struct prodotto{
    string codice;
    string nome;
    float prezzo;
    string categoria;
};

void filtra(prodotto *p, int n){
    string sezione;
    int filtVal;
    //0 => filtra per codice
    //1 => filtra per nome
    //2 => filtra per prezzo
    //3 => filtra per categoria
    cout<<"0 => filtra per codice"<<endl;
    cout<<"1 => filtra per nome"<<endl;
    cout<<"2 => filtra per prezzo"<<endl;
    cout<<"3 => filtra per categoria"<<endl;
    cout<<"Inserisci il numero: ";
    cin>>filtVal;



    switch (filtVal)
    {
    case 0:
        cout<<"Inserisci il codice da filtrare: ";
        cin>>sezione;
        for(int i=0; i<n; i++){
            if(p[i].codice == sezione){
                cout << p[i].codice << " " << p[i].nome << " " << p[i].prezzo << " " << p[i].categoria << endl;
            }
        }
        break;

    case 1:
        cout<<"Inserisci il nome da filtrare: ";
        cin>>sezione;
        for(int i=0; i<n; i++){
            if(p[i].nome == sezione){
                cout << p[i].codice << " " << p[i].nome << " " << p[i].prezzo << " " << p[i].categoria << endl;
            }
        }
        break;
    
    case 2:
        cout<<"Inserisci il prezzo da filtrare: ";
        cin>>sezione;
        for(int i=0; i<n; i++){
            if(p[i].prezzo == stof(sezione)){
                cout << p[i].codice << " " << p[i].nome << " " << p[i].prezzo << " " << p[i].categoria << endl;
            }
        }
        break;

    case 3:

        cout<<"Inserisci la categoria da filtrare: ";
        cin>>sezione;
        for(int i=0; i<n; i++){
            if(p[i].categoria == sezione){
                cout << p[i].codice << " " << p[i].nome << " " << p[i].prezzo << " " << p[i].categoria << endl;
            }
        }
        break;

    
    default:
        break;
    }
    
}


void filtra(prodotto *p, int n, string sezione);
void leggi(prodotto tabella[], int &n);
void visualizza(prodotto tabella[], int n);
void aggiungi(prodotto tabella[], int &n);
void elimina(prodotto tabella[], int &n);
string cercaNome(prodotto tabella[], int n, string nome);
void modifica(prodotto tabella[], int n);

int main(){
    prodotto tabella[100];
    int n;
    leggi(tabella, n);
    int scelta;
    do{
        cout << "1. Visualizza tutti i prodotti" << endl;
        cout << "2. Visualizza un prodotto" << endl;
        cout << "3. Aggiungi un prodotto" << endl;
        cout << "4. Elimina un prodotto" << endl;
        cout << "5. Modifica un prodotto" << endl;
        cout << "6. Filtra un prodotto" << endl;
        cout << "7. Esci" << endl;
        cout << "Scelta: ";
        cin >> scelta;
        string nome;
        switch(scelta){
            case 1:
                visualizza(tabella, n);
                break;
            case 2:
                
                cout << "Inserisci il nome del prodotto: ";
                cin >> nome;
                cout << cercaNome(tabella, n, nome);
                break;
            case 3:
                aggiungi(tabella, n);
                break;
            case 4:
                elimina(tabella, n);
                break;
            case 5:
                modifica(tabella, n);
                break;
            case 6:
                filtra(tabella, n);
                break;
            case 7:
                return 0;
                break;
            default:
                cout << "Scelta non valida" << endl;
        }
    }while(scelta != 6);
    return 0;
}
void leggi(prodotto tabella[], int &n){
    ifstream in("restaurantDB.csv");
    if(!in){
        cout << "Errore nell'apertura del file";
        exit(1);
    }
    n = 0;
    string riga;
    while(getline(in, riga)){
        int pos = riga.find(';');
        tabella[n].codice = riga.substr(0, pos);
        riga = riga.substr(pos+1);
        pos = riga.find(';');
        tabella[n].nome = riga.substr(0, pos);
        riga = riga.substr(pos+1);
        pos = riga.find(';');
        tabella[n].prezzo = stof(riga.substr(0, pos));
        riga = riga.substr(pos+1);
        tabella[n].categoria = riga;
        n++;
    }
    in.close();
}

void visualizza(prodotto tabella[], int n){
    cout<<endl<<endl;
    for(int i=0; i<n; i++){
        cout << tabella[i].codice << " ";
        cout << tabella[i].nome << " ";
        cout << tabella[i].prezzo << " ";
        cout << tabella[i].categoria << endl;
    }
    cout<<endl <<endl;
}

void aggiungi(prodotto tabella[], int &n){
    cout << "Codice: ";
    cin >> tabella[n].codice;
    cout << "Nome: ";
    cin >> tabella[n].nome;
    cout << "Prezzo: ";
    cin >> tabella[n].prezzo;
    cout << "Categoria: ";
    cin >> tabella[n].categoria;
    n++;
}
void elimina(prodotto tabella[], int &n){
    string codice;
    cout << "Codice: ";
    cin >> codice;
    int i;
    for(i=0; i<n; i++){
        if(tabella[i].codice == codice){
            break;
        }
    }
    if(i == n){
        cout << "Prodotto non trovato" << endl;
    }else{
        for(int j=i; j<n-1; j++){
            tabella[j] = tabella[j+1];
        }
        n--;
    }
}
void modifica(prodotto tabella[], int n){
    string codice;
    cout << "Codice: ";
    cin >> codice;
    int i;
    for(i=0; i<n; i++){
        if(tabella[i].codice == codice){
            break;
        }
    }
    if(i == n){
        cout << "Prodotto non trovato" << endl;
    }else{
        cout << "Nuovo nome: ";
        cin >> tabella[i].nome;
        cout << "Nuovo prezzo: ";
        cin >> tabella[i].prezzo;
        cout << "Nuova categoria: ";
        cin >> tabella[i].categoria;
    }
}

string cercaNome(prodotto tabella[], int n, string nome){
    for(int i=0; i<n; i++){
        if(tabella[i].nome == nome){
            return tabella[i].nome;
        }
    }
    return "Prodotto non trovato";
}
