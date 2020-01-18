#include <iostream> 
#include <cmath>
using namespace std; 
  
// gcd calculation 
unsigned gcd(unsigned a, unsigned b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
  
// powermod(b, e, m) = (b^e) % m
unsigned powermod(unsigned b, unsigned e, unsigned m)
{
    if (e == 0)
        return 1;

    unsigned temp = powermod(b, e/2, m);
    unsigned ans = (temp * temp) % m;
    if (e % 2 == 0)
        return ans;
    else
        return (b * ans) % m;
}
 
// Carmicheal
bool checkCarmichael(unsigned n) 
{ 
    int factor = 0;
    int s = sqrt(n);
    for (unsigned b = 2; b < n; b++) { 
        if(b > s && !factor){
            return false;
        }
        if (gcd(b, n) > 1){
            factor = 1;
        }
        else{
            if (powermod(b, n - 1, n) != 1) 
                return false; 
        } 
    } 
    return true; 
} 
   
int main() 
{
    unsigned int n;
    int count = 0;
    for(n = 3;; n++){
        if(checkCarmichael(n)){
            cout << n << endl;
            count++;
        }
        if(count == 10)
            break;
            
    }
    return 0;
} 


