#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    // =========================================================
    // SISTEMA DE REGISTRO E GESTAO DE CONTAS BANCARIAS
    // ETAPA 2 - INF101
    // =========================================================

    // ---------------------------------------------------------
    // DADOS DAS CONTAS (arrays paralelos: o indice i liga tudo)
    // numeroConta[i], nomeCliente[i], saldo[i]... = mesma conta
    // ---------------------------------------------------------
    const int MAX_CONTAS = 100;

    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];

    int quantidadeContas = 0; // quantas contas existem (e proxima posicao livre)

    // ---------------------------------------------------------
    // HISTORICO DE MOVIMENTACOES
    // Cada posicao i representa UMA movimentacao
    // ---------------------------------------------------------
    const int MAX_MOVIMENTACOES = 500;

    int contaMovimentacao[MAX_MOVIMENTACOES];   // numero da conta
    char tipoMovimentacao[MAX_MOVIMENTACOES];   // 'D' deposito, 'S' saque
    double valorMovimentacao[MAX_MOVIMENTACOES];

    int quantidadeMovimentacoes = 0;

    // Formata valores em reais com 2 casas decimais
    cout << fixed << setprecision(2);

    int opcao;

    // ---------------------------------------------------------
    // MENU PRINCIPAL: repete ate o usuario digitar 0
    // ---------------------------------------------------------
    do {
        cout << "\n========== BANCO INF101 ==========\n";
        cout << "1 - Cadastrar conta\n";
        cout << "2 - Listar contas\n";
        cout << "3 - Consultar conta\n";
        cout << "4 - Depositar\n";
        cout << "5 - Sacar\n";
        cout << "6 - Transferir\n";
        cout << "7 - Extrato\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {

        // =====================================================
        // 1 - CADASTRAR CONTA
        // =====================================================
        case 1: {
            // Verifica se ainda ha espaco ANTES de gravar
            if (quantidadeContas >= MAX_CONTAS) {
                cout << "Limite de contas atingido!\n";
                break;
            }

            int numero;
            cout << "Numero da conta: ";
            cin >> numero;

            // Nao permite numero de conta repetido
            bool existe = false;
            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numero) {
                    existe = true;
                }
            }
            if (existe) {
                cout << "Ja existe uma conta com esse numero!\n";
                break;
            }

            // Grava na proxima posicao livre (quantidadeContas)
            numeroConta[quantidadeContas] = numero;

        
            cout << "Nome do cliente: ";
            getline(cin, nomeCliente[quantidadeContas]);

            cout << "CPF: ";
            getline(cin, cpf[quantidadeContas]);

            cout << "Tipo da conta (1 - Corrente, 2 - Poupanca): ";
            cin >> tipoConta[quantidadeContas];

            double saldoInicial;
            cout << "Saldo inicial: R$ ";
            cin >> saldoInicial;
            if (saldoInicial < 0) {
                saldoInicial = 0; // nao aceita saldo inicial negativo
            }
            saldo[quantidadeContas] = saldoInicial;

            contaAtiva[quantidadeContas] = true;

            quantidadeContas++; // so incrementa no final, com tudo preenchido

            cout << "Conta cadastrada com sucesso!\n";
            break;
        }

        // =====================================================
        // 2 - LISTAR CONTAS
        // =====================================================
        case 2: {
            if (quantidadeContas == 0) {
                cout << "Nenhuma conta cadastrada.\n";
                break;
            }

            cout << "\n--- Contas cadastradas ---\n";
            // vai de 0 ate quantidadeContas-1 (so posicoes preenchidas)
            for (int i = 0; i < quantidadeContas; i++) {
                cout << "Conta: " << numeroConta[i]
                     << " | Cliente: " << nomeCliente[i]
                     << " | CPF: " << cpf[i]
                     << " | Tipo: " << (tipoConta[i] == 1 ? "Corrente" : "Poupanca")
                     << " | Saldo: R$ " << saldo[i]
                     << " | " << (contaAtiva[i] ? "Ativa" : "Inativa") << endl;
            }
            break;
        }

        // =====================================================
        // 3 - CONSULTAR CONTA PELO NUMERO
        // =====================================================
        case 3: {
            int numero, indice = -1; // -1 = "nao encontrada"
            cout << "Numero da conta: ";
            cin >> numero;

            // Busca linear
            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numero) {
                    indice = i;
                    break;
                }
            }

            if (indice == -1) {
                cout << "Conta nao encontrada!\n";
                break;
            }

            cout << "\n--- Dados da conta ---\n";
            cout << "Conta: " << numeroConta[indice] << endl;
            cout << "Cliente: " << nomeCliente[indice] << endl;
            cout << "CPF: " << cpf[indice] << endl;
            cout << "Tipo: " << (tipoConta[indice] == 1 ? "Corrente" : "Poupanca") << endl;
            cout << "Saldo: R$ " << saldo[indice] << endl;
            cout << "Situacao: " << (contaAtiva[indice] ? "Ativa" : "Inativa") << endl;
            break;
        }

        // =====================================================
        // 4 - DEPOSITO
        // =====================================================
        case 4: {
            int numero, indice = -1;
            cout << "Numero da conta: ";
            cin >> numero;

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numero) {
                    indice = i;
                    break;
                }
            }

            // Validacoes: valida tudo ANTES de alterar qualquer coisa
            if (indice == -1) {
                cout << "Conta nao encontrada!\n";
                break;
            }
            if (!contaAtiva[indice]) {
                cout << "Conta inativa!\n";
                break;
            }

            double valor;
            cout << "Valor do deposito: R$ ";
            cin >> valor;

            if (valor <= 0) {
                cout << "Valor invalido! Deve ser positivo.\n";
                break;
            }
            if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                cout << "Historico de movimentacoes cheio!\n";
                break;
            }

            // Atualiza o saldo
            saldo[indice] = saldo[indice] + valor;

            // Registra a movimentacao no historico
            contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
            tipoMovimentacao[quantidadeMovimentacoes] = 'D';
            valorMovimentacao[quantidadeMovimentacoes] = valor;
            quantidadeMovimentacoes++;

            cout << "Deposito realizado! Novo saldo: R$ " << saldo[indice] << endl;
            break;
        }

        // =====================================================
        // 5 - SAQUE
        // =====================================================
        case 5: {
            int numero, indice = -1;
            cout << "Numero da conta: ";
            cin >> numero;

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numero) {
                    indice = i;
                    break;
                }
            }

            if (indice == -1) {
                cout << "Conta nao encontrada!\n";
                break;
            }
            if (!contaAtiva[indice]) {
                cout << "Conta inativa!\n";
                break;
            }

            double valor;
            cout << "Valor do saque: R$ ";
            cin >> valor;

            if (valor <= 0) {
                cout << "Valor invalido! Deve ser positivo.\n";
                break;
            }
            // Verifica saldo suficiente (obrigatorio no enunciado)
            if (valor > saldo[indice]) {
                cout << "Saldo insuficiente! Saldo atual: R$ " << saldo[indice] << endl;
                break;
            }
            if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                cout << "Historico de movimentacoes cheio!\n";
                break;
            }

            saldo[indice] = saldo[indice] - valor;

            contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
            tipoMovimentacao[quantidadeMovimentacoes] = 'S';
            valorMovimentacao[quantidadeMovimentacoes] = valor;
            quantidadeMovimentacoes++;

            cout << "Saque realizado! Novo saldo: R$ " << saldo[indice] << endl;
            break;
        }

        // =====================================================
        // 6 - TRANSFERENCIA ENTRE DUAS CONTAS
        // =====================================================
        case 6: {
            int numOrigem, numDestino;
            int indiceOrigem = -1, indiceDestino = -1;

            cout << "Numero da conta de origem: ";
            cin >> numOrigem;
            cout << "Numero da conta de destino: ";
            cin >> numDestino;

            // Procura as DUAS contas
            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numOrigem) {
                    indiceOrigem = i;
                }
                if (numeroConta[i] == numDestino) {
                    indiceDestino = i;
                }
            }

            // As duas precisam existir
            if (indiceOrigem == -1 || indiceDestino == -1) {
                cout << "Conta de origem ou de destino nao encontrada!\n";
                break;
            }
            // Origem e destino devem ser diferentes
            if (indiceOrigem == indiceDestino) {
                cout << "Origem e destino devem ser contas diferentes!\n";
                break;
            }
            // As duas precisam estar ativas
            if (!contaAtiva[indiceOrigem] || !contaAtiva[indiceDestino]) {
                cout << "Uma das contas esta inativa!\n";
                break;
            }

            double valor;
            cout << "Valor da transferencia: R$ ";
            cin >> valor;

            if (valor <= 0) {
                cout << "Valor invalido! Deve ser positivo.\n";
                break;
            }
            if (valor > saldo[indiceOrigem]) {
                cout << "Saldo insuficiente na conta de origem!\n";
                break;
            }
            // Precisa haver espaco para DOIS registros no historico
            if (quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES) {
                cout << "Historico sem espaco para registrar a transferencia!\n";
                break;
            }

            // Atualiza os dois saldos
            saldo[indiceOrigem] = saldo[indiceOrigem] - valor;
            saldo[indiceDestino] = saldo[indiceDestino] + valor;

            // Registro 1: SAIDA na conta de origem
            contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
            tipoMovimentacao[quantidadeMovimentacoes] = 'S';
            valorMovimentacao[quantidadeMovimentacoes] = valor;
            quantidadeMovimentacoes++;

            // Registro 2: ENTRADA na conta de destino
            contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
            tipoMovimentacao[quantidadeMovimentacoes] = 'D';
            valorMovimentacao[quantidadeMovimentacoes] = valor;
            quantidadeMovimentacoes++;

            cout << "Transferencia realizada!\n";
            cout << "Saldo origem (" << numeroConta[indiceOrigem] << "): R$ "
                 << saldo[indiceOrigem] << endl;
            cout << "Saldo destino (" << numeroConta[indiceDestino] << "): R$ "
                 << saldo[indiceDestino] << endl;
            break;
        }

        // =====================================================
        // 7 - EXTRATO
        // =====================================================
        case 7: {
            int numero, indice = -1;
            cout << "Numero da conta: ";
            cin >> numero;

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numero) {
                    indice = i;
                    break;
                }
            }

            if (indice == -1) {
                cout << "Conta nao encontrada!\n";
                break;
            }

            cout << "\n--- Extrato da conta " << numeroConta[indice]
                 << " (" << nomeCliente[indice] << ") ---\n";

            bool temMovimentacao = false;

            // Percorre TODO o historico, mostrando so o que e desta conta
            for (int i = 0; i < quantidadeMovimentacoes; i++) {
                if (contaMovimentacao[i] == numeroConta[indice]) {
                    temMovimentacao = true;
                    if (tipoMovimentacao[i] == 'D') {
                        cout << "Deposito: R$ " << valorMovimentacao[i] << endl;
                    }
                    else if (tipoMovimentacao[i] == 'S') {
                        cout << "Saque: R$ " << valorMovimentacao[i] << endl;
                    }
                }
            }

            if (!temMovimentacao) {
                cout << "Nenhuma movimentacao registrada.\n";
            }
            cout << "Saldo atual: R$ " << saldo[indice] << endl;
            break;
        }

        // =====================================================
        // 0 - SAIR / opcao invalida
        // =====================================================
        case 0:
            cout << "Encerrando o sistema...\n";
            break;

        default:
            cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}
