//Análise do pior caso 

void isertionSort(int arr[], int n){
    int i, key, j;                       //l1 = 1x
    for (i = 1; i < n; i++){             //l2 = n-1x
        key = arr[i];                    //l3 = n-1x
        j = i - 1;                       //l4 = n-1x

        //arr[j] = n2
        while (j >= 0 && arr[j] > key){  //l5 = (n-1)(n2)x
            arr[j + 1] = arr[j];         //l6 = (n-1)(n2)x 
            j = j - 1;                   //l7 = (n-1)(n2)x
        }
        arr[j + 1] = key;                //l8 = n-1x 
    }
}

/* */