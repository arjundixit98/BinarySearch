import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        Random random = new Random();
        int size;
        int[] arr;
        int key;
        int searchResult;

        System.out.println("Enter to upper limit: ");
        size = input.nextInt();

        arr = new int[size];

        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i] = random.nextInt(100));
            System.out.print(" ");
        }
        System.out.println();
        quickSort(arr, 0, arr.length-1);

        System.out.println("Enter value for search: ");
        key = input.nextInt();

        searchResult = binarySearch(arr, key, 0, arr.length-1);

        if(searchResult==-1){
            System.out.println("Is not found value");
        }
        else{
            System.out.println("Is found value " + key);
        }
    }


    static int binarySearch(int[] vec, int key, int left, int right){
        int mid = (left+right)/2;
        int midValue = vec[mid];

        if(left >= right)
            return -1;

        if(key == midValue)
            return mid;

        else if(key < midValue){
            return binarySearch(vec, key, left, mid);
        }
        else {
            return binarySearch(vec, key, mid+1, right);
        }
    }


    static void quickSort(int[] vec1, int left, int right){
        int i = left;
        int j = right;
        int p = vec1[(left+right)/2];

        while(i<=j){
            while(vec1[i]<p){
                i++;
            }

            while(vec1[j]>p){
                j--;
            }

            if(i<=j){
                int temp = vec1[i];
                vec1[i] = vec1[j];
                vec1[j] = temp;
                i++;
                j--;
            }
        }
        if(j>left) quickSort(vec1, left, j);
        if(i<right) quickSort(vec1, i, right);
    }
}


