#include<iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr1[n], arr2[m], arr3[m], i, j, k = 0, x, tot;

   
    for(i = 0; i < n; i++)
    cin >> arr1[i];
    
    for(i = 0; i < m; i++)
    cin >> arr2[i];

    // Finding and storing common elements
    for(i=0; i < n; i++) {
        for(j=0; j < m; j++) {
            if(arr1[i]==arr2[j]) {
                tot = 0;

                for(x=0; x < k; x++) {
                    if(arr1[i]==arr3[x])
                    tot++;
                }

                if(tot==0) {
                    arr3[k] = arr1[i];
                    k++;
                }
            }
        }
    }

    // Printing common elements
    
    for(i=0; i<k; i++)
        cout << arr3[i] << " ";

        cout << endl;
    return 0;
}