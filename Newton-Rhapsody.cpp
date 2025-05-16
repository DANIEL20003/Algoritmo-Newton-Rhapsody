#include <iostream>
#include <cmath>

using namespace std;

double fun(double x){
       return (x * x * x - 3 * x * x + 1); // La función está correctamente definida
}

int main(){
    int contador = 0;
    double x0, x1, df, emax, error;
    cout << "Ingrese el Punto Inicial: "; cin >> x0;
    cout << "Ingrese el error maximo aceptado: "; cin >> emax;

    do{
        df = (fun(x0 + 0.0001) - fun(x0)) / 0.0001; 
        x1 = x0 - (fun(x0) / df);  
        error = fabs(x1 - x0);  
        x0 = x1; 
        contador += 1;  
        cout << "Iteracion " << contador << ": x1 = " << x1 << ", error = " << error << endl;  // Mostrar iteración
    }while (error > emax && contador <= 30);  

    if (contador <= 30){
        cout << endl << "---> La raiz aproximada es:  " << x1 << endl;
    }
    else{
        cout << endl << "---x No existe raiz" << endl;
    }

    return 0;
}
