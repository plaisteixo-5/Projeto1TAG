#include "Graph.cpp"

void menu(vector<int> ajd_list[]){
    int op;

    do{
        system(clear);

        cout << endl << "\t\tMENU" << endl << endl;
        cout << "(1) Mostrar grafo em formato de lista de adjacência." << endl;
        cout << "(2) Lista de cliques." << endl;
        cout << "(3) Mostrar Coeficiente." << endl;
        cout << "(0) Sair." << endl;
        
        cout << "Digite sua opção: ";
        cin >> op;

        switch(op){
            case 0:
                system(clear);

                break;
                
            case 1:
                system(clear);

                showGraph(ajd_list);
                cout << "\nAperte ENTER retornar ao Menu\n";
                getchar();
                getchar();
                break;

            case 2:
                system(clear);
                
                showCliques();

                cout << "\nAperte ENTER retornar ao Menu\n";
                getchar();
                getchar();
                break;

            case 3:
                system(clear);

                cout << calculaCoeficiente(ajd_list) << endl;

                cout << "\nAperte ENTER retornar ao Menu\n";
                getchar();
                getchar();
                break;
            
            default:
                system(clear);

                cout << "Comando não reconhecido. Aperte ENTER para retornar ao Menu\n";
                getchar();
                getchar();
                break;
        }

    } while(op != 0);
}

int main(){
    vector<int> adj_vector[63];
    vector<int> R, P, X;

    for(int i = 1 ; i < 63 ; i++) P.push_back(i); // Initialize P with all 62 vertices

    ifstream file("soc-dolphins.mtx");

    while(file.peek() == '%') file.ignore(2048, '\n');
    file.ignore(2048, '\n');

    int flagValues;
    int values[2];

    flagValues = 0;

    while(!file.eof()){
        if(flagValues == 2){
            addEdge(adj_vector, values);

            flagValues = 0;
        }

        file >> values[flagValues];
        flagValues++;
    }
    file.close();

    BronKerbosch(R, P, X, adj_vector);

    menu(adj_vector);
    
    return 0;
}