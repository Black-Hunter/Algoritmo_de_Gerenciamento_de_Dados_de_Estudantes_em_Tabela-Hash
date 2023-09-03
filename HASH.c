#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct estudantes{
    char nome[20];
    char curso[20];
    int matricula;
    int periodo;
}Estudantes;


int isPrimo(int valor){
    
    int cont = 0;
    
    for(int i = 1; i <= valor; i++){
        if(valor % i == 0){
            cont++;
        }
    }
    
    if(cont == 2)
        return 1;
    else
        return 0;
    
}



int proxPrimo(int valor){
    if(isPrimo(valor)){
        return valor;
    }else{
        return proxPrimo(valor + 1);
    }
}


int hash(int matricula, int TAM){
    return (matricula % TAM);
}


void alterarDados(Estudantes vet[], int pos){
    
    printf("\nDigite o novo nome: ");
    scanf("%s", vet[pos].nome);
    
    printf("\nDigite o novo curso: ");
    scanf("%s", vet[pos].curso);
    
    printf("\nDigite a nova matricula: ");
    scanf("%i", &vet[pos].matricula);
    
    printf("\nDigite o novo periodo: ");
    scanf("%i", &vet[pos].periodo);
    
    printf("\n\n");
}

void excluirDados(Estudantes vet[], int pos){
    
    Estudantes temp;
    strcpy(temp.nome, "NULL");
    temp.matricula = -1;
    temp.periodo = -1;
    strcpy(temp.curso, "NULL");
    
    vet[pos] = temp;
}

void excluirTudo(Estudantes vet[], int TAM){
    
    Estudantes temp;
    strcpy(temp.nome, "NULL");
    temp.matricula = -1;
    temp.periodo = -1;
    strcpy(temp.curso, "NULL");
    
    for(int i = 0; i < TAM; i++){
        vet[i] = temp;
    }
}

void mostrar(Estudantes vet[], int TAM){
    
    for(int i = 0; i < TAM; i++){
        if(vet[i].matricula != -1){
            printf("Nome: %s\n", vet[i].nome);
            printf("Matricula: %i\n", vet[i].matricula);
            printf("Curso: %s\n", vet[i].curso);
            printf("Periodo: %i\n", vet[i].periodo);
        }
    }
}

int main(){
    
    
    int valorProcura, qtdAlunos;
    int op;
    
    
    char nome[20];
    char curso[20];
    int matricula;
    int periodo;
    
    printf("Digite a quantidade de alunos a serem cadastrados: ");
    scanf("%i", &qtdAlunos);
    
    int TAM = proxPrimo(qtdAlunos);
    
    Estudantes vet[TAM];
    
    printf("\n\n\n");
    for(int i = 0; i < qtdAlunos; i++){
        Estudantes temp;
        printf("Digite o nome do aluno %i: ", i+1);
        getchar();
        scanf("%s",temp.nome);
        getchar();
        
        
        printf("Digite o curso do aluno %i: ", i+1);
        scanf("%s",temp.curso);
        getchar();
        
        
        printf("Digite a matricula do aluno %i: ", i+1);
        scanf("%i", &temp.matricula);
        
        printf("Digite o periodo do aluno %i: ", i+1);
        scanf("%i", &temp.periodo);

        vet[hash(temp.matricula,TAM)] = temp;
        
        printf("\n\n\n");
    }
    
  
    do{
        printf("\n\nDigite a matricula para procura ou -1 para sair: ");
        scanf("%i", &valorProcura);
        
        if(valorProcura != -1){
            if(vet[hash(valorProcura,TAM)].matricula == valorProcura){
                int op;
                
                printf("\n\nDados do estudante:\n\n");
                
                printf("Nome: %s\n", vet[hash(valorProcura, TAM)].nome);
                printf("Nome: %s\n", vet[hash(valorProcura, TAM)].curso);
                printf("Matricula: %i\n", vet[hash(valorProcura,TAM)].matricula);
                printf("Periodo: %i\n", vet[hash(valorProcura, TAM)].periodo);
                printf("\n\n\n");
                
                printf("\n1 - Alterar dados do aluno.");
                printf("\n2 - Excluir dados do aluno.");
                printf("\n3 - Procurar novo contato.");
                printf("\n4 - Excluir tudo.");
                
                printf("\n\nDigite sua opcao: ");
                scanf("%i", &op);
                
                if(op == 1){
                    alterarDados(vet, hash(valorProcura, TAM));
                }else if(op == 2){
                    excluirDados(vet, hash(valorProcura, TAM));
                }else if(op == 3){
                    
                }else if (op == 4){
                    excluirTudo(vet, TAM);
                }else if (op == 5){
                    valorProcura = -1;
                }
                
            }else{
                printf("Estudante nao encontrado!!!\n\n");
            }
        }
        
        
    }while(valorProcura != -1);
    
   
    return 0;
}
