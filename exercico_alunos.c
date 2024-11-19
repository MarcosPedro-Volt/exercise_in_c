// O programa deve então realizar as seguintes funções:

// Cadastrar aluno em uma turma.
// Lançar notas de aluno.
// Calcular a média de uma turma.
// Gerar o relatório de turma, exibindo as informações de todos os alunos pertencentes à turma.

#include <stdio.h>
#include <string.h>

struct Aluno
{
    char nome[50];
    int matricula;
    float notas[2];
};

struct Turma
{
    int numeroTurma;
    struct Aluno alunos[30];
    int totalAlunos;
};


int main(){
    struct Aluno alunos[5];
    struct Turma turmas[10];
    int op;



    strcpy(alunos[0].nome, "João");

    alunos[0].matricula = 1001;

    alunos[0].notas[0] = 8.5;

    alunos[0].notas[1] = 7.0;

 

    strcpy(alunos[1].nome, "Maria");

    alunos[1].matricula = 1002;

    alunos[1].notas[0] = 7.5;

    alunos[1].notas[1] = 8.0;

 

    strcpy(alunos[2].nome, "Pedro");

    alunos[2].matricula = 1003;

    alunos[2].notas[0] = 9.0;

    alunos[2].notas[1] = 9.5;

 

    strcpy(alunos[3].nome, "Ana");

    alunos[3].matricula = 1004;

    alunos[3].notas[0] = 7.0;

    alunos[3].notas[1] = 7.5;

 

    strcpy(alunos[4].nome, "Carlos");

    alunos[4].matricula = 1005;

    alunos[4].notas[0] = 8.0;

    alunos[4].notas[1] = 8.5;

 

    // inicializa duas turmas

 

    turmas[0].totalAlunos = 0;

    turmas[0].numeroTurma = 5000;

 

    turmas[1].totalAlunos = 0;

    turmas[1].numeroTurma = 6000;

 

    int a, t;



    do
    {
        printf("1-cadastrar aluno na turma \n");
        printf("2-lancar notas de aluno \n");
        printf("3-calcular a media da turma\n");
        printf("4-relatorio da turma\n");
        printf("5-encerrar\n");
        printf("Opcao: \n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("escolha o id do aluno: ");
            scanf("%d",&a);
            printf("escolha a turma: ");
            scanf("%d",&t);

            if (turmas[t].totalAlunos < 30)
            {
                turmas[t].alunos[turmas[t].totalAlunos] = alunos[a];
                turmas[t].totalAlunos++;
                printf("aluno(a) %s ,cadastrado na turma > %d\n",alunos[a].nome, turmas[t].numeroTurma);
                printf("\n\n");
            }
            else
            {
                printf("turma cheia\n");
            }
            
            break;

        case 2:
            printf("selecione o aluno: \n");
            scanf("%d",&a);

            for (int i = 0; i < 2; i++)
            {
                printf("Nota %d:", i+1);
                scanf("%f", &alunos[a].notas[i]);

                
            }
            
            printf("Nota 1:'%.2f'  Nota 2:'%.2f'\n", alunos[a].notas[0],alunos[a].notas[1]);
            break;

        case 3:
            printf("selecione a turma: ");
            scanf("%d", &t);
            

            float SomaMediaTurmas = 0.0;
            
            for (int i = 0; i < turmas[t].totalAlunos; i++)
            {
                float somanotas = 0.0;

                for (int j = 0; j < 2; j++)
                {
                    somanotas += turmas[t].alunos[i].notas[j];
                }
                
                float mediaAluno = somanotas /2;
                SomaMediaTurmas += mediaAluno;

            }
            float mediaTurma = SomaMediaTurmas / turmas[t].totalAlunos;
            printf("\n Media: %.2f", mediaTurma);
            printf("\n\n");

            break;
            
         
        case 4:

            printf(" Escolha a turma: ");

            scanf("%d", &t);

            printf("\n Turma %d\n", turmas[t].numeroTurma);

            for (int i = 0; i < turmas[t].totalAlunos; i++) {

                printf(" Aluno: %s\n", turmas[t].alunos[i].nome);

                printf(" Matrícula: %d\n", turmas[t].alunos[i].matricula);

                printf(" Notas: ");

                for (int j = 0; j < 2; j++) {

                    printf("%.2f ", turmas[t].alunos[i].notas[j]);

                }

                printf("\n");

            }

            break;

       

        default:

            printf(" programa encerrado!\n\n");

            break;

        }

       
        
        
    } while (op != 5);
    return 0;
}