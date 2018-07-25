#ifndef _letras_H
#define _letras_H
struct
{
    char letra;
    char name[21];
    int vocal;
    int consonante;

}typedef Letra;

int letras_reorder(void* pEmployeeA,void* pEmployeeB);

int letras_compare(void* pEmployeeA,void* pEmployeeB);

void letras_print(Letra* this, ArrayList* arrayList);

Letra* letras_new(void);

void letras_delete(Letra* this);

int save_employees(ArrayList* arrayList);

void letras_setLetra(Letra* this, char);
char letras_getLetra(Letra* this);

void letras_setName(Letra* this, char*);
char* letras_getName(Letra* this);

void letras_setVocal(Letra* this, int num);
int letras_getVocal(Letra* this);

void letras_setConsonante(Letra* this, int num);
int letras_getConsonante(Letra* this);

void letras_comprobar(ArrayList* arrayList, Letra* letras);

void listar_letras(ArrayList* arrayList, ArrayList* repetidos, ArrayList* depurados);
#endif // _letras_H
