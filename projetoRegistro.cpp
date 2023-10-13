#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>


using namespace std;

const string SENHA_MESTRA = "9999";  // Senha mestra

struct Cadastro {
    string nome;
    string idade;
    string curso;
    string usuario;
    string senha;
};


void esconderSenha(string& senha) {
    senha.clear();
    char ch;
    while ((ch = _getch()) != 13) { // 13 é o código para 'Enter'
        if (ch == 8) {  // 8 é o código para 'Backspace'
            if (!senha.empty()) {
                cout << "\b \b";  // Apaga o último caractere impresso
                senha.pop_back();
            }
        } else {
            cout << '*';
            senha.push_back(ch);
        }
    }
    cout << endl;
}

bool usuarioCadastrado(const vector<Cadastro>& registros, const string& usuario, const string& senha) {
    for (const Cadastro& cadastro : registros) {
        if (cadastro.usuario == usuario && cadastro.senha == senha) {
            return true; // Usuário e senha correspondem a um registro existente.
        }
    }
    return false; // Usuário ou senha incorretos.
}
void salvarRegistros(const vector<Cadastro>& registros) {
    ofstream arquivo("registros.txt");

    if (arquivo.is_open()) {
        for (const Cadastro& cadastro : registros) {
            arquivo << cadastro.usuario << " " << cadastro.senha << endl;
        }
        arquivo.close();
        cout << "Registros salvos com sucesso." << endl;
    } else {
        cerr << "Erro ao abrir o arquivo para salvar registros." << endl;
    }
}

void carregarRegistros(vector<Cadastro>& registros) {
    ifstream arquivo("registros.txt");

    if (arquivo.is_open()) {
        registros.clear();
        Cadastro usr;
        while (arquivo >> usr.usuario >> usr.senha) {
            registros.push_back(usr);
        }
        arquivo.close();
        cout << "Registros carregados com sucesso." << endl;
    } else {
        cerr << "Erro ao abrir o arquivo para carregar registros." << endl;
    }
}

void cadastrarUsuario(vector<Cadastro>& registros) {
    Cadastro novoUsuario;
    cout << "Digite o nome de usuario: ";
    cin >> novoUsuario.usuario;

    // Verificar se o nome de usuário já existe
    for (const Cadastro& cadastro : registros) {
        if (cadastro.usuario == novoUsuario.usuario) {
            cout << "Usuario ja existente." << endl;
            return;
        }
    }

    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, novoUsuario.nome);
    cout << "Digite a idade: ";
    cin >> novoUsuario.idade;

    do {
        cout << "Escolha o curso (CC, ADS, SI): ";
        cin >> novoUsuario.curso;

        // Verificar o curso
        if (novoUsuario.curso != "CC" && novoUsuario.curso != "ADS" && novoUsuario.curso != "SI") {
            cout << "Curso invalido. Escolha entre CC, ADS, SI." << endl;
        }
    } while (novoUsuario.curso != "CC" && novoUsuario.curso != "ADS" && novoUsuario.curso != "SI");

    cout << "Digite a senha: ";
    esconderSenha(novoUsuario.senha);

    registros.push_back(novoUsuario);
    cout << "Cadastro realizado com sucesso para o usuario: " << novoUsuario.usuario << endl;
}

void excluirUsuario(vector<Cadastro>& registros) {
    string usuarioParaExcluir;
    cout << "Digite o nome de usuario a ser excluido: ";
    cin.ignore();
    getline(cin, usuarioParaExcluir);

    vector<Cadastro>::iterator it = find_if(registros.begin(), registros.end(), [&](const Cadastro& usr) {
        return usr.usuario == usuarioParaExcluir;
    });

    if (it != registros.end()) {
        registros.erase(it);
        cout << "Usuario excluido com sucesso." << endl;
    } else {
        cout << "Usuario nao encontrado." << endl;
    }
}

void gerarRelatorio(const vector<Cadastro>& registros) {
    cout << "Relatorio de Usuarios:" << endl;
    for (const Cadastro& usr : registros) {
        cout << "Nome: " << usr.nome << endl;
        cout << "Idade: " << usr.idade << endl;
        cout << "Curso: " << usr.curso << endl;
        cout << "Usuario: " << usr.usuario << endl;
        cout << "-----------------------------" << endl;
    }
}

//######### TELA DE CUROS ##############







// ----------------------CURSOS------------------------------

//######################CIENCIA DA COMPUTACAO########################
void cc1() {
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tCIENCIAS DA COMPUTACAO      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tPRIMEIRO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "LOGICA COMPUTACIONAL (EAD)" << "| 40" << std::endl;
    std::cout << std::left << std::setw(40) << "PROGRAMACAO WEB" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "SISTEMAS OPERACIONAIS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "MODELAGEM DE DADOS (EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "CIRCUITOS LOGICOS (EAD)" << "| 40" << std::endl;
    std::cout << std::left << std::setw(40) << "TECNICAS E DESENVOLVIMENTO..." << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "SOCIEDADE E TERRITORIOS (EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "LIBRAS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "OPTATIVA I" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "EXTENSIONISTA I" << "| 50" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao
    //  criar uma funcao ponteiro
    void (*selecionarSemestreCC)() = selecionarSemestreCC;

    // chhamar o metodo com ponteiro
    selecionarSemestreCC();
}
void cc2() {
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tCIENCIAS DA COMPUTACAO      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tSEGUNDO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "PROGRAMACAO ORIENTADA A OBJETOS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "BANCO DE DADOS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "CALCULO DIFERENCIAL I (EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "PROBABILIDADE E ESTATISTICA" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "CLIENTE/SERVIDOR (EAD)" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "OPTATIVA II" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "EXTENSIONISTA II" << "| 50" << std::endl;
    std::cout << std::left << std::setw(40) << "ESTRUTURAS DE DADOS" << "| 60" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao
}
void cc3() {
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tCIENCIAS DA COMPUTACAO      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tTERCEIRO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "INTERFACE HUMANO-COMPUTADOR (EAD)" << "| 40" << std::endl;
    std::cout << std::left << std::setw(40) << "ANALISE E PROJETO DE SISTEMAS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "CALCULO DIFERENCIAL II (EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "ENGENHARIA DE SOFTWARE (EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "OPTATIVA III" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "EXTENSIONISTA III" << "| 50" << std::endl;
    std::cout << std::left << std::setw(40) << "ESTRUTURAS DE DADOS II" << "| 60" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao
}
void cc4() {
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tCIENCIAS DA COMPUTACAO      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tQUARTO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "PROMACAO MOBILE" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "CALCULO NUMERICO (EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "TEORIA DOS GRAFOS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "OPTATIVA IV" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "EXTENSIONISTA IV" << "| 50" << std::endl;
    std::cout << std::left << std::setw(40) << "COMPUTACAO GRAFICA (EAD)" << "| 40" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao
	}
	
void cc5() {
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tCIENCIAS DA COMPUTACAO      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tQUINTO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "COMPUTACAO PARALELA E DISTRIBUIDA)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "QUALIDADE DE SOFTWARE(EAD)" << "| 40" << std::endl;
    std::cout << std::left << std::setw(40) << "BIG DATA (EAD)" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "COMPUTABILIDADE E COMPLEXIDADE DE ALG " << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "LINGUAGENS FORMAIS E AUTOMATOS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "OPTATIVA V" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "EXTENSIONISTA V" << "| 50" << std::endl;
    std::cout << std::left << std::setw(40) << "ESTAGIO SUPERVISIONADO" << "| 100" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao
}
void cc6() {
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tCIENCIAS DA COMPUTACAO      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tSEXTO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "GESTAO ESTRATEGICA DE NEGOCIOS" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "COMPUTACAO EM NUVEM(EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "FUNDAMENTOS DE I.A." << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "OPTATIVA VI" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "TRABALHO DE GRADUACAO " << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "EXTENSIONISTA VI" << "| 70" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao

}
void cc7() {
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tCIENCIAS DA COMPUTACAO      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tSETIMO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "ARQUITETURA DE SISTEMAS (EAD)" << "| 40" << std::endl;
    std::cout << std::left << std::setw(40) << "PARADIGMAS DE LINGUAGENS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "TENDENCIAS EM CC" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "TRABALHO DE GRADUACAO II" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "COMPILADORES E INTERPRETADORES" << "| 80" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao
}
void cc8() {
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tCIENCIAS DA COMPUTACAO      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tOITAVO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "APLICACOES PARA INTERNET" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "ORGANIZACOES E ARQUITETURA (EAD)" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "PROGRAMACAO DE COMPUTADORES" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "PENSAMENTO COMPUTACIONAL" << "| 60" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao
}

//################### ANALISE E DESENVOLVIMENTO DE SISTEMAS
void ads1() {
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tANALISE E DESENVOLVIMENTO DE SISTEMAS      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tPRIMEIRO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "OPTATIVA I" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "LIBRAS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "TECNICAS E DESENVOLVIMENTO ..." << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "EXTENSIONISTA I" << "| 70" << std::endl;
    std::cout << std::left << std::setw(40) << "MATEMATICA APLICADA (EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "QUALIDADE DE SOFTWARE (EAD)" << "| 40" << std::endl;
    std::cout << std::left << std::setw(40) << "PROGRAMACAO WEB" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "SISTEMAS OPERACIONAIS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "MODELAGEM DE DADOS (EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "ENGENHARIA DE SOFTWARE" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "SOCIEDADE E TERRITORIOS (EAD)" << "| 40" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao
}
void ads2() {
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tANALISE E DESENVOLVIMENTO DE SISTEMAS      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tSEGUNDO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "OPTATIVA II" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "OPTATIVA III" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "EXTENSIONISTA II" << "| 70" << std::endl;
    std::cout << std::left << std::setw(40) << "ESTRUTURAS DE DADOS (EAD)" << "| 40" << std::endl;
    std::cout << std::left << std::setw(40) << "ANALISE E PROJETO DE SISTEMAS I" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "COMPUTACAO EM NUVEM (EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "PROGRAMACAO ORIENTADA A OBJETOS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "BANCO DE DADOS" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "CLIENTE/SERVIDOR (EAD)" << "| 60" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao
}

void ads3() {
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tANALISE E DESENVOLVIMENTO DE SISTEMAS      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tTERCEIRO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "EXTENSIONISTA III" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "OPTATIVA IV" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "REDES DE COMPUTADORES" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "COMPUTACAO PARALELA (EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "PROGRAMACAO MOBILE " << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "BIG DATA(EAD)" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "ANALISE E PROJETO DE SISTEMAS II" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "JOGOS PARA INTERNET (EAD)" << "| 40" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao
}
void ads4() {
	
    system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tANALISE E DESENVOLVIMENTO DE SISTEMAS      " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tQUARTO SEMESTRE           " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "DISCIPLINA" << "| CARGA HORARIA" << std::endl;
    std::cout << std::left << std::setw(40) << "APLICACOES PARA INTERNET" << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "GESTAO ESTRATEGICA DE NEGOCIOS" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "EMPREENDEDORISMO (EAD)" << "| 80" << std::endl;
    std::cout << std::left << std::setw(40) << "ORGANIZACAO E ARQUITETURA ..." << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "PROGRAMACAO DE COMPUTADORES " << "| 60" << std::endl;
    std::cout << std::left << std::setw(40) << "MODELAGEM DE NEGOCIOS E REQUISITOS" << "| 60" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "Digite qualquer tecla para voltar: " << std::endl;
	std::cin.ignore(); // esoerar para o usuario digitar
    return; // sair da funcao
}


//############     SISTEMAS DA INFORMACAO #########################





/// ############## SELECIONAAR SEMESTRE #######################



void selecionarSemestreCC(){
	system("cls");
	char semestre;
	do{
	system("cls");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tBEM VINDO A AREA GRADE DE CC     " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tSEMESTRES DO CURSO       " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(20) << "SEMESTRE" << "| CODIGO" << std::endl;
    std::cout << std::left << std::setw(20) << "1o SEMESTRE" << "| 1" << std::endl;
    std::cout << std::left << std::setw(20) << "2o SEMESTRE" << "| 2" << std::endl;
    std::cout << std::left << std::setw(20) << "3o SEMESTRE" << "| 3" << std::endl;
    std::cout << std::left << std::setw(20) << "4o SEMESTRE" << "| 4" << std::endl;
    std::cout << std::left << std::setw(20) << "5o SEMESTRE" << "| 5" << std::endl;
    std::cout << std::left << std::setw(20) << "6o SEMESTRE" << "| 6" << std::endl;
    std::cout << std::left << std::setw(20) << "7o SEMESTRE" << "| 7" << std::endl;
    std::cout << std::left << std::setw(20) << "8o SEMESTRE" << "| 8" << std::endl;
    std::cout << std::left << std::setw(20) << "==S A I R==" << "| 0" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "digite um dos codigos para acessar as materias: " << std::endl;
    std::cin >> semestre;

	
	switch (semestre){
		case '1':
			system("cls");
			cc1();
			system("pause");
			break;
		case '2':
			system("cls");
			cc2();
			system("pause");
			break;
		case '3':
			system("cls");
			cc3();
			system("pause");
			break;
		case '4':
			system("cls");
			cc4();
			system("pause");
			break;
		case '5':
			system("cls");
			cc5();
			system("pause");
			break;
		case '6':
			system("cls");
			cc6();
			system("pause");
			break;
		case '7':
			system("cls");
			cc7();
			system("pause");
			break;
		case '8':
			system("cls");
			cc8();
			system("pause");
			break;
		case '0':
		    return;
		default:
			 std::cout << "Por favor, digite um valor valido" << std::endl;
	}
  }while (semestre != '0');
}
void selecionarSemestreADS(){
	system("cls");
	char semestre;
	do{
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tBEM VINDO A AREA GRADE DE ADS     " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\tSEMESTRES DO CURSO       " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(20) << "SEMESTRE" << "| CODIGO" << std::endl;
    std::cout << std::left << std::setw(20) << "1o SEMESTRE" << "| 1" << std::endl;
    std::cout << std::left << std::setw(20) << "2o SEMESTRE" << "| 2" << std::endl;
    std::cout << std::left << std::setw(20) << "3o SEMESTRE" << "| 3" << std::endl;
    std::cout << std::left << std::setw(20) << "4o SEMESTRE" << "| 4" << std::endl;
    std::cout << std::left << std::setw(20) << "==S A I R==" << "| 5" << std::endl;
    std::cout << '\n' << '\n';
    std::cout << "digite um dos codigos para acessar as materias: " << std::endl;
    std::cout << "PARA VOLTAR DIGITE '5': " << std::endl;
    std::cin >> semestre;
	
	switch (semestre){
		case '1':
			ads1();
			break;
		case '2':
			ads2();
			break;
		case '3':
			ads3();
			break;
		case '4':
			ads4();
			break;
		case '5': 
		    return;
			break;
		default:
			 std::cout << "Por favor, digite um valor valido" << std::endl;
	}
	}while(semestre != '5');
	//usar ponteiro para ter acesso ao metodo menuInicial
	 // criar uma funcao ponteiro
    void (*menuInicial)() = menuInicial;

    // chamar o metodo usando o ponteiro
    menuInicial();
}




//####################  MENU PRINCIPAL   ###########################  
void menuInicial(){
	 vector<Cadastro> registros;
    string nomeUsuario; // Declare a variável nomeUsuario aqui

    // Carregar registros do arquivo no início do programa
    carregarRegistros(registros);

    int escolha, op;
    string senha;

    do {
        cout << "\n    ===== .... INTRODUCAO .... =====:\n";
        cout << "\n";
        cout << "\n    ===== M E N U =====:\n";
        cout << "\n";
        cout << "1- Entrar\n";
        cout << "2- Cadastrar\n";
        cout << "3- Opcoes\n";
        cout << "4- Creditos\n";
        cout << "5. Sair\n";
        cout << "Escolha a opcao: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                system("cls");
                cout << "Login\n";
                cout << "Digite o nome de usuario: ";
                cin >> nomeUsuario; // Aqui vai o usuario cadastrado no nosso banco
                cout << "Digite a senha: ";
                esconderSenha(senha);

                if (usuarioCadastrado(registros, nomeUsuario, senha)) {
                	string curso;
                    cout << "Acesso permitido. Bem-vindo, " << nomeUsuario << "!\n";
                    
			        do {
			        std::cout << "Por favor, confirme seu curso: ";
			        cin >> curso;
			        
			        if (curso == "CC" || curso == "cc" ) {
			            selecionarSemestreCC();
			            break; // Exit the loop if a valid course is entered
			        } else if(curso == "ADS" || curso == "ads"){
			        	selecionarSemestreADS();
					}{
			            std::cout << "Por favor, digite uma opcao valida." << std::endl;
			        }
			    } while (true);
				}
				
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                cadastrarUsuario(registros);
                salvarRegistros(registros); // Salvar após cadastrar
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                cout << "1- Excluir\n";
                cout << "2- Relatorio\n";
                cout << "3- Voltar\n";
                cout << "Escolha a opcao: ";
                cin >> op;

                switch (op) {
                    case 1:
                        system("cls");
                        cout << "SENHA: ";
                        esconderSenha(senha);
                        if (senha == SENHA_MESTRA) {
                            excluirUsuario(registros);
                            salvarRegistros(registros); // Salvar após excluir
                        } else {
                            cout << "Senha incorreta. Acesso negado." << endl;
                        }
                        system("pause");
                        system("cls");
                        break;

                    case 2:
                        system("cls");
                        cout << "SENHA: ";
                        esconderSenha(senha);
                        if (senha == SENHA_MESTRA) {
                            gerarRelatorio(registros);
                        } else {
                            cout << "Senha incorreta. Acesso negado." << endl;
                        }
                        system("pause");
                        system("cls");
                        break;
            case 3:
            	system("cls");
            	system("pause");
            	system("cls");
            	break;			
				}
			break;
			
			case 4:
				system("cls");
				cout <<"Milene faz sua magica nos creditos s2\n";
				system("pause");
				system("cls");
				break;
				
			
            case 5:
                system("cls");
                cout << "Saindo do programa !\n";
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                cout << "  O P C A O   I N V A L I D A.\n";
                cout <<"\n";
                cout << " T E N T E   N O V A M E N T E\n";
                system("pause");
                system("cls");
                break;
        }
        cin.ignore();
    } while (escolha != 5);
    //usar ponteiro para ter acesso ao metodo menuInicial
	 // criar uma funcao ponteiro
    void (*menuInicial)() = menuInicial;

    // chamar o metodo usando o ponteiro
    menuInicial();
}


int main() {
   	menuInicial();
    return 0;
}



