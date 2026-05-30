/******************************************************************************

Jakub Gara
Informatyka St. 1 rok

"Kalkulator (przynajmniej) 8 dzialaniowy"
02 XII 2025 r.

*******************************************************************************/

#include <iostream>
#include <cmath>
#include <tuple>
using namespace std;

// deklaracja funkcji

void text(int funtionTextNumber);

double operationNumber();

tuple < double, bool > operationResult(double functionDefaultNumber, int functionOperationName);

// glowna

int main()
{
    double defaultNumber;
    
    // pobieranie liczby do operacji
    text(1);
	cin >> defaultNumber;
	cout << endl;
    
    // deklaracja zmiennej do petli
    bool loop = true;
    
    // petla kalkulatora
    while(loop == true) 
    {
        // spis obliczen
        text(2);
        
        int operationName;
       
        // pobieranie numeru dzialania
        text(3);
        cin >> operationName;
        
        // jesli input nie jest liczba to przypisuje wartosc do zakonczenia
        if (cin.fail()) 
        {
            operationName = 99;
        }
        
        cout << endl;
        
        // tuple
        tie(defaultNumber, loop) = operationResult(defaultNumber, operationName);
        
        // podanie wyniku dzialania
        if (loop == true)
        {
	        text(5);
            cout << defaultNumber << endl;
            cout << endl;
        }
    }
    
    // podanie wyniku ostecznego kalkulatora
    text(7);
    cout << defaultNumber;
    
    return 0;
}

// funkcje do wypisywania tekstu
void text(int funtionTextNumber)
{
    switch (funtionTextNumber)
    {
        case 1:
            cout << "Liczba początkowa: " << endl;
            break;
        
        case 2:
            cout << "[0] Dodawanie"             << endl;
            cout << "[1] Odejmowanie"           << endl;
            cout << "[2] Mnożenie"              << endl;
            cout << "[3] Dzielenie"             << endl;
            cout << "[4] Potęgowanie"           << endl;
            cout << "[5] Pierwiastkowanie"      << endl;
            cout << "[6] Modulo"                << endl;
            cout << "[7] Logarytm naturalny"    << endl;
            cout << "[8] Liczba przeciwna"      << endl;
            cout << "[9] Liczba odwrotna"       << endl;
            cout << endl;
            cout << "[!] Cokolwiek innego zakończy program" << endl;
            cout << endl;
            break;
        
        case 3:
            cout << "Numer działania: " << endl;    
            break;
        
        case 4:
            cout << "Liczba działania: " << endl;  
            break;
        
        case 5:
            cout << "Wynik:" << endl;  
            break;
            
        case 6:
            cout << "Błąd działania - podano 0. Spróbuj ponownie." << endl;
            break;
            
        case 7:
            cout << "Ostateczny wynik:" << endl;
            break;
    }
}

// funkcja pobierania liczby potrzebenj do niektorych obliczen
double operationNumber()
{
    double operationNumber;
    
    text(4);
    cin >> operationNumber;
    cout << endl;
    
    return operationNumber;
}


// funkcja obliczeniowa
tuple < double, bool > operationResult(double functionDefaultNumber, int functionOperationName)
{

    double functionResult = functionDefaultNumber;
    bool functionLoop = true; 
    
    double functionOperationNumber;
    
    switch(functionOperationName)
    {
        // dodawanie
        case 0:
            functionOperationNumber = operationNumber();
            functionResult = functionDefaultNumber + functionOperationNumber;
            break;
        
        // odejmowanie
        case 1:
            functionOperationNumber = operationNumber();
            functionResult = functionDefaultNumber - functionOperationNumber;
            break;
            
        // mnozenie    
        case 2:
            functionOperationNumber = operationNumber();
            functionResult = functionDefaultNumber * functionOperationNumber;
            break;
        
        // dzielenie    
        case 3:
            functionOperationNumber = operationNumber();
            
            // sprawdzanie dzielenia przez 0
            if (functionOperationNumber != 0) 
            {
               functionResult = functionDefaultNumber / functionOperationNumber; 
            }
            else
            {
                text(6);
                cout << endl;
            }
            break;
        
        // potega    
        case 4:
            functionOperationNumber = operationNumber();
            functionResult = pow(functionDefaultNumber, functionOperationNumber);
            break;
        
        // pierwiastkowanie do potegi n-tej    
        case 5:
            functionOperationNumber = operationNumber();
            
            //sprawdzanie pierwiastka stopnia 0
            if (functionOperationNumber != 0) 
            {
                functionResult = pow(functionDefaultNumber, (1 / functionOperationNumber));
            }
            else
            {
                text(6);
                cout << endl;
            }
            break;
        
        // modulo
        case 6:
            functionOperationNumber = operationNumber();
            
            //sprawdzanie modulo przez 0
            if (functionOperationNumber != 0) 
            {
                functionResult = fmod(functionDefaultNumber, functionOperationNumber);
            }
            else
            {
                text(6);
                cout << endl;
            }
            break;
        
        // logarytm naturalny     
        case 7:
            functionResult = log(functionDefaultNumber);
            break;
        
        // liczba przeciwna    
        case 8:
            functionResult = (-1) * functionDefaultNumber;
            break;
        
        // liczba odwrotna    
        case 9:
            functionResult = 1 / functionDefaultNumber;
            break;
        
        // koniec
        default:
            functionLoop = false;
            break;
    }
    
    // zwracanie tupla
    return make_tuple(functionResult, functionLoop);
}