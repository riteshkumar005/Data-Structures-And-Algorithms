#include <iostream>
using namespace std;

int main() {
  // pattern 1
  for(int i = 0; i < 4; i++){
    for(int j = 0; j <4; j++) {
        cout << "*";
    }  
    cout << endl;  
  }

  // pattern 2

  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=4; j++) {
      cout << i << " " ;
    }
    cout << endl;
  }

  // pattern 3

  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <= 4; j++) {
      cout << j <<" ";
    }
    cout << endl;
  }
  
  // pattern 4
  for(int i = 1; i <= 4; i++){
    for(int j = 4; j >= 1; j--) {
      cout << j <<" ";
    }
    cout << endl;
  }  
  
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <= 4; j++){
      cout << 4 - j + 1 <<" ";
    }
    cout << endl;
  }

  // pattern 5

  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <= i; j++){
      cout << "*" <<" ";
    }
    cout << endl;
  }

  // pattern 6
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <= i; j++){
      cout << i <<" ";
    }
    cout << endl;
  }

  // pattern 7
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=4; j++){
      cout << 4-j+1 <<" ";
    }
    cout << endl;
  }

  //pattern 
  int n;
  cin >> n;
  int i =1;
  int count = 1;
  while(i <= n){
    int j = 1;
    while(j <= n){
      cout << count << " ";
      count = count + 1;
      j = j + 1;
    }
    cout <<endl;
    i = i + 1;

  }

  // pattern
  int n;
  cin >> n;
  int i =1;
  int count = 1;
  while(i <= n){
    int j = 1;
    while(j <= i){
      cout << count << " ";
      count = count + 1;
      j = j + 1;
    }
    cout <<endl;
    i = i + 1;

  }



  //pattern 8
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=i; j++){
      cout << i+j-1<<" ";
    }
    cout << endl;
  }

  //pattern 9
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=i; j++){
      cout << i+1-j<<" ";
    }
    cout << endl;
  }

  //pattern 10
  
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=4; j++){
      char x = 'A' + i-1;
      cout << x << " ";
    }
    cout << endl;
  }

  //pattern 11
  
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=4; j++){
      char x = 'A' + j-1;
      cout << x << " ";
    }
    cout << endl;
  }

   //pattern 12
   int n;
   cin >> n;
   int count = 0;
   for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=4; j++){
      char x = 'A'+ count;
      cout << x << " ";
      count = count + 1;
    }
    cout << endl;
  }

  //  //pattern 13
  
   for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=4; j++){
      char x = 'A' + i + j-2;
      cout << x << " ";
    }
    cout << endl;
  }

   //pattern 14
  
   for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=i; j++){
      char x = 'A' + i-1;
      cout << x << " ";
    }
    cout << endl;
  }

  //pattern 15
  
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=i; j++){
      char x = 'A' + i-1;
      cout << x << " ";
    }
    cout << endl;
  }

  //pattern 16
  
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=i; j++){
      char x = 'A' + i + j-2;
      cout << x << " ";
    }
    cout << endl;
  }


  //pattern 17
  
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <=i; j++){
      char x = 'A' + 4 - i+j-1;
      cout << x << " ";
    }
    cout << endl;
  }

  
  //pattern 18
  int n ;
  cin >> n;
  int i = 1;
 
  while(i <= n){
    int space = n - i;
    while(space){
      cout << "_"<<" ";
      space--;
    }
    
    int j = 1;
    while(j<=i){
      cout << "*"<<" ";
      j++;
    }
    
    cout << endl;
    i++;
  }

  //pattern 19
  
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <= 4-i+1; j++){

      cout << "*" << " ";
    }
    cout << endl;
  }


  // pattern 20
  int n;
  cin >> n;
  int i = 1;

  while(i <= n){
    int space = i - 1;
    while(space){
      cout << "-";
      space--;
    }
    int j = 1;
    while(j<= n-i +1){
      cout << "*" << " ";
      j++;
    }
    cout << endl;
    i++;
  }


  //pattern 21
  
  int n;
  cin >> n;
  int i = 1;

  while(i <= n){
    int space = i - 1;
    while(space){
      cout << "-";
      space--;
    }
    int j = 1;
    while(j<= n-i +1){
      cout << i << " ";
      j++;
    }
    cout << endl;
    i++;
  }

  // pattern 22
  int n;
  cin >> n;
  int i = 1;

  while(i <= n){
    int space = n - i;
    while(space){
      cout << "-";
      space--;
    }
    int j = 1;
    while(j<= i){
      cout <<i << " ";
      j++;
    }
    cout << endl;
    i++;
  }


  // pattern 23
  int n;
  cin >> n;
  int i = 1;

  while(i <= n){
    int space = i - 1;
    while(space){
      cout << "-";
      space--;
    }
    int j = 1;
    int count = i;
    while(j<= n - i + 1){
      cout << count<< " ";
      count++;
      j++;
    }
    cout << endl;
    i++;
  }



  // pattern 24
  int n;
  cin >> n;
  int i = 1;
  int count = 1;

  while(i <= n){
    int space = i - 1;
    while(space){
      cout << "-";
      space--;
    }
    int j = 1;
    while(j<= n-i +1){
      cout << count<< " ";
      count++;
      j++;
    }
    cout << endl;
    i++;
  }

  // pattern 25
  int n;
  cin >> n;
  int i = 1;
  
  
  while(i <= n){
    int space = n - i;
    while(space){
      cout << "-";
      space--;
    }
    int j = 1;
    while(j<= i){
      cout << j<< " ";
      
      j++;
    }
    int k = 1;
    int count = i - 1;
    while( k <= i-1){
      cout << count << " ";
      count--;
      k++;
    }
    cout << endl;
    i++;
  }

  // patter 26

  int n;
  cin >> n;

  int i =1;
  while( i <= n){
    int j = 1;
    while( j <= n-i+1){
      cout << j << " ";
      j++;
    }
    int k=1;
    while( k <= 2*i -2){
      cout <<"*"<<" ";
      k++;

    }
    int l = 1;
    int count  = n - i + 1;
    while(l <= n-i+1){
      cout << count << " ";
      count--;
      l++;
    }
    cout<<endl;
    i++;

  }


  

  return 0;
}
