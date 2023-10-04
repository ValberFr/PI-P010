#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Aluno {
    string nome;
    float nota1;
    float nota2;
    float media;
    string resultado;
};

// Função para realizar a ordenação dos alunos pelo nome usando o Bubble Sort
void bubbleSort(vector<Aluno>& alunos) {
    int n = alunos.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (alunos[i].nome > alunos[i + 1].nome) {
                swap(alunos[i], alunos[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    int N;
    vector<Aluno> alunos;

    // Solicita o limite de alunos e valida a entrada
    while (true) {
        cout << "Digite o limite de alunos: ";
        if (cin >> N && N > 0) {
            break;
        } else {
            cout << "Número inválido, por favor digite um número válido!\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    while (N > 0) {
        cout << "\nInformações do aluno " << alunos.size() + 1 << ":" << endl;
        Aluno aluno;

        // Solicita e valida o nome do aluno
        cout << "Nome do aluno: ";
        cin.ignore();
        getline(cin, aluno.nome);

        // Solicita e valida a primeira nota
        while (true) {
            cout << "Nota 1: ";
            if (cin >> aluno.nota1) {
                break;
            } else {
                cout << "\nNota 1 inválida, por favor digite um valor numérico válido." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        // Solicita e valida a segunda nota
        while (true) {
            cout << "Nota 2: ";
            if (cin >> aluno.nota2) {
                break;
            } else {
                cout << "\nNota 2 inválida, por favor digite um valor numérico válido." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        aluno.media = (aluno.nota1 + aluno.nota2) / 2;
        
        if(aluno.media >= 7){
            aluno.resultado = "Aprovado";
        }else{
            aluno.resultado = "Reprovado";
        }

        alunos.push_back(aluno);

        N--; // Reduza o limite de alunos restantes

        if(N > 0){
            cout << "\nDeseja incluir mais alunos (s/n)? ";
            string resposta;
            cin >> resposta;

            if (resposta != "s" && resposta != "S") {
                break;
            }
        }
        
    }

    bubbleSort(alunos);

    return 0;
}