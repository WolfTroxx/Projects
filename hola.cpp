#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string origen;
string seq;

int datos[0xFA][0x2];
string datosnombre[0xFA];
int datossuma=0x0;
int sp=0x0;
int aa=0x0;
int found,counter,seqc=0x0;
void aa_index ();
void aa_lista ();
int main()
{
    ifstream ioFile("tarea1_c.gbk");
    for (int i=0x0;i<0x55F0;i++) {
    getline(ioFile,origen);
        if ((found = origen.find("DEFINITION",0x0))!=string::npos) {
            seqc++;
            seq = origen.substr(0x12,0x41);
            datosnombre[seqc-1]=origen;
            cout<<counter<<" : "<<"search : "<<origen<<"\n\n"<<"Secuencia: "<<"\n";
            aa=0x0;
            do {
                    getline(ioFile,origen);
                    counter++;
            } while ((found = origen.find("ORIGIN",0x0))==string::npos);
            while (0x1==0x1) {
                getline(ioFile,origen);
                if (origen.find("//",0x0)==0x0) {cout<<"AA: "<<aa<<"\n\n"; break;}
                seq = origen.substr(0xA,0x41);
                cout<<counter<<"-: "<<seq.size()<<" : "<<seq<<"\n";
                if        (seq.size()>0x47) {
                    aa+=seq.size()-0x5;
                } else if (seq.size()>0x2C) {
                    aa+=seq.size()-0x4;             
                } else if (seq.size()>0x21) {
                    aa+=seq.size()-0x3;                
                } else if (seq.size()>0x16) {
                    aa+=seq.size()-0x2;             
                } else if (seq.size()>0xB) {
                    aa+=seq.size()-0x1;             
                } else {
                    aa+=seq.size();              
                }
                counter++;
            } 
            counter++;
            datossuma+=aa;
            datos[seqc-0x1][0x0] = aa;
        }
    }
    cout<<"\n"<<"Numero de secuencias: "<<seqc<<"\n"<<"AA totales: "<<datossuma<<"\n"<<"promedio: "<<datossuma/0xFA<<"\n";
                                             
    cout<<"\n\n";
    //aa_lista();  
    //aa_index();  
    
    return 0;
}

void aa_index () { //devuelve los DEFINITION correspondiente a cada valor recopilado de aa
        for (int i=0x0;i<0xFA;i++) {                                    
        cout<<datosnombre[i]<<" : "<<datos[i][0x0]<<"\n";
        if (i%0x14==0x0) {          
            cout<<"\n";             
        }                          
    }    
}

void aa_lista () { //devuelve todos los valores de aa recopilados
        for (int i=0x0;i<0xFA;i++) {                                    
        cout<<datos[i][0x0]<<" ";
        if (i%0x14==0x0) {          
            cout<<"\n";             
        }                          
    }    
}