//функция проверки и поиска (по середине используя binarySearch)
int binarySearch(int arr[], int low, int high, int x){
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) // If the element is present at the middle
            return mid;
 
        if (arr[mid] > x)  //если середина больше то уйдет влево по значениям
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x); //иначе уйдет вправо (так как больше середины)
    }
    return -1; //если не прошел поиск то -1
}