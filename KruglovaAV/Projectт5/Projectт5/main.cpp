#include <iostream>
#include "vector.h"

using namespace std;

int main(int argc, char** argv)
{   
    int n1 = 0, n2 = 0, operation = 0;
    TVector v1, v2, res;
    char* infilename, * outfilename;
    if (argc < 4) {
        cout << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return 1;
    }
    infilename = argv[2];
    outfilename = argv[3];
  
	/*std::cin >> v1 >> v2;
	std::cout << v1;
	std::cout << v2;
	std::cout << res;
	return 0;*/
    while (true) {
        cout << "Выберите операцию над векторами: \n1 - сложение векторов 2 - вычитание векторов 3 - скалярное произведение векторов 4 - выход\n";
        int operation;
        cin >> operation;

        TVector res; 
        double result;

        switch (operation) {
        case 1:
            res = v1 + v2;
            res.rff()

            break;
        case 2:
            res = v1 - v2;
            
            //write(outfilename, &res, "разность");
            break;
        case 3:
            result = v1 * v2;
            

            cout << "Скалярное произведение векторов: " << /// << endl;
            break;
        case 4:
            return 0;
        default:
            cout << "Некорректный ввод\n";
        }
    }
    
}