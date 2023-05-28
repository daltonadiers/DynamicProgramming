#include <iostream>
#include <vector>
using namespace std;

int main(){
    int capacidade, itens;
    cout << "Digite a capacidade da sua mochila: ";
    cin >> capacidade;
    capacidade+=1;
    cout << endl;
    cout << "Digite agora o numero de itens disponiveis que voce tem: ";
    cin >> itens;
    cout << endl;
    int matriz[itens][2];
    cout << "Preciso de informacoes sobre os itens..." << endl;
    for(int i=0; i<itens; i++){
        cout << "Digite o peso e o lucro para o item " << i << endl;
        cin >> matriz[i][0] >> matriz[i][1];
    }
    cout << "Agora que temos os valores, podemos comecar..." << endl;
    cout << "Calculando..." << endl;



    int matrizAns[itens][capacidade];           //VAMOS COMEÇAR A CONSTRUIR A MATRIZ DE RESPOSTA
    for(int i=0; i<itens; i++){
        for(int j=0; j<capacidade; j++){
            if(i==0 || j==0){                   //CASO QUALQUER UM DOS ÍNDICES (I OU J) SEJA 0, A 
                matrizAns[i][j]=0;              // POSIÇÃO SERÁ PREENCHIDA COM 0, POIS SEM CAPACIDADE
            }                                   //SEM LUCRO, SEM ITEM, SEM LUCRO;
            
            //IMPORTANTE: LINHA SE REFERE AO ÍNDICE I, ENQUANTO CAPACIDADE SE REFERE AO ÍNDICE J;


            else{
                if(j<matriz[i][0]){                         //AQUI VERIFICAMOS SE O LUCRO DA CAPACIDADE
                    matrizAns[i][j] = matrizAns[i-1][j];    //REFERIDA JÁ FOIPREENCHIDO ANTERIORMENTE, EM CASO POSITIVO, O COPIAMOS PARA A POSIÇÃO ATUAL
                }else{
                int valor1;
                valor1 = matriz[i][1];             //A VARIAVEL AUXILIAR VALOR1 RECEBE O LUCRO GERADO PELO ITEM DE CAPACIDADE ATUAL
                int aux = matriz[i][0];            //A VARIAVEL AUX RECEBE O VALOR DO PESO DO ITEM ATUAL
                if((j-aux)>0){ 
                    valor1+= matrizAns[i-1][j-aux];  //SE A CAPACIDADE FOR MAIOR DO QUE O PESO DO ITEM, VOLTAMOS NA LINHA ANTERIOR E SOMAMOS O VALOR ASSOCIADO A CAPACIDADE RESTANTE À VARIÁVEL VALOR1 
                }
                if(valor1>=matrizAns[i-1][j]){      //SE VALOR1 FOR MAIOR OU IGUAL AO VALOR REFERIDO DESTA CAPACIDADE NA LINHA ANTERIOR, O ÍNDICE ATUAL [I][J]DA MATRIZ RECEBE VALOR1
                    matrizAns[i][j] = valor1;
                    if(j==11){
                        cout << "Indice: " << i << ", " << j << ", " << valor1 << endl;
                    }
                }else{                              //CASO CONTRARIO, RECEBE O VALOR DE MESMA CAPACIDADE DA LINHA ANTERIOR
                    matrizAns[i][j]=matrizAns[i-1][j];
                }
            }
            }
        }
    }
    //MOSTRAR MATRIZ    
    for (int i = 0; i < itens; i++) {
        for (int j = 0; j < capacidade; j++) {
            std::cout << matrizAns[i][j] << " ";
        }
        std::cout << "\n";
    }
    int aux2 = matrizAns[itens-1][capacidade-1];
    cout << "" << endl;
    cout << "Verifique se a matriz está construida corretamente!!!" << endl;
    cout << "Nosso lucro maximo obtido foi de: " << aux2 << endl;
    cout << "Agora vamos verificar quais itens foram adicionados na mochila..." << endl;

    //SABEMOS QUE NOSSO VALOR MAXIMO É O ÚLTIMO ÍNDICE DA MATRIZ
    //PARA IDENTIFICAR OS ITENS COLOCADOS NA MOCHILA COMEÇAMOS POR ELE
    int n=0;
    int i = itens-1;
    int j = capacidade-1;
    vector <int> answer;
    while(n<aux2){
        if(matrizAns[i][j]==matrizAns[i-1][j]){
            i--;
        }else{
            answer.push_back(matriz[i][0]);
            n += matriz[i][1];
            j -= matriz[i][0];
            i--;
        }
    }
    //JA DESCOBRIMOS OS ITENS E ARMAZENAMOS NO VETOR ANSWER, VAMOS MOSTRÁ-LOS:
    cout << "Peso dos itens utilizados: ";
    for(int t=0; t<answer.size(); t++){
        cout << answer[t] << ", ";
    }
    cout << endl;
}
