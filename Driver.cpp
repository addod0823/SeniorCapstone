#include <iostream>
#include <fstream>
#include "KD_TREE.h"
#include <string>

using namespace std;

ifstream fin;
void menu();
Node* sample_objects(int N, Node* root);
void DoSearch(Node *root);

int main()
{
        int choice;
        string line;
        int N = 0;
        struct Node *root = NULL;
        cout << endl;
        cout << "****************Menu***************" << endl;
        menu();
        cout << "choice: ";
        cin >> choice;
        while(choice != 4)
        {
                switch(choice)
                {
                        case 1:
                        //system("python serial_port.py");
                        fin.open("x_y.txt");
                        while(!fin.eof())
                        {
                                getline(fin, line);
                                N++;
                        }
                        fin.close();
                        N = N - 1;
                        root = sample_objects(N, root);break; //Sample objs for system to recognize
                        case 2:
                        system("python plot_x_y.py"); break;//show recognized objects in a graph
                        case 3:
                        DoSearch(root);
                        break;//Perfrom range search and graph
                        default: cout << "Invalid Selection. Please select again"<< endl;
                }
        menu();
        cout << "choice: ";
        cin >> choice;
        cout << endl;
        }
        cout << "SYSTEM EXITING..." << endl;
        std::ofstream fout("x_y.txt", std::fstream::out|std::fstream::trunc);
        std::ofstream fout2("output.txt", std::fstream::out|std::fstream::trunc);

return 0;
}
void menu()
{
        cout << "1 - Sample colored objects to be recognized" << endl;
        cout << "2 - Show recognized objects in a graph" << endl;
        cout << "3 - Perform range search and graph" << endl;
        cout << "4 - Quit" << endl;
}

Node *sample_objects(int N, Node* root)
{

        int ROWS = N / k;
        cout << ROWS << " Objects recognized"  << endl;

        int points[ROWS][k];
        ifstream fin;

        fin.open("x_y.txt");
        for(int i = 0; i < ROWS; i++)
        {
                for(int j = 0; j < k; j++)
                {
                        fin >> points[i][j];
                }

        }
        fin.close();

        int n = sizeof(points)/sizeof(points[0]);
        for (int i=0; i<n; i++)
        root = insert(root, points[i]);

        return root;
}
void DoSearch(Node *root)
{
        std::ofstream fout("output.txt", std::fstream::out|std::fstream::trunc);

        int p1[2];
        int p2[2];
        cout << "Enter first point. Point should be in the correct graph range. See Graph for Correct range" << endl;
        cin >> p1[0];
        cin >> p1[1];
        cout << "Enter second point. Point should be in the correct graph range. See Graph for Correct range" << endl;
        cin >> p2[0];
        cin >> p2[1];

        vector<Node> inp = rangesearch(root, p1, p2);
        for(int i=0; i<inp.size(); i++)
        {
          cout << inp[i].point[0] << "," << inp[i].point[1] << "\n";
           fout<<inp[i].point[0]<<","<<inp[i].point[1]<<"\n";
        }
        fout.close();
        system("python plot_range.py");
}


