// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Lucas Costa Ribeiro Fiscina
//  email:lucas.cribeiro@hotmail.com
//  Matrícula: 20251160030
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

char toLower  (char c){
  if (c >= 'A' && c <= 'Z') {
    return c +32;
  }
  return c;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
 int datavalida = 1;

 DataQuebrada dq = quebraData(data);
 datavalida = dq.valido;
 if (datavalida)
 return 1;
 else
 return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      DataQuebrada dtIni = quebraData (datainicial);
      DataQuebrada dtFim = quebraData (datafinal);

      if (dtIni.iAno > dtFim.iAno || (dtIni.iAno == dtFim.iAno & dtIni.iMes > dtFim.iMes)
    || (dtIni.iAno == dtFim.iAno && dtIni.iMes == dtFim.iMes && dtIni.iDia > dtFim.iDia) ){
      dma.retorno = 4;
      return dma;
    }

    dma.qtdAnos = dtFim.iAno - dtIni.iAno;
    dma.qtdMeses = dtFim.iMes - dtIni.iMes;
    dma.qtdDias = dtFim.iDia - dtIni.iDia;

    if (dma.qtdDias < 0){
      dma.qtdMeses--;
      int mesAnterior = dtFim.iMes - 1;
      int anoRef = dtFim.iAno;
      if(mesAnterior == 0){
        mesAnterior = 12;
        anoRef--;
      }
      int diasMesAnterior;
      if (mesAnterior == 2){
          if ((anoRef % 4 == 0 && anoRef % 100 != 0) || (anoRef % 400 == 0)){
            diasMesAnterior = 29;
          }else 
          diasMesAnterior = 28;
      } else if (mesAnterior == 4 || mesAnterior == 6 || mesAnterior == 9 || mesAnterior==11){
        diasMesAnterior = 30;
      }else { 
        diasMesAnterior = 31;
      }
      dma.qtdDias += diasMesAnterior; 
    }
    if (dma.qtdMeses < 0){
      dma.qtdAnos--;
      dma.qtdMeses += 12;
    }
      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    int i = 0;
    while (texto[i] != '\0'){
      if (isCaseSensitive == 1){
          if (texto[i] == c){
            qtdOcorrencias++;
          }
      } else{
        if (toLower(texto[i]) == toLower(c)){
          qtdOcorrencias++;
        }
      }
      i++;
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */



int q4(char *strTexto, char *strBusca, int posicoes[30])
{

    int qtdOcorrencias = 0;
    int i = 0, j = 0;
    int lenTexto = 0;
    int lenBusca = 0;
    while (strTexto[lenTexto] != '\0') lenTexto++;
    while (strBusca[lenBusca] != '\0') lenBusca++;
    if (lenBusca== 0 || lenBusca > lenTexto){
        return 0;
    }
    
    int count = 0;
    for (i = 0; i <= lenTexto - lenBusca; i++){
        int match  = 1; 

        for (j = 0; j <lenBusca; j++){
            if(strTexto[i + j] != strBusca [j]){
                match = 0;
                break;
            }
        }
        if (match){ 
            qtdOcorrencias++;

            int char_pos_start = 0;
            int k = 0;
            
           
            while (k < i) {
              
                if (((unsigned char)strTexto[k]) >= 192) {
                    
                    char_pos_start++;
                    k += 2; 
                } else {
                    
                    char_pos_start++;
                    k++; 
                }
            }
            
           
            if(count + 1 < 30) { 
                posicoes[count++] = char_pos_start + 1;
                posicoes[count++] = char_pos_start + lenBusca;
            }
        }
        
        
        if (match == 0 && ((unsigned char)strTexto[i]) >= 192) {
            i++; 
        }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  if(num < 0 ) num = -num;
  
  int numero_invertido = 0;
  int temp = num;

  while (temp> 0){
    int digito = temp % 10;
    numero_invertido = numero_invertido * 10 + digito;
    temp /=10;
  }

    return numero_invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{   int qtdOcorrencias = 0;
    char strBase [20];
    char strBusca [20];

    if (numerobase < 0) numerobase = -numerobase;
    if (numerobusca < 0) numerobusca = -numerobusca;

    sprintf (strBase, "%d", numerobase);
    sprintf (strBusca, "%d", numerobusca);

    int lenBase = 0;
    while (strBase[lenBase] != '\0') {
      lenBase++;
    }
    
    int lenBusca = 0;
    while (strBusca[lenBusca] != '\0') {
      lenBusca++;
    }

    if (lenBusca == 0 || lenBusca > lenBase){
      return 0;
    }

    for (int i = 0; i <=lenBase - lenBusca; i++){
      int match = 1;
      for (int j= 0; j < lenBusca; j++){
      if (strBase[i+j] != strBusca[j]){
        match = 0;
        break;
      }
      }
      if (match){
        qtdOcorrencias++;
      }
    }
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
    int num_linhas = 8;
    int num_colunas = 10;
    int tamanho_palavra = 0;
    while (palavra[tamanho_palavra] != '\0'){ 
      tamanho_palavra++;}

    if (tamanho_palavra == 0) {
      return 0;
    }
    
    int direcoes [8] [2] = {
      {-1,0},
      {1, 0},   
      {0, -1},  
      {0, 1},   
      {1, 1},   
      {-1, 1},  
      {1, -1},  
      {-1, -1}
    };

    for (int l = 0; l < num_linhas; l++){
      for (int c= 0; c < num_colunas; c++){
        if (matriz [l][c] != palavra[0]){
          continue;
        }
        for (int d= 0; d < 8 ; d++){
          int dl = direcoes[d][0];
          int dc= direcoes[d][1];
          int achou_direcao = 1;

          for (int k = 1; k < tamanho_palavra; k++){
            int proxima_l = l + k *dl;
            int proxima_c = c + k *dc;

            if (proxima_l < 0 || proxima_l >= num_linhas || proxima_c < 0 || proxima_c >= num_colunas){
              achou_direcao = 0;
              break;
            }
            if (matriz[proxima_l] [proxima_c] != palavra[k]){
              achou_direcao = 0;
              break;
            }
          }
          if (achou_direcao)
          return 1;
        }
      }
    }
     
     return 0;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

  sDia [0] = '\0'; sMes [0] = '\0'; sAno [0] = '\0';

	for (i = 0; data[i] != '/' && data[i] != '\0'; i++){
      if (i< 2) sDia[i] = data[i];		
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;



	for (; data[j] != '/' && data[j] != '\0'; j++){
      if (i< 2) sMes [i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  if (data[j] != '/'){
    dq.valido = 0; 
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
    if(i < 4) sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;

  if (dq.iMes < 1 || dq.iMes > 12) dq.valido = 0;
  if (dq.iDia < 1 || dq.iDia > 31) dq.valido = 0;

  int bissexto =0 ;
  if ((dq.iAno % 4 == 0 && dq.iAno % 100 != 0 ) || (dq.iAno % 400 == 0)){
    bissexto = 1;
  }

  if (dq.iMes == 2 ) {
    if(bissexto == 1){
      if (dq.iDia >29 ){
        dq.valido = 0;
      }
    }else {
      if(dq.iDia > 28 ){
        dq.valido =0;
      }
    }
  }

  if (dq.iMes == 4 || dq.iMes == 6|| dq.iMes == 9|| dq.iMes == 11){
    if(dq.iDia >30 ){
      dq.valido = 0; 
    }
  }

  if(dq.iAno > 2025 || dq.iAno < 0 ){
    dq.valido = 0;
  }
    
  return dq;
}
