#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    // =========================================================
    // SISTEMA DE REGISTRO E GESTÃO DE CONTAS BANCÁRIAS
    // ETAPA 1 - INF01
    // Sistema: BANCO INF01
    // =========================================================

    // ---------------------------------------------------------
    // VARIÁVEIS DA CONTA 1
    // ---------------------------------------------------------
    int numeroConta1 = 0;
    string nomeCliente1 = "";
    string cpf1 = "";
    int tipoConta1 = 0;
    double saldo1 = 0.0;
    bool contaAtiva1 = false;

    // ---------------------------------------------------------
    // VARIÁVEIS DA CONTA 2
    // ---------------------------------------------------------
    int numeroConta2 = 0;
    string nomeCliente2 = "";
    string cpf2 = "";
    int tipoConta2 = 0;
    double saldo2 = 0.0;
    bool contaAtiva2 = false;

    // ---------------------------------------------------------
    // VARIÁVEIS DA CONTA 3
    // ---------------------------------------------------------
    int numeroConta3 = 0;
    string nomeCliente3 = "";
    string cpf3 = "";
    int tipoConta3 = 0;
    double saldo3 = 0.0;
    bool contaAtiva3 = false;

    // ---------------------------------------------------------
    // VARIÁVEIS DA CONTA 4
    // ---------------------------------------------------------
    int numeroConta4 = 0;
    string nomeCliente4 = "";
    string cpf4 = "";
    int tipoConta4 = 0;
    double saldo4 = 0.0;
    bool contaAtiva4 = false;

    // ---------------------------------------------------------
    // VARIÁVEIS DA CONTA 5
    // ---------------------------------------------------------
    int numeroConta5 = 0;
    string nomeCliente5 = "";
    string cpf5 = "";
    int tipoConta5 = 0;
    double saldo5 = 0.0;
    bool contaAtiva5 = false;

    // Variáveis auxiliares
    int opcao;
    int contaEscolhida;
    bool contaEncontrada;

    // ---------------------------------------------------------
    // MENU PRINCIPAL
    // ---------------------------------------------------------
    do {

        cout << "\n";
        cout << "==========================================" << endl;
        cout << "              BANCO INF01                 " << endl;
        cout << "==========================================" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair" << endl;
        cout << "==========================================" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            // =================================================
            // OPÇÃO 1 - CADASTRAR CONTA
            // =================================================
            case 1:

                // Verifica qual das 5 posições está disponível
                if (numeroConta1 == 0) {
                    contaEscolhida = 1;
                }
                else if (numeroConta2 == 0) {
                    contaEscolhida = 2;
                }
                else if (numeroConta3 == 0) {
                    contaEscolhida = 3;
                }
                else if (numeroConta4 == 0) {
                    contaEscolhida = 4;
                }
                else if (numeroConta5 == 0) {
                    contaEscolhida = 5;
                }
                else {
                    contaEscolhida = 0;
                }

                if (contaEscolhida == 0) {

                    cout << "\nNao ha espaco para novas contas." << endl;
                    cout << "Limite de 5 contas atingido." << endl;

                }
                else {

                    cout << "\n==========================================" << endl;
                    cout << "          CADASTRO DE CONTA               " << endl;
                    cout << "==========================================" << endl;

                    int novoNumero;
                    string novoNome;
                    string novoCpf;
                    int novoTipo;
                    double novoSaldo;

                    // Validação do número da conta
                    do {
                        cout << "Numero da conta: ";
                        cin >> novoNumero;

                        if (novoNumero <= 0) {
                            cout << "Erro: o numero da conta deve ser maior que zero." << endl;
                        }

                    } while (novoNumero <= 0);

                    // Verifica se o número já existe
                    bool numeroExiste = false;

                    if (numeroConta1 == novoNumero ||
                        numeroConta2 == novoNumero ||
                        numeroConta3 == novoNumero ||
                        numeroConta4 == novoNumero ||
                        numeroConta5 == novoNumero) {

                        numeroExiste = true;
                    }

                    if (numeroExiste) {

                        cout << "Erro: esse numero de conta ja esta cadastrado." << endl;

                    }
                    else {

                        cin.ignore();

                        cout << "Nome do titular: ";
                        getline(cin, novoNome);

                        cout << "CPF do titular: ";
                        getline(cin, novoCpf);

                        // Validação do tipo da conta
                        do {
                            cout << "Tipo da conta:" << endl;
                            cout << "1 - Corrente" << endl;
                            cout << "2 - Poupanca" << endl;
                            cout << "Escolha: ";
                            cin >> novoTipo;

                            if (novoTipo != 1 && novoTipo != 2) {
                                cout << "Erro: escolha apenas 1 ou 2." << endl;
                            }

                        } while (novoTipo != 1 && novoTipo != 2);

                        // Validação do saldo
                        do {
                            cout << "Saldo inicial: R$ ";
                            cin >> novoSaldo;

                            if (novoSaldo < 0) {
                                cout << "Erro: o saldo nao pode ser negativo." << endl;
                            }

                        } while (novoSaldo < 0);

                        // -----------------------------------------
                        // Armazena os dados na conta disponível
                        // -----------------------------------------

                        if (contaEscolhida == 1) {

                            numeroConta1 = novoNumero;
                            nomeCliente1 = novoNome;
                            cpf1 = novoCpf;
                            tipoConta1 = novoTipo;
                            saldo1 = novoSaldo;
                            contaAtiva1 = true;

                        }
                        else if (contaEscolhida == 2) {

                            numeroConta2 = novoNumero;
                            nomeCliente2 = novoNome;
                            cpf2 = novoCpf;
                            tipoConta2 = novoTipo;
                            saldo2 = novoSaldo;
                            contaAtiva2 = true;

                        }
                        else if (contaEscolhida == 3) {

                            numeroConta3 = novoNumero;
                            nomeCliente3 = novoNome;
                            cpf3 = novoCpf;
                            tipoConta3 = novoTipo;
                            saldo3 = novoSaldo;
                            contaAtiva3 = true;

                        }
                        else if (contaEscolhida == 4) {

                            numeroConta4 = novoNumero;
                            nomeCliente4 = novoNome;
                            cpf4 = novoCpf;
                            tipoConta4 = novoTipo;
                            saldo4 = novoSaldo;
                            contaAtiva4 = true;

                        }
                        else if (contaEscolhida == 5) {

                            numeroConta5 = novoNumero;
                            nomeCliente5 = novoNome;
                            cpf5 = novoCpf;
                            tipoConta5 = novoTipo;
                            saldo5 = novoSaldo;
                            contaAtiva5 = true;
                        }

                        cout << "\nConta cadastrada com sucesso!" << endl;
                        cout << "Numero da conta: " << novoNumero << endl;
                    }
                }

                break;

            // =================================================
            // OPÇÃO 2 - CONSULTAR CONTA
            // =================================================
            case 2:

                cout << "\n==========================================" << endl;
                cout << "             CONSULTAR CONTA              " << endl;
                cout << "==========================================" << endl;

                cout << "Digite o numero da conta: ";
                cin >> contaEscolhida;

                contaEncontrada = false;

                if (numeroConta1 == contaEscolhida) {

                    cout << "\nConta encontrada!" << endl;
                    cout << "Numero: " << numeroConta1 << endl;
                    cout << "Titular: " << nomeCliente1 << endl;
                    cout << "CPF: " << cpf1 << endl;

                    if (tipoConta1 == 1)
                        cout << "Tipo: Corrente" << endl;
                    else
                        cout << "Tipo: Poupanca" << endl;

                    cout << fixed << setprecision(2);
                    cout << "Saldo: R$ " << saldo1 << endl;

                    if (contaAtiva1)
                        cout << "Status: ATIVA" << endl;
                    else
                        cout << "Status: INATIVA" << endl;

                    contaEncontrada = true;
                }

                else if (numeroConta2 == contaEscolhida) {

                    cout << "\nConta encontrada!" << endl;
                    cout << "Numero: " << numeroConta2 << endl;
                    cout << "Titular: " << nomeCliente2 << endl;
                    cout << "CPF: " << cpf2 << endl;

                    if (tipoConta2 == 1)
                        cout << "Tipo: Corrente" << endl;
                    else
                        cout << "Tipo: Poupanca" << endl;

                    cout << fixed << setprecision(2);
                    cout << "Saldo: R$ " << saldo2 << endl;

                    if (contaAtiva2)
                        cout << "Status: ATIVA" << endl;
                    else
                        cout << "Status: INATIVA" << endl;

                    contaEncontrada = true;
                }

                else if (numeroConta3 == contaEscolhida) {

                    cout << "\nConta encontrada!" << endl;
                    cout << "Numero: " << numeroConta3 << endl;
                    cout << "Titular: " << nomeCliente3 << endl;
                    cout << "CPF: " << cpf3 << endl;

                    if (tipoConta3 == 1)
                        cout << "Tipo: Corrente" << endl;
                    else
                        cout << "Tipo: Poupanca" << endl;

                    cout << fixed << setprecision(2);
                    cout << "Saldo: R$ " << saldo3 << endl;

                    if (contaAtiva3)
                        cout << "Status: ATIVA" << endl;
                    else
                        cout << "Status: INATIVA" << endl;

                    contaEncontrada = true;
                }

                else if (numeroConta4 == contaEscolhida) {

                    cout << "\nConta encontrada!" << endl;
                    cout << "Numero: " << numeroConta4 << endl;
                    cout << "Titular: " << nomeCliente4 << endl;
                    cout << "CPF: " << cpf4 << endl;

                    if (tipoConta4 == 1)
                        cout << "Tipo: Corrente" << endl;
                    else
                        cout << "Tipo: Poupanca" << endl;

                    cout << fixed << setprecision(2);
                    cout << "Saldo: R$ " << saldo4 << endl;

                    if (contaAtiva4)
                        cout << "Status: ATIVA" << endl;
                    else
                        cout << "Status: INATIVA" << endl;

                    contaEncontrada = true;
                }

                else if (numeroConta5 == contaEscolhida) {

                    cout << "\nConta encontrada!" << endl;
                    cout << "Numero: " << numeroConta5 << endl;
                    cout << "Titular: " << nomeCliente5 << endl;
                    cout << "CPF: " << cpf5 << endl;

                    if (tipoConta5 == 1)
                        cout << "Tipo: Corrente" << endl;
                    else
                        cout << "Tipo: Poupanca" << endl;

                    cout << fixed << setprecision(2);
                    cout << "Saldo: R$ " << saldo5 << endl;

                    if (contaAtiva5)
                        cout << "Status: ATIVA" << endl;
                    else
                        cout << "Status: INATIVA" << endl;

                    contaEncontrada = true;
                }

                if (!contaEncontrada) {
                    cout << "\nConta nao encontrada." << endl;
                }

                break;

            // =================================================
            // OPÇÃO 3 - VERIFICAR SALDO
            // =================================================
            case 3:

                cout << "\n==========================================" << endl;
                cout << "              VERIFICAR SALDO             " << endl;
                cout << "==========================================" << endl;

                cout << "Digite o numero da conta: ";
                cin >> contaEscolhida;

                contaEncontrada = false;

                if (numeroConta1 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva1) {
                        cout << fixed << setprecision(2);
                        cout << "Saldo da conta: R$ " << saldo1 << endl;
                    }
                    else {
                        cout << "Operacao nao permitida." << endl;
                        cout << "A conta esta inativa." << endl;
                    }
                }

                else if (numeroConta2 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva2) {
                        cout << fixed << setprecision(2);
                        cout << "Saldo da conta: R$ " << saldo2 << endl;
                    }
                    else {
                        cout << "Operacao nao permitida." << endl;
                        cout << "A conta esta inativa." << endl;
                    }
                }

                else if (numeroConta3 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva3) {
                        cout << fixed << setprecision(2);
                        cout << "Saldo da conta: R$ " << saldo3 << endl;
                    }
                    else {
                        cout << "Operacao nao permitida." << endl;
                        cout << "A conta esta inativa." << endl;
                    }
                }

                else if (numeroConta4 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva4) {
                        cout << fixed << setprecision(2);
                        cout << "Saldo da conta: R$ " << saldo4 << endl;
                    }
                    else {
                        cout << "Operacao nao permitida." << endl;
                        cout << "A conta esta inativa." << endl;
                    }
                }

                else if (numeroConta5 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva5) {
                        cout << fixed << setprecision(2);
                        cout << "Saldo da conta: R$ " << saldo5 << endl;
                    }
                    else {
                        cout << "Operacao nao permitida." << endl;
                        cout << "A conta esta inativa." << endl;
                    }
                }

                if (!contaEncontrada) {
                    cout << "Conta nao encontrada." << endl;
                }

                break;

            // =================================================
            // OPÇÃO 4 - ALTERAR TIPO DA CONTA
            // =================================================
            case 4:

                cout << "\n==========================================" << endl;
                cout << "          ALTERAR TIPO DA CONTA            " << endl;
                cout << "==========================================" << endl;

                cout << "Digite o numero da conta: ";
                cin >> contaEscolhida;

                contaEncontrada = false;

                if (numeroConta1 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva1) {

                        do {
                            cout << "Novo tipo:" << endl;
                            cout << "1 - Corrente" << endl;
                            cout << "2 - Poupanca" << endl;
                            cout << "Escolha: ";
                            cin >> tipoConta1;

                            if (tipoConta1 != 1 && tipoConta1 != 2) {
                                cout << "Tipo invalido." << endl;
                            }

                        } while (tipoConta1 != 1 && tipoConta1 != 2);

                        cout << "Tipo da conta alterado com sucesso!" << endl;

                    }
                    else {
                        cout << "Operacao nao permitida. Conta inativa." << endl;
                    }
                }

                else if (numeroConta2 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva2) {

                        do {
                            cout << "Novo tipo:" << endl;
                            cout << "1 - Corrente" << endl;
                            cout << "2 - Poupanca" << endl;
                            cout << "Escolha: ";
                            cin >> tipoConta2;

                            if (tipoConta2 != 1 && tipoConta2 != 2) {
                                cout << "Tipo invalido." << endl;
                            }

                        } while (tipoConta2 != 1 && tipoConta2 != 2);

                        cout << "Tipo da conta alterado com sucesso!" << endl;

                    }
                    else {
                        cout << "Operacao nao permitida. Conta inativa." << endl;
                    }
                }

                else if (numeroConta3 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva3) {

                        do {
                            cout << "Novo tipo:" << endl;
                            cout << "1 - Corrente" << endl;
                            cout << "2 - Poupanca" << endl;
                            cout << "Escolha: ";
                            cin >> tipoConta3;

                            if (tipoConta3 != 1 && tipoConta3 != 2) {
                                cout << "Tipo invalido." << endl;
                            }

                        } while (tipoConta3 != 1 && tipoConta3 != 2);

                        cout << "Tipo da conta alterado com sucesso!" << endl;

                    }
                    else {
                        cout << "Operacao nao permitida. Conta inativa." << endl;
                    }
                }

                else if (numeroConta4 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva4) {

                        do {
                            cout << "Novo tipo:" << endl;
                            cout << "1 - Corrente" << endl;
                            cout << "2 - Poupanca" << endl;
                            cout << "Escolha: ";
                            cin >> tipoConta4;

                            if (tipoConta4 != 1 && tipoConta4 != 2) {
                                cout << "Tipo invalido." << endl;
                            }

                        } while (tipoConta4 != 1 && tipoConta4 != 2);

                        cout << "Tipo da conta alterado com sucesso!" << endl;

                    }
                    else {
                        cout << "Operacao nao permitida. Conta inativa." << endl;
                    }
                }

                else if (numeroConta5 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva5) {

                        do {
                            cout << "Novo tipo:" << endl;
                            cout << "1 - Corrente" << endl;
                            cout << "2 - Poupanca" << endl;
                            cout << "Escolha: ";
                            cin >> tipoConta5;

                            if (tipoConta5 != 1 && tipoConta5 != 2) {
                                cout << "Tipo invalido." << endl;
                            }

                        } while (tipoConta5 != 1 && tipoConta5 != 2);

                        cout << "Tipo da conta alterado com sucesso!" << endl;

                    }
                    else {
                        cout << "Operacao nao permitida. Conta inativa." << endl;
                    }
                }

                if (!contaEncontrada) {
                    cout << "Conta nao encontrada." << endl;
                }

                break;

            // =================================================
            // OPÇÃO 5 - ATIVAR / DESATIVAR CONTA
            // =================================================
            case 5:

                cout << "\n==========================================" << endl;
                cout << "         ATIVAR / DESATIVAR CONTA         " << endl;
                cout << "==========================================" << endl;

                cout << "Digite o numero da conta: ";
                cin >> contaEscolhida;

                contaEncontrada = false;

                if (numeroConta1 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva1) {
                        contaAtiva1 = false;
                        cout << "Conta desativada com sucesso!" << endl;
                    }
                    else {
                        contaAtiva1 = true;
                        cout << "Conta ativada com sucesso!" << endl;
                    }
                }

                else if (numeroConta2 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva2) {
                        contaAtiva2 = false;
                        cout << "Conta desativada com sucesso!" << endl;
                    }
                    else {
                        contaAtiva2 = true;
                        cout << "Conta ativada com sucesso!" << endl;
                    }
                }

                else if (numeroConta3 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva3) {
                        contaAtiva3 = false;
                        cout << "Conta desativada com sucesso!" << endl;
                    }
                    else {
                        contaAtiva3 = true;
                        cout << "Conta ativada com sucesso!" << endl;
                    }
                }

                else if (numeroConta4 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva4) {
                        contaAtiva4 = false;
                        cout << "Conta desativada com sucesso!" << endl;
                    }
                    else {
                        contaAtiva4 = true;
                        cout << "Conta ativada com sucesso!" << endl;
                    }
                }

                else if (numeroConta5 == contaEscolhida) {

                    contaEncontrada = true;

                    if (contaAtiva5) {
                        contaAtiva5 = false;
                        cout << "Conta desativada com sucesso!" << endl;
                    }
                    else {
                        contaAtiva5 = true;
                        cout << "Conta ativada com sucesso!" << endl;
                    }
                }

                if (!contaEncontrada) {
                    cout << "Conta nao encontrada." << endl;
                }

                break;

            // =================================================
            // OPÇÃO 6 - SAIR
            // =================================================
            case 6:

                cout << "\n==========================================" << endl;
                cout << "      Obrigado por utilizar o BANCO INF01" << endl;
                cout << "              Programa encerrado.         " << endl;
                cout << "==========================================" << endl;

                break;

            // =================================================
            // OPÇÃO INVÁLIDA
            // =================================================
            default:

                cout << "\nOpcao invalida!" << endl;
                cout << "Escolha uma opcao de 1 a 6." << endl;

        }

    } while (opcao != 6);

    return 0;
}