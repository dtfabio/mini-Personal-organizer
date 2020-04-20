#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

struct persona
{
      int nome;
      int cognome;
      int email;
      int data;
      int cell;
};
      
persona agenda; //dichiarazione record;

int potenza(int b, int e)
{
    int ris=1;
    int k;
    for(k=1;k<=e;k++)
        ris=ris*b;
    return ris;   
}

int val(char s[])
{    
    int d=0,so=0;
    int k;
    
    while(s[d] != '\0')
        d++;
    int v[d];
    
    for(k=0;k<=d-1;k++)
          v[k]=s[k]-48;                     
    
    for(k=0;k<=d-1;k++)
        so=so+v[k]*(potenza(10,d-1-k));
    
    return so;   
}
int main()
{
          int dataintero;
          char fine;
          fstream fagenda;
          fagenda.open("c:/4cdati/agenda.dat", ios::out | ios::binary);
          
          do
          {
            cout<<"Inserisci il nome: "<<endl;
            cin>>(agenda.nome);
            cout<<endl;
            cout<<"Inserisci il cognome: "<<endl;
            cin>>(agenda.cognome);
            cout<<endl;
            cout<<"Inserisci l'email: "<<endl;
            cin>>(agenda.email);
            cout<<endl;
            cout<<"Inserire la data di nascita:"<<endl;
            cin>>(agenda.data);
            cout<<endl;
            cout<<"Inserire il numero cellulare:"<<endl;
            cin>>(agenda.cell);
            //assegno variabile char a int
            dataintero=val(agenda.data);
       
            
            //Scrivere un record in archivio
            fagenda.write((int*) & agenda, sizeof(agenda));
             cout<<"Proseguire con l'inserimento? (s/n) "<<endl;
            cin>>fine;
            
           }
          
           while((fine=='s'));
           fagenda.close();
system("pause");
}
            
            
      
