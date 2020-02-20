#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
int main() {
  int maxSlices; // No.of Maximum Slices
  int pizzas; // Type of Pizzas Available
  //int slices[pizzas];
  int *slices;
  fstream file;
  int word; // For Reading characters from file
  string fileName; // Filename of Test Cases
  cin >> fileName;
  int *usedPizza;// No. of Slices in Each pizza
  int *total;
  int sum = 0;
  int max = 0;
  int nPizzas = 0;
  int a=0;
  file.open(fileName);
  file >> maxSlices;
  file >> pizzas;
  // 
  slices = (int*) malloc(pizzas*sizeof(int));
  //
  total=(int*)malloc(pizzas*sizeof(int));
  usedPizza=(int*)malloc(pizzas*sizeof(int));
  int count = pizzas;
  int **indexPizzas;
  indexPizzas = (int**)malloc(pizzas*sizeof(int*)*pizzas);
  for(int i = 0; i < pizzas; i++) {
    indexPizzas[i] = (int*)malloc(pizzas*sizeof(int)*pizzas);
  }
  //
  for(int i=0; i < pizzas ; i++) {
    file >> slices[i];
  }
  for(int i = 0; i < pizzas; i++) {
    for(int j = count-1; j >= 0; j--) {
    	if((sum + slices[j]) > maxSlices) {
    		indexPizzas[i][j] = -1;
    		continue;
    	}
      sum += slices[j];
      indexPizzas[i][j] = j;
      usedPizza[i] = j;
    }
    total[i] = sum;
    count--;
    sum = 0;
  }
  max = total[0];
  for(int i = 0; i < pizzas; i++) {
    if(max <= maxSlices ) {
      if(total[i+1]>max && total[i+1]<=maxSlices)
      {
        max=total[i+1];
    	  a = i+1;
      }
    	for(int j=0; j<pizzas; j++) {
    		if(indexPizzas[a][j] != -1) {
    			nPizzas++;
    		}
    		//nPizzas++;
    	}
    	break;
    }
  }
  cout << nPizzas << endl;
  for(int i =0; i< pizzas; i++) {
  	if(indexPizzas[a][i] == -1) {
  		continue;
  	}
  	cout << indexPizzas[a][i] << " ";
  }
  free(indexPizzas);
  free(total);
  free(usedPizza);
  free(slices);
  return 0;
}

