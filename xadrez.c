#include <stdio.h>
// NIVEL MESTRE - MOVIMENTANDO PEÇAS DO JOGO XADREZ
// ====================================================================
// CONSTANTES GLOBAIS
// ====================================================================

// Torre: 5 casas para a direita (Recursividade)
#define CASAS_TORRE 5

// Rainha: 8 casas para a esquerda (Recursividade)
#define CASAS_RAINHA 8

// Bispo: 5 casas diagonal (Recursividade + Loops Aninhados)
#define CASAS_BISPO 5 

// Cavalo: L (2 Cima, 1 Direita) (Loops Aninhados Complexos)
#define CAVALO_CIMA 2
#define CAVALO_DIREITA 1

// ====================================================================
// PROTÓTIPOS DAS FUNÇÕES RECURSIVAS E COMPLEXAS
// ====================================================================

// Recursividade para movimentos simples
void mover_rainha_recursivo(int casas_restantes);
void mover_torre_recursivo(int casas_restantes);

// Recursividade combinada com loops aninhados
void mover_bispo_recursivo_aninhado(int casas_restantes);

// Loops aninhados complexos
void mover_cavalo_complexo();

// ====================================================================
// FUNÇÃO PRINCIPAL (MAIN)
// ====================================================================

int main() {
    printf("==================================================\n");
    printf("        SIMULACAO DE MOVIMENTO DE XADREZ          \n");
    printf("              (Nivel MESTRE)                      \n");
    printf("==================================================\n\n");

    // 1. Simulação da Rainha usando RECURSIVIDADE
    printf("--- 1. Movimento da RAINHA (8 casas para a Esquerda - RECURSIVO) ---\n");
    mover_rainha_recursivo(CASAS_RAINHA);
    printf("Rainha completou o movimento recursivo.\n\n");
    
    // 2. Simulação da Torre usando RECURSIVIDADE
    printf("--- 2. Movimento da TORRE (5 casas para a Direita - RECURSIVO) ---\n");
    mover_torre_recursivo(CASAS_TORRE);
    printf("Torre completou o movimento recursivo.\n\n");

    // 3. Simulação do Bispo usando RECURSIVIDADE E LOOPS ANINHADOS
    printf("--- 3. Movimento do BISPO (5 casas Diagonal Cima/Direita - RECURSIVO & ANINHADO) ---\n");
    mover_bispo_recursivo_aninhado(CASAS_BISPO);
    printf("Bispo completou o movimento complexo.\n\n");
    
    // 4. Simulação do Cavalo usando LOOPS ANINHADOS COMPLEXOS
    printf("--- 4. Movimento do CAVALO (L: 2 Cima, 1 Direita - LOOPS COMPLEXOS) ---\n");
    mover_cavalo_complexo();
    printf("Cavalo completou o movimento complexo em 'L'.\n\n");

    printf("\n==================================================\n");
    printf("Simulacao Mestre Concluida.\n");
    
    return 0;
}

// ====================================================================
// IMPLEMENTAÇÃO DA RECURSIVIDADE
// ====================================================================

/**
 * Movimento da Rainha (Esquerda): Funcao recursiva simples.
 * A condicao de parada e quando casas_restantes <= 0.
 */
void mover_rainha_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return; // Condicao de parada da recursao
    }
    
    printf("Esquerda\n");
    
    // Chamada recursiva com o problema reduzido
    mover_rainha_recursivo(casas_restantes - 1);
}

/**
 * Movimento da Torre (Direita): Funcao recursiva simples.
 * A condicao de parada e quando casas_restantes <= 0.
 */
void mover_torre_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return; // Condicao de parada
    }
    
    printf("Direita\n");
    
    // Chamada recursiva com o problema reduzido
    mover_torre_recursivo(casas_restantes - 1);
}

// ====================================================================
// IMPLEMENTAÇÃO RECURSIVA COM LOOPS ANINHADOS
// ====================================================================

/**
 * Movimento do Bispo (Diagonal Cima, Direita): Recursividade + Loops Aninhados.
 * A recursividade controla o numero de casas (a diagonal).
 * Os loops aninhados simulam os componentes (Cima e Direita) de cada passo diagonal.
 */
void mover_bispo_recursivo_aninhado(int casas_restantes) {
    int vertical;
    int horizontal;
    
    if (casas_restantes <= 0) {
        return; // Condicao de parada da recursao
    }

    // Loop externo (Movimento Vertical: Cima)
    for (vertical = 0; vertical < 1; vertical++) {
        
        // Loop interno (Movimento Horizontal: Direita)
        // O laco horizontal so executa se o laco vertical nao for interrompido
        for (horizontal = 0; horizontal < 1; horizontal++) {
            printf("Cima, Direita\n");
            // Nota: break ou continue nao sao necessarios aqui,
            // mas estao disponiveis para controle complexo.
        }
    }
    
    // Chamada recursiva para o proximo passo da diagonal
    mover_bispo_recursivo_aninhado(casas_restantes - 1);
}

// ====================================================================
// IMPLEMENTAÇÃO DE LOOPS ANINHADOS COMPLEXOS
// ====================================================================

/**
 * Movimento do Cavalo (L: 2 Cima, 1 Direita): Loops aninhados complexos.
 * O laco externo controla a direcao principal (Cima).
 * O laco interno controla a direcao perpendicular (Direita).
 * Usa 'break' e 'continue' para controle de fluxo.
 */
void mover_cavalo_complexo() {
    int i; 
    int j;
    
    // Loop principal: Simula o movimento de 2 casas na primeira direcao (Cima)
    // Multipla condicao: i deve ser menor que o total E a proxima direcao ainda nao deve ter sido executada.
    for (i = 0; i < CAVALO_CIMA; i++) {
        
        printf("Cima\n");
        
        // Exemplo de 'continue': Simula um salto em uma casa especifica
        if (i == 0) {
            // Continua para a proxima iteracao, sem executar o bloco 'L' interno
            continue; 
        }

        // Loop aninhado: Simula a direcao perpendicular (Direita),
        // executado apenas uma vez após as primeiras 2 casas verticais (simulação).
        // Na prática, o Cavalo completa o L em um único movimento, mas 
        // a simulação exige a separação das etapas.
        for (j = 0; j < CAVALO_DIREITA; j++) {
            printf("Direita\n");
            
            // Exemplo de 'break': Garante que a direcao perpendicular so seja
            // executada uma vez e encerra o loop interno imediatamente.
            if (j == 0) {
                break; 
            }
        }
    }
return 0;
}
